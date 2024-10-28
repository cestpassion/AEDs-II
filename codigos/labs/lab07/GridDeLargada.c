/*
Na Nlogônia, vai ser realizada a sensacional final mundial da fórmula 17. Os competidores se
alinham na largada e disputam a corrida. Você vai ter acesso aos grids de largada e de chegada. A
questão é determinar o número mínimo de ultrapassagens que foram efetuadas durante a competição.

Entrada:
    - Cada caso de teste utiliza três linhas.
    - A primeira linha de um caso de teste contém um inteiro N indicando o número de competidores.
    - Cada competidor é identificado com um número de 1 a N.
    - A segunda linha de cada caso tem os N competidores, em ordem do grid de largada.
    - A terceira linha de cada caso tem os mesmos competidores, porém agora na ordem de chegada.

Saída:
    Para cada caso de teste imprima uma linha contendo um único número inteiro, que indica o número
    mínimo de ultrapassagens necessárias para se chegar do grid de largada ao grid de chegada.

Código-fonte:
    Em seu código, apresente como forma de comentários a análise de complexidade detalhando as
    operações relevantes que são executadas para a computação do resultado.
*/

/*
OBJETIVO: Número mínimo de ultrapassagens que foram feitas durante a competição

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;

    while(scanf("%d", &N) == 1){
        int *compLargada = (int*)malloc(N * sizeof(int));
        int *compChegada = (int*)malloc(N * sizeof(int));

        for(int i = 0; i < N; i++)
            scanf("%d", &compLargada[i]);

        for(int i = 0; i < N; i++)
            scanf("%d", &compChegada[i]);

        int j = N, ultrapassagens = 0;

        for(int i = N - 1; i >= 0; i--){
            if(compLargada[i] != compChegada[i]){
                j = N;

                while(compLargada[i] != compChegada[j]){
                    j--;
                    ultrapassagens++;
                }
            }
            printf("%d\n", ultrapassagens);
        }

        /* int j = N, ultrapassagens = 0;
        for(int i = N; i >= 0; i--){
            if(compLargada[j] == compChegada[i])
                j--;
            else
                ultrapassagens++;
        } */
        printf("%d\n", ultrapassagens);
    }
}