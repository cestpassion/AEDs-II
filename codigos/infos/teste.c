#include <stdio.h>

int main(){
    char str[] = "oscar";
    int soma = 0;
    
    for(int i = 0; str[i] != '\0'; i++){
        soma += (int)str[i];
    }

    printf("%d\n", soma);

    printf("%d", (int)str % 15);
}