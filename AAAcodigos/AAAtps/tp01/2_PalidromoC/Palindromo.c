/* Palíndromo em C:
 * Refaça a questão anterior na linguagem C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alocando dinâmicamente uma string
char *string(char *str){
    char buffer[1000]; // É declarado primeiro um buffer para definir o tamanho do malloc

    scanf("%[^\n]", buffer);
    getchar();

    str = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(str, buffer);

    return str;
}

// Identificador a string "FIM"
int isFim(char *s){
    return strcmp(s, "FIM") == 0 ? 0 : 1;
}

// Identificador iterativo de palíndromos
int palindromo(char *s){
    int tam = strlen(s);

    for(int i = 0; i < (tam/2); i++){
        if(s[i] != s[(tam - i - 1)]){
            return 1;
        }
    }
    return 0;
}

// Função principal
int main(){
    char *str;

    while(isFim(str = string(str)) == 1){ // Atribui o valor recebido ao ponteiro str e chama o método isFIM  
        if(palindromo(str) == 0)
            printf("SIM\n");
        else
            printf("NAO\n");
        free(str);
    }
}