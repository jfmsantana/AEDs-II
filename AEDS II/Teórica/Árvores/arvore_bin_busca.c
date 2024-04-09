#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore_
{
    int valor;
    struct noArvore_ *esq;
    struct noArvore_ *dir;
} noArvore;

noArvore *insere(noArvore *raiz, int valor)
{
    if (raiz == NULL)
    {
        noArvore *n = malloc(sizeof(noArvore));
        n->valor = valor;
        n->esq = NULL;
        n->dir = NULL;
        return n;
    }
    if (valor > raiz->valor)
    {
        raiz->dir = insere(raiz->dir, valor);
    }
    else
    {
        raiz->esq = insere(raiz->esq, valor);
    }
    return raiz;
}

noArvore *busca(noArvore *raiz, int k)
{
    if (raiz == NULL || raiz->valor == k) //Se a raiz não existir, retorna NULL. Se for logo o primeiro
    {                                     // o primeiro elemento (raiz), retorna ela mesma.
        return raiz;
    }
    if (k > raiz->valor)
    {
        return busca(raiz->dir, k);
    }
    else
    {
        return busca(raiz->esq, k);
    }
}

noArvore *buscaPai(noArvore *raiz, noArvore *n)
{ // Verifica se tem um nó pai
    if (raiz->valor == n->valor || raiz == NULL) //Se não houver raiz, ou se for logo o primeiro elemento (raiz)
                                                 // sendo buscado, retorna NULL, pois a raiz não tem nó pai 
    {
        return NULL;
    }
    if (raiz->esq == n || raiz->dir == n)
    {
        return raiz;
    }
    if (n->valor > raiz->valor)
    {
        return buscaPai(raiz->dir, n);
    }
    else
    {
        return buscaPai(raiz->esq, n);
    }
}

noArvore *removeRaiz(noArvore *raiz, int valor) {
    noArvore *n = busca(raiz, valor);
    if (n == NULL) {
        return raiz; // Nó a ser removido não encontrado, retorne a raiz original
    }

    if (n->esq == NULL && n->dir == NULL) { // Nó a ser removido é uma folha
        if (n == raiz) {
            raiz = NULL;
        } else {
            noArvore *pai = buscaPai(raiz, n);
            if (pai->esq == n) {
                pai->esq = NULL;
            } else {
                pai->dir = NULL;
            }
        }
        free(n);
    } else if (n->esq == NULL) { // Nó a ser removido tem apenas filho direito
        if (n == raiz) {
            raiz = n->dir;
        } else {
            noArvore *pai = buscaPai(raiz, n);
            if (pai->esq == n) {
                pai->esq = n->dir;
            } else {
                pai->dir = n->dir;
            }
        }
        free(n);
    } else if (n->dir == NULL) { // Nó a ser removido tem apenas filho esquerdo
        if (n == raiz) {
            raiz = n->esq;
        } else {
            noArvore *pai = buscaPai(raiz, n);
            if (pai->esq == n) {
                pai->esq = n->esq;
            } else {
                pai->dir = n->esq;
            }
        }
        free(n);
    } else { // Nó a ser removido tem dois filhos
        noArvore* aux = n->esq;
        noArvore* paiAux = n;
        while (aux->dir != NULL) {
            paiAux = aux;
            aux = aux->dir;
        }
        // Copia o valor do nó aux para o nó n
        n->valor = aux->valor;
        // Se aux é filho esquerdo de seu pai, atualiza o filho esquerdo do pai de aux
        if (paiAux->esq == aux) {
            paiAux->esq = aux->esq;
        } else { // Se aux é filho direito de seu pai, atualiza o filho direito do pai de aux
            paiAux->dir = aux->esq;
        }
        free(aux);  
    }
    return raiz;
}

void mostraArvorePreOrdem(noArvore* raiz){
    if (raiz != NULL)
    {
        printf("%d \t", raiz->valor);
        mostraArvorePreOrdem(raiz->esq);
        mostraArvorePreOrdem(raiz->dir);
    }
}

int main() {
    noArvore *raiz = NULL;

    raiz = insere(raiz, 50);
    raiz = insere(raiz, 30);
    raiz = insere(raiz, 20);
    raiz = insere(raiz, 40);
    raiz = insere(raiz, 70);
    raiz = insere(raiz, 60);
    raiz = insere(raiz, 80);

    mostraArvorePreOrdem(raiz);

    raiz = removeRaiz(raiz, 20);
    printf("\n\n");
    mostraArvorePreOrdem(raiz);

    return 0;
}