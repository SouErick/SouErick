#include <stdio.h>

#define MAX 502

int main(void)
{
    char primeiro_numero[MAX], segundo_numero[MAX];
    int resultado[MAX];

    printf("Digite o primeiro numero: ");
    scanf("%s", primeiro_numero);

    printf("Digite o segundo numero: ");
    scanf("%s", segundo_numero);

    // Inicialize o resultado com zero
    for (int i = 0; i < MAX; i++)
    {
        resultado[i] = 0;
    }

    int casas_primeiro_numero = 0;
    int casas_segundo_numero = 0;

    // Contar o número de casas decimais em cada número
    while (primeiro_numero[casas_primeiro_numero] != '\0')
    {
        casas_primeiro_numero++;
    }

    while (segundo_numero[casas_segundo_numero] != '\0')
    {
        casas_segundo_numero++;
    }

    // Realizar a soma das casas decimais
    int vai_um = 0; // Vai armazenar o "vai um" da soma
    int max_casas = (casas_primeiro_numero > casas_segundo_numero) ? casas_primeiro_numero : casas_segundo_numero;
    int i = 0, j = 0;

    while (i < casas_primeiro_numero || j < casas_segundo_numero)
    {
        int digito1 = (i < casas_primeiro_numero) ? primeiro_numero[casas_primeiro_numero - 1 - i] - '0' : 0;
        int digito2 = (j < casas_segundo_numero) ? segundo_numero[casas_segundo_numero - 1 - j] - '0' : 0;

        int soma = digito1 + digito2 + vai_um;
        vai_um = soma / 10;
        resultado[max_casas - 1 - i] = soma % 10;

        i++;
        j++;
    }

    if (vai_um > 0)
    {
        resultado[max_casas - 1 - i] = vai_um;
        max_casas++;
    }

    // Imprimir o resultado
    printf("Resultado da soma:\n");
    for (int k = 0; k < max_casas; k++)
    {
        printf("%d", resultado[k]);
    }
    printf("\n");

    return 0;
}