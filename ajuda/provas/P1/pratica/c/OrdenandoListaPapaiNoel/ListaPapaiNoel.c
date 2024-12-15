#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int N;
    char **criancas;
    int mal = 0;
    int bom = 0;

    scanf("%d", &N);
    
    criancas = (char**)malloc(N * sizeof(char*));
    for(int i = 0; i < N; i++){
        criancas[i] = (char*)malloc(20 * sizeof(char));
    }

    for(int i = 0; i < N; i++){
        scanf("%[^ ]", criancas[i]);

        if(criancas[i][0] == '-'){
            mal++;
        }else{
            bom++;
        }
        scanf("%c", &criancas[i][0]); 

        scanf("%[^\n]", criancas[i]);
        getchar();
    }

    char temp[20];

    for(int i = 0; i < N; i++){
        criancas[i][0] += 32;
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = i; j < N; j++){
            if(strcmp(criancas[i], criancas[j]) > 0){
                strcpy(temp, criancas[i]);
                strcpy(criancas[i], criancas[j]);
                strcpy(criancas[j], temp);
            }
        }
    }

    for(int i = 0; i < N; i++){
        criancas[i][0] -= 32;
        printf("%s\n", criancas[i]);
    }

    printf("Se comportaram: %d | Nao se comportaram: %d", bom, mal);
}