// JOGO DE ADIVINHAÇÃO
/* Fazer um jogo de adivinhação com números randômicos mostrando no final a pontuação do usuário */
// FEITO POR ERICK SOUSA SARAIVA 10/08/2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CONTADOR 1
#define ERROR 0
#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

int main()
{
    int numero_usuario, nivel, numero_tentativa;

    double pontos = 1000;

    // FUNÇÃO NÚMERO RANDÔMICO.
    int segundos = time(0);
    srand(segundos);
    int numero_sorteado = rand();
    int numero_certo = (numero_sorteado % 100);

    // CABEÇALHO.
    printf("--------------------------------------------\n");
    printf("Bem vindo ao jogo de adivinhacao!\n");
    printf("--------------------------------------------\n");
    printf("SELECIONE UM NIVEL [1] FACIL [2] MEDIO [3] DIFICIL\n");
    printf("Escolha um nivel: ");
    fflush(stdin);
    scanf("%d", &nivel);
    printf("\n");
    printf("                     Tente acertar o numero que pensei. . .                     \n");
    printf("\n");

    switch (nivel) // ESCOLHA DE NIVEL.
    {
    case FACIL:
        numero_tentativa = 20;
        printf("Nivel escolhido: FACIL - 20 TENTATIVAS -\n");
        break;
    case MEDIO:
        numero_tentativa = 15;
        printf("Nivel escolhido: MEDIO - 15 TENTATIVAS - \n");
        break;
    case DIFICIL:
        numero_tentativa = 5;
        printf("Nivel escolhido: DIFICIL - 5 TENTATIVAS -\n");
        break;
    default:
        numero_tentativa = 0;
        printf("            NIVEL NAO ENCONTRADO            \n");
        break;
    }

    int contador = CONTADOR;

    while (contador <= numero_tentativa) // LOOPING DETERMINADO POR NUMEROS DE TENTATIVAS.
    {
        printf("Tentativa %d de %d\n", contador, numero_tentativa);
        printf("Digite um numero: ");
        fflush(stdin);
        scanf("%d", &numero_usuario);
        printf("O numero digitado foi: %d\n", numero_usuario);
        printf("--------------------------------------------\n");

        int erro = (numero_usuario < ERROR);

        if (erro) // CASO USUÁRIO DIGITE VALOR MENOR QUE ZERO.
        {
            printf("Numero incorreto, por favor, digite o numero certo.\n");
            continue;
        }

        int certo = (numero_usuario == numero_certo);
        int numero_maior = (numero_usuario > numero_certo);

        if (certo)
        {
            printf("PARABENS! O numero %d e o correto.\n", numero_usuario);
            printf("Voce precisou de %d chances de %d para acertar\n", contador, numero_tentativa);
            break;
        }
        else if (numero_maior) // CASO NUMERO DO USUÁRIO FOR MAIOR E O SORTEADO SEJA MENOR.
        {
            printf("O numero que eu pensei e menor...\n");
        }
        else // CASO NUMERO DO USUÁRIO FOR MENOR E O SORTEADO SEJA MAIOR.
        {
            printf("O numero que eu pensei e maior...\n");
        }
        
        // AÇÃO DE ARMAZENAR OS PONTOS
        int pontos_perdidos = abs(numero_usuario - numero_certo) / (double)2;
        pontos = (pontos - pontos_perdidos);

        contador++;

        if (contador > numero_tentativa)
        { // CASO USUÁRIO NÃO ACERTE.
            printf("SUAS CHANCES ACABARAM!\n");
            printf("O numero que pensei foi: %d\n", numero_certo);
            break;
        }
    }
    // FIM.
    printf("--------------------------------------------\n");
    printf("FIM DE JOGO!\n");
    printf("Pontuacao: %.1f de 1000 \n", pontos);
    printf("--------------------------------------------\n");
    return (0);
}
