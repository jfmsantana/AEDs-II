#include <stdio.h>
#include <stdlib.h>

int main() {
    int* gradeAverage = NULL;
    int numberOfStudents = 0;
    int higherAPC = 0;
    int newGrade = 0;

    printf("Digite o CDA do aluno %d: ", numberOfStudents);
    while (newGrade >= 0){
        scanf("%d", &newGrade);

        if (newGrade < 0){
            printf("O maior CDA entre os alunos da UNIFAL é: %d \n", higherAPC);
            exit(0);
        }

        gradeAverage = (int*) malloc(numberOfStudents * sizeof(int));
        if (gradeAverage == NULL){
            printf("Erro na alocação dinâmica!\n");
            exit(1);
        }
        
        int* newGradeAverage = (int*) realloc(gradeAverage, (numberOfStudents + 1) * sizeof(int));
        if (newGradeAverage == NULL) {
            printf("Erro na alocação dinâmica!\n");
            exit(1);
        }

        gradeAverage = newGradeAverage;
        gradeAverage[numberOfStudents] = newGrade;

        if (newGrade > higherAPC) {
            higherAPC = newGrade;
        }

        numberOfStudents++;

        printf("Digite o CDA do aluno %d: ", numberOfStudents); 

    }
    
    printf("O maior CDA entre os alunos da UNIFAL é: %d\n", higherAPC);
    
    free(gradeAverage);
    
    return 0;
}