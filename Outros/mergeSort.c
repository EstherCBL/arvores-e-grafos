#include <stdio.h>

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Funcao para mesclar dois subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // Copiando os elementos para os subarrays L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Mesclar os dois subarrays ordenados de volta em arr[]
    while (i < n1 && j < n2) {
        printf("Comparando %d e %d\n", L[i], R[j]);
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Imprime o array atualizado APOS toda a mesclagem estar completa
    printf("Arr apos a fusao: ");
    imprimirArray(arr, r + 1);
}

// Funcao recursiva MergeSort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {64, 34, 25, 90, 12, 22, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nArray ordenado com Merge Sort: ");
    imprimirArray(arr, n);

    return 0;
}
