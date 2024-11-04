/**
 * Ordenação Interna - Algoritmo Quicksort com Tipos Nativos em C
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

#include <stdio.h>
#include <stdlib.h>

// Função de comparação para ordenar inteiros em ordem crescente.
// A função `comparar_inteiros` deve retornar:
// - Um valor negativo se o primeiro valor (`a`) for menor que o segundo (`b`),
// - Zero se os valores forem iguais,
// - Um valor positivo se o primeiro valor for maior que o segundo.
int comparar_inteiros(const void *a, const void *b) {
    int primeiro = *(int *)a;   // Converte o ponteiro `a` para `int *` e obtém o valor
    int segundo = *(int *)b;    // Converte o ponteiro `b` para `int *` e obtém o valor
    return primeiro - segundo;  // Retorna a diferença para definir a ordem
}

int main() {
    int array[] = {101, 115, 30, 63, 47, 20};  // Define o array que será ordenado
    int tamanho = sizeof(array) / sizeof(array[0]);  // Calcula o número de elementos no array

    // Chama a função `qsort` para ordenar o array
    // Parâmetros de `qsort`:
    // 1. Ponteiro para o início do array (`array`)
    // 2. Número de elementos do array (`tamanho`)
    // 3. Tamanho em bytes de cada elemento (usando `sizeof(int)`)
    // 4. Ponteiro para a função de comparação (`comparar_inteiros`)
    qsort(array, tamanho, sizeof(int), comparar_inteiros);

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);  // Exibe cada elemento do array ordenado
    }
    printf("\n");

    return 0;
}
