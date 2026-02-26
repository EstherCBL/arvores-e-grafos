#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 20

/* FUNÇÃO AUXILIAR: Imprime os elementos de um array */
void printArray(int arr[], int n, const char *label) {
    printf("  %s: [ ", label);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");
}

/* FUNÇÃO AUXILIAR: Copia um array para outro */
void copyArray(int src[], int dst[], int n) {
    memcpy(dst, src, n * sizeof(int));
}

/* FUNÇÃO AUXILIAR: Troca dois elementos*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* 1. BUBBLE SORT  —  O(n²) médio/pior  |  O(n) melhor */
void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        /* A cada iteração externa, os últimos `i` elementos já estão no lugar */
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        /* Otimização: se nenhuma troca ocorreu, o array está ordenado */
        if (!swapped) break;
    }
}

/* 2. SELECTION SORT  —  O(n²) sempre */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        /* Encontra o índice do menor elemento na sublista [i+1 .. n-1] */
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        /* Coloca o mínimo encontrado na posição correta */
        if (minIdx != i)
            swap(&arr[i], &arr[minIdx]);
    }
}

/* 3. INSERTION SORT  —  O(n²) médio/pior  |  O(n) melhor */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; /* Elemento a ser inserido */
        int j   = i - 1;
        /* Desloca para a direita os elementos maiores que `key` */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; /* Insere na posição correta */
    }
}

/* 4. QUICK SORT  —  O(n log n) médio  |  O(n²) pior

/* Particiona o array e retorna o índice final do pivô */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; /* Pivô = último elemento */
    int i     = low - 1;  /* Índice do menor elemento */

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    /* Coloca o pivô em sua posição definitiva */
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); /* Índice do pivô após partição */
        quickSort(arr, low, pi - 1);        /* Ordena subarray esquerdo     */
        quickSort(arr, pi + 1, high);       /* Ordena subarray direito      */
    }
}

/* 5. MERGE SORT  —  O(n log n) sempre */

/* Intercala duas metades ordenadas: arr[l..m] e arr[m+1..r] */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    /* Intercala L e R de volta em arr[l..r] */
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;   /* Evita overflow em (l+r)/2 */
        mergeSort(arr, l, m);       /* Ordena metade esquerda    */
        mergeSort(arr, m + 1, r);   /* Ordena metade direita     */
        merge(arr, l, m, r);        /* Intercala as metades      */
    }
}

/* 6. SHELL SORT  —  O(n log² n) a O(n^1.5) dependendo do gap */
void shellSort(int arr[], int n) {
    /* Começa com gap grande, vai reduzindo à metade */
    for (int gap = n / 2; gap > 0; gap /= 2) {
        /* Insertion Sort com espaçamento `gap` */
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j    = i;
            /* Desloca elementos anteriores maiores que temp */
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

/* Copia dados, ordena, mede tempo*/
typedef void (*SortFn)(int[], int);

void runSort(const char *name, SortFn sortFn, int original[], int n) {
    int arr[MAX_SIZE];
    copyArray(original, arr, n);

    printArray(arr, n, "Antes ");

    clock_t start = clock();
    sortFn(arr, n);
    clock_t end   = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    printArray(arr, n, "Depois");
    printf("  Tempo de execucao: %.4f ms\n\n", elapsed);
}

void quickSortWrapper(int arr[], int n) { quickSort(arr, 0, n - 1); }
void mergeSortWrapper(int arr[], int n) { mergeSort(arr, 0, n - 1); }

void printMenu() {
    printf("\n");
    printf("  +======================================+\n");
    printf("  |     ALGORITMOS DE ORDENACAO EM C     |\n");
    printf("  +======================================+\n");
    printf("  |  1. Bubble Sort                      |\n");
    printf("  |  2. Selection Sort                   |\n");
    printf("  |  3. Insertion Sort                   |\n");
    printf("  |  4. Quick Sort                       |\n");
    printf("  |  5. Merge Sort                       |\n");
    printf("  |  6. Shell Sort                       |\n");
    printf("  |  7. Executar TODOS                   |\n");
    printf("  |  0. Sair                             |\n");
    printf("  +======================================+\n");
    printf("  Escolha uma opcao: ");
}


int main(void) {
    int original[MAX_SIZE] = {64, 34, 25, 12, 22, 11, 90,  5, 77, 43,
                               58, 19, 36, 81, 47,  3, 66, 29, 52,  8};
    int n = MAX_SIZE;

    printf("\n  Dataset com %d elementos:\n", n);
    printArray(original, n, "Dados ");

    int opcao;
    do {
        printMenu();
        if (scanf("%d", &opcao) != 1) { opcao = -1; }
        printf("\n");

        switch (opcao) {
            case 1:
                printf("  -- Bubble Sort ---------------------\n");
                runSort("Bubble Sort", bubbleSort, original, n);
                break;
            case 2:
                printf("  -- Selection Sort ------------------\n");
                runSort("Selection Sort", selectionSort, original, n);
                break;
            case 3:
                printf("  -- Insertion Sort ------------------\n");
                runSort("Insertion Sort", insertionSort, original, n);
                break;
            case 4:
                printf("  -- Quick Sort ----------------------\n");
                runSort("Quick Sort", quickSortWrapper, original, n);
                break;
            case 5:
                printf("  -- Merge Sort ----------------------\n");
                runSort("Merge Sort", mergeSortWrapper, original, n);
                break;
            case 6:
                printf("  -- Shell Sort ----------------------\n");
                runSort("Shell Sort", shellSort, original, n);
                break;
            case 7:
                printf("  -- Executando TODOS os algoritmos --\n\n");
                printf("  [1] Bubble Sort\n");
                runSort("Bubble Sort",    bubbleSort,       original, n);
                printf("  [2] Selection Sort\n");
                runSort("Selection Sort", selectionSort,    original, n);
                printf("  [3] Insertion Sort\n");
                runSort("Insertion Sort", insertionSort,    original, n);
                printf("  [4] Quick Sort\n");
                runSort("Quick Sort",     quickSortWrapper, original, n);
                printf("  [5] Merge Sort\n");
                runSort("Merge Sort",     mergeSortWrapper, original, n);
                printf("  [6] Shell Sort\n");
                runSort("Shell Sort",     shellSort,        original, n);
                break;
            case 0:
                printf("  Saindo... ate mais!\n\n");
                break;
            default:
                printf("  Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
