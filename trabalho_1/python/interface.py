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

'''
OPTIONS
    --uri=<uri>
    --crop
    --save-as=<png, jpeg>
    --filters=<color, contrast, detail, smooth>
    --mod=<float > 1>
'''


if __name__ == "__main__":
    uri = sys.argv[1]

    ir = ImageResolver(uri)
    ir.loadImageFromWeb()
    ir.mapFaceRect()
    ir.cropImage()
    colorEnhance = ir.colorFilter(ir.croppedIm[0])
    ir.saveAs(im=colorEnhance, format='png')

    # for arg in sys.argv:
    #     print(arg)
