# Projeto Toy-Assembly
*Instituto Federal de Brasília (Taguatinga)\
Aluno: Erick Sousa Saraiva\
Disciplina: Programação de Computadores I\
Professor: Daniel Saad\
Data: 29/10/2023*
## Descrição
Se denominam linguagens assembly aquelas linguagens de baixo nível, que estão em
um nível de abstração bem próximo a da arquitetura da máquina programada.
O objetivo deste projeto é construir um interpretador de uma linguagem assembly
simples (toy assembly).

## Estrutura dos Módulos
O código está organizado da seguinte forma:

- `main.c`: O ponto de entrada do programa.
- `leitura.c`: Eefetua a leitura do programa de entrada
- `leitura.h`: Declaração das funções relacionadas à leitura.
- `controle.c`: Gerencia o fluxo de execução das operações.
- `controle.h`: Declaração das funções relacionadas ao controle.
- `memoria.c`: Trata de operações de memória.
- `memoria.h`: Declaração das funções relacionadas à memória.
- `aritmetico.c`: Contém funções para operações aritméticas.
- `aritmetico.h`: Declaração das funções relacionadas a operações aritméticas.
- `logica.c`: Contém funções para operações lógicas.
- `logica.h`: Declaração das funções relacionadas a operações lógicas.
- `saida.c`:  Efetua a impressão dos dados
- `saida.h`: Declaração das funções relacionadas à saída.
- `makefile`: Um arquivo Makefile para compilar o código.

## Como Compilar
Para compilar o código, você pode usar o Makefile fornecido. Certifique-se de que você tem o GCC (GNU Compiler Collection) instalado no seu sistema.

Windows  
--------- 
```
1. Abra um terminal na pasta onde estão os arquivos.
2. Execute o comando:
mingw32-make
Isso compilará o código e gerará um arquivo executável chamado main.
Após compilar o código, você pode executá-lo com o seguinte comando:
./main
```
Linux 
-------
```
1. Abra um terminal na pasta onde estão os arquivos.
2. Execute o comando:
make
Isso compilará o código e gerará um arquivo executável chamado main.
Após compilar o código, você pode executá-lo com o seguinte comando:
./main
Comando para limpar .o e .exe: Make Clean
```
