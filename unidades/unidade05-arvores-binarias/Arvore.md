# 🌲 Árvore Binária
<br>

# 📄 Sumário

>1. [**Definição**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-defini%C3%A7%C3%A3o)
>2. [**Estrutura Básica**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-estrutura-b%C3%A1sica)
>3. [**Tipos de Árvore**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-tipos-de-%C3%A1rvore)
>4. [**Considerações**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#%EF%B8%8F-considera%C3%A7%C3%B5es)
>5. [**Classe No em Java**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-classe-no-em-java)
>6. [**Classe ArvoreBinaria em Java**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-classe-arvorebinaria-em-java)
>7. [**Método de Inserção**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-m%C3%A9todo-de-inser%C3%A7%C3%A3o)
>8. [**Método de Remoção**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-m%C3%A9todo-de-remo%C3%A7%C3%A3o)
>9. [**Método de Pesquisa**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-m%C3%A9todo-de-pesquisa)
>10. [**Métodos de Caminhamento**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-m%C3%A9todos-de-caminhamento)
>11. [**Métodos Extras**](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#%EF%B8%8F-m%C3%A9todos-extras)

<br>

##  📘 Definição

Uma **árvore** é uma estrutura de dados formada por um conjunto finito de **nós** (vértices) conectados por **arestas**. A árvore é estruturada de forma hierárquica, com um nó raiz e nós filhos conectados a ela. 

- **Custo de inserção, remoção e pesquisa**: Θ(lg(n)) comparações em uma árvore balanceada.
- A **raiz** está no nível 0, e os nós subsequentes possuem níveis incrementados conforme a distância da raiz.
<br>

## 🔧 Estrutura Básica

- **Nó Raiz**: O nó superior da árvore (nível 0).
- **Nó Interno**: Nó que possui pelo menos um filho.
- **Folha**: Nó sem filhos.
- **Árvore Binária**: Cada nó possui no máximo dois filhos.

### Exemplo de Árvore Binária

```plaintext
            5
         /     \
        3       7
       / \     /  \
      2   4   6    □
     /
    1
```

- A **altura (h)** é a maior distância entre a raiz e uma folha (nó mais distante).
- Os nós 1, 2, e 4 formam uma **subárvore** com raiz no nó 3.
<br>
  
## 🌳 Tipos de Árvore

### 1. **Árvore Binária de Pesquisa (ABP)**

Em uma Árvore Binária de Pesquisa (também chamada de **Binary Search Tree - BST**), os nós são organizados de forma que:

- Todos os nós à **esquerda** de um nó são **menores**.
- Todos os nós à **direita** de um nó são **maiores**.

### 2. **Árvore Binária Completa**

Uma **Árvore Binária Completa** possui as seguintes características:

- Cada nó é uma folha **OU** possui exatamente dois filhos.
- Todos os nós folhas possuem a mesma altura.
- O número de nós internos é 2ʰ - 1, e o número de nós folhas é 2ʰ, onde **h** é a altura da árvore.
- O número total de nós é 2⁽ʰ⁺¹⁾ - 1.

#### Exemplo de Árvore Binária Completa

```plaintext
                      B
                   /     \
                 D         E
               /   \     /   \
             1      4   C     6
           /  \    /  \ /  \  /  \
          9    2  F   A 7   3 8   5
         / \  / \ / \ / \ / \ / \ / \
        □  □ □  □ □  □ □ □ □ □ □ □ □
```

- **Altura**: A altura da árvore é 3 (a raiz está no nível 0).
- **Número de Nós Internos**: 7 (2³ - 1).
- **Número de Nós Folhas**: 8 (2³).
- **Número Total de Nós**: 15 (2⁽³⁺¹⁾ - 1).

### 3. **Árvore Balanceada**

Uma **Árvore Balanceada** é uma árvore em que, para **todos os nós**, a diferença entre a altura das suas subárvores à esquerda e à direita é sempre 0 ou ±1.

<br>

## ⚖️ Considerações

- A **Árvore Binária de Pesquisa (ABP)** também é chamada de **Árvore Binária de Busca (ABB)** ou **Binary Search Tree (BST)**.
- Para este material, assume-se que todas as árvores binárias discutidas são do tipo **Árvore Binária de Pesquisa**.

### Operações em Árvores

As operações mais comuns realizadas em árvores binárias incluem:

- **Inserção**: Inserir um novo nó na árvore, garantindo a propriedade de pesquisa.
- **Remoção**: Remover um nó da árvore e reorganizar para manter a estrutura de pesquisa.
- **Pesquisa**: Encontrar um nó específico na árvore, aproveitando a ordenação binária.
- **Cálculo da Altura**: Determinar a altura de um nó ou da árvore.
  
Essas operações têm um custo **Θ(lg(n))** em uma árvore balanceada, mas podem ser mais lentas em árvores não balanceadas, dependendo da estrutura da árvore.

As árvores binárias são fundamentais em estruturas de dados devido à sua eficiência em operações como inserção, remoção e pesquisa. Além disso, as árvores balanceadas, como a Árvore Binária de Pesquisa, são muito úteis em diversos algoritmos e aplicações que requerem eficiência no gerenciamento de dados ordenados.

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-%C3%A1rvore-bin%C3%A1ria)
---
<br>

## 🪢 Classe `No` em Java

A classe `No` representa a unidade básica de uma árvore binária. Cada nó contém um elemento (ou valor) e referências para seus filhos esquerdo e direito. Essa estrutura permite a construção de árvores binárias de forma dinâmica.

### Estrutura da Classe

```java
class No {
    public int elemento;  // Valor armazenado no nó
    public No esq;        // Referência para o filho à esquerda
    public No dir;        // Referência para o filho à direita

    // Construtor que inicializa o nó com um elemento
    public No(int elemento) {
        this(elemento, null, null); // Chama o construtor completo com filhos nulos
    }

    // Construtor completo que inicializa o nó com um elemento e seus filhos
    public No(int elemento, No esq, No dir) {
        this.elemento = elemento;  // Atribui o valor ao nó
        this.esq = esq;            // Define o filho à esquerda
        this.dir = dir;            // Define o filho à direita
    }
}
```

### Explicação

1. **Atributos:**
   - `elemento`: Armazena o valor do nó (número inteiro neste caso).
   - `esq`: Referência para o nó filho à esquerda.
   - `dir`: Referência para o nó filho à direita.

2. **Construtores:**
   - **Construtor Simples:** Cria um nó com um valor e filhos inicialmente nulos.
   - **Construtor Completo:** Permite criar um nó especificando seu valor e referências para os filhos esquerdo e direito.

### Representação Gráfica

A estrutura de um nó pode ser representada graficamente como:

```plaintext
      elemento
         〇
    esq ⬋   ⬊ dir
```

- **`elemento`**: Valor armazenado no nó.
- **`esq`**: Referência ao nó filho à esquerda.
- **`dir`**: Referência ao nó filho à direita.

### Exemplo de Uso

Abaixo está um exemplo de como criar um nó e conectar outros nós para formar uma pequena árvore binária:

```java
public class Main {
    public static void main(String[] args) {
        // Cria nós individuais
        No no1 = new No(1);
        No no2 = new No(2);
        No no3 = new No(3, no1, no2); // Nó 3 com filhos 1 e 2

        // Exibe os valores e estrutura
        System.out.println("Raiz: " + no3.elemento);         // Saída: 3
        System.out.println("Filho Esquerdo: " + no3.esq.elemento); // Saída: 1
        System.out.println("Filho Direito: " + no3.dir.elemento);  // Saída: 2
    }
}
```

### Conclusão

A classe `No` é fundamental para a construção de árvores binárias, fornecendo a estrutura necessária para organizar os dados e possibilitar operações como inserção, remoção e pesquisa. Sua implementação simples e modular facilita a expansão para árvores mais complexas, como árvores balanceadas ou de busca binária.

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-%C3%A1rvore-bin%C3%A1ria)
---
<br>

