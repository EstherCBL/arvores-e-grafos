#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int alunos[] = {512, 102, 678, 205, 789, 317, 404};
    int matricula;
    int pos1;
    printf("Digite a matricula: ");
    scanf("%d", &matricula);
    pos1 = pesquisaSequencial(alunos, 7, matricula);
    if (pos1 != -1)
        printf("Aluno encontrado na posicao %d\n", pos1);
    else
        printf("Aluno nao encontrado\n");
return 0;
}