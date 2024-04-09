#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct no
{
    int info;
    struct no *esq;
    struct no *dir;
} Node;

Node *insere(Node *raiz, int valor)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->info = valor;
    node->esq = NULL;
    node->dir = NULL;
    if (raiz == NULL)
    {
        return node;
    }
    else
    {
        // Vamos para a esquerda
        if (valor < raiz->info)
        {
            raiz->esq = insere(raiz->esq, valor);
        }
        if (valor > raiz->info)
        {
            raiz->dir = insere(raiz->dir, valor);
        }
    }
    return raiz;
}

// TODO: Mostrar a árvore
// Notações: Pré-Ordem, Em-Ordem e Pós-Ordem
void mostraArvorePreOrdem(Node *raiz)
{
    // printf("%d \t", raiz->info);
    if (raiz != NULL)
    { // if (raiz)
        printf("%d \t", raiz->info);
        mostraArvorePreOrdem(raiz->esq);
        mostraArvorePreOrdem(raiz->dir);
    }
}

void mostraArvoreEmOrdem(Node *raiz)
{
    // printf("%d \t", raiz->info);
    if (raiz != NULL)
    { // if (raiz)
        mostraArvoreEmOrdem(raiz->esq);
        printf("%d \t", raiz->info);
        mostraArvoreEmOrdem(raiz->dir);
    }
}

void mostraArvorePosOrdem(Node *raiz)
{
    // printf("%d \t", raiz->info);
    if (raiz != NULL)
    { // if (raiz)
        mostraArvorePosOrdem(raiz->esq);
        mostraArvorePosOrdem(raiz->dir);
        printf("%d \t", raiz->info);
    }
}
// TODO: Remover da árvore
// DECISÃO: Maior item subárvore esquerda OU menor item subárvore direita
// ESCOLHA: Maior item subárvore esquerda
// remove(raiz, NULL, 5)
Node *remover(Node *raiz, int valor)
{
    // Se a árvore estiver vazia
    if (raiz == NULL)
    {
        return raiz;
    }
    if (raiz->info == valor)
    { // Se o valor informado for o valor do nó a ser removido
        if (raiz->esq == NULL && raiz->dir == NULL)
        {               // Sem nenhum filho
            free(raiz); // Apenas retira-se da memória, sem precisar arrumar ponteiros
            return NULL;
        }
        // As próximas duas condições são para quando o nó a ser removido possui apenas um filho
        if (raiz->esq == NULL)
        {
            Node *temp = raiz->dir;
            free(raiz);
            return temp;
        }
        if (raiz->dir == NULL)
        {
            Node *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        // Se o nó a ser removido possui dois filhos
        Node *temp = raiz->esq; // Pega o maior valor da subárvore esquerda
        while (temp->dir != NULL)
        {
            temp = temp->dir;
        }
        raiz->info = temp->info;                    // Copia o valor do maior nó da subárvore esquerda para o nó a ser removido
                                                    // pois agora ele será o nó raiz da subárvore esquerda
        raiz->esq = remover(raiz->esq, temp->info); // Remove o nó que teve o valor copiado
    }
    return raiz;
}

// TODO: Buscar elemento na árvore O(log n)
int busca(Node *raiz, int valor)
{
    if (raiz == NULL)
    {
        return FALSE;
    }
    if (raiz->info == valor)
    {
        return TRUE;
    }
    if (raiz->info > valor)
    {
        return busca(raiz->esq, valor);
    }
    else
    {
        return busca(raiz->dir, valor);
    }
}

int main()
{
    // Podemos suprimir a função "inicia" / "iniciaArvore"
    Node *raiz = NULL;
    raiz = insere(raiz, 50);
    raiz = insere(raiz, 80);
    raiz = insere(raiz, 35);
    // raiz = insere(raiz, 80);
    // raiz = insere(raiz, 20);
    // raiz = insere(raiz, 45);
    // raiz = insere(raiz, 90);
    // raiz = insere(raiz, 75);
    raiz = remover(raiz, 50);
    printf("Nó removido com sucesso!");
    // raiz = insere(raiz, 50);
    printf("\nImpressão pre-ordem: \n");
    mostraArvorePreOrdem(raiz);
    printf("\n");
    // int result = busca(raiz, -50);
    // printf("Valor existe na árvore? %d", result);
    // printf("Valor eh: %d\n", raiz->info);
    return 0;
}