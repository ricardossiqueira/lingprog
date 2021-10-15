# Trabalho - Linguagens de Programação

**Aluno:** Ricardo Santos Siqueira\
**DRE:** 118167558\
**Período:** 2021.1 

## Ambiente de desenvolvimento

**OS:** Manjaro Linux x86_64\
**Kernel:** 5.13.12-1-MANJARO\
**Shell:** fish **3.3**.1

## Objetivo

  Programa para download e tratamento básico de imagens feito em C++ e [Python 3.9](./python/README.md).  

## Dependências

Esse projeto depende de alguma bibliotecas Python para funcionar, caso já não tenha instalado, favor instalar antes de tentar executar. Mais informações no [README do script Python](./python/README.md).

**Antes de compilar e executar tenha ceteza de visitar a referência acima.**

## Compilação

```console
make all
```

## Limpeza

```console
make clean
```

## Utilização

```console
# Antes de executar tenha certeza que o ambiente pipenv está ativo

./main
```
  Após a inicialização do programa o usuário inicialmente deve entrar com a URL referente a imagem que deseja utilizar. Uma vez inicializada corretamente a url o programa apresentará um menu com as opções disponíveis, sendo estas:

  1 - Cortar faces\
  2 - Ajustar proporção da imagem para 3:4\
  3 - [Filtro] Suavizar detalhes\
  4 - [Filtro] Realcar detalhes\
  5 - [Filtro] Ajustar cor\
  6 - [Filtro] Ajustar contraste\
  7 - Salvar cópias e sair

  Ao selecionar uma opção um submenu é exibido e o usuário entra com os parâmetros para executar a ação ou pode retornar ao menu principal.

  O programa é finalizado ao selecionar a opção 7, correspondente a salvar as imagens geradas e sair do programa.

## Exemplo de imagem editada

   | [Original](https://images.unsplash.com/photo-1494790108377-be9c29b29330?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=668&q=80) |                 Editada                 |
   | :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :-------------------------------------: |
   |                                                                ![Original](assets/original.png "Original")                                                                | ![Editada](assets/edited.png "Editada") |
  
  Parâmetros da edição: Cortar face, ajuste 3:4, suavizar detalhes, ajuste de cor 1.3 (130%) e ajuste de contraste 1.1 (110%).

  Sugestão de imagem para teste do programa: [link](https://images.unsplash.com/photo-1628891890377-57dba2715caf?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=1171&q=80).


## Referências externas

[How to make std::cin take only numbers (stackoverflow)](https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers)

[Call destructor in C++](https://www.delftstack.com/howto/cpp/call-destructor-in-cpp/)

## Créditos

Esse programa utiliza o algoritimo [Haarcascade Frontal Face Alt2](https://github.com/opencv/opencv/blob/master/data/haarcascades/haarcascade_frontalface_alt2.xml) disponível na biblioteca OpenCV para detecção facial.