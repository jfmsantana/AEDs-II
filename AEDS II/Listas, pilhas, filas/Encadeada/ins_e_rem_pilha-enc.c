#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ * prox;
} no;

void inserir_pilha_enc(no **topo,no *novo_no){
    (*novo_no).prox = *topo;
    *topo = novo_no;
}


no *remove_pilha_enc (no **topo){
    no *tmp = NULL;
    if (*topo != NULL){ //Se houver elemento a ser retirado
        tmp = *topo;    
        (*topo) = (*(*topo)).prox;
    }
    return tmp;
}
