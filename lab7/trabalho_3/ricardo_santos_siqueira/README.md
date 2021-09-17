# Exercício Avaliado 3 - Linguagens de Programação

**Aluno:** Ricardo Santos Siqueira\
**DRE:** 118167558\
**Período:** 2021.1 

## Ambiente de desenvolvimento

**OS:** Manjaro Linux x86_64\
**Kernel:** 5.13.12-1-MANJARO\
**Shell:** fish **3.3**.1

## Objetivo

  Implementação de um catálogo de filmes com uso de struct e operators.

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

  Ao iniciar o programa um menu contendo todas as 8 possíveis opções é exibido. 
  Cada item possui um submenu onde o usuário pode confirmar sua escolha e depois
  entrar com os parâmetros necessários para execução do programa.\


  **Os dados só são salvos caso o programa finalize com a opção adequada, logo caso o usuário finalize o programa com o comando ```Ctrl+c```, por exemplo os dados serão perdidos!**\

  Opções dispoiníveis:\
  ```
  Opcoes:
  1 - Adicionar filme.
  2 - Remover filme.
  3 - Buscar filme.
  4 - Editar produtora.
  5 - Editar nota.
  6 - Listar filmes.
  7 - Exibir filme com maior nota.
  8 - Salvar e sair.
  ```

## Referências externas

[Readinf from file until EOF(stackoverflow)](https://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line)
