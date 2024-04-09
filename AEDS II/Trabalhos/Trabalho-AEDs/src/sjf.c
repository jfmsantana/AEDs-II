#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/lista.h"

void sjf(int delay)
{

    int processosCriados = 0;
    // Se existir algo no arquivo, a função vai apagar
    limparArquivo("exe/logs/sjfLog");
    no *ptLista = malloc(sizeof(no)); // Criando uma estrutura para alocar os processos.
    ptLista->prox = NULL;

    // Considera-se cada loop do while como uma iteração
    while (1)
    {
        // Abrindo o arquivo de log
        FILE *arquivo = fopen("exe/logs/sjfLog", "a");
        no *primeiroNo = ptLista->prox;
        if (tentarCriarProcesso()) // Se criar um processo
        {
            no *processoAtual = alocarNo(&processosCriados); // Aloca um novo nó
            inserirListaFim(ptLista, processoAtual);         // Insere o nó no final da lista por meio da função inserirListaFim

            printf("\033[0;34mProcesso %d de tamanho %d criado!\033[0m\n", processoAtual->id, processoAtual->tamanho);
            fprintf(arquivo, "\n\tProcesso %d de tamanho %d criado!\n\n", processoAtual->id, processoAtual->tamanho);
        }

        if (primeiroNo != NULL) // Se houver um processo na lista
        {
            printf("Processo %d executando...\n", primeiroNo->id);
            fprintf(arquivo, "Processo %d executando...\n", primeiroNo->id);

            printf("Tamanho restante: %d\n", primeiroNo->tamanho);
            fprintf(arquivo, "Tamanho restante: %d\n", primeiroNo->tamanho);

            // Esperando o tempo
            sleep(delay);
            primeiroNo->tamanho--;        // Diminui o tamanho do processo em uma iteração, já que cada loop do while é uma iteração
            if (primeiroNo->tamanho == 0) // Se o processo acabou (ou quando o processo acabar)
            {
                printf("\033[0;32mProcesso %d finalizado!\033[0m\n", primeiroNo->id);
                fprintf(arquivo, "\n==================== Processo %d finalizado! ====================\n\n", primeiroNo->id);
                sleep(delay);
                removerLista(ptLista, primeiroNo->id); // Remove o processo da lista por meio da função removerLista
                ordenaListaTam(&ptLista);              //Ordena lista por ordem de tamanho
            }
        }
        else
        {
            printf("Nenhum processo criado, aguarde até que outro processo seja criado\n");
            fputs("Nenhum processo criado, aguarde até que outro processo seja criado\n", arquivo);

            // Esperando o tempo
            sleep(delay);
        }

        // Fecha o arquivo para salvar o que foi escrito
        fclose(arquivo);
    }
}
