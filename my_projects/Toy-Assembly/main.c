#include <stdio.h>
// Cabeçalhos arquivos.h que vão ligar os arquivos.c nesse projeto. 
#include "leitura.h"
#include "controle.h"
#include "memoria.h"
#include "aritmetico.h"
#include "saida.h"
#include "logica.h"
int linhas;
char matriz[TAMANHO][TAMANHO];
int main(void)
{
    leitura(matriz, linhas); // Função leitura que vai trazer a matriz com os valores estabelecidos.
    controle(matriz, linhas); // Chamando a função controle que vai fazer a decodificação e a executação do programa.
    return 0;
}

