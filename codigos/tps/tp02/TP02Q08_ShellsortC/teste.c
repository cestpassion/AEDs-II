#include <stdio.h>
#include <stdlib.h>

void shellsort(int *array, int n) {
    int i, j, h;
    int aux;
    
    for(h = 1; h < n; h = 3 * h + 1); // calcula o h inicial.
    
    while(h > 0) {
        h = (h - 1) / 3; // atualiza o valor de h.

        for(i = h; i < n; i++) {
            aux = array[i];
            j = i;

            while(array[j - h] > aux) { // efetua comparações entre elementos com distância h
                array[j] = array[j - h];
                j -= h;

                if(j < h)
                    break;
            }
            array[j] = aux;
        }
    }
}

int main(){

}