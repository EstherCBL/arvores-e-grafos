#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int livros[] = {10, 23, 35, 47, 59, 62, 78, 91};
    int idLivro;
    int iteracoes;
    int esq3, dir3, meio3, pos3;
    printf("Digite o ID do livro: ");
    scanf("%d", &idLivro);
    iteracoes = 0;
    esq3 = 0;
    dir3 = 7;
    pos3 = -1;
    while (esq3 <= dir3) {
        meio3 = (esq3 + dir3) / 2;
        iteracoes++;
        if (livros[meio3] == idLivro) { pos3 = meio3; break; }
        if (livros[meio3] < idLivro) esq3 = meio3 + 1;
        else dir3 = meio3 - 1;
    }
    if (pos3 != -1)
        printf("Livro encontrado na posicao %d\n", pos3);
    else
        printf("Livro nao encontrado\n");
    printf("Iteracoes realizadas: %d\n", iteracoes);
return 0;
}