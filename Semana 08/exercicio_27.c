#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int vet27[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int val27;
    int posIter27;
    int i27;
    Node* arvore27;
    Node* res27;
    printf("Digite o valor para buscar: ");
    scanf("%d", &val27);
    posIter27 = pesquisaBinaria(vet27, 0, 7, val27);
    if (posIter27 != -1)
        printf("Iterativa: encontrado na posicao %d\n", posIter27);
    else
        printf("Iterativa: nao encontrado\n");
    arvore27 = NULL;
    for (i27 = 0; i27 < 8; i27++) arvore27 = inserir(arvore27, vet27[i27]);
    res27 = buscar(arvore27, val27);
    if (res27 != NULL)
        printf("Recursiva (arvore): encontrou o valor %d\n", res27->valor);
    else
        printf("Recursiva (arvore): nao encontrado\n");
return 0;
}