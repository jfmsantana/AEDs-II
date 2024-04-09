#include <stdio.h>
#include <stdlib.h>

int main()
{
    char p1[100], p2[100];
    char *pont1 = p1, *pont2 = p2;

    printf("Digite uma palavra: ");
    scanf("%s", p1);
    printf("Digite outra palavra: ");
    scanf("%s", p2);

    int encontrou = 0; // Inicialmente sem encontrar

    for (int i = 0; i < 100; i++)
    {
        if (*pont1 == *pont2)
        {
            char *tmp1 = pont1;
            char *tmp2 = pont2;

            while (*pont1 == *pont2 && *pont1 != '\0' && *pont2 != '\0')
            {
                pont1++;
                pont2++;
            }
            if (*pont2 == '\0')
            {
                encontrou = 1;
                printf("A palavra está dentro da outra. \n");
                break;
            }

            pont1 = tmp1 + 1;
            pont2 = tmp2;
        }
        else
        {
            pont1++;
        }
    }

    if (encontrou == 0)
    {
        printf("A palavra p2 não está dentro da p1\n");
    }

    return 0;
}