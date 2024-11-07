/*
Fila do SUS

- Descrição

Os pacientes que chegam na fila do SUS passam por uma triagem imediatamente e vão para a fila de atendimento. Na triagem 
a enfermeira anota o horário de entrada do paciente e quantos minutos ele tem até que sua condição de saúde se torne 
crítica. Sabe-se que os pacientes são atendidos de 30 em 30 minutos (sempre nas horas cheias ou meias horas) quando na 
fila de atendimento. O inicio da triagem e do atendimento se dá às 7h da manhã, se não há nenhum paciente sendo atendido 
e a fila está vazia, o primeiro paciente é atendido no instante que chega na triagem. O médico atende até o último paciente 
na fila. A preocupação é se algum paciente atingiu uma condição crítica enquanto não tenha sido atendido. Para tanto você 
foi convidado para verificar na fila quantos pacientes atingem a condição crítica.


- Entrada

A entrada contém vários casos de teste. Cada caso de teste começa com uma linha com o número inteiro N, 0 < N < 25;o número 
de pacientes que chegam à triagem. A seguir são N linhas com os valores inteiros H, M e C, com 7 < H < 19, e 0 ≤ M <60, 
a hora e minuto que o paciente chega à triagem. O paciente da linha i sempre chega antes que, e no máximo junto com, o 
paciente da linha i + 1. E 0 ≤C ≤ 720 o número de minutos antes do paciente atingir a condição crítica de saúde.


- Saída

Para cada caso de teste pede-se que se imprima em uma linha única o número de pacientes que atingiram a condição crítica ainda
na fila de atendimento.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Paciente{
    int horarioChegada;
    int minCritico;
} Paciente;
typedef struct Celula{
    Paciente paci;
    struct Celula *prox;
} Celula;

Celula *newCelula(Paciente paci){
    Celula *new = (Celula*)malloc(sizeof(Celula));
    new->paci = paci;
    new->prox = NULL;

    return new;
}

// IF RI
typedef struct Fila{
    Celula *primeiro;
    Celula *ultimo;
} Fila;

void start(Fila *fi){
    Paciente tmp = {-1, -1};
    fi->primeiro = newCelula(tmp);
    fi->ultimo = fi->primeiro;
}

void inserirFila(Fila *fi, Paciente paci){
    if(fi->primeiro != fi->ultimo){
        fi->ultimo->prox = newCelula(paci);
        fi->ultimo = fi->ultimo->prox;
    }else{}
}

Paciente removerFila(Fila *fi){
    Paciente removedPaci = fi->primeiro->paci;
    Celula *tmp = fi->primeiro;

    fi->primeiro = fi->primeiro->prox;
    tmp->prox = NULL;
    free(tmp);

    return removedPaci;
}

int main(){

}




// ATOÇAÂO MAX: a passagem de parametros na linguagem c sempre será por valor
// Nas linguagens C++ e C# temos a passagem de parametros por valor E por referencia. na declaração, de uma função em C++
// indentificamos a passagem por referencia usando o simbulo de &. na passagem d eparametros por referencia, nós não criamos
// uma nova variável. nós reaproveitamos o espaço de memória


