#include <stdio.h>
#include <string.h>
// Cabeçalhos arquivos.h que vão ligar os arquivos.c nesse projeto.
#include "leitura.h"
#include "controle.h"
#include "memoria.h"
#include "aritmetico.h"
#include "saida.h"
#include "logica.h"
char opcode[TAMANHO];
int indiceRegistroX, indiceRegistroY, indiceRegistroZ;
extern int registro[32]; // Usando o valor do registro atribuido na outra memória.
void saida(char linha[TAMANHO]) // Função saida.
{
    if (sscanf(linha, "%s R%d", opcode, &indiceRegistroX) == 2 && indiceRegistroX >= 0 && indiceRegistroX < 32)
    {
        printf("%d\n", registro[indiceRegistroX]); // Imprime uma linha na tela com o o valor de RX.
    }
}