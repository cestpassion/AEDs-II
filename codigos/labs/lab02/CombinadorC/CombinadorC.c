/*Combinador em C:
Implemente um programa denominado Combinador, que recebe duas strings e deve combiná-las, alternando as
letras de cada string, começando com a primeira letrada primeira string, seguido pela primeira letra da
segunda string, em seguida pela segunda letra da primeira string, e assim sucessivamente. As letras restantes
da cadeia mais longa devem seradicionadas ao fim da string resultante e retornada*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str(char **str){
    char buffer[1000];

    scanf("%[^\n ]", buffer);
    getchar();

    *str = (char*)malloc((strlen(buffer) + 1) * sizeof(char));

    strcpy(*str, buffer);
}

void concatenar(char *s1, char *s2, char *sConcat){
    
    while(*s1 != '\0' && *s2 != '\0'){
        *(sConcat++) = *(s1++);
        *(sConcat++) = *(s2++);
    }

    if(strlen(s1) > strlen(s2)){
        while(*s1 != '\0')
            *(sConcat++) = *(s1++);
    }else{
        while(*s2 != '\0')
            *(sConcat++) = *(s2++);
    }
    *sConcat = '\0';
}

int main(){
    char *str1;
    char *str2;
    
    str(&str1);
    str(&str2);
        
    char *strConcat = (char*)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));

    concatenar(str1, str2, strConcat);
    printf("%s\n", strConcat);
    
    free(str1);
    free(str2);
    free(strConcat);
}