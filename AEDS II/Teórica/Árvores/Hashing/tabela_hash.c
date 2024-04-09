#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_hashing.c"

typedef struct estudante_
{
    int matricula; // Chave
    char nome[50]; // Valor
    struct estudante_ *prox;
} estudante;

typedef struct hash_
{
    int qtd, TABLE_SIZE;
    estudante **estudantes;
} hash;

estudante *cria_estudante(char *nome, int matricula)
{
    estudante *e = malloc(sizeof(estudante));
    e->matricula = matricula;
    strncpy(e->nome, nome, strlen(nome));
    return e;
}

hash *cria_hash(int TABLE_SIZE)
{
    hash *h = malloc(sizeof(hash));

    if (h != NULL)
    {
        int i;
        h->estudantes = malloc(TABLE_SIZE * sizeof(estudante *));
        if (h->estudantes == NULL)
        {
            free(h);
            return NULL;
        }
        h->TABLE_SIZE = TABLE_SIZE;
        h->qtd = 0;
        for (i = 0; i < TABLE_SIZE; i++)
        {
            h->estudantes[i] = NULL;
        }
    }
    return h;
}

void libera_hash(hash *h)
{
    if (h != NULL)
    {
        int i;
        for (i = 0; i < h->TABLE_SIZE; i++)
        {
            if (h->estudantes[i] != NULL)
            {
                free(h->estudantes[i]);
            }

            free(h->estudantes);
            free(h);
        }
    }
}

int insere_hash_s_colisao(hash *h, estudante *e)
{
    if (h == NULL || h->qtd == h->TABLE_SIZE)
    {
        return 0;
    }
    int pos = chave_divisao(e->matricula, h->TABLE_SIZE);

    h->estudantes[pos] = e;
    h->qtd++;
    return 1;
}

char *busca_hash_s_colisao(hash *h, int matricula)
{
    int pos = chave_divisao(matricula, h->TABLE_SIZE);
    return &(h->estudantes[pos]->nome[0]);
}

int insere_hash_end_aberto(hash *h, estudante *e)
{
    if (h == NULL || h->qtd == h->TABLE_SIZE)
    {
        return 0;
    }
    int pos, i;
    pos = chave_divisao(e->matricula, h->TABLE_SIZE);
    // pos = chave_multiplicacao(e->matricula, h->TABLE_SIZE);
    // pos = chave_dobra(e->matricula, h->TABLE_SIZE);
    for (i = 0; i < h->TABLE_SIZE; i)
    {
        pos = sondagem_linear(pos, i, h->TABLE_SIZE);
        // pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
        // pos = duplo_hash(pos, e->matricula, i, h->TABLE_SIZE);
        if (h->estudantes[pos] == NULL)
        {
            h->estudantes[pos] = e;
            h->qtd++;
            return 1;
        }
    }
    return 0;
}

char *busca_hash_end_aberto(hash *h, int matricula)
{
    int i, pos;
    pos = chave_divisao(matricula, h->TABLE_SIZE);
    // pos = chave_multiplicacao(matricula, h->TABLE_SIZE);
    // pos = chave_dobra(matricula, h->TABLE_SIZE);
    for (i = 0; i < h->TABLE_SIZE; i++)
    {
        pos = sondagem_linear(pos, i, h->TABLE_SIZE);
        // pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
        // pos = duplo_hash(pos, matricula, i, h->TABLE_SIZE);
        if (h->estudantes[pos] == NULL)
        {
            return NULL;
        }
        else if (h->estudantes[pos]->matricula == matricula)
        {
            return &(h->estudantes[pos]->nome[0]);
        }
    }
    return NULL;
}

int insere_hash_end_aberto(hash *h, estudante *e)
{
    if (h == NULL || h->qtd == h->TABLE_SIZE)
    {
        return 0;
    }
    int pos, i;
    pos = chave_divisao(e->matricula, h->TABLE_SIZE);
    // pos = chave_multiplicacao(e->matricula, h->TABLE_SIZE);
    // pos = chave_dobra(e->matricula, h->TABLE_SIZE);
    for (i = 0; i < h->TABLE_SIZE; i)
    {
        pos = sondagem_linear(pos, i, h->TABLE_SIZE);
        // pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
        // pos = duplo_hash(pos, e->matricula, i, h->TABLE_SIZE);
        if (h->estudantes[pos] == NULL)
        {
            h->estudantes[pos] = e;
            h->qtd++;
            return 1;
        }
    }
    return 0;
}

char *busca_hash_end_aberto(hash *h, int matricula)
{
    int i, pos;
    pos = chave_divisao(matricula, h->TABLE_SIZE);
    // pos = chave_multiplicacao(matricula, h->TABLE_SIZE);
    // pos = chave_dobra(matricula, h->TABLE_SIZE);
    for (i = 0; i < h->TABLE_SIZE; i++)
    {
        pos = sondagem_linear(pos, i, h->TABLE_SIZE);
        // pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
        // pos = duplo_hash(pos, matricula, i, h->TABLE_SIZE);
        if (h->estudantes[pos] == NULL)
        {
            return NULL;
        }
        else if (h->estudantes[pos]->matricula == matricula)
        {
            return &(h->estudantes[pos]->nome[0]);
        }
    }
    return NULL;
}

/*TODO
    -- Implementar insere_hash_enc_separado
    -- Implementar busca_hash_enc_separado
    -- Implementar remove_hash_enc_separado
*/

int insere_hash_enc_separado(hash *h, estudante *e)
{
    if (h == NULL || h->qtd == h->TABLE_SIZE)   
    {
        return 0;
    }
    int pos;
    
    pos = chave_divisao(e->matricula, h->TABLE_SIZE);
    
    if (h->estudantes[pos] == NULL)
    {
        h->estudantes[pos] = e;
        h->qtd++;
        return 1;
    }
    if (h->estudantes[pos] == NULL)
    {
        h->estudantes[pos] = e;
        h->qtd++;
        return 1;
    }
    else
    {
        estudante *aux = h->estudantes[pos];
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = e;
        h->qtd++;
        return 1;
    }
}

char *busca_hash_enc_separado(hash *h, int matricula)
{
    int pos = chave_divisao(matricula, h->TABLE_SIZE);
    estudante *aux = h->estudantes[pos];
    while (aux != NULL)
    {
        if (aux->matricula == matricula)
        {
            return aux->nome; // Retorna o endereço do nome, com 0 pq é o primeiro char da lista de strings encontrada
        }
        aux = aux->prox;
    }
    return NULL;
}

int remove_hash_enc_separado(hash *h, int matricula)
{
    if (busca_hash_enc_separado(h, matricula) == NULL)
    {
        return 0; // Não encontrou, não está na tabela
    }
    else
    {
        int pos = chave_divisao(matricula, h->TABLE_SIZE);
        estudante *aux = h->estudantes[pos];
        estudante *ant = NULL;
        while (aux != NULL)
        {
            if (aux->matricula == matricula)
            {
                if (ant == NULL)
                {
                    h->estudantes[pos] = aux->prox;
                }
                else
                {
                    ant->prox = aux->prox;
                }
                free(aux);
                h->qtd--;
                return 1;
            }
            ant = aux;
            aux = aux->prox;
        }
    }
}
