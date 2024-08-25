/* Palíndromo em C:
 * Refaça a questão anterior na linguagem C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isFim(char s[]){
    return (strlen(s) == 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M') ? 0 : 1;
}

int palindromo(char s[]){
    int tam = strlen(s);

    for(int i = 0; i < (tam/2); i++){
        if(s[i] != s[(tam - i - 1)]){
            return 1;
        }
    }
    return 0;
}

int main(){
    char str[1000];

    while(scanf("%[^\n]", str) == 1 && isFim(str) == 1){
        getchar();
        if(palindromo(str) == 0)
            printf("SIM\n");
        else
            printf("NAO\n");
    }
}