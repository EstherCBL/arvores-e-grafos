#include <stdio.h>   // Biblioteca para entrada e saída (printf)
#include <time.h>    // Biblioteca para medir o tempo (clock)

// -------------------------------------------------------
// BUBBLE SORT
// Recebe o vetor, seu tamanho, e ponteiros para contadores
// -------------------------------------------------------
void bubbleSort(int vetor[], int tamanho, long long *comparacoes, long long *movimentacoes) {
    int temp; // Variável auxiliar para realizar a troca de dois elementos

    // Loop externo: repete (tamanho - 1) vezes, pois a cada passagem
    // o maior elemento "borbulha" para o final
    for (int i = 0; i < tamanho - 1; i++) {

        // Loop interno: percorre os elementos ainda não ordenados
        // A cada passagem do loop externo, o último elemento já está no lugar,
        // por isso subtraímos (i + 1)
        for (int j = 0; j < tamanho - 1 - i; j++) {

            (*comparacoes)++; // Conta a comparação que será feita abaixo

            // Se o elemento atual for maior que o próximo, troca os dois
            if (vetor[j] > vetor[j + 1]) {

                temp = vetor[j];          // Salva o valor de vetor[j] em temp
                vetor[j] = vetor[j + 1];  // Coloca o valor de vetor[j+1] em vetor[j]
                vetor[j + 1] = temp;      // Coloca o valor salvo em vetor[j+1]
                (*movimentacoes)++;       // Conta a troca realizada
            }
        }
    }
}

// -------------------------------------------------------
// SELECTION SORT
// Recebe o vetor, seu tamanho, e ponteiros para contadores
// -------------------------------------------------------
void selectionSort(int vetor[], int tamanho, long long *comparacoes, long long *movimentacoes) {
    int temp;       // Variável auxiliar para realizar a troca
    int indiceMenor; // Guarda o índice do menor elemento encontrado

    // Loop externo: a cada iteração, encontra o menor elemento
    // a partir da posição i e o coloca na posição correta
    for (int i = 0; i < tamanho - 1; i++) {

        indiceMenor = i; // Assume que o menor elemento está na posição atual

        // Loop interno: percorre o restante do vetor buscando
        // um elemento menor do que o atual "menor"
        for (int j = i + 1; j < tamanho; j++) {

            (*comparacoes)++; // Conta a comparação feita abaixo

            // Se encontrou um elemento menor, atualiza o índice do menor
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j; // Registra a posição do novo menor elemento
            }
        }

        // Só realiza a troca se o menor elemento não for o da posição atual
        if (indiceMenor != i) {
            temp = vetor[i];              // Salva o valor da posição i
            vetor[i] = vetor[indiceMenor]; // Coloca o menor na posição i
            vetor[indiceMenor] = temp;    // Coloca o valor salvo na posição do menor
            (*movimentacoes)++;           // Conta a troca realizada
        }
    }
}

// -------------------------------------------------------
// Função para preencher o vetor em ordem DECRESCENTE
// Ex: tamanho=5 -> vetor = [5, 4, 3, 2, 1]
// -------------------------------------------------------
void preencherDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i; // O primeiro elemento é o maior, e vai diminuindo
    }
}

// -------------------------------------------------------
// Função que executa um algoritmo de ordenação e imprime
// os resultados (tempo, comparações e movimentações)
// -------------------------------------------------------
void executarETabelar(const char *nomeAlgoritmo, int tamanho, int usaBubble) {
    int vetor[tamanho]; // Declara o vetor com o tamanho recebido

    long long comparacoes  = 0; // Contador de comparações entre elementos
    long long movimentacoes = 0; // Contador de trocas/movimentações

    clock_t inicio, fim; // Variáveis para marcar o tempo inicial e final
    double tempo_ms;     // Armazena o tempo de execução em milissegundos

    preencherDecrescente(vetor, tamanho); // Preenche o vetor em ordem decrescente
                                          // (pior caso para ambos os algoritmos)

    inicio = clock(); // Marca o momento antes de iniciar a ordenação

    // Chama o algoritmo correto de acordo com o parâmetro recebido
    if (usaBubble) {
        bubbleSort(vetor, tamanho, &comparacoes, &movimentacoes);
    } else {
        selectionSort(vetor, tamanho, &comparacoes, &movimentacoes);
    }

    fim = clock(); // Marca o momento após o término da ordenação

    // Calcula o tempo em milissegundos
    // (fim - inicio) dá o número de "ticks" do processador
    // dividir por CLOCKS_PER_SEC converte para segundos
    // multiplicar por 1000 converte para milissegundos
    tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    // Imprime a linha da tabela com os resultados obtidos
    printf("%-15s | %7d | %10.3f | %13lld | %13lld\n",
           nomeAlgoritmo, tamanho, tempo_ms, comparacoes, movimentacoes);
}

// -------------------------------------------------------
// Função principal: ponto de entrada do programa
// -------------------------------------------------------
int main() {
    // Tamanhos de vetor que serão testados
    int tamanhos[] = {100, 1000, 10000};
    int qtdTamanhos = 3; // Quantidade de tamanhos definidos acima

    // Imprime o cabeçalho da tabela de resultados
    printf("%-15s | %7s | %10s | %13s | %13s\n",
           "Algoritmo", "Tamanho", "Tempo (ms)", "Comparações", "Movimentações");

    // Linha separadora para melhor visualização
    printf("-----------------------------------------------------------------------------\n");

    // Loop que testa o Bubble Sort para cada tamanho de vetor
    for (int i = 0; i < qtdTamanhos; i++) {
        executarETabelar("Bubble Sort", tamanhos[i], 1); // 1 = usar Bubble Sort
    }

    // Linha separadora entre os dois algoritmos
    printf("-----------------------------------------------------------------------------\n");

    // Loop que testa o Selection Sort para cada tamanho de vetor
    for (int i = 0; i < qtdTamanhos; i++) {
        executarETabelar("Selection Sort", tamanhos[i], 0); // 0 = usar Selection Sort
    }

    // Linha final da tabela
    printf("-----------------------------------------------------------------------------\n");

    // Observações sobre os resultados esperados
    printf("\nObservacoes:\n");
    printf("- O tempo de execucao cresce significativamente com o aumento do tamanho.\n");
    printf("- As comparacoes sao similares nos dois algoritmos (ambos O(n^2)).\n");
    printf("- O Bubble Sort tende a ter mais movimentacoes no pior caso.\n");
    printf("- O Selection Sort faz no maximo (n-1) trocas.\n");
    printf("- O tempo pode variar entre execucoes e computadores diferentes.\n");

    return 0; // Indica que o programa terminou sem erros
}