## 🌲💻 Classe `ArvoreBinaria` em Java

A classe `ArvoreBinaria` implementa a estrutura de uma árvore binária. Ela é projetada para gerenciar os nós, permitindo operações como inserção, remoção, pesquisa e caminhamentos em diferentes ordens.

### Estrutura da Classe

```java
class ArvoreBinaria {
    private No raiz; // Raiz da árvore

    // Construtor que inicializa a árvore vazia
    public ArvoreBinaria() {
        raiz = null;
    }

    // Métodos de Inserção
    public void inserir(int x) { ... }
    private No inserir(int x, No i) { ... }

    // Métodos de Inserção com Pai
    public void inserirPai(int x) { ... }
    private void inserirPai(int x, No i, No pai) { ... }

    // Métodos de Pesquisa
    public boolean pesquisar(int x) { ... }
    private boolean pesquisar(int x, No i) { ... }

    // Métodos de Caminhamento
    public void caminharCentral() { ... }
    private void caminharCentral(No i) { ... }
    public void caminharPre() { ... }
    private void caminharPre(No i) { ... }
    public void caminharPos() { ... }
    private void caminharPos(No i) { ... }

    // Método de Remoção
    public void remover(int x) { ... }
    private No remover(int x, No i) { ... }
}
```

### Explicação dos Métodos

