#include <stdio.h>
#define TAM 8

typedef struct {
    int info;
    int prox;
} Node;

int comeco, disponivel;

void iniciaLista(Node *lista, int *comeco, int *disponivel) {
    for (int i = 0; i < TAM-1; i++) {
        lista[i].info = 0;
        lista[i].prox = i + 1;
    }
    lista[TAM-1].info = 0;
    lista[TAM-1].prox = -1;
    *comeco = -1;
    *disponivel = 0;
}
// Comeco == 0
void imprimeLista(Node *lista, int comeco, int disponivel) {
    if (comeco == -1) {
        printf("Lista vazia!\n");
    } else {
        int proximo = lista[comeco].prox;
        printf("Lista / Info: %d, Prox: %d\n", lista[comeco].info, lista[comeco].prox);
        while(proximo != -1 && proximo != disponivel) {
            printf("Lista / Info: %d, Prox: %d\n", lista[proximo].info, lista[proximo].prox);
            proximo = lista[proximo].prox;
        }
    }
}

void adicionaNaLista(Node *lista, int *comeco, int *disponivel, int valor) {
    if (*disponivel == -1) {
        printf("Lista cheia! Impossivel adicionar o valor %d na lista \n", valor);
    } else {
        if (*comeco == -1) {
            *comeco = *disponivel;            
        }
        lista[*disponivel].info = valor;
        *disponivel = lista[*disponivel].prox;
        printf("Valor %d adicionado com sucesso na lista!\n", valor);
    }
}

void removerDaLista(Node *lista, int comeco, int *disponivel, int valor) {
    int atual = comeco;
    int anterior = atual;
    int fim = lista[atual].prox;
    while(lista[fim].prox != -1) {
        if (valor == lista[fim].info) {
            anterior = fim;
            atual = fim;
        }
        fim = lista[fim].prox;
    }
    printf("Anterior: %d \t Atual: %d \t Fim: %d \n", anterior, atual, fim);
    
    if (valor == lista[atual].info) {
        lista[anterior].prox = lista[atual].prox;
        lista[atual].prox = -1;
    }
}

void removerPrimeiroElemento(Node *lista, int *comeco, int *disponivel) {
    if (*comeco != -1) {
        int primeiroElemento = *comeco;
        *comeco = lista[primeiroElemento].prox;
        lista[primeiroElemento].prox = *disponivel;
        *disponivel = primeiroElemento;
    } else {
        printf("Lista vazia! Nada a remover.\n");
    }
}

void removerElemento(Node *lista, int *comeco, int *disponivel, int valor) {
    int atual = *comeco;
    int anterior = -1;

    // Percorre a lista para encontrar o elemento a ser removido
    while (atual != -1) {
        if (lista[atual].info == valor) {
            if (anterior != -1) {
                lista[anterior].prox = lista[atual].prox;
            } else {
                // Se o elemento a ser removido é o primeiro, atualiza o ponteiro de início
                *comeco = lista[atual].prox;
            }

            lista[atual].prox = *disponivel;
            *disponivel = atual;

            printf("Valor %d removido com sucesso da lista!\n", valor);
            return;
        }
        anterior = atual;
        atual = lista[atual].prox;
    }

    printf("Valor %d não encontrado na lista.\n");
}

int main() {
    Node lista[TAM];
    iniciaLista(lista, &comeco, &disponivel);
    imprimeLista(lista, comeco, disponivel);
    adicionaNaLista(lista, &comeco, &disponivel, 18);
    adicionaNaLista(lista, &comeco, &disponivel, 22);
    adicionaNaLista(lista, &comeco, &disponivel, 3);
    adicionaNaLista(lista, &comeco, &disponivel, 28);
    adicionaNaLista(lista, &comeco, &disponivel, 21);
    adicionaNaLista(lista, &comeco, &disponivel, 17);
    adicionaNaLista(lista, &comeco, &disponivel, 8);
    adicionaNaLista(lista, &comeco, &disponivel, 9);
    adicionaNaLista(lista, &comeco, &disponivel, 30);
    if (disponivel == -1) { //Remove primeiro elemento de uma lista cheia
        removerPrimeiroElemento(lista, &comeco, &disponivel);
    }
    removerElemento(lista, &comeco, &disponivel, 22);
    removerDaLista(lista, comeco, &disponivel, 21);
    imprimeLista(lista, comeco, disponivel);
    return 1;
}