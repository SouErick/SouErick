#include <stdio.h>
#include <string.h>
// Cabeçalhos arquivos.h que vão ligar os arquivos.c nesse projeto.
#include "leitura.h"
#include "controle.h"
#include "memoria.h"
#include "aritmetico.h"
#include "saida.h"
#include "logica.h"
#define TAMANHO 100
// Variáveis que serão usadas nesse programa.
int registro[32] = {0};
int indiceRegistroX, indiceRegistroY;
char opcode[TAMANHO];
int constante;
void mov(char linha[TAMANHO]) // Função MOV, há duas vertentes do MOV.
// MOV RX CONSTANTE.
// MOV RX RY.
{

    if (sscanf(linha, "%s R%d %d", opcode, &indiceRegistroX, &constante) == 3) // Caso MOV RX CONSTANTE.
    {
        if (strcmp(opcode, "MOV") == 0 && indiceRegistroX >= 0 && indiceRegistroX < 32) // Se o OPCODE for igual ao da operação MOV, executar a operação.
        {
            registro[indiceRegistroX] = constante; // Array Registro RX vai receber o valor da constante (atribui a RX o valor do INTEIRO).
        }
    }
    else if (sscanf(linha, "%s R%d R%d", opcode, &indiceRegistroX, &indiceRegistroY) == 3) // Caso MOV RX RY.
    {
        if (strcmp(opcode, "MOV") == 0 && indiceRegistroX >= 0 && indiceRegistroX < 32 && indiceRegistroY >= 0 && indiceRegistroY < 32)
        {
            registro[indiceRegistroX] = registro[indiceRegistroY]; // Registro RX vai receber o valor de RY (atribui a RX o valor de RY).
        }
    }
}
void load(char linha[TAMANHO]) // Função LOAD.
{
    if (sscanf(linha, "%s R%d R%d", opcode, &indiceRegistroX, &indiceRegistroY) == 3) 
    {
        if (strcmp(opcode, "LOAD") == 0 && indiceRegistroX >= 0 && indiceRegistroX < 32 && indiceRegistroY >= 0 && indiceRegistroY < 32) // Se o OPCODE for igual ao da operação LOAD, executar a operação.
        {
            registro[indiceRegistroX] = registro[indiceRegistroY];  // Carrega o conteúdo de memoria[RY] para o registrador RX.
        }
    }
}
void store(char linha[TAMANHO]) // Função STORE.
{
    if (sscanf(linha, "%s R%d R%d", opcode, &indiceRegistroX, &indiceRegistroY) == 3) 
    {
        if (strcmp(opcode, "STORE") == 0 && indiceRegistroX >= 0 && indiceRegistroX < 32 && indiceRegistroY >= 0 && indiceRegistroY < 32) // Se o OPCODE for igual ao da operação LOAD, executar a operação.
        {
            registro[indiceRegistroY] = registro[indiceRegistroX]; // Carrega o conteúdo de RX para memoria[RY].
        }
    }
}
