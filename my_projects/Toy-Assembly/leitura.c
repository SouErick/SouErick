#include <stdio.h>
#include <string.h>
// Cabeçalhos arquivos.h que vão ligar os arquivos.c nesse projeto. 
#include "leitura.h"
#include "controle.h"
#include "memoria.h"
#include "saida.h"
#include "logica.h"
#define TAMANHO 100 // Tamanho da matriz 100x100.
void leitura(char matriz[TAMANHO][TAMANHO], int linhas) // Função chamada na main que receberá uma Matriz e a quantidade de operações que o usuário desejar.
{
    scanf("%d", &linhas); // Quantidade de operações que o usuário deseja fazer.
    for (int cont = 0; cont <= linhas; cont++) // Estrutura de repetição que vai até o final desejado pelo usuário. 
    {
        fgets(matriz[cont], TAMANHO, stdin); // (Padrão fgets): pegando cada linha [cont] da matriz, tamanho da linha e entrada padrão STDIN.
    }
    controle(matriz, linhas); // Função leitura que vai receber cada linha na matriz para efetuar as operações desejadas.
}