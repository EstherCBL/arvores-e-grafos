#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int filmes[] = {501, 123, 876, 234, 654, 345, 999};
    int idFilme;
    int verificados18;
    int pos18;
    int i18;
    printf("Digite o ID do filme: ");
    scanf("%d", &idFilme);
    verificados18 = 0;
    pos18 = -1;
    for (i18 = 0; i18 < 7; i18++) {
        verificados18++;
        if (filmes[i18] == idFilme) {
            pos18 = i18;
            break;
        }
    }
    if (pos18 != -1)
        printf("Filme encontrado na posicao %d\n", pos18);
    else
        printf("Filme nao encontrado. Elementos verificados: %d\n", verificados18);
return 0;
}