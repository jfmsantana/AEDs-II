#include <stdio.h>
#include <stdlib.h>
#define ERRO -1

int encontrapai (int i){
  return(i-1)/2;
}

int encontradireita(int i){
  return (2*i)+2;
}

int encontraesquerda(int i){
  return (2*i)+1;
}

void troca (int * i , int * j){
  int tmp = *i;
  *i = *j;
  *j = tmp;
}

void inserir (int * arvore, int * tamanhoatual, int * capacidade, int  novo){
  
  if ((*tamanhoatual) == (*capacidade)){ 
    printf("Sua árvore está cheia!\n");
    return;
  }

  (*tamanhoatual)++;
  int i = (*tamanhoatual) - 1;
  arvore[i] = novo;

  while (i != 0 && arvore[encontrapai(i)] > arvore[i]){
    troca(&arvore[encontrapai(i)], &arvore[i]);
    i = encontrapai(i);
  }
}

void ajustar (int * arvore, int tamanhoatual, int i){
  
  int direita = encontradireita(i);
  int esquerda = encontraesquerda(i);
  int menor = i;
  if (esquerda < tamanhoatual && arvore[esquerda] < arvore[i]){
    menor = esquerda;
  }
  if (direita < tamanhoatual && arvore[direita] < arvore[menor]){
    menor = direita;
  }
  if (menor != i){
    troca(&arvore[i], &arvore[menor]);
    ajustar(arvore, tamanhoatual, menor);
  }
  
}

int remover (int * arvore, int * tamanhoatual){
  if (*tamanhoatual <= 0){
    printf("Sua árvore está vazia!\n");
    return ERRO;
  }
  if (*tamanhoatual == 1){
    (*tamanhoatual)--;
    return arvore[0];
  }

  int removido = arvore[0];
  arvore[0] = arvore[(*tamanhoatual) - 1];
  (*tamanhoatual)--;
  ajustar(arvore, *tamanhoatual, 0);
  return removido;
  
}


int main() {
  int tamanhoatual = 0, capacidade, continua = 1;
  
  printf("Digite o tamanho da arvore:");
  scanf("%d", &capacidade);

  int * arvore =  malloc(capacidade * sizeof(int));

  while (continua != 0){
    printf("Digite o que deseja fazer: 1. adicionar | 2. remover | 3. mostrar | 0. sair\n");
    scanf("%d", &continua);
    if (continua == 1){
      int novo;
      printf("Digite o valor que deseja adicionar:");
      scanf("%d", &novo);
      inserir(arvore, &tamanhoatual, &capacidade, novo);
    } else if (continua == 2){
      int removido = remover(arvore, &tamanhoatual);
      if (removido != ERRO){
        printf("O valor removido foi %d \n", removido);
      }
    } else if (continua == 3){
      printf("Mostrando arvore HEAP: ");
      for (int i = 0; i < tamanhoatual; i++){
        printf("%d\t", arvore[i]);
      }
      printf("\n");
    }
  }

  free(arvore);

}