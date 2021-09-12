'''
Trabalho 1 - Linguagens de Programacao EL1
Aluno: Ricardo Santos Siqueira
DRE: 118167558
Periodo: 2021.1
Arquivo: interface.py
Descricao: Interface da classe ImageResolver com C++
'''

# Importando a classe criada em ./ImageResolver.py
from ImageResolver import ImageResolver

# Biblioteca para uso das diretivas argc e argv
import sys

if __name__ == "__main__":
    uri, faces, _3x4, smooth, detail, color, contrast = sys.argv[1:]
    color, contrast = float(color), float(contrast)

    # Instancia classe e carrega a URI
    ir = ImageResolver(uri)
    # Baixa a imagem, armazena o BLOB e retorna uma copia
    im = [ir.loadImageFromWeb()]

    if (faces == 'true'):
        # Mapeia os rostos na imagem
        ir.mapFaceRect()
        # Corta os rostos mapeados e cria o array im
        ir.cropImage()
        
        if (_3x4 == 'true'):
            im = ir.croppedIm3x4
        else:
            im = ir.croppedIm

    if (smooth == 'true'):
        tmp=[]
        for elem in im:
            # Aplica o filtro de cor para todas as subimagens em im
            tmp.append(ir.smoothFilter(im=elem))
        im=tmp

    if (detail == 'true'):
        tmp=[]
        for elem in im:
            # Aplica o filtro de cor para todas as subimagens em im
            tmp.append(ir.detailFilter(im=elem))
        im=tmp

    if (color != 1.0):
        tmp=[]
        for elem in im:
            # Aplica o filtro de cor para todas as subimagens em im
            tmp.append(ir.colorFilter(im=elem, mod=color))
        im=tmp

    if (contrast != 1.0):
        tmp=[]
        for elem in im:
            # Aplica o filtro de contraste para todas as subimagens em im
            tmp.append(ir.contrastFilter(im=elem, mod=contrast))
        im=tmp

    imName=[]
    for elem in im:
        imName.append(ir.saveAs(im=elem, format='png'))
    
    sys.stdout.write('\n'.join(imName))
