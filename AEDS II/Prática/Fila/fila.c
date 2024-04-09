#include<stdio.h>
#define TAM 8

typedef struct _Pessoa {
    char nome[20];
    int idade;
} Pessoa;

void mostraFila(Pessoa *fila, int comeco, int fim, int tamanho) {
    if (tamanho == 0) {
        printf("Fila vazia!\n");
    } else {
        // FILA CIRCULAR
        // COMEÇO → FIM
        while (comeco != fim) {
            if (comeco == TAM-1) {
                comeco = 0;
            }
            printf("Pessoa #%d \t Nome: %s \t Idade: %d\n", comeco, fila[comeco].nome, fila[comeco].idade);
            comeco += 1;
        }
        
    }
}

void insereNaFila(Pessoa *fila, Pessoa pessoa, int *fim, int *tamanho) {
    if (*tamanho == TAM) {
        printf("Fila Cheia! \n"); // Queue
    } else {
        *fim = (*fim == TAM-1) ? 0 : *fim + 1;
        fila[*fim] = pessoa;
        *tamanho = *tamanho + 1;
    }
}

int main() {
    Pessoa fila[TAM];
    int comeco = 0;
    int fim = -1;
    int tamanho = 0;

    while (tamanho < TAM){
        Pessoa p;
        printf("Digite seu nome: ");
        scanf("%s", p.nome);
        printf("Digite sua idade: ");
        scanf("%d", &p.idade);
        insereNaFila(fila, p, &fim, &tamanho);
    }
    printf("Fila cheia, não é possível adicionar!\n");
    mostraFila(fila, comeco, fim, tamanho);

    
    return 0;
}