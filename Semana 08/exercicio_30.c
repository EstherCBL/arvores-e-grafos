#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    Node* arvore30;
    Node* res30;
    int val30;
    arvore30 = NULL;
    arvore30 = inserir(arvore30, 10);
    arvore30 = inserir(arvore30, 5);
    arvore30 = inserir(arvore30, 15);
    printf("Digite um valor para buscar e depois remover da arvore: ");
    scanf("%d", &val30);
    res30 = buscar(arvore30, val30);
    if (res30 != NULL) {
        printf("Valor %d encontrado na arvore\n", res30->valor);
        arvore30 = remover(arvore30, val30);
        res30 = buscar(arvore30, val30);
        if (res30 == NULL)
            printf("Apos remover, valor nao esta mais na arvore\n");
    } else {
        printf("Valor nao encontrado na arvore\n");
    }

    return 0;
}