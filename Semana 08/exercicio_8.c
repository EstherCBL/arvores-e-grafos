#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int notas[] = {2, 3, 5, 6, 7, 8, 9, 10};
    int nota;
    int pos8;
    int maiores8;
    int i8;
    printf("Digite a nota para buscar: ");
    scanf("%d", &nota);
    pos8 = pesquisaBinaria(notas, 0, 7, nota);
    if (pos8 != -1) {
        maiores8 = 0;
        for (i8 = 0; i8 < 8; i8++) {
            if (notas[i8] > nota) maiores8++;
        }
        printf("Nota encontrada. Alunos com nota maior: %d\n", maiores8);
    } else {
        printf("Nota nao encontrada\n");
    }
return 0;
}