# Exercicio Avalidado 4 - Linguagens de Programação

**Aluno:** Ricardo Santos Siqueira\
**DRE:** 118167558\
**Período:** 2021.1 

## Ambiente de desenvolvimento

**OS:** Manjaro Linux x86_64\
**Kernel:** 5.13.12-1-MANJARO\
**Shell:** fish **3.3**.1

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
./main <ARGS>
```
  Ao iniciar o programa um menu contendo todas as 3 possíveis opções é exibido. Após selecionar uma opção o usuário deve entrar com os parâmetros necessários para o item selecionado.

  Opções dispoiníveis:
  ```
  Opcoes:
  1 - Adicionar paciente.
    1.1 - Pediatria.
    1.2 - Cardiologia.
  2 - Buscar paciente.
  3 - Listar pacientes.
  4 - Sair.
  ```

  O usuário também pode optar por passar valores via ```argc``` e ```argv``` contúdo essa prática não é recomendada para fluxos mais complexos, tendo em vista que opções que exijam entradas do mesmo como "Adicionar paciente.", por exemplo transferirão o controle para o mesmo.

  **Caso de uso:**

  Para verificar a lista de filmes, por exemplo, o usuário pode utilizar a comodidade dos ```argc``` e ```argv```, como comando exemplo a seguir:

  ```console
  ./main 1 3 4
  ```

  O exemplo acima executa as opcoes 1, 3 e 4. Nesse caso o output esperado:
  
  ```console
  $ make -s all; ./main 1 3 4; make -s clean;
  Nome do paciente:
  >>> foo
  Idade do paciente:
  >>> 23
  Genero do paciente:
  >>> bar
  Especialidade desejada:
  1- Pediatria.
  2- Cardiologia.
  >>> 1
  Nome dos pais do paciente:
  >>> baz
  Paciente foo adicionado com sucesso!
  Lista de pacientes
  Nome: foo
  Idade: 23
  Genero: bar
  Pais: baz
  $
  ```
## Referências externas

[Polymorphism in C++](https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm)

[C++ Templates](https://www.tutorialspoint.com/cplusplus/cpp_templates.htm)

[Undefined reference to function in C++](https://stackoverflow.com/questions/12772103/undefined-reference-to-function-c)
