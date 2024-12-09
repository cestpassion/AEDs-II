# Balanceamento de Árvores Binárias

Este documento aborda o conceito de balanceamento de árvores binárias, explicando como o balanceamento é realizado para melhorar a eficiência das operações em uma árvore binária. Também são detalhados os métodos de rotação usados para manter a árvore balanceada durante as inserções e remoções de elementos.

## Índice

1. [Definição de Árvore Binária Balanceada](#definição-de-árvore-binária-balanceada)
2. [Importância do Balanceamento](#importância-do-balanceamento)
3. [Tipos de Árvores Balanceadas](#tipos-de-árvores-balanceadas)
4. [Métodos de Rotação](#métodos-de-rotação)
    - [Rotação Simples](#rotação-simples)
    - [Rotação Dupla](#rotação-dupla)
5. [Exemplo de Implementação](#exemplo-de-implementação)
6. [Análise de Complexidade](#análise-de-complexidade)

---

## Definição de Árvore Binária Balanceada

Uma árvore binária balanceada é uma estrutura de dados onde a altura das subárvores esquerda e direita de qualquer nó nunca diferem por mais do que um. Isso garante que a árvore permaneça equilibrada, evitando que a altura da árvore cresça de forma descontrolada, o que afetaria negativamente a eficiência das operações.

### Propriedade de Balanceamento

Uma árvore binária de busca (BST) é balanceada se, para cada nó `n` da árvore, a diferença de altura entre sua subárvore esquerda e sua subárvore direita for no máximo 1.

## Importância do Balanceamento

O balanceamento de árvores binárias é crucial para otimizar a complexidade das operações de inserção, remoção e pesquisa. Sem balanceamento, uma árvore binária pode degenerar em uma lista ligada, o que resultaria em um tempo de execução ineficiente (O(n)) para essas operações. Árvores binárias balanceadas, como as Árvores AVL ou Árvores Rubro-Negras, garantem um tempo de execução de O(log n) para essas operações, mesmo no pior caso.

## Tipos de Árvores Balanceadas

Existem várias implementações de árvores binárias balanceadas, entre elas:

- **Árvore AVL**: Uma árvore binária de busca balanceada, onde a diferença de altura entre as subárvores esquerda e direita de qualquer nó nunca pode ser maior que 1.
- **Árvore Rubro-Negra**: Uma árvore binária de busca balanceada com uma propriedade de cor de cada nó, usada para garantir o balanceamento.

## Métodos de Rotação

As rotações são os métodos principais para manter o balanceamento em uma árvore binária. Quando a altura de uma subárvore de um nó excede o limite permitido (geralmente 1), uma rotação é realizada para restaurar o balanceamento. Existem dois tipos principais de rotações:

### Rotações Simples

1. **Rotação à Direita** (ou "rotação simples à direita"):  
   É utilizada quando a subárvore esquerda de um nó está mais alta. O nó esquerdo é promovido à raiz, e o nó original se torna o filho direito do novo nó raiz.

    ```java
    public No rotacaoDireita(No y) {
        No x = y.esq;
        y.esq = x.dir;
        x.dir = y;
        return x;
    }
    ```

2. **Rotação à Esquerda** (ou "rotação simples à esquerda"):  
   Utilizada quando a subárvore direita de um nó está mais alta. O nó direito é promovido à raiz, e o nó original se torna o filho esquerdo do novo nó raiz.

    ```java
    public No rotacaoEsquerda(No x) {
        No y = x.dir;
        x.dir = y.esq;
        y.esq = x;
        return y;
    }
    ```

### Rotações Duplas

As rotações duplas são uma combinação de uma rotação à esquerda e à direita. Elas são usadas para corrigir o desequilíbrio quando a subárvore esquerda de um nó tem um filho direito mais alto (ou a subárvore direita tem um filho esquerdo mais alto). Existem duas rotas principais:

1. **Rotação à Esquerda-Direita**:  
   Utilizada quando a subárvore esquerda de um nó está mais alta e o filho esquerdo da subárvore esquerda também está mais alto à direita.

    ```java
    public No rotacaoEsquerdaDireita(No z) {
        z.esq = rotacaoEsquerda(z.esq);
        return rotacaoDireita(z);
    }
    ```

2. **Rotação à Direita-Esquerda**:  
   Utilizada quando a subárvore direita de um nó está mais alta e o filho direito da subárvore direita também está mais alto à esquerda.

    ```java
    public No rotacaoDireitaEsquerda(No z) {
        z.dir = rotacaoDireita(z.dir);
        return rotacaoEsquerda(z);
    }
    ```

## Exemplo de Implementação

Aqui está um exemplo de código Java que demonstra como as rotações simples e duplas podem ser implementadas em uma árvore binária de busca (BST) para manter o balanceamento:

```java
class No {
    int valor;
    No esq, dir;

    public No(int valor) {
        this.valor = valor;
        esq = dir = null;
    }
}

class ArvoreBinaria {
    No raiz;

    // Método para realizar rotação à direita
    public No rotacaoDireita(No y) {
        No x = y.esq;
        y.esq = x.dir;
        x.dir = y;
        return x;
    }

    // Método para realizar rotação à esquerda
    public No rotacaoEsquerda(No x) {
        No y = x.dir;
        x.dir = y.esq;
        y.esq = x;
        return y;
    }

    // Método para inserção balanceada
    public No inserir(No raiz, int valor) {
        if (raiz == null) {
            return new No(valor);
        }

        if (valor < raiz.valor) {
            raiz.esq = inserir(raiz.esq, valor);
        } else if (valor > raiz.valor) {
            raiz.dir = inserir(raiz.dir, valor);
        }

        // Balanceamento após a inserção
        int balance = altura(raiz.esq) - altura(raiz.dir);
        
        // Rotação à esquerda-direita
        if (balance > 1 && valor > raiz.esq.valor) {
            return rotacaoEsquerdaDireita(raiz);
        }
        
        // Rotação à direita-esquerda
        if (balance < -1 && valor < raiz.dir.valor) {
            return rotacaoDireitaEsquerda(raiz);
        }
        
        // Rotações simples
        if (balance > 1) {
            return rotacaoDireita(raiz);
        }
        if (balance < -1) {
            return rotacaoEsquerda(raiz);
        }

        return raiz;
    }
}
```

## Análise de Complexidade

- **Melhor Caso**: A altura da árvore é logarítmica, O(log n), quando a árvore está balanceada. As operações de inserção e remoção têm complexidade O(log n).
- **Pior Caso**: O pior caso ocorre quando a árvore se torna uma lista encadeada (não balanceada). As operações podem ter complexidade O(n).
- **Médio Caso**: O tempo médio de operação para uma árvore binária balanceada é O(log n), pois a altura da árvore é mantida em um nível equilibrado.

--- 

Compreender o balanceamento e os métodos de rotação é crucial para garantir que as operações em uma árvore binária de busca sejam eficientes. As rotações permitem que a árvore se mantenha balanceada após inserções e remoções, otimizando a busca e outros processos.

```

Este modelo de `README.md` descreve de forma concisa o balanceamento de árvores binárias, seus tipos, as rotações e a implementação de métodos de rotação, além de explicar a análise de complexidade envolvida.