1. **Inserção:**
   - Permite adicionar um valor à árvore de forma ordenada, respeitando a propriedade da Árvore Binária de Pesquisa (menores à esquerda, maiores à direita).
   - A inserção recursiva percorre a árvore até encontrar uma posição adequada para o novo valor.

2. **Inserção com Pai:**
   - Uma variação que considera o nó pai ao inserir, útil em situações específicas como reconstruções ou árvores que precisam de relacionamentos explícitos entre pai e filho.

3. **Pesquisa:**
   - Verifica se um valor específico está presente na árvore.
   - O método recursivo percorre os nós de acordo com o valor pesquisado, reduzindo o número de comparações.

4. **Caminhamento:**
   - Existem três ordens de caminhamento:
     - **Central (In-Order):** Visita a subárvore esquerda, o nó atual e a subárvore direita.
     - **Pré-Ordem (Pre-Order):** Visita o nó atual antes das subárvores.
     - **Pós-Ordem (Post-Order):** Visita as subárvores antes do nó atual.
   - Essenciais para diferentes aplicações, como listar valores em ordem crescente ou salvar a árvore.

5. **Remoção:**
   - Remove um nó da árvore. Existem três casos principais:
     - Nó sem filhos (folha).
     - Nó com um filho.
     - Nó com dois filhos (substituir pelo sucessor ou predecessor).

### Exemplo de Uso

```java
public class Main {
    public static void main(String[] args) {
        ArvoreBinaria arvore = new ArvoreBinaria();

        // Inserção de elementos
        arvore.inserir(10);
        arvore.inserir(5);
        arvore.inserir(15);

        // Pesquisa
        System.out.println(arvore.pesquisar(5)); // Saída: true
        System.out.println(arvore.pesquisar(20)); // Saída: false

        // Caminhamento Central
        arvore.caminharCentral(); // Saída: 5, 10, 15

        // Remoção
        arvore.remover(10);
        arvore.caminharCentral(); // Saída: 5, 15
    }
}
```

### Conclusão

A classe `ArvoreBinaria` fornece uma base poderosa para manipular árvores binárias em Java. Sua implementação modular permite fácil expansão para casos mais complexos, como árvores balanceadas ou otimizadas para desempenho específico. Além disso, os métodos implementados refletem os conceitos fundamentais de estruturas de dados em árvores, essenciais em Ciência da Computação.

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-%C3%A1rvore-bin%C3%A1ria)
---
<br>

## ➕ Método de Inserção

O método de inserção na árvore binária é responsável por adicionar novos elementos, mantendo a estrutura de uma **Árvore Binária de Pesquisa**. Ele organiza os valores de forma que os menores que um nó estejam à sua esquerda, e os maiores à sua direita.

<br>

### Funcionamento do Método

- **Entrada:** Um elemento `x` que será inserido na árvore.
- **Processo:**
  - Se a árvore estiver vazia, o elemento será inserido como a **raiz**.
  - Caso contrário:
    - Se `x` for menor que o valor do nó atual, tenta inseri-lo na subárvore esquerda.
    - Se `x` for maior, tenta inseri-lo na subárvore direita.
    - Se `x` for igual ao valor do nó atual, ocorre uma **exceção**, pois valores duplicados não são permitidos.
- **Saída:** O nó atualizado com o novo elemento inserido.

<br>

### Implementação com Retorno de Referência

```java
public void inserir(int x) throws Exception {
    raiz = inserir(x, raiz);
}

private No inserir(int x, No i) throws Exception {
    if (i == null) {
        i = new No(x); // Criação de um novo nó se a posição estiver vazia
    } else if (x < i.elemento) {
        i.esq = inserir(x, i.esq); // Inserção à esquerda
    } else if (x > i.elemento) {
        i.dir = inserir(x, i.dir); // Inserção à direita
    } else {
        throw new Exception("Erro! Elemento duplicado.");
    }
    return i; // Retorna o nó atualizado
}
```

#### Vantagens:
- O método retorna a referência atualizada do nó, facilitando a manipulação em chamadas recursivas.
- Simples e direto para árvores binárias básicas.

<br>

### Implementação com Passagem de Pai

