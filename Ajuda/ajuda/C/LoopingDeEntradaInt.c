#include <stdio.h>

int main () {
    int x;
    
    while (scanf("%d", &x) == 1) // ou != EOF
        printf ("consegui ler x = %d\n", x);

    return 0;
}
