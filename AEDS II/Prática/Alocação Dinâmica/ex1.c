#include <stdio.h>
#include <stdlib.h>

int main(){
    int **matriz;
    int linhas = 3;
    int colunas = 3;

    matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL){
        printf("Falha na alocação de memória para as linhas da matriz");
        return 1;
    }
    
    for (int i = 0; i < linhas; i++){
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL){
            printf("Falha na alocação de memória para as colunas da matriz");
            return 1;
        }
    }

    printf("Matriz 3x3: \n");
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("Digite o valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }    

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    

    
    

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    
    return 0;
}