#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, chave;
    
    printf("\nProcesso do Insertion Sort:\n");

    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        printf("\nPasso %d: Inserindo %d na parte ordenada\n", i, chave);

        // Mover elementos maiores que a chave para frente
        while (j >= 0 && arr[j] > chave) {
            printf("Comparando %d e %d -> %d E maior, movendo para frente\n", arr[j], chave, arr[j]);
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = chave;
        printf("Colocado %d na posicao correta\n", chave);

        // Exibir array após cada inserção
        printf("Array apos o passo %d: ", i);
        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 70, 03};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, n);

    insertionSort(arr, n);

    printf("\nArray ordenado com Insertion Sort: ");
    imprimirArray(arr, n);

    return 0;
}
