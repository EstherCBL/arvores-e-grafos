#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/*InsertionSort:
-Crie uma função insertionSort que receba um vetor e o tamanho do vetor.
-Utilize o algoritmo para inserir cada elemento na posição correta em um subarray já ordenado.*/

void insertionSort(int arr[], int n){
    int i, j, chave;

    for(i=1; i<n; i++){
        chave = arr[i];
        j = i - 1; // Índice do elemento anterior
    }

    while(j>=0 &&arr[j] > chave){
        arr[ j + 1 ] = arr[j]; // Move o elemento para a direita
        j--;
    }
    arr[j + 1] = chave; // Insere a chave na posição correta

}

/*QuickSort:
- Crie a função quickSort, que deve incluir uma função auxiliar partition e a função swap.
- A função swap deve trocar os valores de duas variáveis inteiras utilizando, por exemplo, uma variável temporária.*/

void imprimirArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
        printf("\n");
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high]; //ultimo elemento como pivô
    int i = low - 1; // Índice do menor elemento

    for(int j = low; j<high; i++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i]; // Troca arr[i] e arr[j]
            arr[i] = arr[j]; 
            arr[j] = temp; // Troca arr[i+1] e arr[high] (ou pivô)
        }
    }
}

int temp = arr{i+1};
arr[i+1] = arr[high];