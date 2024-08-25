// Divitir uma string em sub strings

#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "- This, a ample strings";
    char *pch;

    printf("Splitting string \"%s\" into tokens:\n", str);

    pch = strtok(str, " ,.-");

    while(pch != NULL){
        printf("%s\n", pch);
        pch = strtok(NULL, " ,.-");
    }
    return 0;
}