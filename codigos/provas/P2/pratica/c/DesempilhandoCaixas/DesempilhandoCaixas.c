#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int elemento;
    struct Celula *prox;
} Celula;

Celula *newCelula(int elemento){
    Celula *new = (Celula*)malloc(sizeof(Celula));
    new->elemento = elemento;
    new->prox = NULL;

    return new;
}

typedef struct Pilha{
    Celula *top;
} Pilha;

typedef struct Fila{
    Celula *primeiro;
    Celula *ultimo;
} Fila;

void start(Pilha *pi, Fila *fi){
    pi->top = newCelula(-1);

    fi->primeiro = newCelula(-1);
    fi->ultimo = fi->primeiro;
}

// IF RF
void inserirPilha(Pilha *pi, int numCaixas){

}

int removerPilha(Pilha *pi){

}

void 