```java
public void inserirPai(int x) throws Exception {
    if (raiz == null) {
        raiz = new No(x); // Inserção na raiz
    } else if (x < raiz.elemento) {
        inserirPai(x, raiz.esq, raiz);
    } else if (x > raiz.elemento) {
        inserirPai(x, raiz.dir, raiz);
    } else {
        throw new Exception("Erro! Elemento duplicado.");
    }
}

private void inserirPai(int x, No i, No pai) {
    if (i == null) {
        if (x < pai.elemento) {
            pai.esq = new No(x); // Inserção à esquerda do pai
        } else {
            pai.dir = new No(x); // Inserção à direita do pai
        }
    } else if (x < i.elemento) {
        inserirPai(x, i.esq, i); // Avança para a subárvore esquerda
    } else if (x > i.elemento) {
        inserirPai(x, i.dir, i); // Avança para a subárvore direita
    } else {
        throw new Exception("Erro! Elemento duplicado.");
    }
}
```

#### Vantagens:
- Útil quando é necessário rastrear o nó pai durante o processo de inserção, como em algumas árvores balanceadas.
- Torna mais explícita a relação entre pai e filho.

<br>

### Análise de Complexidade

A eficiência do método de inserção depende do formato da árvore:

1. **Melhor Caso:**  
   - Ocorre ao inserir na raiz de uma árvore vazia.  
   - Complexidade: **Θ(1)**.

2. **Pior Caso:**  
   - Ocorre quando a árvore se assemelha a uma lista encadeada, como ao inserir elementos em ordem crescente ou decrescente.  
   - Complexidade: **Θ(n)**, onde `n` é o número de nós.

3. **Caso Médio:**  
   - Ocorre em uma árvore balanceada, onde a altura é proporcional a **lg(n)**.  
   - Complexidade: **Θ(lg(n))**.

**Nota:** Inserções aleatórias em uma árvore não balanceada têm, em média, **≈ 1,39 x lg(n)** comparações.

<br>

### Exemplo Prático

**Inserção dos elementos:** `3, 5, 1, 8, 2, 4, 7, 6`

1. Primeiro, insere-se o `3` como raiz.  
2. Depois, `5` vai para a direita de `3`.  
3. `1` é inserido à esquerda de `3`, e assim por diante.

```
 1)   🠗          2)   🠗            3)        🠗             4)        🠗                 5)        🠗                                        
     |3|              3                     3                       3                           3
   ⬋    ⬊           ⬋    ⬊                 ⬋  ⬊                    ⬋  ⬊                        ⬋  ⬊               
                          |5|           |1|      5               1       5                   1       5     
                          ⬋  ⬊         ⬋  ⬊     ⬋  ⬊           ⬋  ⬊     ⬋  ⬊               ⬋  ⬊     ⬋  ⬊
                                                                            |8|               |2|       8 
                                                                            ⬋ ⬊               ⬋ ⬊      ⬋ ⬊                                                                          
 6)        🠗              7)        🠗                    8)       🠗                                                
           3                        3                             3               
         ⬋  ⬊                      ⬋  ⬊                          ⬋  ⬊                   
       1       5                 1       5                     1       5      
     ⬋  ⬊     ⬋  ⬊             ⬋  ⬊     ⬋  ⬊                 ⬋  ⬊     ⬋  ⬊                                    
         2  |4|   8                2   4    8                    2   4    8  
        ⬋ ⬊ ⬋ ⬊  ⬋ ⬊              ⬋ ⬊ ⬋ ⬊  ⬋ ⬊                  ⬋ ⬊ ⬋ ⬊  ⬋ ⬊   
                                             |7|                            7
                                              ⬋⬊                           ⬋⬊
                                                                         |6|
```

O resultado final será:

```
          3
       /     \
      1       5
       \     / \
        2   4   8
                 /
                7
               /
              6
```

<br>

O método de inserção é essencial para manter a árvore organizada, servindo como base para operações como pesquisa e remoção.

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-%C3%A1rvore-bin%C3%A1ria)
---
<br>

## ➖ Método de Remoção

### Funcionamento Básico

O método de **remoção** em Árvores Binárias de Busca (ABB) segue estas etapas:

1. **Elemento em uma folha**: Se o elemento a ser removido está em um nó folha, basta removê-lo.
2. **Elemento com um único filho**: Se o nó a ser removido possui apenas um filho, o nó é substituído pelo seu filho, fazendo com que o pai do nó aponte diretamente para este.
3. **Elemento com dois filhos**: Substitui-se o nó pelo maior elemento da subárvore esquerda **ou** pelo menor elemento da subárvore direita.

<br>

### Implementação: Métodos de Apoio

#### Maior Elemento
Retorna o maior elemento da árvore (mais à direita):
```java
public int getMaior() {
    int maior = -1;
    if (raiz != null) {
        No i;
        for (i = raiz; i.dir != null; i = i.dir);
        maior = i.elemento;
    }
    return maior;
}
```

