#include <stdio.h>
#include <string.h>

void abertura()
{
    printf("------------------------------------------------------\n");
    printf("-                   JOGO DA FORCA                    -\n");
    printf("------------------------------------------------------\n\n");
}

void chuta(char chutes[26], int *tentativas)
{
    char chute_usuario;
    scanf(" %c", &chute_usuario);
    chutes[(*tentativas)] = chute_usuario;
    (*tentativas)++;
}

int chute_feito(char chutes[26], int tentativas, char letra)
{
    int achou = 0;

    for (int j = 0; j < tentativas; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

int main()
{
    char palavra_secreta[20];
    sprintf(palavra_secreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do
    {
        for (int i = 0; i < strlen(palavra_secreta); i++)
        {
            int achou = chute_feito(chutes, tentativas, palavra_secreta[i]);
            if (achou)
            {
                printf("%c ", palavra_secreta[i]);
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n");
        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);

    return (0);
}
