/*Combinador em C:
Implemente um programa denominado Combinador, que recebe duas strings e deve combiná-las, alternando as
letras de cada string, começando com a primeira letrada primeira string, seguido pela primeira letra da
segunda string, em seguida pela segunda letra da primeira string, e assim sucessivamente. As letras restantes
da cadeia mais longa devem ser adicionadas ao fim da string resultante e retornada*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *str1;
    char *str2;
    
    char buffer[1000];
    char *s;

    while (scanf("%[^\n]", buffer) == 1){
        getchar();

        s = strtok(buffer, " ");
        str1 = (char*)malloc((strlen(s) + 1) * sizeof(char));
        strcpy(str1, s);

        s = strtok(NULL, " ");
        str2 = (char*)malloc((strlen(s) + 1) * sizeof(char));
        strcpy(str2, s);

        while(*str1 != '\0' && *str2 != '\0'){
             printf("%c%c", *(str1++), *(str2++));
        }

        if(strlen(str1) > strlen(str2)){
            while(*str1 != '\0')
                printf("%c", *(str1++));
        }else{
            while(*str2 != '\0')
                printf("%c", *(str2++));
        }
        printf("\n");
    }
}