#### Menor Elemento
Retorna o menor elemento da árvore (mais à esquerda):
```java
public int getMenor() {
    int menor = -1;
    if (raiz != null) {
        No i;
        for (i = raiz; i.esq != null; i = i.esq);
        menor = i.elemento;
    }
    return menor;
}
```

<br>

### Implementação: Método de Remoção Básico

#### Remoção Simples
Este método substitui o nó a ser removido conforme as condições:
```java
public void remover(int x) throws Exception {
    raiz = remover(x, raiz);
}

private No remover(int x, No i) throws Exception {
    if (i == null) {
        throw new Exception("Erro! Não há elementos para remover.");
    } else if (x < i.elemento) {
        i.esq = remover(x, i.esq);
    } else if (x > i.elemento) {
        i.dir = remover(x, i.dir);
    } else if (i.dir == null) {
        i = i.esq;
    } else if (i.esq == null) {
        i = i.dir;
    } else {
        i.esq = maiorEsq(i, i.esq);
    }
    return i;
}
```

#### Substituição pelo Maior Elemento da Subárvore Esquerda
```java
private No maiorEsq(No i, No j) {
    if (j.dir == null) {
        i.elemento = j.elemento;
        j = j.esq;
    } else {
        j.dir = maiorEsq(i, j.dir);
    }
    return j;
}
```

<br>

### Alterações no Método: Retorno `void`

A remoção pode ser implementada sem retornar o nó, usando o pai para atualizar os ponteiros:
```java
public void remover2(int x) throws Exception {
    if (raiz == null) {
        throw new Exception("Erro! Não há elementos para remover.");
    } else if (x < raiz.elemento) {
        remover2(x, raiz.esq, raiz);
    } else if (x > raiz.elemento) {
        remover2(x, raiz.dir, raiz);
    } else if (raiz.dir == null) {
        raiz = raiz.esq;
    } else if (raiz.esq == null) {
        raiz = raiz.dir;
    } else {
        raiz.esq = maiorEsq(raiz, raiz.esq);
    }
}

private void remover2(int x, No i, No pai) throws Exception {
    if (i == null) {
        throw new Exception("Erro! Não há elementos para remover.");
    } else if (x < i.elemento) {
        remover2(x, i.esq, i);
    } else if (x > i.elemento) {
        remover2(x, i.dir, i);
    } else if (i.dir == null) {
        if (x < pai.elemento)
            pai.esq = i.esq;
        else
            pai.dir = i.esq;
    } else if (i.esq == null) {
        if (x < pai.elemento)
            pai.esq = i.dir;
        else
            pai.dir = i.dir;
    } else {
        i.esq = maiorEsq(i, i.esq);
    }
}
```

<br>

### Alterações no Método: Retornando o Elemento Removido

Este método pode ser ajustado para retornar o valor do nó removido:
```java
public int remover3(int x) throws Exception {
    int removido;
    No retorno = remover3(x, raiz);
    removido = retorno != null ? retorno.elemento : -1;
    return removido;
}

private No remover3(int x, No i) throws Exception {
    if (i == null) {
        throw new Exception("Erro! Não há elementos para remover.");
    } else if (x < i.elemento) {
        i.esq = remover3(x, i.esq);
    } else if (x > i.elemento) {
        i.dir = remover3(x, i.dir);
    } else if (i.dir == null) {
        return i.esq;
    } else if (i.esq == null) {
        return i.dir;
    } else {
        i.esq = maiorEsq(i, i.esq);
    }
    return i;
}
```

<br>

### Análise de Complexidade

- **Melhor Caso**: Θ(1) - ocorre quando o elemento está na raiz.
- **Pior Caso**: Θ(n) - ocorre em árvores degeneradas (ex: lista ligada).
- **Caso Médio**: Θ(log n) - em árvores balanceadas, a altura é proporcional a log n.

OBS: O desempenho depende diretamente da estrutura da árvore e do balanceamento dos nós.

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-%C3%A1rvore-bin%C3%A1ria)
---
<br>

## 🔍 Método de Pesquisa

O método de pesquisa em uma árvore binária segue uma abordagem recursiva e busca determinar a existência de um elemento, retornando se ele está presente ou não. A ideia é, a partir da raiz, comparar o valor do nó com o elemento desejado e decidir em qual subárvore o elemento deve ser procurado, baseando-se no seu valor.

### Funcionamento Básico

