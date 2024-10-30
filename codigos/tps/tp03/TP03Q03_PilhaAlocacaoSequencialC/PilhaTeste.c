#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Tamanho máximo da pilha

// Definição da estrutura da pilha
struct Stack {
    int top;
    int items[MAX];
};

// Inicializa a pilha
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Insere um elemento na pilha
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Erro: Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Remove um elemento da pilha
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Stack underflow\n");
        return -1; // Retorna -1 para indicar erro
    }
    return stack->items[stack->top--];
}

// Mostra o elemento no topo da pilha
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return -1; // Retorna -1 para indicar erro
    }
    return stack->items[stack->top];
}

// Testa a pilha
int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    printf("Elemento no topo: %d\n", peek(&stack));

    printf("Removido da pilha: %d\n", pop(&stack));
    printf("Elemento no topo agora: %d\n", peek(&stack));

    // Tentar remover de uma pilha vazia
    pop(&stack);
    pop(&stack);

    return 0;
}
