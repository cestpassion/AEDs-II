#include <stdio.h>
#include <stdlib.h>
#include <err.h>

//TIPO CELULA ===================================================================
typedef struct Celula {
    int elemento;        // Elemento inserido na celula.
    struct Celula* prox; // Aponta a celula prox.
} Celula;

Celula* novaCelula(int elemento) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = NULL;
    return nova;
}

//PILHA PROPRIAMENTE DITA =======================================================
Celula* topo; // Sem celula cabeca.

/**
 * Cria uma pilha sem elementos.
 */
void start() {
    topo = NULL;
}

/**
 * Insere elemento na pilha de forma recursiva.
 * @param x int elemento a inserir.
 * @param atual ponteiro para o nó atual.
 */
Celula* inserirRecursivo(int x, Celula* atual) {
    if (atual == NULL) {
        return novaCelula(x);
    } else {
        atual->prox = inserirRecursivo(x, atual->prox);
        return atual;
    }
}

void inserir(int x) {
    topo = inserirRecursivo(x, topo);
}

/**
 * Remove elemento da pilha de forma recursiva.
 * @param atual ponteiro para o nó atual.
 * @return Elemento removido.
 */
int removerRecursivo(Celula** atual) {
    if (*atual == NULL) {
        errx(1, "Erro ao remover!");
    }

    int elemento;
    if ((*atual)->prox == NULL) {
        elemento = (*atual)->elemento;
        free(*atual);
        *atual = NULL;
    } else {
        elemento = removerRecursivo(&(*atual)->prox);
    }
    return elemento;
}

int remover() {
    return removerRecursivo(&topo);
}

/**
 * Mostra os elementos separados por espacos, comecando do topo de forma recursiva.
 * @param atual ponteiro para o nó atual.
 */
void mostrarRecursivo(Celula* atual) {
    if (atual != NULL) {
        printf("%d ", atual->elemento);
        mostrarRecursivo(atual->prox);
    }
}

void mostrar() {
    printf("[");
    mostrarRecursivo(topo);
    printf("] \n");
}

//METODO PRINCIPAL ==============================================================
int main(int argc, char** argv) {
    int x1, x2, x3;

    printf("==== PILHA FLEXIVEL ====\n");

    start();

    inserir(0);
    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);

    printf("Apos insercoes: \n");
    mostrar();

    x1 = remover();
    x2 = remover();
    x3 = remover();

    printf("Apos as remocoes (%d, %d, %d) \n", x1, x2, x3);
    mostrar();

    return 0;
}
