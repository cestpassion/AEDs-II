# 📚 Pilha
<br>

## 📄 Sumário

>1. [**Conceitos Básicos**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-conceitos-b%C3%A1sicos)
>2. [**Header**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-header)
>3. [**Soluções**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-solu%C3%A7%C3%B5es)
>4. [**Método de Inserção (push)**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-m%C3%A9todo-de-inser%C3%A7%C3%A3o-push)
>5. [**Método de Remoção (pop)**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-m%C3%A9todo-de-remo%C3%A7%C3%A3o-pop)
>6. [**Método Mostrar**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#%EF%B8%8F-m%C3%A9todo-mostrar)
>7. [**Método Pesquisar**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-m%C3%A9todo-pesquisar)
>8. [**Método Ordenar**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-m%C3%A9todo-ordenar)
---
<br>

## 📘 Conceitos Básicos

As pilhas são um Tipo Abstrato de Dados (TAD) no qual o primeiro elemento que entra é o último a sair

> First In, Last Out (FILO)

### Variáveis:

- stack (de elementos)
```plaintext
           ___                   ___
          |   |                 |   |
          |---|                 |---|
          |   |                 | 7 |
          |---|                 |---|
          |   |                 | 5 |
          |---|                 |---|
          |   |                 | 3 |
          |---|                 |---|
    stack |   |           stack | 1 |
          '---'                 '---'
```
- top (contador)
```plaintext
         ___                    ___
    top |-1 |              top | 3 |
        '---'                  '---'
```

### Métodos:

- **Construtores** 

- **Inserção de elemento**
  - void push(elemento)
    
- **Remoção de elementos**
  - elemento pop()
    
- **Mostrar, pesquisar, ordenar, ...**

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-pilha)
---
<br>

## 🧩 Soluções

### Primeira Solução IF e RF

Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:

                                            • Na primeira remoção, retiramos o número 7        
                   |7|                      • Na segunda remoção, retiramos o número 5   
               |5|  5                            P: X    S: X
           |3|  3   3                               5       X
       |1|  1   1   1                               3       3
                                                    1       1

### Segunda Solução II e RI (inserção e remoção não eficientes)

> Em cada inserção ou remoção, movemos todos os elementos

Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:

                                            • Primeira remoção: Retorna o 7 e move todos os demais
                    1                       • Segunda remoção: Retorna o 5 e move todos os demais
                1   3                           P:  X   S:  X
            1   3   5                               1       X
       |1| |3| |5| |7|                              3       1
                                                    5       3 

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-pilha)
---
<br>

## 📌 Header

>### C:

```c
typedef struct Stack
{
    Pokemon *stack;
    int MAXTAM;
    int top;
} Stack;

List newStack(int tam){
    Stack newStack;

    newList.MAXTAM = tam;
    newStack.stack = (int*)malloc(MAXTAM * sizeof(int));
    newList.top = -1;

    return newStack;
}

// Potótipos das funções - Pilha
void push(Stack *, int);
int pop(Stack *);
void mostrar(Stack);
int pesquisar(Stack);
void ordenar(Stack);
void invertStack(Stack *);
void reverseStack(Stack *, int);
```
<br>

>### Java:

```java

```
---
<br>

## ➕ Método de Inserção (push)

>### C:

```c
void push(Stack *pilha, int elemento)
{
    if (pilha->top >= pilha->MAXTAM)
    {
        pilha->MAXTAM++;
        pilha->stack = (int *)realloc(pilha->stack, pilha->MAXTAM * sizeof(int));

        if (!pilha->pokemonStack)
        {
            printf("Erro de memória na realocação\n");
            pilha->stack--;
            exit(1);
        }
    }
    pilha->stack[++pilha->top] = elemento;
}
```
<br>

>### Java:

```java

```
<br>

>### Teste de mesa



#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-pilha)
---
<br>

## ➖ Método de Remoção (pop)

>### C:

```c
Pokemon pop(Stack *pilha)
{
    if (pilha->top == -1)
    {
        printf("Erro! Não há elementos para remover.\n");
        exit(1);
    }

    return pilha->stack[pilha->top--];
}
```
<br>

>### Java:

```java

```
<br>

>### Teste de mesa



#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-pilha)
---
<br>

## 👁️ Método Mostrar

>### C:

```c
void mostrar(Stack pilha)
{
    for (int i = pilha.top; i >= 0; --i)
    {
        printf("[%d]\t%d", i, pilha.stack[i]);
    }
}
```
<br>

>### Java:

```java

```
<br>

>### Teste de mesa



#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-pilha)
---
<br>

## 🔍 Método Pesquisar

>### C:

```c

```
<br>

>### Java:

```java

```
<br>

>### Teste de mesa



#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-pilha)
---
<br>

## 🔄 Método Ordenar

>### C:

```c

```
<br>

>### Java:

```java

```
<br>

>### Teste de mesa



#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-pilha)
