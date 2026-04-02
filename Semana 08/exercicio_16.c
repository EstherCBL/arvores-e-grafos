#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int votos[] = {3, 1, 4, 2, 5, 3, 2, 1, 4};
    int candidato;
    int total16;
    int i16;
    printf("Digite o numero do candidato: ");
    scanf("%d", &candidato);
    total16 = 0;
    for (i16 = 0; i16 < 9; i16++) {
        if (votos[i16] == candidato) total16++;
    }
    printf("O candidato %d recebeu %d voto(s)\n", candidato, total16);
return 0;
}