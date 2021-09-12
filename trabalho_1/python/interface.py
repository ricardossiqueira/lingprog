'''
Trabalho - Linguagens de Programacao
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
    # Baixa a imagem e armazena o BLOB na classe
    im = ir.loadImageFromWeb()

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
        im = map(ir.smoothFilter, im)

    if (detail == 'true'):
        im = map(ir.detailFilter, im)

    if (color != 1.0):
        # A funcao map espera que todos os argumentos da funcao de iteracao 
        # sejam vetores de mesmo comprimento, mas como o valor do modificador e
        # uma constante utilizo uma lambda function para abstrair o segundo
        # parametro da funcao anonima passada como argumento da funcao map
        im = map(lambda arg: ir.colorFilter(im=arg, mod=color), im)

    if (contrast != 1.0):
        im = map(lambda arg: ir.contrastFilter(im=arg, mod=contrast), im)

    imName=[]
    for i in range(len(im)):
        imName.append(ir.saveAs(im=im[i], index=i))
    
    sys.stdout.write('\n'.join(imName))
