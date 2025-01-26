/*
 * INFO:
 * 
 * - As pilhas são um Tipo Abstrato de Dados (TAD) no qual o primeiro elemento que entra é o último a sair
 *     > First In, Last Out (FILO)
 * 
 * - Tem basicamente os métodos de inserir (empilhar, pop) e remover (desempilhar, push)
 * 
 * - Primeira solução IF e RF
 *     > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
 *                     7                               X   X
 *                 5   5                               5   X
 *             3   3   3                               3   3
 *         1   1   1   1                               1   1
 * 
 * - Segunda solução II e RI (inserção e remoção não eficientes)
 *     > Em cada inserção ou remoção, movemos todos os elementos
 *     > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
 *                     1                       • Primeira remoção: Retorna o 7 e move todos os demais
 *                 1   3                       • Segunda remoção: Retorna o 5 e move todos os demais
 *             1   3   5                               X   X
 *         1   3   5   7                               1   X
 *                                                     3   1
 *                                                     5   3
 */

/**
 * Pilha com Alocação Linear em C
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int *stack;
    int MAXTAM;
    int top;
} Stack;

Stack newStack(int tam){
    Stack newStack;

    newStack.MAXTAM = tam;
    newStack.stack = (int*)malloc(newStack.MAXTAM * sizeof(int));
    newStack.top = -1;

    return newStack;
}

// Potótipos das funções - Pilha
void push(Stack *, int);
int pop(Stack *);
void mostrar(Stack);
// int pesquisar(Stack);
// void ordenar(Stack);
// void invertStack(Stack *);
// void reverseStack(Stack *, int);

int main(){
    int n;

    printf("Digite o tamanho da pilha: ");
    scanf("%d%*c", &n);

    Stack pilha = newStack(n);
    char sc[50];

    printf("\nInsira os elementos na pilha ou digite \"FIM\" para sair.\n");
    scanf("%s", sc);

    while(strcmp(sc, "FIM") != 0){
        push(&pilha, atoi(sc));
        scanf("%s", sc);
    }

    printf("\nPilha:\n");
    mostrar(pilha);

    printf("\nInsira o numero de elementos que deseja remover da pilha.\n");
    scanf("%d%*c", &n);

    for(int i = 0; i < n; i++)
        printf("Elemento \"%d\" removido.\n", pop(&pilha));

    printf("\nPilha:\n");
    mostrar(pilha);

    free(pilha.stack);

    return 0;
}

void push(Stack *pilha, int elemento)
{
    if (pilha->top >= (pilha->MAXTAM - 1))
    {
        pilha->MAXTAM++;
        pilha->stack = (int *)realloc(pilha->stack, pilha->MAXTAM * sizeof(int));

        if (!pilha->stack)
        {
            printf("Erro de memoria na realocacao\n");
            pilha->MAXTAM--;
            return;
        }
    }
    pilha->stack[++pilha->top] = elemento;
}

int pop(Stack *pilha)
{
    if (pilha->top == -1)
    {
        printf("Erro! Nao ha elementos para remover.\n");
        return -1;
    }

    return pilha->stack[pilha->top--];
}

void mostrar(Stack pilha)
{
    if(pilha.top == -1){
        printf("Erro! Não ha elementos para mostrar.\n");
        return;
    }

    for (int i = pilha.top; i >= 0; --i)
        printf("[%d]\t%d\n", i, pilha.stack[i]);
}