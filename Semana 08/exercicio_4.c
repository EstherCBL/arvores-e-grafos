#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int usuarios[] = {101, 203, 305, 407, 509, 611, 713};
    int idUser;
    int pos4;
    printf("Digite o ID do usuario: ");
    scanf("%d", &idUser);
    pos4 = pesquisaBinaria(usuarios, 0, 6, idUser);
    if (pos4 != -1)
        printf("Acesso permitido\n");
    else
        printf("Usuario nao encontrado\n");
return 0;
}