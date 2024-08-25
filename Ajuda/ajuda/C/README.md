# Códigos em C Auxiliares:

<br>

## Sumário

- [Leitura e Impressão de Números Inteiros de uma Linha em Looping](#leitura-e-impress%C3%A3o-de-n%C3%BAmeros-inteiros-de-uma-linha-em-looping)
- [Leitura e Impressão de Strings de uma Linha em Looping](#mesmo-c%C3%B3digo-mas-lendo-strings)
- [Divisão de Strings em Substrings (Tokens)](#divis%C3%A3o-de-strings-em-substrings-tokens)


<br>

## Leitura e Impressão de Números Inteiros de uma Linha em Looping

```c
#include <stdio.h>

int main () {
    int x;

    while (scanf("%d", &x) == 1) // ou != EOF
        printf ("%d\n", x);

    return 0;
}
```

#### Explicando:
* O loop while continua enquanto a função scanf consegue ler um número inteiro da entrada padrão.
* Quando scanf lê um número corretamente, ela retorna 1 (indicando que um número inteiro foi lido). Se não conseguir ler um número (por exemplo, se o usuário inserir um caractere ou se a entrada terminar), a função retorna um valor diferente de 1 (normalmente EOF, que indica o final do arquivo ou uma falha na leitura).
* O loop para quando scanf não consegue mais ler um número (por exemplo, quando o usuário entra com um caractere ou quando a entrada termina).

### Exemplo de entrada:
    1
    77 84
    29390 18234 3242 1
    A

### Exemplo de saída:
    1
    77
    84
    29390
    18234
    3242
    1

<br>

## Mesmo código, mas lendo strings:

```c
#include <stdio.h>

int main () {
    char x[100];
    
    while (scanf("%s", &x) == 1) // ou != EOF
        printf ("%s\n", x);
    
    return 0;
}
```

#### Explicando:
* O loop para quando scanf não consegue mais ler uma string (por exemplo, quando o usuário entra com um ctrl + Z ).

### Exemplo de entrada:
    Bom dia
    Ola, tudo bem com voce?
    123 2
    ^Z

### Exemplo de saída:
    Bom
    dia
    Ola,
    tudo
    bem
    com
    voce?
    123
    2

<br>


## Divisão de Strings em Substrings (Tokens):

```c
#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "- Essa, e uma string completa.";
    char *pch; // pointer to character

    printf("Separando a string \"%s\" em tokens:\n\n", str);

    pch = strtok(str, " ,.-");

    while(pch != NULL){
        printf("%s\n", pch); // Imprime o token atual
        pch = strtok(NULL, " ,.-");
    }
    return 0;
}
```

#### Explicando:
```c
pch = strtok(str, " ,.-");
```
* Chama a função strtok para iniciar a separação da string. O primeiro parâmetro é a string a ser dividida (str), e o segundo parâmetro é uma string de delimitadores (" ,.-").
* A função strtok encontra o primeiro token na string str, usando os delimitadores fornecidos. O resultado é atribuído a pch.
```c
while(pch != NULL){
```
* Inicia um loop que continuará enquanto pch não for NULL. pch será NULL quando não houver mais tokens a serem encontrados.
```c
pch = strtok(NULL, " ,.-");
```
* Chama strtok novamente para encontrar o próximo token na string. Passar NULL como o primeiro argumento faz com que strtok continue a partir da posição onde parou na string original.

### Saída:
    Separando a string "- Essa, e uma string completa." em tokens:
    
    Essa
    e
    uma
    string
    completa

<br>
