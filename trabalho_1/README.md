# Trabalho - Linguagens de Programação

**Aluno:** Ricardo Santos Siqueira\
**DRE:** 118167558\
**Período:** 2021.1 

## Ambiente de desenvolvimento

**OS:** Manjaro Linux x86_64\
**Kernel:** 5.13.12-1-MANJARO\
**Shell:** fish **3.3**.1

## Objetivo

  Programa para download e tratamento básico de imagens feito em C++ e [Python](./python/README.md).  

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
./main
```
  Após a inicialização do programa o usuário inicialmente deve entrar com a URL referente a imagem que deseja utilizar. Uma vez inicializada corretamente a url o programa apresentará um menu com as opções disponíveis, sendo estas:

  1 - Cortar faces\
  2 - Ajustar proporcao da imagem para 3:4\
  3 - [Filtro] Suavizar detalhes\
  4 - [Filtro] Realcar detalhes\
  5 - [Filtro] Ajustar cor\
  6 - [Filtro] Ajustar contraste\
  7 - Salvar copias e sair

  Ao selecionar uma opção um submenu é exibido e o usuário entra com os parâmetros para executar a ação ou pode retornar ao menu principal.

  O programa é finalizado ao selecionar a opção 7, correspondente a salvar as imagens geradas e sair do programa.

## Exemplo de imagem editada
  **[Original](https://images.unsplash.com/photo-1494790108377-be9c29b29330?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=668&q=80):** 
  <img align="center" src="assets/original.png" height=300/>
  
  **Editada:** 
  <img align="center" src="assets/edited.png" height=300/>
  
  Parâmetros da edição: Cortar face, ajuste 3:4, suavizar detalhes, ajuste de cor 1.3 (130%) e ajuste de contraste 1.1 (110%).

## Referências externas

[How to make std::cin take only numbers (stackoverflow)](https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers)

[Call destructor in C++](https://www.delftstack.com/howto/cpp/call-destructor-in-cpp/)