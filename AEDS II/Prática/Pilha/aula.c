#include <stdio.h>
#define TAM 4

void mostraPilha(char *pilha, int topo) {
    printf("-----------------\n");
    if (topo == -1) {
        printf("A pilha está vazia!\n");
    }
    for (int i = topo; i >= 0; i--) {
        printf("Pilha[%d]: %c\n", i, pilha[i]);
    }
    printf("-----------------\n");
}

void empilhar(char *pilha, int *topo, char valor) { // push
    if (*topo >= TAM-1) {
        printf("Pilha cheia!\n");
    } else {
        *topo = *topo + 1;
        pilha[*topo] = valor;   
    }
}

char desempilha(char *pilha, int *topo) { // pop
    if (*topo == -1) {
        printf("Pilha vazia! Impossível remover.\n");
        return '\0';
    }
    *topo = *topo - 1;
    return pilha[*topo + 1];
}

int main() {
    char pilha[TAM];
    int topo = -1;

    // Mostrar a Pilha → Inicialmente vazia
    mostraPilha(pilha, topo);

    desempilha(pilha, &topo);

    // Empilhar elementos
    empilhar(pilha, &topo, 'i');
    empilhar(pilha, &topo, 'j');
    empilhar(pilha, &topo, 'k');
    empilhar(pilha, &topo, 'l');
    empilhar(pilha, &topo, 'm');

    printf("Valor desempilhado: %c\n", desempilha(pilha, &topo));
    printf("Valor desempilhado: %c\n", desempilha(pilha, &topo));

    // Mostrar a Pilha → Agora com elementos
    mostraPilha(pilha, topo);

    return 0;
}