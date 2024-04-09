#include<stdio.h>
#include<stdlib.h>

//João Felipe Martins Santana
//2023.1.08.007

typedef struct no {
    int info;
    struct no *prox;
} Node;

typedef struct {
    struct no *comeco;
} Lista;

// Iniciar a lista
void iniciaLista(Lista *lista) {
    lista->comeco = NULL;
}

// Mostrar/Exibir a lista
void mostraLista(Lista lista) {
    Node *aux = lista.comeco;
    while (aux != NULL) {
        printf("%d \t", aux->info);
        aux = aux->prox;
    }
}

// Inserir na lista DE FORMA ORDENADA
void insere(Lista *lista, int valor) {
    Node *aux = lista->comeco;
    Node novoNoh = (Node) malloc(sizeof(Node));
    novoNoh->info = valor;
    // LISTA VAZIA
    if (aux == NULL) {
        lista->comeco = novoNoh;
        novoNoh->prox = NULL;
    } else { // LISTA NÃO VAZIA
        Node *ant = NULL;
        while (aux != NULL && aux->info < valor) {
            ant = aux;
            aux = aux->prox;
        }
        if (ant == NULL) {
            novoNoh->prox = lista->comeco;
            lista->comeco = novoNoh;
        } else {
            novoNoh->prox = ant->prox;
        ant->prox = novoNoh;

        }
    }
}

int main() {
    Lista lista;
    iniciaLista(&lista);
    insere(&lista, 5);
    insere(&lista, 6);
    insere(&lista, 3);
    insere(&lista, 4);
    mostraLista(lista);
}