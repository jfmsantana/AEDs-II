#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore_
{
    int valor;
    struct noArvore_ *esq;
    struct noArvore_ *dir;
} noArvore;

noArvore *busca(noArvore *raiz, int k)
{
    if (raiz = NULL || raiz->valor == k)
    {
        return raiz;
    }
    if (k > raiz->dir)
    {
        return busca(raiz->dir, k);
    }
    else
    {
        return busca(raiz->esq, k);
    }
}

noArvore *buscaPai(noArvore *raiz, noArvore *n)
{
    if (raiz == NULL || raiz == n)
    {
        return NULL;
    }
    if (raiz->dir == n || raiz->esq == n)
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

noArvore *insere(noArvore *raiz, noArvore *n)
{
    if (raiz == NULL)
    {
        return n;
    }
    if (n->valor > raiz->valor)
    {
        raiz->dir = insere(raiz->dir, n);
    }
    else
    {
        raiz->esq = insere(raiz->esq, n);
    }
    return raiz;
}

noArvore *removeRaiz(noArvore *raiz)
{
    noArvore *p, *q;

    if (raiz->esq == NULL)
    {
        q = raiz->dir;
        free(raiz);
        return (q);
    }

    p = raiz;
    q = raiz->esq;

    while (q->dir != NULL)
    {
        p = q;
        q = q->dir;
    }

    if (p != raiz)
    {
        p->dir = q->esq;
        q->esq = raiz->esq;
    }

    q->dir = raiz->dir;
    free(raiz);
    return (q);
}

noArvore *removeNo(noArvore *raiz, int valor)
{
    noArvore *n = busca(raiz, valor);
    if (n != NULL)
    {
        noArvore *pai = buscaPai(raiz, n);
        if (pai != NULL)
        {
            if (pai->dir == n)
            {
                pai->dir = removeRaiz(n);
            } else
            {
                pai->esq = removeRaiz(n);
            }
        } else
        {
            raiz = removeRaiz(n);
        }
         
        
    } 
    return raiz;
}

