/* Palíndromo Recursivo em C:
 * Refaça a questão anterior na linguagem C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isFim(char s[]){
    return (strlen(s) == 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M') ? 0 : 1;
}

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

int main(){
    char str[100];

    while(scanf("%[^\n]", str) == 1 && isFim(str) == 1){
        getchar();
        if(palindromo(str, 0, (strlen(str) - 1)) == 0)
            printf("SIM\n");
        else
            printf("NAO\n");
    }
}