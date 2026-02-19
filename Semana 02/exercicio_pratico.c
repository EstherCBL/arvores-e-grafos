#include <stdio.h>
#include <time.h>

void bubbleSort(int vetor[], int tamanho, long long *comparacoes, long long *movimentacoes){
    int temp;
    for (int i = 0; i < tamanho - 1; i++){
        for (int j = 0; j < tamanho - 1 - i; j++){
            (*comparacoes)++;
            if (vetor[j] > vetor[j + 1]){
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*movimentacoes)++;
            }
        }
    }
}

void selectionSort(int vetor[], int tamanho, long long *comparacoes, long long *movimentacoes){
    int temp;
    int indiceMenor;
    
    for (int i = 0; i < tamanho - 1; i++){
        indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++){
            (*comparacoes)++;
            if (vetor[j] < vetor[indiceMenor]){
                indiceMenor = j;
            }
        }

        if (indiceMenor != i){
            temp = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = temp;
            (*movimentacoes)++;
        }
    }
}

void preencherDecrescente(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        vetor[i] = tamanho - i;
    }
}

void executarETabelar(const char *nomeAlgoritmo, int tamanho, int usaBubble){
    int vetor[tamanho];

    long long comparacoes = 0;
    long long movimentacoes = 0;

    clock_t inicio, fim;
    double tempo_ms;

    preencherDecrescente(vetor, tamanho);

    inicio = clock();

    if (usaBubble){
        bubbleSort(vetor, tamanho, &comparacoes, &movimentacoes);
    }
    else{
        selectionSort(vetor, tamanho, &comparacoes, &movimentacoes);
    }

    fim = clock();

    tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    printf("%-15s | %7d | %10.3f | %13lld | %13lld\n",
           nomeAlgoritmo, tamanho, tempo_ms, comparacoes, movimentacoes);
}

int main(){
    int tamanhos[] = {100, 1000, 10000};
    int qtdTamanhos = 3;

    printf("%-15s | %7s | %10s | %13s | %13s\n",
           "Algoritmo", "Tamanho", "Tempo (ms)", "Comparações", "Movimentações");

    printf("-----------------------------------------------------------------------------\n");

    for (int i = 0; i < qtdTamanhos; i++)
    {
        executarETabelar("Bubble Sort", tamanhos[i], 1);
    }

    printf("-----------------------------------------------------------------------------\n");

    for (int i = 0; i < qtdTamanhos; i++)
    {
        executarETabelar("Selection Sort", tamanhos[i], 0);
    }

    printf("-----------------------------------------------------------------------------\n");

    printf("\nObservacoes:\n");
    printf("- O tempo de execucao cresce significativamente com o aumento do tamanho.\n");
    printf("- As comparacoes sao similares nos dois algoritmos (ambos O(n^2)).\n");
    printf("- O Bubble Sort tende a ter mais movimentacoes no pior caso.\n");
    printf("- O Selection Sort faz no maximo (n-1) trocas.\n");
    printf("- O tempo pode variar entre execucoes e computadores diferentes.\n");

    return 0;
}