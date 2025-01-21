# 📚 Pilha
<br>

## 📄 Sumário

>1. [**Conceitos Básicos**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-conceitos-b%C3%A1sicos)
>2. [**Header**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Pilha.md#-header)
>3. [**Soluções](hhh)
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
    int top;
} Stack;

List newStack(int tam){
    Stack newStack;

    newStack.stack = (int*)malloc(tam * sizeof(int));
    newList.top = -1;

    return newStack;
}

// Potótipos das funções - Pilha
void push(Stack *, int);
int pop(Stack *);
void mostrar(Stack);
void invertStack(Stack *);
void reverseStack(Stack *, int);
int pesquisar(Stack);
void ordenar(Stack);
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
