# Árvore AVL

A Árvore AVL é uma árvore binária de busca balanceada, onde a diferença de altura entre a subárvore esquerda e a subárvore direita de qualquer nó não pode ser maior que 1. Esse balanceamento garante que a árvore tenha uma altura logarítmica, o que torna as operações de inserção, remoção e pesquisa mais eficientes.

Este documento explica como a Árvore AVL é implementada, como realizar o teste de mesa, e qual a complexidade das suas operações.

## Índice

1. [Definição de Árvore AVL](#definição-de-árvore-avl)
2. [Propriedades da Árvore AVL](#propriedades-da-árvore-avl)
3. [Implementação da Árvore AVL](#implementação-da-árvore-avl)
    - [Inserção](#inserção)
    - [Remoção](#remoção)
    - [Balanceamento e Rotações](#balanceamento-e-rotações)
4. [Teste de Mesa](#teste-de-mesa)
5. [Complexidade das Operações](#complexidade-das-operações)
6. [Exemplo de Código](#exemplo-de-código)
7. [Conclusão](#conclusão)

---

## Definição de Árvore AVL

A Árvore AVL (Adelson-Velsky and Landis) é uma árvore binária de busca em que, para qualquer nó, a diferença entre as alturas das subárvores esquerda e direita (fator de balanceamento) deve ser no máximo 1. Caso contrário, a árvore é balanceada utilizando rotações.

A propriedade de balanceamento da Árvore AVL garante que a árvore permaneça equilibrada, evitando a degeneração em uma lista encadeada. Como resultado, as operações de pesquisa, inserção e remoção são eficientes, com uma complexidade de tempo de O(log n).

---

## Propriedades da Árvore AVL

1. **Fator de Balanceamento**: O fator de balanceamento de um nó é a diferença entre a altura da subárvore esquerda e da subárvore direita.
    - Fator de balanceamento = altura(subárvore esquerda) - altura(subárvore direita)
    - O fator de balanceamento de qualquer nó em uma Árvore AVL deve ser -1, 0 ou 1.

2. **Rotações**: Quando um nó se torna desequilibrado, as rotações são realizadas para restaurar o balanceamento:
   - **Rotação Simples** (à esquerda ou à direita).
   - **Rotação Dupla** (esquerda-direita ou direita-esquerda).

---

## Implementação da Árvore AVL

### Inserção

A inserção em uma Árvore AVL segue as mesmas regras de uma árvore binária de busca, mas, após cada inserção, o fator de balanceamento de cada nó é verificado e as rotações são realizadas, se necessário, para garantir que a árvore permaneça balanceada.

### Remoção

A remoção de um nó em uma Árvore AVL é semelhante à remoção em uma árvore binária de busca. Após a remoção, o fator de balanceamento é recalculado e, se necessário, são feitas rotações para manter o balanceamento da árvore.

### Balanceamento e Rotações

O balanceamento é feito através de rotações. As rotações podem ser simples ou duplas, dependendo da direção do desequilíbrio:

- **Rotação Simples à Esquerda**:
    - Realizada quando o nó direito está mais alto que o nó esquerdo.
    ```java
    public No rotacaoEsquerda(No x) {
        No y = x.dir;
        x.dir = y.esq;
        y.esq = x;
        return y;
    }
    ```

- **Rotação Simples à Direita**:
    - Realizada quando o nó esquerdo está mais alto que o nó direito.
    ```java
    public No rotacaoDireita(No y) {
        No x = y.esq;
        y.esq = x.dir;
        x.dir = y;
        return x;
    }
    ```

- **Rotação Dupla Esquerda-Direita**:
    - Realizada quando o nó esquerdo tem um filho direito mais alto.
    ```java
    public No rotacaoEsquerdaDireita(No z) {
        z.esq = rotacaoEsquerda(z.esq);
        return rotacaoDireita(z);
    }
    ```

- **Rotação Dupla Direita-Esquerda**:
    - Realizada quando o nó direito tem um filho esquerdo mais alto.
    ```java
    public No rotacaoDireitaEsquerda(No z) {
        z.dir = rotacaoDireita(z.dir);
        return rotacaoEsquerda(z);
    }
    ```

---

## Teste de Mesa

O teste de mesa é uma ferramenta útil para entender como as operações de inserção e remoção afetam a estrutura da Árvore AVL. Ele consiste em desenhar a árvore e acompanhar as mudanças na estrutura à medida que as operações são realizadas.

### Exemplo de Teste de Mesa

Considere a inserção dos seguintes valores: [10, 20, 30, 15, 25].

1. **Inserir 10**:
    - A árvore começa vazia.
    - A árvore se torna: [10].

2. **Inserir 20**:
    - A árvore agora é [10, 20].
    - A árvore permanece balanceada.

3. **Inserir 30**:
    - A árvore se torna: [10, 20, 30].
    - O nó 10 agora tem um fator de balanceamento de -2 (subárvore direita mais alta).
    - Realiza-se uma rotação à esquerda no nó 10, fazendo o nó 20 ser a nova raiz. A árvore se torna:
    ```
       20
      /  \
     10   30
    ```

4. **Inserir 15**:
    - A árvore se torna: [10, 15, 20, 30].
    - O nó 30 agora tem um fator de balanceamento de -1 e a árvore permanece balanceada.

5. **Inserir 25**:
    - A árvore se torna: [10, 15, 20, 25, 30].
    - O nó 20 agora tem um fator de balanceamento de 2, realizando uma rotação à direita no nó 20. A árvore final fica:
    ```
       20
      /  \
     10   25
         /  \
        15   30
    ```

---

## Complexidade das Operações

1. **Inserção**: O tempo de inserção em uma Árvore AVL é O(log n), pois a árvore é balanceada e a altura da árvore é logarítmica.

2. **Remoção**: A remoção de um nó também tem tempo O(log n), já que a árvore é balanceada e as rotações são feitas para manter o equilíbrio.

3. **Pesquisa**: A pesquisa em uma Árvore AVL também tem tempo O(log n), devido ao fato de que a altura da árvore é mantida equilibrada.

---

## Exemplo de Código

Aqui está um exemplo de implementação simples de uma Árvore AVL em Java:

```java
class No {
    int valor;
    No esq, dir;
    int altura;

    public No(int valor) {
        this.valor = valor;
        esq = dir = null;
        altura = 1;
    }
}

class ArvoreAVL {
    No raiz;

    // Método para calcular a altura de um nó
    int altura(No N) {
        if (N == null) return 0;
        return N.altura;
    }

    // Método para calcular o fator de balanceamento
    int fatorBalanceamento(No N) {
        if (N == null) return 0;
        return altura(N.esq) - altura(N.dir);
    }

    // Rotação simples à direita
    No rotacaoDireita(No y) {
        No x = y.esq;
        y.esq = x.dir;
        x.dir = y;
        y.altura = Math.max(altura(y.esq), altura(y.dir)) + 1;
        x.altura = Math.max(altura(x.esq), altura(x.dir)) + 1;
        return x;
    }

    // Rotação simples à esquerda
    No rotacaoEsquerda(No x) {
        No y = x.dir;
        x.dir = y.esq;
        y.esq = x;
        x.altura = Math.max(altura(x.esq), altura(x.dir)) + 1;
        y.altura = Math.max(altura(y.esq), altura(y.dir)) + 1;
        return y;
    }

    // Inserção
    No inserir(No raiz, int valor) {
        if (raiz == null) return new No(valor);

        if (valor < raiz.valor) raiz.esq = inserir(raiz.esq, valor);
        else if (valor > raiz.valor) raiz.dir = inserir(raiz.dir, valor);
        else return raiz;

        raiz.altura = Math.max(altura(raiz.esq), altura(raiz.dir)) + 1;
        
        int balance = fatorBalanceamento(raiz);

        if (balance > 1 && valor < raiz.esq.valor) return rotacaoDireita(raiz);
        if (balance < -1 && valor > raiz.dir.valor) return rotacaoEsquerda(raiz);
        if (balance > 1 && valor > raiz.esq.valor) {
            raiz.esq = rotacaoEsquerda(raiz.esq);
            return rotacaoDireita(raiz);
        }
        if (balance < -1 && valor < raiz.dir.valor) {
            raiz.dir = rotacaoDireita(raiz.dir);
            return rotacaoEsquerda(raiz);
        }

        return raiz;
    }
}
```

---

## Conclusão

A Árvore AVL é uma estrutura de dados fundamental para garantir que as operações de busca, inserção e remoção em uma árvore binária de busca sejam eficientes, mantendo uma altura logarítmica. As rotações são cruciais para manter o balanceamento da árvore após cada operação, e o teste de mesa é uma excelente ferramenta para entender o funcionamento interno dessas operações.

Com uma implementação eficiente, a Árvore AVL oferece um desempenho consistente e otimizado para muitos algoritmos de busca e manipulação de dados.
