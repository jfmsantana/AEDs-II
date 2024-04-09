#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct no {
    int info;
    struct no *prox;
    struct no *ant;
} Node;

typedef struct {
    struct no *comeco;
    struct no *fim;
} Lista;

// Iniciar a lista
void iniciaLista(Lista *lista) {
    lista->comeco = NULL;
    lista->fim = NULL;
}

// Mostrar/Exibir a lista
void mostraLista(Lista lista) {
    Node *aux = lista.comeco;
    while (aux != NULL) {
        printf("%d \t", aux->info);
        aux = aux->prox;
    }
}

//Mostrar/Exibir a lista do fim até o começo
void mostraListaInversa(Lista lista) {
    Node *aux = lista.fim;
    while (aux != NULL) {
        printf("%d \t", aux->info);
        aux = aux->ant;
    }   
}

// Inserir na lista DE FORMA ORDENADA
void insere(Lista *lista, int valor) {
    Node *novoNoh = (Node*) malloc(sizeof(Node));
    novoNoh->info = valor;
    novoNoh->ant = NULL;
    novoNoh->prox = NULL;

    Node *ant = NULL;
    Node *atual = lista->comeco;

    // LISTA VAZIA
    if (atual == NULL || atual->info >= valor) {
        novoNoh->prox = atual;
        if (atual != NULL) {
            atual->ant = novoNoh;
        }
        lista->comeco = novoNoh;
        novoNoh->ant = NULL;
    } else { // LISTA NÃO VAZIA
        while (atual != NULL && atual->info < valor) {
            atual->ant = atual;
            atual = atual->prox;
        }
        novoNoh->prox = atual;
        novoNoh->ant = ant;
        if (ant != NULL) {
            ant->prox = novoNoh;
        }
        if (atual != NULL) {
            atual->ant = novoNoh;
        }
    }

    if (novoNoh->prox == NULL) {
        lista->fim = novoNoh;
    }
}

// Remover um elemento da lista
int removeDaLista(Lista *lista, int valor) {
    if (lista->comeco == NULL) {
        printf("Lista vazia. Impossível remover!\n");
        return FALSE;
    }
    Node *ant = NULL;
    Node *atual = lista->comeco;
    // LISTA: 1 -> 3 -> 4 -> 8
    // REMOVER: 1
    if (atual->info == valor) {
        lista->comeco = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = NULL;
        } else {
            lista->fim = NULL;
        }
        free(atual);
        return TRUE;
    }
    while (atual != NULL) {
        if (atual->info == valor) {
            if (atual->ant != NULL) {
                atual->ant->prox = atual->prox;
            }
            if (atual->prox != NULL) {
                atual->prox->ant = atual->ant;
            } else {
                lista->fim = atual->ant;
            }
            free(atual);
            return TRUE;
        }
        ant = atual;
        atual = atual->prox;
    }
    return FALSE;
}

int main() {
    Lista lista;
    iniciaLista(&lista);
    int a = removeDaLista(&lista, 5);
    insere(&lista, 5);
    insere(&lista, 6);
    insere(&lista, 3);
    insere(&lista, 4);
    insere(&lista, 8);
    insere(&lista, 2);
    insere(&lista, 1);
    insere(&lista, 7);
    insere(&lista, -1);
    mostraLista(lista);
    mostraListaInversa(lista);
    removeDaLista(&lista, 6);
    removeDaLista(&lista, 8);
    removeDaLista(&lista, -1);
    int elemento = removeDaLista(&lista, 99);
    if (elemento == FALSE) {
        printf("\nValor não encontrado.\n");
    }
    printf("\n\n");
    mostraLista(lista);
    mostraListaInversa(lista);

return 0;
}