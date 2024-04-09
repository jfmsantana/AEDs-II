#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ * prox;
} no;

void inserir_fila_enc(no **inicio, no **fim, no *novo_no){
    if (*fim != NULL){ //Verifica se a fila não está vazia
        (*(*fim)).prox = novo_no; //Se não estiver vazia
    } else {
        (*inicio) = novo_no; //Se estiver vazia
    }
    (*fim) = novo_no; //Independente de qualquer coisa, atualiza o ponteiro *fim para apontar para a última posição
}

no *remover_fila_enc(no **inicio, no **fim){
    no *tmp = NULL;
    if ((*inicio) != NULL){ //Se existir elemento na fila
        tmp = *inicio;
        *inicio = (*(*inicio)).prox;
        if (*inicio == NULL){ //Se o *inicio agora aponta para NULL
            *fim = NULL;//Significa que era o único elemento e agora está vazia
        }
    } 
    return tmp;
}