1. **Se a raiz estiver vazia**, isso significa que a árvore está vazia ou que o elemento não foi encontrado, retornando uma **pesquisa negativa**.
2. **Se o elemento procurado for igual ao da raiz**, a busca foi bem-sucedida, e é retornado uma **pesquisa positiva**.
3. **Se o elemento procurado for menor que o da raiz**, a pesquisa continua na **subárvore à esquerda**.
4. **Se o elemento procurado for maior que o da raiz**, a pesquisa continua na **subárvore à direita**.

#### Exemplo

Imaginemos uma árvore binária com os seguintes elementos:

```
           50
         /    \
       30      70
      /  \     /  \
    20   40   60   80
```

Caso quisermos buscar o número **40**, a sequência de passos seria:

1. A raiz é **50**, e como **40** é menor que **50**, a pesquisa vai para a subárvore à esquerda (30).
2. O próximo nó é **30**, e como **40** é maior que **30**, a pesquisa vai para a subárvore à direita (40).
3. O nó **40** é encontrado, logo a pesquisa é **positiva**.

### Implementação: Algoritmo em Java

```java
// Método de pesquisa que chama a versão recursiva.
boolean pesquisar(int x) {
    return pesquisar(x, raiz);
}

// Método recursivo para pesquisa.
boolean pesquisar(int x, No i) {
    boolean resp;

    if (i == null) {
        resp = false;  // Elemento não encontrado.
    } else if (x == i.elemento) {
        resp = true;   // Elemento encontrado.
    } else if (x < i.elemento) {
        resp = pesquisar(x, i.esq);  // Pesquisa na subárvore esquerda.
    } else {
        resp = pesquisar(x, i.dir);  // Pesquisa na subárvore direita.
    }
    return resp;
}
```

### Análise de Complexidade da Pesquisa

A análise de complexidade pode ser feita em termos de comparação de nós durante a busca:

- **Melhor Caso**: A pesquisa encontra o elemento logo na raiz da árvore, realizando **Θ(1)** comparações.
- **Pior Caso**: A pesquisa precisa percorrer toda a árvore, realizando **Θ(n)** comparações, o que ocorre quando a árvore está desbalanceada (como uma lista encadeada).
- **Caso Médio**: Quando a árvore está balanceada, a pesquisa precisa percorrer aproximadamente o caminho mais curto entre a raiz e uma folha, resultando em **Θ(log n)** comparações.

Essa análise é importante para entender a eficiência da pesquisa em árvores binárias e como o balanceamento da árvore pode afetar a performance das operações de busca.

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-%C3%A1rvore-bin%C3%A1ria)
---
<br>

## 🧭 Métodos de Caminhamento

Os métodos de caminhamento (ou percorrimento) de uma árvore binária são usados para visitar e exibir todos os elementos presentes na árvore. Esse processo pode ser feito de diferentes formas, dependendo da ordem em que os nós são visitados. Cada tipo de caminhamento tem suas características e pode ser utilizado conforme a necessidade do algoritmo ou operação que se deseja realizar.

A análise de complexidade para todos os métodos de caminhamento é **Θ(n)**, pois é necessário visitar todos os nós da árvore uma vez.

### 1. Caminhamento Central ou **Em Ordem**

No **caminhamento em ordem (ou in-order)**, o algoritmo visita primeiro a subárvore esquerda, depois o nó atual, e por fim a subárvore direita. Esse tipo de caminhamento é comumente utilizado em árvores binárias de busca, pois visita os elementos em ordem crescente.

```
            6
         /     \
       3         9
    /   \       /   \
  1      5     8     10
/  \   /  \   /  \   /  \
x  2   4  x   7  x   x  11
```

**Saída esperada (em ordem):** 1 2 3 4 5 6 7 8 9 10 11

#### Implementação em Java

```java
public void caminharCentral(No i) {
    if (i != null) {
        caminharCentral(i.esq);         // Visita a subárvore esquerda
        System.out.print(i.elemento + " ");  // Visita o nó atual
        caminharCentral(i.dir);         // Visita a subárvore direita
    }
}
```

### 2. Caminhamento Pós-fixado ou **Pós-ordem**

No **caminhamento pós-ordem (ou post-order)**, o algoritmo visita primeiro a subárvore esquerda, depois a subárvore direita, e por último o nó atual. Este tipo de caminhamento é útil em algoritmos que precisam processar primeiro os filhos e depois o nó pai, como na remoção de nós em uma árvore.

```
            6
         /     \
       3         9
    /   \       /   \
  1      5     8     10
/  \   /  \   /  \   /  \
x  2   4  x   7  x   x  11
```

