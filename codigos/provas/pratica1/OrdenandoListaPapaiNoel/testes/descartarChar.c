#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

/*
Para descartar um caractere em C, pode-se usar a expressão scanf(“%*c”);. 

Para remover um valor de um array em C, é necessário mover todos os valores seguintes uma posição para trás.
Por exemplo,for(int contador = i; contador < size_str1; contador++) str1[contador] = str1[contador + 1];. 

Para remover o primeiro e último caractere de uma string em C, pode-se usar a função sscanf. Por exemplo,
sscanf(x, "%*c%d%*c", &n);. 
 */