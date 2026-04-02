#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int vetor25[] = {77, 12, 89, 34, 56, 23, 90};
    int val25;
    int verificacoes25;
    int pos25;
    int i25;
    printf("Digite o valor para buscar: ");
    scanf("%d", &val25);
    verificacoes25 = 0;
    pos25 = -1;
    for (i25 = 0; i25 < 7; i25++) {
        verificacoes25++;
        if (vetor25[i25] == val25) {
            pos25 = i25;
            break;
        }
    }
    if (pos25 != -1)
        printf("Valor encontrado na posicao %d\n", pos25);
    else
        printf("Valor nao encontrado\n");
    printf("Verificacoes realizadas: %d\n", verificacoes25);
return 0;
}