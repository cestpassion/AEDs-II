// Divitir uma string em sub strings

#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "- Essa, e uma string completa.";
    char *pch; // pointer to character

    printf("Separando a string \"%s\" em tokens:\n\n", str);

    pch = strtok(str, " ,.-");

    while(pch != NULL){
        printf("%s\n", pch);
        pch = strtok(NULL, " ,.-");
    }
    return 0;
}