**Saída esperada (pós-ordem):** 2 1 4 5 3 7 8 11 10 9 6

#### Implementação em Java

```java
public void caminharPos(No i) {
    if (i != null) {
        caminharPos(i.esq);         // Visita a subárvore esquerda
        caminharPos(i.dir);         // Visita a subárvore direita
        System.out.print(i.elemento + " ");  // Visita o nó atual
    }
}
```

### 3. Caminhamento Pré-fixado ou **Pré-ordem**

No **caminhamento pré-ordem (ou pre-order)**, o algoritmo visita primeiro o nó atual, depois a subárvore esquerda e por fim a subárvore direita. Esse tipo de caminhamento é útil quando precisamos processar o nó antes de seus filhos, como ao copiar ou criar uma árvore.

```
            6
         /     \
       3         9
    /   \       /   \
  1      5     8     10
/  \   /  \   /  \   /  \
x  2   4  x   7  x   x  11
```

**Saída esperada (pré-ordem):** 6 3 1 2 5 4 9 8 7 10 11

#### Implementação em Java

```java
public void caminharPre(No i) {
    if (i != null) {
        System.out.print(i.elemento + " ");  // Visita o nó atual
        caminharPre(i.esq);         // Visita a subárvore esquerda
        caminharPre(i.dir);         // Visita a subárvore direita
    }
}
```

---
<br>

### Resumo dos Métodos de Caminhamento:

- **Caminhamento Central (In-order):** Visita a subárvore esquerda, depois o nó atual, e por fim a subárvore direita. Comumente usado em árvores binárias de busca.
- **Caminhamento Pós-fixado (Post-order):** Visita a subárvore esquerda, depois a subárvore direita, e por último o nó atual. Ideal para processamento de filhos antes dos pais.
- **Caminhamento Pré-fixado (Pre-order):** Visita o nó atual, depois a subárvore esquerda, e por fim a subárvore direita. Útil para criar ou copiar árvores.

### Análise de Complexidade

Para todos os métodos de caminhamento, a complexidade de tempo é **Θ(n)**, pois o algoritmo precisa visitar todos os nós da árvore, onde **n** é o número total de nós presentes. A complexidade é linear em relação ao número de nós na árvore.

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-%C3%A1rvore-bin%C3%A1ria)
---
<br>

## ⚙️ Métodos Extras

Os métodos extras descritos abaixo são funções adicionais que podem ser usadas para realizar operações específicas em uma árvore binária. Cada método é útil para diferentes tipos de análises e manipulações de dados dentro da árvore.

<br>

### 1. **Altura da Árvore**

A altura de uma árvore é a distância do nó raiz até o nó mais distante. Ela é medida pelo número de arestas no caminho mais longo da raiz até a folha. O método `getAltura()` chama uma função recursiva que calcula a altura de uma árvore binária.

**Descrição do método:**
- **getAltura():** Este método é o ponto de entrada para calcular a altura da árvore, começando pela raiz. Ele chama a função recursiva `getAltura(No i, int altura)`, passando a altura inicial como 0.
- **getAltura(No i, int altura):** Função recursiva que percorre a árvore para calcular a altura, comparando as alturas das subárvores esquerda e direita e retornando a maior delas.

**Implementação em Java:**

```java
public int getAltura() {
    return getAltura(raiz, 0);
}

public int getAltura(No i, int altura) {
    if (i == null) {
        altura--;
    } else {
        int alturaEsq = getAltura(i.esq, altura + 1);
        int alturaDir = getAltura(i.dir, altura + 1);
        altura = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
    }
    return altura;
}
```

---
<br>

### 2. **Número de Elementos na Árvore**

Este método calcula o número total de elementos (nós) presentes na árvore binária. A função recursiva percorre todos os nós, incrementando o contador.

**Descrição do método:**
- **numElementos():** Este método é o ponto de entrada que inicia a contagem de elementos a partir da raiz.
- **numElementos(No i, int resp):** Função recursiva que percorre a árvore e conta os elementos em cada nó, incrementando o contador.

**Implementação em Java:**

```java
public int numElementos() {
    return numElementos(raiz, 0);
}

private int numElementos(No i, int resp) {
    if (i == null) {
        resp--;
    } else if (i != null) {
        numElementos(i.esq, ++resp);
        numElementos(i.dir, ++resp);
    }
    return resp;
}
```

---
<br>

### 3. **Soma dos Elementos na Árvore**

Este método retorna a soma de todos os elementos (valores) presentes nos nós da árvore binária. A função recursiva percorre a árvore e acumula os valores.

