// Aluno: Erick Sousa Saraiva
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
void operacoes(char linha[TAMANHO]) // Funções de operações aritméticas.
{
    char opcode[TAMANHO];
    int indiceRegistroX, indiceRegistroY, indiceRegistroZ; // Indices dos registradores, registro = R0, indíce = 0.
    extern int registro[32];                               // Registro com os valores alocados no módulo da memória, possuindo 32 bits.
    // Observei que as operações aritméticas tem um padrão de OPCODE RX RY RZ, decidi colocar em apenas uma função.
    if (sscanf(linha, "%s R%d R%d R%d", opcode, &indiceRegistroX, &indiceRegistroY, &indiceRegistroZ) == 4) // Lendo a linha da matriz e separando em OPCODE e Indice X,Y,Z. O indice é atribuido apos ler o R.
    {
        // Filtragem dos indíces para que o usuário não coloque, por exemplo, R34. Retornará 1 se for verdadeiro e 0 se for falso.
        int filtroX = ((indiceRegistroX >= 0) && (indiceRegistroX < 32));
        int filtroY = ((indiceRegistroY >= 0) && (indiceRegistroY < 32));
        int filtroZ = ((indiceRegistroZ >= 0) && (indiceRegistroZ < 32));
        if (strcmp(opcode, "ADD") == 0 && filtroX && filtroY && filtroZ) // Se o OPCODE for igual ao da operação aritmética, executar a operação.
        {
            registro[indiceRegistroX] = registro[indiceRegistroY] + registro[indiceRegistroZ]; // RX = RY + RZ (soma os valores de RY e RZ e armazena o resultado em RX).
        }
        else if (strcmp(opcode, "SUB") == 0 && filtroX && filtroY && filtroZ)
        {
            registro[indiceRegistroX] = registro[indiceRegistroY] - registro[indiceRegistroZ]; // RX = RY - RZ (subtrai RZ de RY e armazena o resultado em RX).
        }
        else if (strcmp(opcode, "MUL") == 0 && filtroX && filtroY && filtroZ)
        {
            registro[indiceRegistroX] = registro[indiceRegistroY] * registro[indiceRegistroZ]; // RX = RY * RZ (multiplica RY por RZ e armazena o resultado em RX).
        }
        else if (strcmp(opcode, "DIV") == 0 && filtroX && filtroY && filtroZ)
        {
            registro[indiceRegistroX] = (int)registro[indiceRegistroY] / (int)registro[indiceRegistroZ]; // RX = RY / RZ (divide RY por RZ e armazena o resultado em RX).
            // A divisão é inteira, isto é, a parte fracionária é desprezada.
        }
        else if (strcmp(opcode, "MOD") == 0 && filtroX && filtroY && filtroZ) // RX = RY % RZ (toma o resultado de RY mod RZ e armazena o resultado em RX).
        {
            int resto = registro[indiceRegistroY] % registro[indiceRegistroZ];
            // O resultado RX da operação de mod é sempre 0 ≤ RX < RZ.
            if (resto < 0)
            {
                registro[indiceRegistroX] = resto + registro[indiceRegistroZ]; // Se o resto for menor que 0 adiciona o valor do RZ.
            }
            else
            {
                registro[indiceRegistroX] = resto; // Se não apenas atribua o valor para RX.
            }
        }
    }
}