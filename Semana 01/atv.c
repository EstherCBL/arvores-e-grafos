#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int dados[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p)
{
    p->topo = -1;
}

int estaVazia(Pilha *p)
{
    return p->topo == -1;
}

int estaCheia(Pilha *p)
{
    return p->topo == MAX - 1;
}

int empilhar(Pilha *p, int valor)
{
    if (estaCheia(p))
        return 0;
    p->dados[++(p->topo)] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valor)
{
    if (estaVazia(p))
        return 0;
    *valor = p->dados[(p->topo)--];
    return 1;
}

void limpar(Pilha *p)
{
    p->topo = -1;
}

void mostrar(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Conteúdo da pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; --i)
    {
        printf("%d\n", p->dados[i]);
    }
}

int menu()
{
    int op;
    printf("\n=== Menu Pilha ===\n");
    printf("1. Empilhar\n");
    printf("2. Desempilhar\n");
    printf("3. Limpar pilha\n");
    printf("4. Mostrar pilha\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    if (scanf("%d", &op) != 1)
    {
        // limpar buffer e retornar opção inválida
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        return -1;
    }
    return op;
}

int main(void)
{
    Pilha p;
    inicializa(&p);
    int opcao = 0;
    int valor;

    while (1)
    {
        opcao = menu();
        switch (opcao)
        {
        
        case 1:
            printf("Valor a empilhar: ");
            if (scanf("%d", &valor) != 1)
            {
                int c;  
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                printf("Entrada inválida. Tente novamente.\n");
                break;
            }
            if (empilhar(&p, valor))
                printf("%d empilhado.\n", valor);
            else
                printf("Erro: pilha cheia.\n");
            break;
        case 2:
            if (desempilhar(&p, &valor))
                printf("Desempilhado: %d\n", valor);
            else
                printf("Erro: pilha vazia.\n");
            break;
        case 3:
            limpar(&p);
            printf("Pilha limpa.\n");
            break;
        case 4:
            mostrar(&p);
            break;
        case 5:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opção inválida. Digite um número entre 1 e 5.\n");
        }
    }

    return 0;
}
