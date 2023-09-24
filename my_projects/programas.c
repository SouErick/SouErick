#include <stdio.h>
#include <string.h>

#define TAMANHO 502

int comparacao(char str_primeiro[], char str_segundo[]) // Função para comparar o tamanho das strings.
{
    int tamanho_str1 = strlen(str_primeiro); // Armazenando o tamanho da string.
    int tamanho_str2 = strlen(str_segundo);

    if (tamanho_str1 > tamanho_str2) // Se a primeira string for maior, retorne ela. Assim como, se a segunda string for maior, retorne ela.
    {
        return tamanho_str1;
    }
    else
    {
        return tamanho_str2;
    }
}

void removerZerosEsquerda(char numero[], int tamanho)
{
    int contador_zero = 0;
    while (numero[contador_zero] == '0' && contador_zero < tamanho - 1)
    {
        contador_zero++;
    }
    for (int i = contador_zero; i < tamanho; i++)
    {
        numero[i - contador_zero] = numero[i];
    }

    numero[tamanho - contador_zero] = '\0';
}

void subtracao(const char *num1, const char *num2, char *resultado) // Motivo da minha depressão
{
    int comparar = strcmp(num1, num2);
    if (comparar < 0)
    {
        resultado[0] = '-';
        const char *temp = num1;
        num1 = num2;
        num2 = temp;
    }
    else
    {
        resultado[0] = '0';
    }
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int max_len = (len1 > len2) ? len1 : len2;
    int diferenca = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = max_len;
    while (i >= 0 || j >= 0)
    {
        int digito1 = (i >= 0) ? num1[i] - '0' : 0;
        int digito2 = (j >= 0) ? num2[j] - '0' : 0;
        int subtracao = digito1 - digito2 - diferenca;
        if (subtracao < 0)
        {
            subtracao += 10;
            diferenca = 1;
        }
        else
        {
            diferenca = 0;
        }
        resultado[k] = subtracao + '0';
        i--;
        j--;
        k--;
    }
    resultado[max_len + 1] = '\0';
    printf("%s\n", resultado);
}

void multiplicacao(char primeiro_numero[], char segundo_numero[], char resultado[]) // Função multiplicação.
{
    int tamanho_primeiro_numero = strlen(primeiro_numero);
    int tamanho_segundo_numero = strlen(segundo_numero);
    // O tamanho máximo do resultado será a soma dos tamanhos das duas strings
    int tamanho_resultado = tamanho_primeiro_numero + tamanho_segundo_numero;
    // Inicialize o resultado com zeros
    for (int i = 0; i < tamanho_resultado; i++)
    {
        resultado[i] = '0';
    }
    resultado[tamanho_resultado] = '\0';
    // Comece multiplicando a partir dos dígitos menos significativos
    for (int i = tamanho_primeiro_numero - 1; i >= 0; i--)
    {
        int empresta = 0;
        int digito_primeiro = primeiro_numero[i] - '0';
        for (int j = tamanho_segundo_numero - 1; j >= 0; j--)
        {
            int digito_segundo = segundo_numero[j] - '0';
            int multiplicacao = (resultado[i + j + 1] - '0') + (digito_primeiro * digito_segundo) + empresta;
            resultado[i + j + 1] = (multiplicacao % 10) + '0';
            empresta = multiplicacao / 10;
        }
        // Adicione qualquer transporte restante ao dígito mais significativo atual
        resultado[i] = ((resultado[i] - '0') + empresta) + '0';
    }
    removerZerosEsquerda(resultado, tamanho_resultado);
    printf("%s\n", resultado);
}

