#include <stdio.h>
#include <stdlib.h>

typedef struct dados_ {
    int chave;
    int valor;
} dados;

int buscar (dados L[], int x, int n){
    int i = 0;
    int retorno = -1;
    while (i < n)
    {
        if (L[i].chave == x)
        {
            retorno = i;
            i = n;
        } else{
            i = i + 1;
        }
    }
    return retorno;

}



int buscar_2 (dados L[], int x, int n){
    int i = 0;
    L[n].chave = x;
    while (L[i].chave != x){
        i = i + 1;
    }
    if (i != n) {
        return i;
    } 
    return -1;
}


int busca_ord (dados L[], int x, int n){
    int i = 0;
    L[n].chave = x;
    while (L[i].chave < x) {
        i = i + 1;
    }
    if ((i == n) || (L[i].chave = x))
    {
        return -1;
    }
    return i;  
}



int busca_bin (dados L[], int x, int n){
    int inf = 0;
    int sup = n - 1;
    while (inf <= sup)
    {
        int meio = (inf + sup)/2;
        if (L[meio].chave == x)
        {
            return meio;
        } else if (L[meio].chave < x)
        {
            inf = meio + 1;
        } else {
            sup = meio -1;
        } 
    }
    return -1;
}
