#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int cpfs[] = {112233344, 223344455, 334455566, 445566677, 556677788, 667788899};
    int cpf;
    int etapas14;
    int esq14, dir14, meio14, pos14;
    printf("Digite o CPF para buscar: ");
    scanf("%d", &cpf);
    etapas14 = 0;
    esq14 = 0;
    dir14 = 5;
    pos14 = -1;
    while (esq14 <= dir14) {
        meio14 = (esq14 + dir14) / 2;
        etapas14++;
        if (cpfs[meio14] == cpf) { pos14 = meio14; break; }
        if (cpfs[meio14] < cpf) esq14 = meio14 + 1;
        else dir14 = meio14 - 1;
    }
    if (pos14 != -1)
        printf("CPF encontrado na posicao %d. Etapas: %d\n", pos14, etapas14);
    else
        printf("CPF nao encontrado. Etapas: %d\n", etapas14);
return 0;
}