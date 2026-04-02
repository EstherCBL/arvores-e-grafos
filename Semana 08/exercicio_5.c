#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int numeros[] = {45, 12, 78, 3, 56, 89, 23, 67};
    int val5;
    int temp5;
    int pos5;
    int i5, j5;
    printf("Vetor antes da ordenacao: ");
    for (i5 = 0; i5 < 8; i5++) printf("%d ", numeros[i5]);
    printf("\n");
    for (i5 = 0; i5 < 7; i5++) {
        for (j5 = 0; j5 < 7 - i5; j5++) {
            if (numeros[j5] > numeros[j5 + 1]) {
                temp5 = numeros[j5];
                numeros[j5] = numeros[j5 + 1];
                numeros[j5 + 1] = temp5;
            }
        }
    }
    printf("Vetor depois da ordenacao: ");
    for (i5 = 0; i5 < 8; i5++) printf("%d ", numeros[i5]);
    printf("\n");
    printf("Digite o valor para buscar: ");
    scanf("%d", &val5);
    pos5 = pesquisaBinaria(numeros, 0, 7, val5);
    if (pos5 != -1)
        printf("Valor encontrado na posicao %d\n", pos5);
    else
        printf("Valor nao encontrado\n");
return 0;
}