#include <stdio.h>

// faz a troca de dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// função para manter a propriedade do Max-Heap
void heapify(int v[], int n, int i) {
    int maior = i;        // assume que o pai é o maior
    int esq = 2*i + 1;   // filho esquerdo
    int dir = 2*i + 2;   // filho direito

    if (esq < n && v[esq] > v[maior])
        maior = esq;

    if (dir < n && v[dir] > v[maior])
        maior = dir;

    if (maior != i) {
        trocar(&v[i], &v[maior]);
        heapify(v, n, maior); // recursão para corrigir subárvore
    }
}

// constrói o Max-Heap
void buildMaxHeap(int v[], int n) {
    // Começa pelo último nó interno e vai até a raiz
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(v, n, i);
}

// extrai o elemento máximo (raiz)
int extrairMax(int v[], int *n) {
    int max = v[0];
    v[0] = v[*n - 1]; // Move o último para a raiz
    (*n)--;            // Reduz o tamanho
    heapify(v, *n, 0); // Restaura a propriedade
    return max;
}

// imprime o vetor
void imprimirVetor(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n-1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int v[] = {30, 12, 45, 6, 18, 3};
    int n = 6;

    printf("Vetor original:      ");
    imprimirVetor(v, n);

    // a) Construir Max-Heap
    buildMaxHeap(v, n);
    printf("Max-Heap construído: ");
    imprimirVetor(v, n);

    // b) Primeira extração da raiz
    int max = extrairMax(v, &n);
    printf("\nElemento extraído: %d\n", max);
    printf("Vetor após extração: ");
    imprimirVetor(v, n);

    return 0;
}