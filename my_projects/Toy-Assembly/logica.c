#include <stdio.h>
#include <string.h>
// Cabeçalhos arquivos.h que vão ligar os arquivos.c nesse projeto.
#include "leitura.h"
#include "controle.h"
#include "memoria.h"
#include "aritmetico.h"
#include "saida.h"
#include "logica.h"
#define MAX 100000
int linhas;
char opcode[TAMANHO];
int indiceRegistroX, indiceRegistroY, indiceRegistroZ;
extern int registro[32]; // Usando o valor do registro atribuido na outra memória.
int endereco;
void comparacao(char linha[TAMANHO], int *linhas) // Função comparação, pois ambas são operações que comparam (BEQ, BLT).
// Ponteiro na linha que for chamada pelos operadores lógicos.
{
    // Filtragem dos indíces para que o usuário não coloque, por exemplo, R34. Retornará um se for verdadeiro e zero se for falso.
    int filtroX = ((indiceRegistroX >= 0) && (indiceRegistroX < 32));
    int filtroY = ((indiceRegistroY >= 0) && (indiceRegistroY < 32));
    int endereco; // Constante que terá o valor da linha desejada do usuário.
    sscanf(linha, "%s R%d R%d %d", opcode, &indiceRegistroX, &indiceRegistroY, &endereco);
    if (strcmp(opcode, "BEQ") == 0 && filtroX && filtroY) // Se o OPCODE for igual ao da operação lógica, executar a operação.
    {
        // O fluxo do programa é direcionado para a instrução que ocupa a linha de número ENDERECO caso RX seja igual a RY.
        if (registro[indiceRegistroX] == registro[indiceRegistroY]) // Operação BEQ RX == RY.
        {
            *linhas = endereco; // A linha receberá o endereço desejado, por exemplo, se for verdade a comparação (BEQ RX RY 1), retornará para a primeira linha.
        }
    }
    else if (strcmp(opcode, "BLT") == 0 && filtroX && filtroY)
    {
        // O fluxo do programa é direcionado para a instrução que ocupa a linha de número ENDERECO caso RX < RY.
        if (registro[indiceRegistroX] < registro[indiceRegistroY])
        {
            *linhas = endereco; // A linha receberá o endereço desejado, por exemplo, se for verdade a comparação (BLT RX RY 1), retornará para a primeira linha.
        }
    }
}

void jump(char linha[TAMANHO], int *linhas) // Função JUMP.
{
    int endereco;
    sscanf(linha, "%s %d", opcode, &endereco);
    if (strcmp(opcode, "JMP") == 0)
    {
        // O fluxo do programa é direcionado para a instrução que ocupa a linha de número ENDERECO.
        *linhas = endereco; // A linha receberá o endereço desejado, por exemplo, se for verdade a comparação (JMP 0), retornará para a primeira linha.
    }
}
