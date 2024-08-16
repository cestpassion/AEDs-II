/* 2. Aquecimento Recursivo:
 * Refa¸ca a questão anterior de forma recursiva. Atente-se para os detalhes dos retornos de cada um dos métodos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numStrings = 0;

void str(char **str){
    char buffer[1000];

    scanf("%[^\n]", buffer);

    str[numStrings] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));

    strcpy(str[numStrings], buffer);
}

int isFIM(char** str){
    if(strlen(str[numStrings]) == 3 && str[numStrings][0] == 'F' && str[numStrings][1] == 'I' && str[numStrings][2] == 'M'){
        numStrings++;
        return 0;
    }
    else{
        numStrings++;
        return 1;
    }
}

int contMaiusculo(char** str, int num, int indice){
    int cont = 0;

    if(indice < strlen(str[num])){
            if(str[num][indice] >= 'A' && str[num][indice] <= 'Z'){
                cont = 1 + contMaiusculo(str, num, ++indice);
            }
            else{
                cont = contMaiusculo(str, num, ++indice);
            }
    }
    return cont;
}
        

int main(){
    char **strings;

    strings = (char**)malloc(1000 * sizeof(char*));

    do{
        str(strings);
        getchar();
    } while (isFIM(strings) == 1);
    numStrings--;

    for(int i = 0; i < numStrings; i++){
        printf("%d\n", contMaiusculo(strings, i, 0));
    }
}