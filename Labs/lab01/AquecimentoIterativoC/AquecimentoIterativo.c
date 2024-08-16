/* 1. Aquecimento Iterativo:
 * Crie um método iterativo em C que receba como parâmetro uma string e retorne seu número de caracteres maiúsculos.
 * Em seguida, teste o método anterior usando redirecionamento de entrada e saída. A entrada padrão é composta por várias
 * linhas sendo que a última contém a palavra "FIM1". A saída padrão contém um número inteiro para cada linha de entrada.
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
    
    for(int i = 0; i < indice; i++){
        cont += (str[num][i] >= 'A' && str[num][i] <= 'Z') ? 1 : 0;
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
        printf("%d\n", contMaiusculo(strings, i, strlen(strings[i])));
    }
}