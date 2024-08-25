/* Alteração Aleatória em C:
 * Refaça a questão Alteração Aleatória na linguagem C e de forma recursiva.
 */

// ERRADO! CORRIJA!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Identificador a string "FIM"
int isFIM(char string[]) {
    return strcmp(string, "FIM") == 0 ? 0 : 1;
}

// Alteração das letras de forma "aleatória"
void alteracaoAleatoria(char string[], char letra1, char letra2, int cont) {
    if (cont >= strlen(string)) 
        return;

    if (string[cont] == letra1) 
        string[cont] = letra2;

    alteracaoAleatoria(string, letra1, letra2, cont + 1);
}

// Função principal  
int main(){
    char str[1000];
    srand(4);

    while(scanf("%[^\n]", str) == 1 && isFIM(str) == 1){
        getchar();

        // Desloca o caractere 'a' a partir de um número aleatório entre 0 e 25
        char letra01 = 'a' + (abs(rand()) % 26);
        char letra02 = 'a' + (abs(rand()) % 26);
        
        alteracaoAleatoria(str, letra01, letra02, 0);        
        
        printf("%s\n", str);
    }
}
