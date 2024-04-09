#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "oi.c"

typedef struct estudante_
{
    int matricula; // Chave
    char nome[50]; // Valor
    struct estudante_ *prox;
} estudante;

typedef struct hash_
{
    int qtd, TABLE_SIZE;
    estudante **estudantes;
} hash;

estudante *cria_estudante(char *nome, int matricula)
{
    estudante *e = malloc(sizeof(estudante));
    e->matricula = matricula;
    strncpy(e->nome, nome, strlen(nome));
    return e;
}

hash *cria_hash(int TABLE_SIZE)
{
    hash *h = malloc(sizeof(hash));

    if (h != NULL)
    {
        int i;
        h->estudantes = malloc(TABLE_SIZE * sizeof(estudante *));
        if (h->estudantes == NULL)
        {
            free(h);
            return NULL;
        }
        h->TABLE_SIZE = TABLE_SIZE;
        h->qtd = 0;
        for (i = 0; i < TABLE_SIZE; i++)
        {
            h->estudantes[i] = NULL;
        }
    }
    return h;
}

void libera_hash(hash *h)
{
    if (h != NULL)
    {
        int i;
        for (i = 0; i < h->TABLE_SIZE; i++)
        {
            if (h->estudantes[i] != NULL)
            {
                free(h->estudantes[i]);
            }
        }
        free(h->estudantes);
        free(h);
    }
}

void mostrar_tabela(hash *h)
{
    if (h != NULL)
    {
        int i;
        for (i = 0; i < h->TABLE_SIZE; i++)
        {
            if (h->estudantes[i] != NULL)
            {
                printf("Posição %d: %s\n", i, h->estudantes[i]->nome);
            }
            else
            {
                printf("Posição %d: NULL\n", i);
            }
        }
    }
}

int chave_divisao(int chave, int TABLE_SIZE)
{
    if (chave < 0)
    {
        chave = chave * -1;
    }
    return chave % TABLE_SIZE;
}

int chave_multiplicacao(int chave, int TABLE_SIZE)
{
    if (chave < 0)
    {
        chave = chave * -1;
    }
    double A = 0.6180339887;
    double val = chave * A;
    val = val - (int)val;
    return (int)(TABLE_SIZE * val);
}

int chave_dobra(int chave, int TABLE_SIZE)
{
    int soma = 0;
    char str[20];
    sprintf(str, "%d", chave); // Converte a chave para uma string

    for (int i = 0; i < strlen(str); i += 2)
    {
        int num = 0;
        if (i + 1 < strlen(str))
        {
            num = (str[i] - '0') * 10 + (str[i + 1] - '0'); // Combina dois dígitos
        }
        else
        {
            num = str[i] - '0'; // Último dígito se o número de dígitos for ímpar
        }
        soma += num;
        if (soma >= TABLE_SIZE)
        {
            soma = soma % 10 + soma / 10; // Dobra a soma se for maior que o tamanho da tabela
        }
    }
    return soma;
}

// Endereçamento Aberto (Rehashing)
int sondagem_linear(int pos, int i, int TABLE_SIZE)
{
    return ((pos + i) % TABLE_SIZE);
}

int sondagem_quadratica(int pos, int i, int TABLE_SIZE)
{
    pos = pos + 2 * i + 5 * i * i;
    return (pos % TABLE_SIZE);
}

int duplo_hash(int H1, int chave, int i, int TABLE_SIZE)
{
    int H2 = chave_divisao(chave, TABLE_SIZE - 1) + 1;
    return ((H1 + i * H2) % TABLE_SIZE);
}

int insere_hash_end_aberto(hash *h, estudante *e)
{
    if (h == NULL || h->qtd == h->TABLE_SIZE)
    {
        return 0;
    }
    int pos, i;
    pos = chave_divisao(e->matricula, h->TABLE_SIZE);
    // pos = chave_multiplicacao(e->matricula, h->TABLE_SIZE);
    // pos = chave_dobra(e->matricula, h->TABLE_SIZE);
    for (i = 0; i < h->TABLE_SIZE; i++)
    {
        pos = sondagem_linear(pos, i, h->TABLE_SIZE);
        // pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
        // pos = duplo_hash(pos, e->matricula, i, h->TABLE_SIZE);
        if (h->estudantes[pos] == NULL)
        {
            h->estudantes[pos] = e;
            h->qtd++;
            return 1;
        }
    }
    return 0;
}

