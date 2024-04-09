#include <stdio.h>
#include <stdlib.h>

int main(){
    int m[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Insira o valor para [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("\nm[%d][%d]: %d \n", i, j, m[i][j]);
            
        }
    }
    return 0;
}