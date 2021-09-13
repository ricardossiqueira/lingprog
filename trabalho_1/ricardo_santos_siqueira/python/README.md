# Trabalho - Linguagens de Programação

**Aluno:** Ricardo Santos Siqueira\
**DRE:** 118167558\
**Período:** 2021.1 

## Ambiente de desenvolvimento

**OS:** Manjaro Linux x86_64\
**Kernel:** 5.13.12-1-MANJARO\
**Shell:** fish **3.3**.1

## Dependências

  Esse script depende das seguintes bibliotecas:

  - numpy
  - pillow
  - opencv-python
  - requests

  Todas podem ser instaladas via **pipenv** configurado no projeto via comando

  ```console
    pipenv install

    # Caso nao possua o pipenv instalado, pode instala-lo com seguinte comando:
    # pip install pipenv
  ```
  Após executar esse comando inicie o ambiente **pipenv** com o comando
  
  ```console
  pipenv shell
  ```
  Para desativar o ambiente **pipenv** execute o comando
  
  ```console
  deactivate
  ```

## Referências externas

[Basic Usage of Pipenv](https://pipenv.pypa.io/en/latest/basics/)

[NumPy.asarray documentation](https://numpy.org/doc/stable/reference/generated/numpy.asarray.html)

[Pillow documentation](https://pillow.readthedocs.io/en/stable/)

[OpenCV documentation](http://www.opencv.org.cn/opencvdoc/2.3.2/html/genindex.html)

[Haarcascade Frontal Face Alt2](https://github.com/opencv/opencv/blob/master/data/haarcascades/haarcascade_frontalface_alt2.xml)

## Créditos

Esse programa utiliza o algoritimo [Haarcascade Frontal Face Alt2](https://github.com/opencv/opencv/blob/master/data/haarcascades/haarcascade_frontalface_alt2.xml) disponível na biblioteca OpenCV para detecção das faces nas imagens.