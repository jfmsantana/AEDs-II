#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primeiro_digito(int n)
{
    if (n > -10 && n < 10)
    {
        return n;
    }
    while (n > 10 || n < -10)
    {
        n = (int)(n / 10);
    }
    return n;
}

int ultimoDigito(int n)
{
    return n % 10;
}

int numero_de_digitos(int n)
{
    int contador = 0;
    while (n > 0 || n < 0)
    {
        n = (int)(n / 10);
        contador++;
    }
    return contador;
}

int remover_primeiro_e_ultimo(int n)
{
    if (n > -10 && n < 10)
    {
        return 0;
    }

    int primeiro = primeiro_digito(n);
    int numero_digitos = numero_de_digitos(n);
    primeiro = primeiro * pow(10, numero_digitos - 1);

    int novo = n - primeiro;
    novo = (int)(novo / 10);

    return novo;
}

// int main()
//{
//     printf("Digite um número: \n");
//     int n;
//     scanf("%d", &n);
//     printf("O primeiro dígito do número é: %d\n", primeiro_digito(n));
//     printf("O último dígito do número é: %d\n", ultimoDigito(n));
//     printf("O número de dígitos do número é: %d\n", numero_de_digitos(n));
//     printf("A soma do primeiro e do último dígito é: %d\n", primeiro_digito(n) + ultimoDigito(n));
//     printf("O número restante, excluindo o primeiro e último algarismo é: %d\n", remover_primeiro_e_ultimo(n));
// }