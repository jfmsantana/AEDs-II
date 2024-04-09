#include <stdio.h>
#include <stdlib.h>

typedef struct letras_ {
    char letra;
    struct letras_ *prox;
} letra;

void inserirLetra_pilha(letra **topo, char nova_letra) {
    letra *nova_letra_ptr = (letra *)malloc(sizeof(letra));
    nova_letra_ptr->letra = nova_letra;
    nova_letra_ptr->prox = *topo;
    *topo = nova_letra_ptr;
}

letra *removeLetra_pilha(letra **topo) {
    letra *tmp = NULL; 
    if (*topo != NULL) {
        tmp = *topo;
        *topo = (*(*topo)).prox;
    }
    return tmp;
}

int main() {
    char p1[100];
    letra *topo = NULL;

    printf("Digite uma palavra: ");
    scanf("%s", p1);

    for (int i = 0; p1[i] != '\0'; i++) {
        inserirLetra_pilha(&topo, p1[i]);
    }

    int palindromo = 1;
    for (int i = 0; p1[i] != '\0'; i++) {
        letra *letra_removida = removeLetra_pilha(&topo);
        if (letra_removida == NULL) {
            printf("Pilha está vazia, impossível remover");
        }

        if (p1[i] != letra_removida->letra) {
            palindromo = 0;
            break;
        }
        free(letra_removida);
    }

    if (palindromo == 1) {
        printf("A palavra é um palíndromo. \n");
    } else {
        printf("Não é palíndromo. \n");
    }

    return 0;
}