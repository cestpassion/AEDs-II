/* Palíndromo Recursivo em C:
 * Refaça a questão anterior na linguagem C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Identificador a string "FIM"
int isFim(char s[]){
    return strcmp(s, "FIM") == 0 ? 0 : 1;
}

// Identificador recursivo de palíndromos
int palindromo(char s[], int left, int right){
    int bool = 0;

    if(left < right){
        if(s[left] == s[right])
            bool = palindromo(s, ++left, --right);
        else   
            bool = 1;
    }
    return bool;
}

// Função principal
int main(){
    char str[1000];

    while(scanf("%[^\n]", str) == 1 && isFim(str) == 1){ // Atribui o valor recebido à variável str e chama o método isFIM   
        getchar();
        if(palindromo(str, 0, (strlen(str) - 1)) == 0)
            printf("SIM\n");
        else
            printf("NAO\n");
    }
}