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
#define MAX 100000 // Definindo o limite das operações 10^5.
int linhas;
int cont = 0;
void controle(char matriz[TAMANHO][TAMANHO], int linhas) // Função que vai decodificar e instruir as ações a serem feitas.
{
    for (int i = 0; i < linhas; i++) // Estrutura de repetição que recebe as linhas da matriz.
    {
        if (cont > MAX) // Interromper caso caia em um loop dos operadores lógicos (BEQ, BLT, JMP).
        {
            break;
        }
        char opcode[TAMANHO];
        sscanf(matriz[i], "%s", opcode); // Usando o sscanf para diferir o OPCODE que é uma string.
        // Inicio dos Operadores aritmeticos (ADD, SUB, MUL, DIV, MOD).
        if (strcmp(opcode, "ADD") == 0) // Comparando o OPCODE com a string para efetuar a operação desejada pelo usuário, caso a string seja igual a instruida o valor retornará zero.
        {
            operacoes(matriz[i]); // A linha que possuir o OPCODE instruido irá para a execução.
            // ADD RX, RY, RZ.
        }
        else if (strcmp(opcode, "SUB") == 0)
        {
            operacoes(matriz[i]);
            // SUB RX, RY, RZ.
        }
        else if (strcmp(opcode, "MUL") == 0)
        {
            operacoes(matriz[i]);
            // MUL RX, RY, RZ.
        }
        else if (strcmp(opcode, "DIV") == 0)
        {
            operacoes(matriz[i]);
            // DIV RX, RY, RZ.
        }
        else if (strcmp(opcode, "MOD") == 0)
        {
            operacoes(matriz[i]);
            // MOD RX, RY, RZ.
        }
        // Início dos operadores lógicos (BEQ, BLT, JMP).
        else if (strcmp(opcode, "BEQ") == 0)
        {
            comparacao(matriz[i], &i);
            // BEQ RX, RY, ENDERECO.
        }
        else if (strcmp(opcode, "BLT") == 0)
        {
            comparacao(matriz[i], &i);
            // BLT RX, RY, ENDERECO.
        }
        else if (strcmp(opcode, "JMP") == 0)
        {
            jump(matriz[i], &i);
            // JMP ENDERECO.
        }
        // Início operadores de endereço (LOAD E STORE).
        else if (strcmp(opcode, "MOV") == 0) // Coloquei o mov no módulo de memória, pois o MOV assemelha-se com o LOAD e STORE.
        {
            mov(matriz[i]);
            // MOV RX, RY.
            // MOV RX, CONSTANTE.
        }
        else if (strcmp(opcode, "LOAD") == 0)
        {
            load(matriz[i]);
            // LOAD RX, RY.
        }
        else if (strcmp(opcode, "STORE") == 0)
        {
            store(matriz[i]);
            // STORE RX, RY.
        }
        // Operador de saída (PRINT).
        else if (strcmp(opcode, "PRINT") == 0) 
        {
            saida(matriz[i]);
            // PRINT RX.
        }
        else if (strcmp(opcode, "EXIT") == 0) // Interromper as operações após a linha chegar no EXIT.
        {
            break;
        }
        cont++; // Contador das operações efetuadas, interromper 10^5 instruções.
    }
}