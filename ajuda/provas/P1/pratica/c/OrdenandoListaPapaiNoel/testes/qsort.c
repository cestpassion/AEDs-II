#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// https://learn.microsoft.com/pt-br/cpp/c-runtime-library/reference/qsort?view=msvc-170

int compare(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}

int main(){
    int N;
    char **criancas;
    int mal = 0;
    int bom = 0;

    scanf("%d\n", &N);
    
    criancas = (char**)malloc(N * sizeof(char*));
    for(int i = 0; i < N; i++){
        criancas[i] = (char*)malloc(20 * sizeof(char));
    }

    for(int i = 0; i < N; i++){
        scanf("%c%*c\n", &criancas[i][0]); 

        if(criancas[i][0] == '-')
            mal++;
        else
            bom++;

        scanf("%[^\n]", criancas[i]);
    }

    qsort(criancas, N, sizeof(char) * 100, compare);

    for(int i = 0; i < N; i++){
        printf("%s\n", criancas[i]);
    }

    printf("Se comportaram: %d | Nao se comportaram: %d", bom, mal);
}