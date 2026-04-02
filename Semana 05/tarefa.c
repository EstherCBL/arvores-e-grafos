#include <stdio.h>
#include <time.h>

int comparacoes = 0, trocas = 0;

void exibirArray(int arr[], int n)
{
    printf("\nEstrutura atual: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// -------------------------------------------------------------

void bubbleSort(int arr[], int n)
{
    int temp, trocou;
    for (int i = 0; i < n - 1; i++)
    {
        trocou = 0;
        for (int j = 0; j < n - 1; j++)
        {
            comparacoes++;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocas++;
                trocou = 1;
            }
        }
        if (trocou == 0)
        {
            break;
        }
    }
}

// -------------------------------------------------------------

void selectionSort(int arr[], int n)
{
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            comparacoes++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            trocas++;
        }
    }
}

// -------------------------------------------------------------

void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            comparacoes++;
            trocas++;
            arr[j + 1] = arr[j];
            j--;
        }
        comparacoes++;
        arr[j + 1] = key;
    }
}

// -------------------------------------------------------------

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    trocas++;

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        comparacoes++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// -------------------------------------------------------------

void swap(int arr[], int i, int j)
{
    trocas++;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        comparacoes++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// -------------------------------------------------------------

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                comparacoes++;
                trocas++;
                arr[j] = arr[j - gap];
                j -= gap;
            }
            comparacoes++;
            arr[j] = temp;
        }
    }
}

// -------------------------------------------------------------

void organizarSubarvore(int vet[], int tamanho, int indiceRaiz)
{
    int maior = indiceRaiz;
    int esquerda = 2 * indiceRaiz + 1;
    int direita = 2 * indiceRaiz + 2;

    comparacoes++;
    if (esquerda < tamanho && vet[esquerda] > vet[maior])
        maior = esquerda;

    comparacoes++;
    if (direita < tamanho && vet[direita] > vet[maior])
        maior = direita;

    if (maior != indiceRaiz)
    {
        trocas++;
        int aux = vet[indiceRaiz];
        vet[indiceRaiz] = vet[maior];
        vet[maior] = aux;

        organizarSubarvore(vet, tamanho, maior);
    }
}

