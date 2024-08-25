#include <stdio.h>
#include <string.h>

int main () {
    char x[100];
    
    while (scanf("%s", &x) == 1) {// ou != EOF
        
        printf ("consegui ler x = %s\n", x);
        getchar();
    }
    return 0;
}
