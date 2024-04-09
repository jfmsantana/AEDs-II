#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chave_divisao(int chave, int TABLE_SIZE)
{
    if (chave < 0)
    {
        chave = chave * -1;
    }
    return chave % TABLE_SIZE;  
}

int chave_multiplicacao(int chave, int TABLE_SIZE){
    if (chave < 0)
    {
        chave = chave * -1;
    }
    double A = 0.6180339887;
    double val = chave * A;
    val = val - (int)val;
    return (int)(TABLE_SIZE * val);
}

int chave_dobra(int chave, int TABLE_SIZE){
    if (chave < 0)
    {
        chave = chave * -1;
    }
    
    while (chave > TABLE_SIZE)
    {
        int soma = 0;
        int primeiroDigito = chave;
        int divisor = 1;
        while (primeiroDigito >= 10) // Encontra o primeiro dígito
        {
            primeiroDigito = chave / divisor;
            divisor *= 10;
        }
        int ultimoDigito = chave % 10; // Encontra o último dígito
        soma = primeiroDigito + ultimoDigito; // Soma o primeiro e o último dígito
        soma = soma % 10; // Despreza a dezena
        chave = soma; // Atualiza a chave
    }

    return chave;
}