void heapSort(int vet[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        organizarSubarvore(vet, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        trocas++;
        int aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;

        organizarSubarvore(vet, i, 0);
    }
}

// -------------------------------------------------------------

int main()
{
    clock_t inicio, fim;
    double tempo_s;
    int arr[2000];
    int totalElementos = 0;
    int controle = -1;
    int totalValores = 0;

    printf("O array já contém números múltiplos de 10 de 0 até 10000 para adicionar complexidade à execução dos algoritmos.\n\n");

    for (int i = 0; i <= 10000; i += 10)
    {
        arr[totalElementos++] = i;
    }

    while (controle != 0)
    {
        comparacoes = 0;
        trocas = 0;
        tempo_s = 0;

        printf("Quantos valores deseja inserir? -> ");
        scanf("%d", &totalValores);

        printf("\n0 - Finalizar programa\n1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n4 - Quick Sort\n5 - Merge Sort\n6 - Shell Sort\n7 - Heap Sort\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &controle);

        switch (controle)
        {

        case 0:
            printf("Programa Finalizado.\n");
            break;

        case 1:
            for (int i = 0; i < totalValores; i++)
            {
                printf("\nDigite o valor: ");
                scanf("%d", &arr[totalElementos]);
                totalElementos++;
                printf("\n=== Executando Bubble Sort ===");
                inicio = clock();
                bubbleSort(arr, totalElementos);
                fim = clock();
                tempo_s += (double)(fim - inicio) / CLOCKS_PER_SEC;
                exibirArray(arr, totalElementos);
            }
            printf("\nResultado Bubble Sort:\n");
            printf("Nº de trocas: %d\nNº de comparações: %d\nTempo de execução (s): %.9f", trocas, comparacoes, tempo_s);
            break;

        case 2:
            for (int i = 0; i < totalValores; i++)
            {
                printf("\nDigite o valor: ");
                scanf("%d", &arr[totalElementos]);
                totalElementos++;
                printf("\n=== Executando Selection Sort ===");
                inicio = clock();
                selectionSort(arr, totalElementos);
                fim = clock();
                tempo_s += (double)(fim - inicio) / CLOCKS_PER_SEC;
                exibirArray(arr, totalElementos);
            }
            printf("\nResultado Selection Sort:\n");
            printf("Nº de trocas: %d\nNº de comparações: %d\nTempo de execução (s): %.9f", trocas, comparacoes, tempo_s);
            break;

        case 3:
            for (int i = 0; i < totalValores; i++)
            {
                printf("\nDigite o valor: ");
                scanf("%d", &arr[totalElementos]);
                totalElementos++;
                printf("\n=== Executando Insertion Sort ===");
                inicio = clock();
                insertionSort(arr, totalElementos);
                fim = clock();
                tempo_s += (double)(fim - inicio) / CLOCKS_PER_SEC;
                exibirArray(arr, totalElementos);
            }
            printf("\nResultado Insertion Sort:\n");
            printf("Nº de trocas: %d\nNº de comparações: %d\nTempo de execução (s): %.9f", trocas, comparacoes, tempo_s);
            break;

        case 4:
            for (int i = 0; i < totalValores; i++)
            {
                printf("\nDigite o valor: ");
                scanf("%d", &arr[totalElementos]);
                totalElementos++;
                printf("\n=== Executando Quick Sort ===");
                inicio = clock();
                quickSort(arr, 0, totalElementos - 1);
                fim = clock();
                tempo_s += (double)(fim - inicio) / CLOCKS_PER_SEC;
                exibirArray(arr, totalElementos);
            }
            printf("\nResultado Quick Sort:\n");
            printf("Nº de trocas: %d\nNº de comparações: %d\nTempo de execução (s): %.9f", trocas, comparacoes, tempo_s);
            break;

        case 5:
            for (int i = 0; i < totalValores; i++)
            {
                printf("\nDigite o valor: ");
                scanf("%d", &arr[totalElementos]);
                totalElementos++;
                printf("\n=== Executando Merge Sort ===");
                inicio = clock();
                mergeSort(arr, 0, totalElementos - 1);
                fim = clock();
                tempo_s += (double)(fim - inicio) / CLOCKS_PER_SEC;
                exibirArray(arr, totalElementos);
            }
            printf("\nResultado Merge Sort:\n");
            printf("Nº de trocas: N/A\nNº de comparações: %d\nTempo de execução (s): %.9f", comparacoes, tempo_s);
            break;

        case 6:
            for (int i = 0; i < totalValores; i++)
            {
                printf("\nDigite o valor: ");
                scanf("%d", &arr[totalElementos]);
                totalElementos++;
                printf("\n=== Executando Shell Sort ===");
                inicio = clock();
                shellSort(arr, totalElementos);
                fim = clock();
                tempo_s += (double)(fim - inicio) / CLOCKS_PER_SEC;
                exibirArray(arr, totalElementos);
            }
            printf("\nResultado Shell Sort:\n");
            printf("Nº de trocas: %d\nNº de comparações: %d\nTempo de execução (s): %.9f", trocas, comparacoes, tempo_s);
            break;

        case 7:
            for (int i = 0; i < totalValores; i++)
            {
                printf("\nDigite o valor: ");
                scanf("%d", &arr[totalElementos]);
                totalElementos++;
                printf("\n=== Executando Heap Sort ===");
                inicio = clock();
                heapSort(arr, totalElementos);
                fim = clock();
                tempo_s += (double)(fim - inicio) / CLOCKS_PER_SEC;
                exibirArray(arr, totalElementos);
            }
            printf("\nResultado Heap Sort:\n");
            printf("Nº de trocas: %d\nNº de comparações: %d\nTempo de execução (s): %.9f", trocas, comparacoes, tempo_s);
            break;

        default:
            printf("Opção inválida.\n");
        }
        if (controle != 0)
        {
            exibirArray(arr, totalElementos);
            printf("\n");
        }
    }
}