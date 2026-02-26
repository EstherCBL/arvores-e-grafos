#include <stdio.h>

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivô escolhido como último elemento
    int i = low - 1;        // Índice do menor elemento

    printf("\nPartition de %d a %d com pivo %d\n", low, high, pivot);

    for (int j = low; j < high; j++) {
        printf("Comparando %d e pivo %d\n", arr[j], pivot);

        if (arr[j] < pivot) {
            i++;
            if (i != j) { // Só imprime troca se i e j forem diferentes
                printf("Trocando %d e %d\n", arr[i], arr[j]);
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Coloca o pivô na posicao correta
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    printf("Pivo %d colocado na posicao correta\n", pivot);

    // Exibir array após a partição
    printf("Array apos posicao: ");
    imprimirArray(arr, high + 1);

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {64, 34, 25, 90, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nArray ordenado com Quick Sort: ");
    imprimirArray(arr, n);

    return 0;
}
