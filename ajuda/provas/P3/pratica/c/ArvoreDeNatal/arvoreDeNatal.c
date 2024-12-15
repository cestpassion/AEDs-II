/*
C [PROVA 03] A Árvore de Natal

Descrição:

Todo ano, Roberto gosta de escolher a sua árvore de natal, ele não deixa ninguém escolher
para ele, pois ele acha que a árvore para ser bonita, deve satisfazer algumas condições,
como altura, espessura e quantidade de galhos, para ele conseguir pendurar muitos enfeites
nela.

Roberto quer que sua árvore tenha pelo menos 200 centímetros de altura, mas não quer que
ela seja maior do que 300 centímetros, ou a árvore não irá caber em sua casa. Quanto a
espessura, ele deseja que a sua árvore tenha um tronco com 50 centímetros de diâmetro ou
mais. O número de galhos da árvore tem que ser igual ou maior a 150.


Entrada

A primeira linha de entrada contém um inteiro N (0 < N ≤ 10000), o número de casos teste.
As N linhas seguintes contém 3 inteiros cada, h, de g (0 < a, d, g ≤ 5000), a altura da
árvore em centímetros, o seu diâmetro em centímetros, e a quantidade de galhos da árvore.

Saída

Sua tarefa é, para cada árvore, imprimir Sim, se ela é uma árvore que Roberto pode escolher,
ou Não, se é uma árvore que ele não deve escolher.
*/

/**
 * @file arvoreDeNatal.c
 * @brief C [PROVA 03] A Árvore de Natal
 *
 * @author Bruna Furtado da Fonseca
 * @version Ubuntu 13.2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N; // número de casos teste
    int altura, diametro, qntGalhos;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &altura, &diametro, &qntGalhos);

        if(altura >= 200 && altura <= 300 && diametro >= 50 && qntGalhos >= 150){
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }

   
    

}