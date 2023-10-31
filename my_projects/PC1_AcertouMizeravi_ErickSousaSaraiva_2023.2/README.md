INSTITUTO FEDERAL DE BRASÍLIA (TAGUATINGA)\
ALUNO: ERICK SOUSA SARAIVA\
PROFESSOR: DANIEL SAAD\
PROJETO: ACERTOU MISERAVI\
DISCIPLINA: PROGRAMAÇÃO DE COMPUTADORES 1\
DATA: 24/09/2023
------------------------------------------------------------------------------
# PROJETO 1 - ACERTOU MISERAVI
### [ SOBRE O PROJETO ] 
O projeto tem que haver as entradas de quantas operações o usuário vai desejar fazer, dois números arbitrariamente grandes e os operadores desejados, que são:\
`[ 1 ] SOMA`\
`[ 2 ] SUBTRAÇÃO`\
`[ 3 ] MULTIPLICAÇÃO`\
A saída vai ter o resultado em cada linha.\
`[ 1 ] SOMA` - Soma dois números inteiros positivos.\
`[ 2 ] SUBTRAÇÃO` - Subtrai o segundo número do primeiro número. Se o resultado for negativo, o programa coloca um sinal de menos (-) na frente.\
`[ 3 ] MULTIPLICAÇÃO` - Multiplica dois números inteiros positivos.

### [ COMO COMPILAR E EXECUTAR ] 
 O projeto usa a linguagem C, então precisa de um sistema operacional GNU ou LINUX, máquina de 32/64 bits e compilador usual da linguagem C recomendado GCC 10.2.0.
 O projeto pode ser executado em vários softwares, os mais recomendados e usais são o VSCODE e GDBonline, respectivamente, um tem que ser instalado e o outro pode ser usado de forma online.
 Você precisa compilar o programa antes de usá-lo. Abra um terminal no diretório onde o código-fonte está localizado e execute o seguinte comando:\
				``` $ gcc -o miseravi miseravi.c ``` \
				``` $ ./calculadora ```\
  O código-fonte está dividido em várias funções:
   * lixo_memoria: Limpa a memória, preenchendo a string com '0'.
   * comparacao: Compara o tamanho de duas strings e retorna o tamanho da maior.
   * remover_zeros: Remove os zeros à esquerda de uma string.
   * subtracao: Realiza a operação de subtração.
   * multiplicacao: Realiza a operação de multiplicação.
   * somar: Realiza a operação de soma.
   * main: Função principal onde o programa é executado. Ela lê as entradas do usuário, chama as funções apropriadas e exibe os resultados.

### [ OBSERVAÇÕES ]
- Quando é obtido o resultado da soma no VSCODE, a linha PODE não "pular" para a próxima, e assim, acabar concatenando a próxima entrada. Entretanto, o resultado não será modificado.
- Entradas negativas não são aceitas.
- Todos os zeros à esquerda são tratados.

### [ CONCLUSÃO ]  
 O projeto tem como objetivo suprir a soma, subtração e multiplicação aritmética de números que ultrapassem o limite de caracteres dos inteiros. Este é um código bem estruturado que separa as funcionalidades em funções individuais para facilitar a manutenção e o entendimento.



~~ [ESS].
