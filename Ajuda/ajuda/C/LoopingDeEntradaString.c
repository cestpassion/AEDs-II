#include <stdio.h>

int main () {
    char x[100];
    
    while (scanf("%s", &x) == 1) // ou != EOF
        printf ("%s\n", x);
    
    return 0;
}
