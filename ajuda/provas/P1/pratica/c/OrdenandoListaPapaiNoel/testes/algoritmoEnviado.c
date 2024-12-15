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
        scanf("%[^\n]", criancas[i]);
        getchar();
    }


    char temp[20];

    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(strcmp(criancas[i], criancas[j]) < 0){
                strcpy(temp, criancas[i]);
                strcpy(criancas[i], criancas[j]);
                strcpy(criancas[j], temp);
            }
        }
    }

    for(int i = 0; i < N; i++){
        printf("%s\n", criancas[i]);
    }

    printf("Se comportaram: %d | Nao se comportaram: %d", bom, mal);
}