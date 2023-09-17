#include <stdio.h>
#define MAX 502

int main(void)
{
    char primeiro_numero[MAX], segundo_numero[MAX];

    printf("Digite o primeiro numero: ");
    scanf("%s", primeiro_numero);

    printf("Digite o segundo numero: ");
    scanf("%s", segundo_numero);

    int casas_primeiro_numero = strlen(primeiro_numero);
    int casas_segundo_numero = strlen(segundo_numero);


    int ascii = 0;

    if(casas_primeiro_numero > casas_segundo_numero)
    {
        
    }
    for (int i = 0; primeiro_numero[i] != '\0'; i++)
    {
        printf("%c ", primeiro_numero[i]);
        ascii = primeiro_numero[i] - '0';

        printf("= %d |", ascii + 48);

    }

    printf("\n");

    for(int j = 0; segundo_numero[j] != '\0'; j++)
    {
        printf("%c ", segundo_numero[j]);
        ascii = segundo_numero[j] - '0';

        printf("= %d |", ascii + 48);

    }
    
    return (0);
}