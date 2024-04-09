#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ * prox;
} no;

void buscar_enc (no *ptlista, int x, no **ant, no **pont){
    *ant = ptlista, *pont = NULL;
    no *ptr = (*ptlista).prox;
    while (ptr != NULL){
        if ((*ptr).chave < x){
            *ant = ptr;
            ptr = (*ptr).prox;
        } else {
            if ((*ptr).chave == x){
            *pont = ptr;
            }
            ptr = NULL;
        }
    }
}
    

no *inserir (no *ptlista, no *novo_no) {
    no *retorno, *ant, *pont;

    buscar_enc(ptlista,(*novo_no).chave, &ant, &pont);
    if (pont == NULL){ //Se não achou o elemento, irá inseri-lo
        (*novo_no).prox = (*ant).prox;
        (*ant).prox = novo_no;
        retorno = NULL; //Atribui ao retorno algo caso haja a inserção
    } else { //Se achou o elemento, ele já está na lista
        retorno = pont; //Atribui ao retorno a posição do elemento já existente
    }
    return retorno; //Retorna 
}

no *remover (no *ptlista, int x){

    no *retorno = NULL, *ant, *pont;
    buscar_enc(ptlista, x, &ant, &pont); //Faz a busca
    if (pont != NULL){ //Se achou o elemento, será possível removê-lo
        (*ant).prox = (*pont).prox;
        retorno = pont;
    }
    return retorno;
}