**Descrição do método:**
- **soma():** Método de entrada para somar os elementos, chamando a função recursiva `soma(No i)`.
- **soma(No i):** Função recursiva que calcula a soma dos valores dos nós da árvore.

**Implementação em Java:**

```java
public int soma() {
    return soma(raiz);
}

public int soma(No i) {
    int resp = 0;
    if (i != null)
        resp = i.elemento + soma(i.esq) + soma(i.dir);
    return resp;
}
```

---
<br>

### 4. **Número de Elementos Pares na Árvore**

Este método conta o número de elementos pares presentes na árvore. A função recursiva percorre a árvore e verifica se o valor do nó é par.

**Descrição do método:**
- **numPares():** Método que chama a função recursiva `numPares(No i)` para contar os elementos pares.
- **numPares(No i):** Função recursiva que verifica se o elemento do nó é par e faz a contagem de forma recursiva.

**Implementação em Java:**

```java
public int numPares() {
    return numPares(raiz);
}

public int numPares(No i) {
    int resp = 0;
    if (i != null)
        resp = ((i.elemento % 2 == 0) ? 1 : 0) + numPares(i.esq) + numPares(i.dir);
    return resp;
}
```

---
<br>

### 5. **Verificação de Número Divisível por 11**

Este método verifica se algum número na árvore é divisível por 11. A função recursiva percorre a árvore e verifica se o valor de qualquer nó é divisível por 11.

**Descrição do método:**
- **hasDiv11():** Método que chama a função recursiva `hasDiv11(No i)` para verificar se existe algum número divisível por 11 na árvore.
- **hasDiv11(No i):** Função recursiva que retorna verdadeiro se encontrar um número divisível por 11 em qualquer nó da árvore.

**Implementação em Java:**

```java
public boolean hasDiv11() {
    return hasDiv11(raiz);
}

public boolean hasDiv11(No i) {
    boolean resp = false;
    if (i != null)
        resp = (i.elemento % 11 == 0 || hasDiv11(i.esq) || hasDiv11(i.dir));
    return resp;
}
```

---
<br>

### 6. **TreeSort**

O **TreeSort** é um algoritmo de ordenação que utiliza uma árvore binária para ordenar os elementos. O algoritmo insere todos os elementos em uma árvore binária de busca (BST) e, em seguida, percorre a árvore em ordem crescente (in-order traversal) para coletar os elementos ordenados em um array.

**Descrição do método:**
- **TreeSort:** A classe que implementa o algoritmo de ordenação utilizando uma árvore binária.
- **sort():** Método que cria um array de inteiros e preenche com os elementos ordenados da árvore.
- **sort(No i, int[] array):** Função recursiva que realiza o caminhamento em ordem e armazena os elementos no array.

**Análise de Complexidade:**
- Se a árvore for balanceada, o custo de inserção de cada elemento é **Θ(log n)** comparações. Como existem **n** elementos, o custo total de inserção será **Θ(n log n)** comparações.
- O caminhamento para coletar os elementos ordenados tem custo **Θ(n)**, pois percorre todos os nós da árvore.

**Implementação em Java:**

```java
class TreeSort {
    private No raiz;
    private int n;

    public TreeSort(No raiz, int n) {
        this.raiz = raiz;
        this.n = n;
    }

    public int[] sort() {
        int[] array = new int[n];
        n = 0;
        sort(raiz, array);
        return array;
    }

    private void sort(No i, int[] array) {
        if (i != null) {
            sort(i.esq, array);       // Caminha pela subárvore esquerda
            array[n++] = i.elemento;   // Armazena o elemento
            sort(i.dir, array);       // Caminha pela subárvore direita
        }
    }
}
```

---
<br>

### Resumo:

- **Altura da Árvore:** Calcula a altura da árvore binária.
- **Número de Elementos:** Conta quantos nós existem na árvore.
- **Soma dos Elementos:** Soma todos os valores dos nós da árvore.
- **Número de Elementos Pares:** Conta quantos elementos na árvore são pares.
- **Divisível por 11:** Verifica se algum número na árvore é divisível por 11.
- **TreeSort:** Implementa o algoritmo de ordenação TreeSort usando uma árvore binária para ordenar os elementos.

Esses métodos adicionais fornecem funcionalidades úteis para análise e manipulação de dados em uma árvore binária. Cada um deles utiliza uma abordagem recursiva para percorrer a árvore e realizar operações específicas.

#### [Voltar ao Início 🔝](https://github.com/cestpassion/AEDs-II/blob/main/unidades/unidade05-arvores-binarias/Arvore.md#-%C3%A1rvore-bin%C3%A1ria)
