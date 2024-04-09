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
    printf("\n\n");
}

//Mostrar/Exibir a lista do fim até o começo
void mostrarListaInversa(Lista lista) {
    Node *aux = lista.fim;
    while (aux != NULL){
        printf("%d \t", aux->info);
        aux = aux->ant;
    }
    printf("\n\n");
}

// Inserir na lista DE FORMA ORDENADA
void insere(Lista *lista, int valor) {
    Node *novoNoh = (Node*) malloc(sizeof(Node));
    novoNoh->info = valor;
    novoNoh->prox = NULL;
    novoNoh->ant = NULL;

    Node *aux = lista->comeco;
    Node *ant = NULL;
    // LISTA VAZIA
    if (lista->comeco == NULL) {
        lista->comeco = novoNoh;
        lista->fim = novoNoh;
    } else if (lista->comeco->info > valor) {
        novoNoh->prox = lista->comeco;
        lista->comeco->ant = novoNoh;
        lista->comeco = novoNoh;
    } else {
        while (aux != NULL && aux->info < valor) {
            ant = aux;
            aux = aux->prox;
        }
        novoNoh->prox = aux;
        novoNoh->ant = ant;
        if (ant != NULL) {
            ant->prox = novoNoh;
        } else {
            lista->comeco = novoNoh;
        }
        if (aux != NULL) {
            aux->ant = novoNoh;
        } else {
            lista->fim = novoNoh;
        }
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
        if (lista->comeco != NULL){
            lista->comeco->ant = NULL;
        } else {
            lista->fim = NULL; //Se a lista ficar vazia após a remoção
        }
        free(atual);
        return TRUE;
    }
    while (atual != NULL) {
        if (atual->info == valor) {
            if (ant != NULL) {
                ant->prox = atual->prox;
            }
            if (atual->prox != NULL){
                atual->prox->ant = ant;
            } else {
                lista->fim = ant;
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
    mostrarListaInversa(lista);
    removeDaLista(&lista, 6);
    removeDaLista(&lista, 8);
    removeDaLista(&lista, -1);
    int elemento = removeDaLista(&lista, 99);
    printf("\nValor foi removido? %d", elemento);
    printf("\n\n");
    mostraLista(lista);
    mostrarListaInversa(lista);
}