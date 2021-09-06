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
    uri = sys.argv[1]

    ir = ImageResolver(uri)
    ir.loadImageFromWeb()
    ir.mapFaceRect()
    ir.cropImage()
    ir.saveAs(im=ir.croppedIm[0], format='jpeg')


# ir = ImageResolver(
#     "https://images.unsplash.com/photo-1494790108377-be9c29b29330?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=668&q=80")
# ir.loadImageFromWeb()
# ir.mapFaceRect()
# ir.cropImage()
# ir.saveAs(im=ir.croppedIm[0], format='jpeg')
