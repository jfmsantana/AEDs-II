#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Endereçamento Aberto (Rehashing)
int sondagem_linear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) % TABLE_SIZE);
}

int sondagem_quadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2*i + 5*i*i;
    return (pos % TABLE_SIZE);
}

int duplo_hash(int H1, int chave, int i, int TABLE_SIZE){
    int H2 = chave_divisao(chave, TABLE_SIZE - 1) + 1;
    return ((H1 + i*H2) % TABLE_SIZE);
}
