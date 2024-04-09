#include <stdio.h>
#include <stdlib.h>

int main(){

int v1[5] = { 1,2,3,4,5 }; // Vetor 1
int *pont = v1; //Ponteiro aponta para o primeiro elemento do vetor

int v2[5] = { 6,7,8,9,10 }; // Vetor 2
int *pont2 = v2; //Ponteiro aponta para o primeiro elemento do vetor

int v3[5]; //Vetor soma resultante de v1 + v2
for (int i = 0; i < 5; i++) {
    v3[i] = (*pont) + (*pont2);
    pont++;
    pont2++;
}

printf("O vetor soma resultante v3 é: ");
printf("v3[5] = {");
    for (int i = 0; i < 5; i++) {
        printf("%d", v3[i]);
        if (i < 4) {
            printf(", ");
        }
    }
    printf("}\n");
return 0;
}