char *busca_hash_end_aberto(hash *h, int matricula)
{
    int i, pos;
    pos = chave_divisao(matricula, h->TABLE_SIZE);
    // pos = chave_multiplicacao(matricula, h->TABLE_SIZE);
    // pos = chave_dobra(matricula, h->TABLE_SIZE);
    for (i = 0; i < h->TABLE_SIZE; i++)
    {
        pos = sondagem_linear(pos, i, h->TABLE_SIZE);
        // pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
        // pos = duplo_hash(pos, matricula, i, h->TABLE_SIZE);
        if (h->estudantes[pos] == NULL)
        {
            return NULL;
        }
        else if (h->estudantes[pos]->matricula == matricula)
        {
            return &(h->estudantes[pos]->nome[0]);
        }
    }
    return NULL;
}

int main()
{
    int pos;
    printf("Digite o tamanho da tabela: ");
    int TABLE_SIZE;
    scanf("%d", &TABLE_SIZE);
    hash *h = cria_hash(TABLE_SIZE);
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        h->estudantes[i] = NULL;
    }
    int opcao;
    printf("Qual função de hashing deseja utilizar?\n");
    printf("1 - Divisão\n");
    printf("2 - Multiplicação\n");
    printf("3 - Dobra\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        while (h->qtd < TABLE_SIZE)
        {
            printf("O que deseja fazer ?\n");
            printf("1 - Inserir\n");
            printf("2 - Buscar\n");
            printf("3 - Mostrar tabela\n");
            printf("4 - Sair\n");
            int opcao;
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                printf("Digite o nome do estudante: ");
                char nome[50];
                scanf("%s", nome);
                printf("Digite a matrícula do estudante: ");
                int matricula;
                scanf("%d", &matricula);
                estudante *e = cria_estudante(nome, matricula);
                int pos = chave_divisao(e->matricula, h->TABLE_SIZE);
                if (h->estudantes[pos] == NULL)
                {
                    insere_hash_end_aberto(h, e);
                }
                else
                {
                    printf("Colisão na posição %d\n", pos);
                    printf("Deseja tratar a colisão?\n");
                    printf("1 - Sim\n");
                    printf("2 - Não\n");
                    int opcao;
                    scanf("%d", &opcao);
                    if (opcao == 1)
                    {
                        printf("Qual método de tratamento de colisão deseja utilizar?\n");
                        printf("1 - Sondagem Linear\n");
                        printf("2 - Sondagem Quadrática\n");
                        printf("3 - Duplo Hash\n");
                        int opcao;
                        scanf("%d", &opcao);
                        if (opcao == 1)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = sondagem_linear(pos, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else if (opcao == 2)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else if (opcao == 3)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = duplo_hash(pos, e->matricula, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else
                        {
                            printf("Opção inválida\n");
                        }
                    }
                    else if (opcao == 2)
                    {
                        printf("O programa encerrará\n");
                        return 0;
                    }
                }
                break;
            case 2:
                printf("Digite a matrícula do estudante (ela será buscada pelo método da divisão): ");
                scanf("%d", &matricula);
                pos = chave_divisao(matricula, h->TABLE_SIZE);
                if (busca_hash_end_aberto(h, matricula) != NULL)
                {
                    printf("Estudante encontrado: %s\n", busca_hash_end_aberto(h, matricula));
                }
                else
                {
                    printf("Estudante não encontrado\n");
                }
                break;
            case 3:
                mostrar_tabela(h);
                break;
            case 4:
                libera_hash(h);
                return 0;
            }
        }
        printf("Tabela cheia\n");
        break;
    case 2:
        while (h->qtd < TABLE_SIZE)
        {
            printf("O que deseja fazer ?\n");
            printf("1 - Inserir\n");
            printf("2 - Buscar\n");
            printf("3 - Mostrar tabela\n");
            printf("4 - Sair\n");
            int opcao;
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                printf("Digite o nome do estudante: ");
                char nome[50];
                scanf("%s", nome);
                printf("Digite a matrícula do estudante: ");
                int matricula;
                scanf("%d", &matricula);
                estudante *e = cria_estudante(nome, matricula);
                int pos = chave_multiplicacao(e->matricula, h->TABLE_SIZE);
                if (h->estudantes[pos] == NULL)
                {
                    insere_hash_end_aberto(h, e);
                }
                else
                {
                    printf("Colisão na posição %d\n", pos);
                    printf("Deseja tratar a colisão?\n");
                    printf("1 - Sim\n");
                    printf("2 - Não\n");
                    int opcao;
                    scanf("%d", &opcao);
                    if (opcao == 1)
                    {
                        printf("Qual método de tratamento de colisão deseja utilizar?\n");
                        printf("1 - Sondagem Linear\n");
                        printf("2 - Sondagem Quadrática\n");
                        printf("3 - Duplo Hash\n");
                        int opcao;
                        scanf("%d", &opcao);
                        if (opcao == 1)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = sondagem_linear(pos, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else if (opcao == 2)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else if (opcao == 3)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = duplo_hash(pos, e->matricula, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else
                        {
                            printf("Opção inválida\n");
                        }
                    }
                    else if (opcao == 2)
                    {
                        printf("O programa encerrará\n");
                        return 0;
                    }
                }
                break;
            case 2:
                printf("Digite a matrícula do estudante (ela será buscada pelo método da multiplicação): ");
                scanf("%d", &matricula);
                pos = chave_multiplicacao(matricula, h->TABLE_SIZE);
                if (busca_hash_end_aberto(h, matricula) != NULL)
                {
                    printf("Estudante encontrado: %s\n", busca_hash_end_aberto(h, matricula));
                }
                else
                {
                    printf("Estudante não encontrado\n");
                }
                break;
            case 3:
                mostrar_tabela(h);
                break;
            case 4:
                libera_hash(h);
                return 0;
            }
        }
        printf("Tabela cheia\n");
        break;
    case 3:
        while (h->qtd < TABLE_SIZE)
        {
            printf("O que deseja fazer ?\n");
            printf("1 - Inserir\n");
            printf("2 - Buscar\n");
            printf("3 - Mostrar tabela\n");
            printf("4 - Sair\n");
            int opcao;
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                printf("Digite o nome do estudante: ");
                char nome[50];
                scanf("%s", nome);
                printf("Digite a matrícula do estudante: ");
                int matricula;
                scanf("%d", &matricula);
                estudante *e = cria_estudante(nome, matricula);
                int pos = chave_dobra(e->matricula, h->TABLE_SIZE);
                if (h->estudantes[pos] == NULL)
                {
                    insere_hash_end_aberto(h, e);
                }
                else
                {
                    printf("Colisão na posição %d\n", pos);
                    printf("Deseja tratar a colisão?\n");
                    printf("1 - Sim\n");
                    printf("2 - Não\n");
                    int opcao;
                    scanf("%d", &opcao);
                    if (opcao == 1)
                    {
                        printf("Qual método de tratamento de colisão deseja utilizar?\n");
                        printf("1 - Sondagem Linear\n");
                        printf("2 - Sondagem Quadrática\n");
                        printf("3 - Duplo Hash\n");
                        int opcao;
                        scanf("%d", &opcao);
                        if (opcao == 1)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = sondagem_linear(pos, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else if (opcao == 2)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = sondagem_quadratica(pos, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else if (opcao == 3)
                        {
                            int i = 0;
                            while (h->estudantes[pos] != NULL)
                            {
                                pos = duplo_hash(pos, e->matricula, i, h->TABLE_SIZE);
                                i++;
                            }
                            h->estudantes[pos] = e;
                            h->qtd++;
                        }
                        else
                        {
                            printf("Opção inválida\n");
                        }
                    }
                    else if (opcao == 2)
                    {
                        printf("O programa encerrará\n");
                        return 0;
                    }
                }
                break;
            case 2:
                printf("Digite a matrícula do estudante (ela será buscada pelo método da dobra): ");
                scanf("%d", &matricula);
                pos = chave_dobra(matricula, h->TABLE_SIZE);
                if (busca_hash_end_aberto(h, matricula) != NULL)
                {
                    printf("Estudante encontrado: %s\n", busca_hash_end_aberto(h, matricula));
                }
                else
                {
                    printf("Estudante não encontrado\n");
                }
                break;
            case 3:
                mostrar_tabela(h);
                break;
            case 4:
                libera_hash(h);
                return 0;
            }
        }
        printf("Tabela cheia\n");
        break;
    default:
        printf("Opção inválida\n");
        break;
    }
    libera_hash(h);
    return 0;
}
