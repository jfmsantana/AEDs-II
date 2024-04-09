#include <stdio.h>
#include <stdlib.h>

//Criando a estrutura de um nó da árvore
typedef struct no_ {
   int chave;
   int conteudo;
   struct no_ *esq, *dir; 
} no;

//Função que visita o nó
void visita(no *pt){
    printf("\nChave: %d ", pt->chave);
    printf("\nConteudo: %d \n", pt->conteudo);
    printf("--------------------------------\n");
}

//Função para criar um novo nó
no *novo_no(int chave, int conteudo) {
    no *novo_no = malloc(sizeof(no));
    novo_no->chave = chave;
    novo_no->conteudo = conteudo;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

//Função para realizar caminhamento em pré-ordem
void pre_ordem(no *pt) {
    if (pt != NULL){
        visita(pt);
        if (pt->esq != NULL){
            pre_ordem(pt->esq);
        } 
        if (pt->dir != NULL){
            pre_ordem(pt->dir);
        }
    }
}

//Função para realizar caminhamento em ordem
void em_ordem(no *pt) {
    if (pt != NULL){
        if (pt->esq != NULL){
            em_ordem(pt->esq);
        }
        visita(pt); 
        if (pt->dir != NULL){
            em_ordem(pt->dir);
        }   
    }
}

//Função para realizar caminhamento pós-ordem
void pos_ordem(no *pt) {
    if (pt != NULL){
        if (pt->esq != NULL){
            pos_ordem(pt->esq);
        }
        if (pt->dir != NULL){
            pos_ordem(pt->dir);
        }
        visita(pt);
    }
}

int main() {
    //Construindo uma árvore binária de exemplo
    no *pt = novo_no(1, 10);
    pt->esq = novo_no(2, 20);
    pt->dir = novo_no(3, 30);
    pt->esq->esq = novo_no(4, 40);
    pt->dir->dir = novo_no(5, 50);

    //Realizando pré-ordem
    printf("Caminhamento pré-ordem: \n");
    pre_ordem(pt);

    //Realizando em ordem
    printf("\nCaminhamento em ordem: \n");
    em_ordem(pt);

    //Realizando pós-ordem
    printf("\nCaminhamento pós-ordem: \n");
    pos_ordem(pt);
        
    
   return 0; 
}
