# 📃 Lista
<br>

## 📄 Sumário

>1. [**Conceitos Básicos**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Lista.md#-conceitos-b%C3%A1sicos)
>2. [**Header**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Lista.md#-header)
>3. [**Métodos de Inserção**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Lista.md#-m%C3%A9todos-de-inser%C3%A7%C3%A3o)
>4. [**Métodos de Remoção**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Lista.md#-m%C3%A9todos-de-remo%C3%A7%C3%A3o)
>5. [**Método Mostrar**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Lista.md#%EF%B8%8F-m%C3%A9todo-mostrar)
>6. [**Método Pesquisar**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Lista.md#-m%C3%A9todo-pesquisar)
>7. [**Método Ordenar**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade02-estruturas-de-dados-basicas-lineares/Lista.md#-m%C3%A9todo-ordenar)
---
<br>

## 📘 Conceitos Básicos

As listas são um Tipo Abstrato de Dados (TAD) no qual podemos inserir e remover elementos em qualquer posição

### Variáveis:

- array (de elementos)
```plaintext
           _______________________
    array | 6 | 4 | 8 | 3 |   |   |
          '---'---'---'---'---'---'
            0   1   2   3   4   5
```
- n (contador)
```plaintext
       ___
    n | 4 |
      '---'
```

### Métodos:

- **Construtores** 

- **Inserção de elemento**
  - void inserirInicio(elemento)
  - void inserirFim(elemento)
  - void inserir(elemento, posição)
    
- **Remoção de elementos**
  - elemento removerInicio()
  - elemento removerFim()
  - elemento remover(posição)
    
- **Mostrar, pesquisar, ordenar, ...**

#### [Voltar ao Início 🔝](https)
---
<br>

## 📌 Header

>### C:

```c
typedef struct List
{
    int *list;
    int MAXTAM;
    int n;
} List;

List newList(int tam){
    List newList;

    newList.MAXTAM = tam;
    newList.list = (int*)malloc(MAXTAM * sizeof(int));
    newList.n = 0;

    return newList;
}

// Potótipos das funções - Lista
void inserirInicio(List *, int);     // Função para inserir no início da Lista
void inserirFim(List *, int);        // Função para inserir no fim da Lista
void inserir(List *, int, int);      // Função para inserir na p-ésima posição da Lista
int removerInicio(List *);           // Função para remover no início da Lista
int removerFim(List *);              // Função para remover no fim da Lista
int remover(List *, int);            // Função para remover na p-ésima posição da Lista
void mostrar(List);                  // Função para imprimir os elementos presentes na Lista
int pesquisar(List);                 // Função para pesquisar o elemento na Lista
void ordenar(List);                  // Função para ordenar os elementos da Lista
```
<br>

>### Java:

```java
class List {
    // Atributos
    private int[] list;
    private int n;

    // Construtor 1
    public List() {
        this(10);
    }

    // Construtor 2
    public List(int tam) {
        this.list = new int[tam];
        this.n = 0;
    }

    // Métodos de Inserção
    public void inserirInicio(int elemento) throws Exception { ... }
    public void inserirFim(int elemento) throws Exception { ... }
    public void inserir(int elemento, int pos) throws Exception { ... }

    // Métodos de Remoção
    int removerInicio() throws Exception { ... }
    int removerFim() throws Exception { ... }
    int remover(int pos) throws Exception { ... }

    // Método Mostrar
    public void mostrar() { ... }

    // Método Pesquisar
    public boolean pesquisar() { ... }

    // Método Ordenar
    public void ordenar() { ... }
}
```
---
<br>

## ➕ Métodos de Inserção

### Inserir no Início

>### C:

```c
void inserirInicio(List *lista, int elemento)
{
    if (lista->n >= lista->MAXTAM)
    {
        lista->MAXTAM++;
        lista->list = (int*)realloc(lista->list, lista->MAXTAM * sizeof(int));

        if (!lista->list)
        {
            printf("Erro de memória na realocação\n");
            lista->MAXTAM--;
            exit(1);
        }
    }

    // Realoca os elementos para o fim do array
    for (int i = lista->n; i > 0; --i)
        lista->list[i] = lista->list[i - 1];

    lista->list[0] = elemento;
    lista->n++;
}
```
<br>

>### Java:

```java
/**
 * Insere um registro na primeira posição da Lista e remaneja os demais
 *
 * @param elemento elemento a ser inserido
 */
public void inserirInicio(int elemento) throws Exception {
    if (n >= list.length) 
        throw new Exception("Erro! Contador maior que a lista.");

    // Realoca os elementos para o fim da lista
    for (int i = n; i > 0; --i)
        list[i] = list[i - 1];

    list[0] = elemento;
    n++;
}
```
<br>

>### Teste de mesa



<br>

### Inserir no Fim

>### C:

```c
void inserirFim(List *lista, int elemento)
{
    if (lista->n >= lista->MAXTAM)
    {
        lista->MAXTAM++;
        lista->list = (int*)realloc(lista->list, lista->MAXTAM * sizeof(int));

        if (!lista->list)
        {
            printf("Erro de memória na realocação\n");
            lista->MAXTAM--;
            exit(1);
        }
    }

    lista->list[lista->n] = elemento;
    lista->n++;
}
```
<br>

>### Java:

```java
/**
 * Insere um registro na última posição da Lista.
 *
 * @param elemento elemento a ser inserido
 */
public void inserirFim(int elemento) throws Exception {
    if (n >= list.length)
        throw new Exception("Erro! Contador maior que a lista.");

    list[n] = elemento;
    n++;
}
```
<br>

>### Teste de mesa
<br>

### Inserir em Qualquer Posição

>### C:

```c
void inserir(List *lista, int elemento, int pos)
{
    if (lista->n >= lista->MAXTAM)
    {
        lista->MAXTAM++;

        lista->list = (int*)realloc(lista->list, lista->MAXTAM * sizeof(int));
        if (!lista->list)
        {
            printf("Erro de memória na realocação\n");
            lista->MAXTAM--;
            exit(1);
        }
    }
    if (pos < 0 || pos > lista->n)
    {
        printf("Erro! Posição inválida.\nPosicoes validas = 0 a %d\nPosicao inserida = %d\n", lista->n, pos);
        exit(1);
    }

    // Realoca os elementos para o fim da lista
    for (int i = lista->n; i > pos; --i)
        lista->list[i] = lista->list[i - 1];

    lista->list[pos] = elemento;
    lista->n++;
}
```
<br>

>### Java:

```java
/**
 * Insere um registro na posição p da Lista, onde p < n e n é o número
 * de registros cadastrados. Em seguida, esse método remaneja os demais
 * registros.
 *
 * @param elemento elemento a ser inserido
 * @param pos     posição em que o elemento será inserido
 */
public void inserir(int elemento, int pos) throws Exception {
    if (n >= list.length)
        throw new Exception("Erro! Contador maior que a lista.");
    else if (pos < 0 || pos > n)
        throw new Exception("Erro! Posição inválida.");

    // Realoca os elementos para o fim da lista
    for (int i = n; i > pos; --i)
        list[i] = list[i - 1];

    list[pos] = elemento;
    n++;
}
```
<br>

>### Teste de mesa



#### [Voltar ao Início 🔝](https)
---
<br>

## ➖ Métodos de Remoção

### Remover no Início

>### C:

```c
int removerInicio(List *lista)
{
    if (lista->n == 0)
    {
        printf("Erro! Não há elementos para remover.\n");
        exit(1);
    }

    int removedElemento = lista->list[0];
    lista->n--;

    for (int i = 0; i < lista->n; ++i)
        lista->list[i] = lista->list[i + 1];

    return removedElemento;
}
```
<br>

>### Java:

```java
/**
 * Remove e retorna o primeiro registro cadastrado na Lista e remaneja os
 * demais.
 * 
 * @return elemento removido
 */
int removerInicio() throws Exception {
    if (n == 0)
        throw new Exception("Erro! Não há elementos para remover.");

    int removedElemento = list[0];
    n--;

    for (int i = 0; i < n; ++i)
        list[i] = list[i + 1];

    return removedElemento;
}
```
<br>

>### Teste de mesa



<br>

### Remover no Fim

>### C:

```c
int removerFim(List *lista)
{
    if (lista->n == 0)
    {
        printf("Erro! Não há elementos para remover.\n");
        exit(1);
    }

    return lista->list[--list->n];
}
```
<br>

>### Java:

```java
/**
* Remove e retorna o último registro cadastrado na lista.
*
* @return elemento removido
*/
int removerFim() throws Exception {
    if (n == 0)
        throw new Exception("Erro! Não há elementos para remover.");

    return list[--n];
}
```
<br>

>### Teste de mesa



<br>

### Remover em Qualquer Posição

>### C:

```c
int remover(List *lista, int pos)
{
    if (lista->n == 0)
    {
        printf("Erro! Não há elementos para remover.\n");
        exit(1);
    }
    if (pos < 0 || pos > lista->n)
    {
        printf("Erro! Posição inválida.\n");
        exit(1);
    }

    int removedElemento = lista->list[pos];
    list->n--;

    for (int i = pos; i < lista->n; ++i)
        lista->list[i] = lista->list[i + 1];

    return removedElemento;
}
```
<br>

>### Java:

```java
/**
 * Remove e retorna o registro cadastrado na p-ésima posição da Lista e remaneja
 * os demais.
 *
 * @param pos posição onde na qual será removido o pokemon
 * @return elemento removido
 */
Pokemon remover(int pos) throws Exception {
    if (n == 0)
        throw new Exception("Erro! Não há elementos para remover.");
    if (pos < 0 || pos > n)
        throw new Exception("Erro! Posição inválida.");

    int removedElemento = list[pos];
    n--;

    for (int i = pos; i < n; ++i)
        list[i] = list[i + 1];

    return removedElemento;
}
```
<br>

>### Teste de mesa



#### [Voltar ao Início 🔝](https)
---
<br>

## 👁️ Método Mostrar

>### C:

```c
void mostrar(List lista)
{
    for (int i = 0; i < lista.n; ++i)
    {
        printf("[%d] ", i);
        imprimir(lista.list[i]);
    }
}
```
<br>

>### Java:

```java
public void mostrar() {
    for (int i = 0; i < n; ++i) {
        System.out.print("[" + i + "] ");
        pokemonList[i].imprimir();
    }
}
```
<br>

>### Teste de mesa



#### [Voltar ao Início 🔝](https)
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



#### [Voltar ao Início 🔝](https)
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



#### [Voltar ao Início 🔝](https)
