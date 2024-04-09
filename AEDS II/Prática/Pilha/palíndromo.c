#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int inserir_letra(char palavra[], int *letra, char nova_letra) {
    int retorno = -1;
    if (*letra != MAX - 1){
        (*letra)++;
        palavra[*letra] = nova_letra;
        retorno = *letra;
    }
    return retorno;
}

char remove_letra(char palavra[], int *letra) {
    char retorno = '\0';
    if (*letra != -1){
        retorno = palavra[*letra];
        (*letra)--;
    }
    return retorno;
}

int main() {
    char palavra[MAX];
    int tamanho = -1;
    int letra = -1;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for (int i = 0; i < MAX; i++){
        if (palavra[i] == '\0'){
            tamanho = i - 1;
            break;
        }
    }
    
    int palindromo = 1;
    for (int i = 0; i <= tamanho; i++){
        inserir_letra(palavra, &letra, palavra[i]);
    }
    for (int i = 0; i <= tamanho; i++){
        char letra_removida = remove_letra(palavra, &letra);
        if (letra_removida == '\0'){
            printf("A pilha está vazia, impossível remover!");
        }

        if (palavra[i] != letra_removida)
        {
            palindromo = 0;
            break;
        }    
    }
    if (palindromo == 1)
    {
        printf("A palavra é um palíndromo!\n");
    } else {
        printf("Não é palíndromo\n");
    }
    
    return 0;
}

