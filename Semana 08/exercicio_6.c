#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
char nomes[5][20] = {"Daniel", "Ana", "Eduarda", "Carlos", "Bruna"};
    char nome[20];
    int pos6;
    int i6;
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    pos6 = -1;
    for (i6 = 0; i6 < 5; i6++) {
        if (strcmp(nomes[i6], nome) == 0) {
            pos6 = i6;
            break;
        }
    }
    if (pos6 != -1)
        printf("Nome encontrado: %s na posicao %d\n", nomes[pos6], pos6);
    else
        printf("Nome nao encontrado\n");
return 0;
}