void somar(char primeiro_numero[], char segundo_numero[], char resultado[]) // Função Soma.
{
    for (int i = 0; i < TAMANHO; i++) // Evitar qualquer lixo de memória.
    {
        resultado[i] = 0; // Basicamente, vai percorrer o tamanho do resultado inteiro alocando o valor zero em cada dígito.
    }

    int tamanho_maior = comparacao(primeiro_numero, segundo_numero); // Chamando função que compara as duas strings.

    int empresta = 0; // Inicializando o empresta da soma aritmetica com zero.

    int tamanho_primeiro_numero = strlen(primeiro_numero); // Contador do primeiro numero.
    for (int i = 0; i < tamanho_maior; i++)                // Percorrer a string do maior numero garantindo que a soma fique organizada igual no papel "um abaixo do outro".
    {
        int digito_primeiro;
        if (i < tamanho_primeiro_numero) // Se o contador for menor que o tamanho do primeiro numero execute:
        {
            digito_primeiro = primeiro_numero[tamanho_primeiro_numero - 1 - i] - '0'; // A transformação de cada digito em ASCII (caracter - inteiro).
            // [tamanho_primeiro_numero - 1 - i] | O -1 está retirando o '\0' do tamanho e fazendo a transformação do último digito até o primeiro |
        }
        else
        {
            digito_primeiro = 0;
            // Quando o contador for maior que o tamanho do primeiro número, ele pode continuar percorrendo o tamanho do maior numero entre as comparações, assim o valor alocado nos digitos será zero.
        }

        int digito_segundo; // Esse bloco faz a mesma função que o primeiro numero, mas com o segundo numero.
        int contador_segundo_numero = strlen(segundo_numero);
        if (i < contador_segundo_numero)
        {
            digito_segundo = segundo_numero[contador_segundo_numero - 1 - i] - '0';
        }
        else
        {
            digito_segundo = 0;
        }

        int soma = digito_primeiro + digito_segundo + empresta; // Cada digito do primeiro numero será somado com o outro digito do segundo numero, assim como no papel, a soma será efetuda junto com empresta.
        empresta = soma / 10;                                   // Quando fazemos a soma de um com outro e o resultado passa de dez, é emprestado uma unidade para a próxima "casa", ou seja, é retirado a dezena desse número, por isso a divisão por dez.
        resultado[i] = (soma % 10) + '0';                       // Faz a transformação de cada resultado da soma dos digitos (inteiro - caracter) em ASCII.
        // resultado[i] = (soma % 10) + '0' |  Isso é feito para converter o valor numérico (0 a 9) em seu caractere correspondente.
    }

    if (empresta > 0) // Se a divisão da soma por dez restar um valor maior que zero, isso significa que aconteceu um emprestimo de unidade.
    {
        resultado[tamanho_maior] = empresta + '0'; // A transformação do empresta em caracter alocando no digito do resultado.
        tamanho_maior++;                           // Incrementado para indicar que o resultado agora tem um dígito a mais.
    }

    resultado[tamanho_maior] = '\0'; // Fim da string.

    for (int i = tamanho_maior - 1; i >= 0; i--) // Percorrendo a string invertida, e dando o resultado de cada soma.
    {
        printf("%c", resultado[i]);
    }
    printf("\n");
}

int main(void)
{
    // Cabeçalho
    char primeiro_numero[TAMANHO];
    char segundo_numero[TAMANHO];
    char resultado[TAMANHO];

    int operacoes, operador;
    scanf("%d", &operacoes);

    for (int i = 0; i < operacoes; i++) // Número de operações que o usuário deseja.
    {
        scanf("%s %s", primeiro_numero, segundo_numero);
        scanf("%d", &operador);
        if (operador == 1)
        {
            somar(primeiro_numero, segundo_numero, resultado); // Chamando a função soma.
        }
        else if (operador == 2)
        {
            subtracao(primeiro_numero, segundo_numero, resultado); // Chamando a função subtração.
        }
        else if (operador == 3)
        {
            multiplicacao(primeiro_numero, segundo_numero, resultado); // Chamando a função subtração
        }
        else
        {
            scanf("%d", &operacoes); // Caso usuário digite errado.
            continue;
        }
    }

    return 0;
}