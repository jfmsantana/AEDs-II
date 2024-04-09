#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
} no;

//Verificar se a lista está cheia
//Se não for encontrado com (busca), adiciona-se
//Se não, retorna o elemento já existente na lista
int inserir (no L[], int n, int m, no d){
    if (n < m){
        if (busca(L, n, d.chave) == -1)
        {
            L[n+1].chave = d.chave;
            L[n+1].valor = d.valor;
            return n+1;
        } else {
            return 0;
        }
    }
    return -1;
}

no * remover (no L[], int *n, int x){
    no * retorno = NULL;
    //Verificar se a lista existe
    //Alocar o indice do elemento achado na função buscar
    //Se for encontrado, copia os valores para o *retorno
    //Desloca todos os elementos uma posição para a esquerda com o for
    //Fora do for, diminui em 1 o tamanho da lista
    if (n != 0)
    {
        int indice = buscar(L, x, *n);
        if (indice >= 0){
            retorno = malloc(sizeof(no));
            (*retorno).chave = L[indice].chave;
            (*retorno).valor = L[indice].valor;

            for (int i = indice; i < (*n) - 1; i++)
            {
                L[i].chave = L[i+1].chave;
                L[i].valor = L[i+1].valor;
            }
            *n = (*n) - 1;
        }
        
    }
    
    return retorno;
}

// PILHA
int insere_pilha(no p[], *topo, int n, no d){
    //Verifica se a lista está cheia
    //Se estiver espaço, (*topo)++ e p[topo] = d;
    //Retorna
    int retorno = -1;
    if (*topo != n - 1)
    {
        (*topo)++;
        p[topo] = d;
        retorno = topo; 
    }
    return retorno;
}


no *removePilha(no p[], int *topo){
    //Verifica se existe pilha
    //Copia os valores de *topo para *retorno
    //Retorno
    no *retorno = NULL;
    if (*topo != -1)
    {
        retorno = malloc(sizeof(no));
        (*retorno).chave = p[*topo].chave;
        (*retorno).valor = p[*topo].valor;
        (*topo)--;
    }

    return retorno;
}

// FILA
int insere_fila(no fila[], int m, int *f, int *r, no x){
    //Estabelece a provisória através da conta
    //Verifica se a fila existe vendo se próximo de *r é *f
    //Adiciona no próximo de *r
    //Se não existia, agora existirá
    int retorno = -1;
    int prov = ((*r) + 1) % m;
    if (prov != *f)
    {
        *r = prov;
        fila[*r] = x;
        retorno = *r;

        if (*f == -1)
        {
            *f = 0;
        }  
    }  
    return retorno;
}

no *remove_fila(no fila[], int m, int r*, int *f){
    //Verifica se há algo na fila
    //Copia o valor de *f para retorno
    //Se tivesse só um elemento, fica vazio
    //Senão *f agora terá de apontar para o próximo (pela conta)
    //Retorna a posição 
    no *retorno = NULL;
    if (*f != -1)
    {
        retorno = malloc(sizeof(no));
        (*retorno).chave = fila[*f].chave;
        (*retorno).valor = fila[*f].valor;
        if (*f == *r)
        {
            *f = *r = -1;
        } else {
            *f = ((*f) + 1) % m;
        }
        *retorno = fila[*f];
        return retorno;
    }
    return *retorno;
}



