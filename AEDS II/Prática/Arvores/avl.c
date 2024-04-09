#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    int fb;
    struct no *esq;
    struct no *dir;
} Node;

/*
    1                       2
        2               1       3
            3
*/

Node *rotacaoEsquerda(Node *raiz)
{
    Node *temp = raiz->dir;
    raiz->dir = temp->esq;
    temp->esq = raiz;
    raiz->fb = 0;
    temp->fb++;

    return temp;
}

/*
        3²               2
    2¹               1       3
1
*/
Node *rotacaoDireita(Node *raiz)
{
    Node *temp = raiz->esq; // 2
    raiz->esq = temp->dir;  // Apontamos para esq da raiz quem está a direita do temp (antigo nó esq)
    temp->dir = raiz;
    raiz->fb = 0;
    temp->fb--;

    return temp;
}

Node *rotacaoDuplaDireita(Node *raiz)
{
    raiz->esq = rotacaoEsquerda(raiz->esq);
    raiz = rotacaoDireita(raiz);
    return raiz;
}

Node *rotacaoDuplaEsquerda(Node *raiz)
{
    raiz->dir = rotacaoDireita(raiz->dir);
    raiz = rotacaoEsquerda(raiz);
    return raiz;
}

Node *insere(Node *raiz, int valor)
{
    if (raiz == NULL)
    {
        Node *novoNoh = (Node *)malloc(sizeof(Node));
        novoNoh->info = valor;
        novoNoh->esq = NULL;
        novoNoh->dir = NULL;
        novoNoh->fb = 0;
        return novoNoh;
    }
    if (raiz->info > valor)
    {
        raiz->fb++;
        raiz->esq = insere(raiz->esq, valor);
        if (raiz->fb >= 2)
        {
            if (raiz->esq->esq != NULL)
            {
                raiz = rotacaoDireita(raiz);
            }
            else
            {
                raiz = rotacaoDuplaDireita(raiz);
            }
        }
    }
    if (raiz->info < valor)
    {
        raiz->fb--;
        raiz->dir = insere(raiz->dir, valor);
        if (raiz->fb <= -2)
        {
            if (raiz->dir->dir != NULL)
            {
                raiz = rotacaoEsquerda(raiz);
            }
            else
            {
                raiz = rotacaoDuplaEsquerda(raiz);
            }
        }
    }
    return raiz;
}

int main()
{
    Node *raiz = insere(NULL, 5);
    raiz = insere(raiz, 2);
    raiz = insere(raiz, 4);
    // Rotação Dupla Direita OU Esquerda Direita
    // Node *n1 = (Node*) malloc(sizeof(Node));
    // n1->info = 5;
    // n1->fb = -2;
    // Node *n2 = (Node*) malloc(sizeof(Node));
    // n2->info = 8;
    // n2->fb = 1;
    // Node *n3 = (Node*) malloc(sizeof(Node));
    // n3->info = 7;
    // n3->fb = 0;
    // n1->dir = n2;
    // n2->esq = n3;

    // Rotação direita
    // Node *n7 = (Node*) malloc(sizeof(Node));
    // n7->info = 35;
    // n7->fb = 2;
    // Node *n6 = (Node*) malloc(sizeof(Node));
    // n6->info = 25;
    // n6->fb = 1;
    // Node *n5 = (Node*) malloc(sizeof(Node));
    // n5->info = 15;
    // n5->fb = 0;
    // Node *n4 = (Node*) malloc(sizeof(Node));
    // n4->info = 1;
    // n4->fb = 0;
    // Node *n1 = (Node*) malloc(sizeof(Node));
    // n1->info = 30;
    // n1->fb = 0;
    // Node *n2 = (Node*) malloc(sizeof(Node));
    // n2->info = 20;
    // n2->fb = 0;
    // Node *n3 = (Node*) malloc(sizeof(Node));
    // n3->info = 40;
    // n3->fb = 0;
    // n7->esq = n6;
    // n7->dir = n3;
    // n6->esq = n5;
    // n6->dir = n1;
    // n5->esq = n4;
    // n5->dir = n2;

    // Rotação Esquerda
    // Node *n1 = (Node*) malloc(sizeof(Node));
    // n1->info = 1;
    // n1->fb = -2;
    // Node *n0 = (Node*) malloc(sizeof(Node));
    // n0->info = 0;
    // n0->fb = 0;
    // Node *n2 = (Node*) malloc(sizeof(Node));
    // n2->info = 5;
    // n2->fb = -1;
    // Node *n3 = (Node*) malloc(sizeof(Node));
    // n3->info = 10;
    // n3->fb = 0;
    // Node *n4 = (Node*) malloc(sizeof(Node));
    // n4->info = 12;
    // n4->fb = 0;
    // Node *n5 = (Node*) malloc(sizeof(Node));
    // n5->info = 7;
    // n5->fb = 0;
    // Node *n6 = (Node*) malloc(sizeof(Node));
    // n6->info = 3;
    // n6->fb = 0;
    // n1->esq = n0;
    // n1->dir = n2;
    // n2->dir = n3;
    // n3->dir = n4;
    // n3->esq = n5;
    // n2->esq = n6;
    // Node *raiz = n1;
    // raiz = rotacaoEsquerda(raiz);
    return 1;
}