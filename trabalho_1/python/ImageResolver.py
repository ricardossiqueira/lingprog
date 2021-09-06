'''
Trabalho 1 - Linguagens de Programacao EL1
Aluno: Ricardo Santos Siqueira
DRE: 118167558
Periodo: 2021.1
Arquivo: ImageResolver.py
Descricao: Classe que implementa as funcoes de manipulacao de imagens
'''

# Biblioteca de processamento de imagens
from PIL import Image, ImageFilter, ImageEnhance

# Biblioteca para lidar com o buffer de imagem
from numpy import asarray

# Biblioteca para requisicoes http
import requests

# Biblioteca do opencv para aplicar o algoritimo de deteccao
import cv2

# handle argc and argv
import sys


class ImageResolver:
    # Modelo para extracao das coordenadas do rosto da pessoa
    __haarcascade = './haarcascade_frontalface_alt2.xml'  # Static

    # Getters
    @property
    def croppedIm(__self__):
        return __self__.__croppedIm

    @property
    def croppedIm3x4(__self__):
        return __self__.__croppedIm3x4

    # Constructor
    def __init__(__self__, uri):
        __self__.uri = uri
        __self__.__croppedIm = []
        __self__.__croppedIm3x4 = []

    # Carrega uma imagem da internet dada uma URI
    def loadImageFromWeb(__self__):
        try:
            req = requests.get(__self__.uri, stream=True)
            req.raise_for_status()
        except requests.exceptions.HTTPError as err:
            print(f'Erro: <{err}>')
            exit(1)
        else:
            req = requests.get(__self__.uri, stream=True)
            __self__.im = Image.open(req.raw)

    # Mapeia os valores de corte para os rostos encontrados nas imagens
    def mapFaceRect(__self__):
        # Converte a imagem para tons de cinza
        grayScaleIm = cv2.cvtColor(asarray(__self__.im), cv2.COLOR_BGR2GRAY)

        # Aplica o algoritimo
        faceCascade = cv2.CascadeClassifier(__self__.__haarcascade)
        __self__.facesMap = faceCascade.detectMultiScale(grayScaleIm, 1.1, 4)

    # Recentraliza a imagem no rosto apos o cropping
    def offsetAdjust(__self__, _3x4, original):
        xf, yf, wf, hf = _3x4  # sempre menor que o tam original
        _, _, w0, h0 = original

        skewX = w0 - wf
        skewY = h0 - hf

        return xf+(skewX//2), yf+(skewY//2), wf+(skewX//2), hf+(skewY//2)

    # Algoritimo para ajustar o aspect ratio da imagem para 3:4. Pode ser
    # ajustado por soma ou subtracao no tamanho do corte, sendo o default a soma
    def aspectRatio3x4(__self__, croppingParams, pref='add'):
        x, y, w, h = croppingParams

        done = False
        while (not done):
            ratio = (w-x)/(h-y)
            if (ratio > 3/4):
                if (pref == 'sub'):
                    w -= 1
                elif (pref == 'add'):
                    h += 1
            elif (ratio < 3/4):
                if (pref == 'sub'):
                    h -= 1
                elif (pref == 'add'):
                    w += 1
            else:
                done = True

        return __self__.offsetAdjust((x, y, w, h), croppingParams)

    # Melhor ajuste para o ajuste do aspect ratio da imagem para 3:4
    def aspectMode(__self__, sizes):
        # se o crop por adicao estourar o limite da imagem retorna indicando para
        # fazer o crop por subtracao
        x, y, w, h = __self__.aspectRatio3x4(sizes, pref='add')
        max_w, max_h = __self__.im.size

        if (x < 0 or y < 0 or w > max_w or h > max_h):
            return "sub"
        else:
            return "add"

    # Aplicando os algoritimos para lidar com o corte das imagens
    def cropImage(__self__):
        max_w, max_h = __self__.im.size

        for (x, y, w, h) in __self__.facesMap:
            i, j, k, l = (x, y, w, h)
            cropBorder = w*max_w//max_h

            if (x - cropBorder < 0):
                i = 0
            else:
                i = x - cropBorder

            if (y - cropBorder < 0):
                j = 0
            else:
                j = y - cropBorder

            if (x + w + cropBorder > max_w):
                k = max_w
            else:
                k = x + w + cropBorder

            if (y + h + cropBorder > max_h):
                l = max_h
            else:
                l = y + h + cropBorder

            __self__.__croppedIm.append(__self__.im.crop((i, j, k, l)))

            __self__.__croppedIm3x4 = __self__.im.crop(
                __self__.aspectRatio3x4(
                    croppingParams=(i, j, k, l),
                    pref=__self__.aspectMode(
                        __self__.aspectRatio3x4(
                            croppingParams=(i, j, k, l)
                        )
                    )
                )
            )

    # Filtros de imagem
    def smoothFilter(__self__, im=None):
        if (im == None):
            im = __self__.im
        im.filter(ImageFilter.SMOOTH)
        return

    def detailFilter(__self__, im=None):
        if (im == None):
            im = __self__.im
        im.filter(ImageFilter.DETAIL)
        return

    def contrastFilter(__self__, im=None, mod=1.3):
        if (im == None):
            im = __self__.im
        ImageEnhance.Contrast(im).enhance(mod)
        return

    def colorFilter(__self__, im=None, mod=1.3):
        if (im == None):
            im = __self__.im
        ImageEnhance.Color(im).enhance(mod)
        return

    def saveAs(__self__, im=None, format='PNG', index=None):
        if (im == None):
            im = __self__.im
        im.save(
            f'image{"" if (index == None) else index }.{format.lower()}',
            format.upper()
        )
