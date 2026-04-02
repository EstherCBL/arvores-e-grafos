#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    Node* arvore29;
    Node* res29;
    int val29;
    arvore29 = NULL;
    arvore29 = inserir(arvore29, 50);
    arvore29 = inserir(arvore29, 30);
    arvore29 = inserir(arvore29, 70);
    arvore29 = inserir(arvore29, 20);
    arvore29 = inserir(arvore29, 40);
    printf("Digite o valor para buscar na arvore: ");
    scanf("%d", &val29);
    res29 = buscar(arvore29, val29);
    if (res29 != NULL)
        printf("Valor %d encontrado na arvore\n", res29->valor);
    else
        printf("Valor nao encontrado na arvore\n");
return 0;
}