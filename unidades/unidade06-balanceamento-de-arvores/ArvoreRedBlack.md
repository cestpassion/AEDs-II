# Árvore Red-Black

A Árvore Red-Black (ou Árvore Vermelha e Preta) é uma árvore binária de busca balanceada, onde cada nó tem uma cor (vermelha ou preta) e segue um conjunto de regras rigorosas que garantem que a árvore permaneça balanceada. Essa estrutura garante operações eficientes de inserção, remoção e busca, com complexidade O(log n), onde n é o número de nós na árvore.

Este documento explica como a Árvore Red-Black é implementada, como realizar o teste de mesa, a complexidade das operações e exemplos de código.

## Índice

1. [Definição de Árvore Red-Black](#definição-de-árvore-red-black)
2. [Propriedades da Árvore Red-Black](#propriedades-da-árvore-red-black)
3. [Implementação da Árvore Red-Black](#implementação-da-árvore-red-black)
    - [Inserção](#inserção)
    - [Remoção](#remoção)
    - [Regras de Balanceamento](#regras-de-balanceamento)
4. [Teste de Mesa](#teste-de-mesa)
5. [Complexidade das Operações](#complexidade-das-operações)
6. [Exemplo de Código](#exemplo-de-código)
7. [Conclusão](#conclusão)

---

## Definição de Árvore Red-Black

A Árvore Red-Black é uma árvore binária de busca que satisfaz as seguintes propriedades:

1. **Cada nó é vermelho ou preto.**
2. **A raiz é sempre preta.**
3. **As folhas (nulos) são pretas.**
4. **Se um nó é vermelho, seus filhos devem ser pretos (nenhum nó vermelho pode ter um filho vermelho).**
5. **Para cada nó, o caminho da raiz até as folhas passará por um número igual de nós pretos (isso é chamado de "propriedade de caminho preto").**

Essas propriedades garantem que a árvore tenha uma altura logarítmica, permitindo que as operações de busca, inserção e remoção sejam feitas de forma eficiente.

---

## Propriedades da Árvore Red-Black

As propriedades acima garantem o balanceamento da árvore. Isso é alcançado através de uma combinação de regras de cores e rotações.

### Regras de Balanceamento

1. **Balanceamento com Cores**: A árvore mantém a propriedade de balanceamento através de rotações e a manipulação das cores dos nós. Quando um nó é inserido ou removido, a árvore pode ficar desequilibrada, mas as cores são ajustadas para restaurar o equilíbrio.
   
2. **Inserção**: Ao inserir um nó, ele é inicialmente colorido de vermelho. Isso pode violar a regra que diz que um nó vermelho não pode ter filhos vermelhos. Se isso ocorrer, são realizadas rotações e alterações de cores para corrigir o desequilíbrio.

3. **Remoção**: Quando um nó é removido, se ele for preto, isso pode causar um desequilíbrio na propriedade de caminho preto. A remoção é seguida de ajustes de cores e rotações para manter o balanceamento da árvore.

### Rotações

As rotações são essenciais para manter o balanceamento da árvore. Existem dois tipos de rotações principais:

- **Rotação à esquerda**: Usada para mover um nó para a esquerda, corrigindo desequilíbrios onde o filho direito é mais pesado.
- **Rotação à direita**: Usada para mover um nó para a direita, corrigindo desequilíbrios onde o filho esquerdo é mais pesado.

As rotações são aplicadas quando a árvore quebra alguma das regras de balanceamento após inserção ou remoção.

---

## Implementação da Árvore Red-Black

### Inserção

A inserção em uma Árvore Red-Black segue o mesmo processo básico de inserção de uma árvore binária de busca. No entanto, após a inserção, é necessário ajustar a árvore para manter o balanceamento, realizando rotações e mudanças de cores conforme necessário.

### Remoção

A remoção em uma Árvore Red-Black também é semelhante à remoção em uma árvore binária de busca. Após a remoção de um nó, a árvore pode precisar de ajustes para restaurar o balanceamento, especialmente se a remoção de um nó preto violar a propriedade de caminho preto.

---

## Teste de Mesa

O teste de mesa é uma excelente maneira de entender o comportamento da árvore durante as operações de inserção e remoção.

### Exemplo de Teste de Mesa

Vamos inserir os valores `[10, 20, 30, 15, 25]` em uma Árvore Red-Black. Vamos acompanhar as operações de inserção e os ajustes necessários para manter o balanceamento.

1. **Inserir 10**:
    - A árvore começa vazia.
    - O nó 10 é inserido e colorido de vermelho.
    - A árvore se torna:
    ```
       10(R)
    ```

2. **Inserir 20**:
    - O nó 20 é inserido à direita de 10.
    - O nó 20 é colorido de vermelho.
    - Não há conflito, pois o nó 10 é preto.
    - A árvore permanece balanceada:
    ```
       10(B)
        \
         20(R)
    ```

3. **Inserir 30**:
    - O nó 30 é inserido à direita de 20.
    - O nó 30 é colorido de vermelho.
    - Agora, temos dois nós vermelhos consecutivos (20 e 30), o que viola a regra de que um nó vermelho não pode ter filhos vermelhos.
    - Realiza-se uma rotação à esquerda no nó 10, resultando na árvore balanceada:
    ```
       20(B)
      /  \
    10(R) 30(R)
    ```

4. **Inserir 15**:
    - O nó 15 é inserido à esquerda de 20 e à direita de 10.
    - O nó 15 é colorido de vermelho.
    - A árvore permanece balanceada:
    ```
       20(B)
      /  \
    10(R) 30(R)
      \
      15(R)
    ```

5. **Inserir 25**:
    - O nó 25 é inserido à esquerda de 30.
    - O nó 25 é colorido de vermelho.
    - A árvore permanece balanceada, mas as cores e a estrutura podem precisar ser ajustadas conforme a inserção.

---

## Complexidade das Operações

1. **Inserção**: A inserção em uma Árvore Red-Black tem uma complexidade de tempo O(log n). Embora a inserção requeira algumas rotações e mudanças de cores, a altura da árvore nunca excede O(log n), garantindo que as operações sejam eficientes.

2. **Remoção**: A remoção também tem uma complexidade de O(log n). Embora o processo de remoção possa exigir a atualização de cores e a aplicação de rotações, a altura da árvore é logarítmica, o que mantém a eficiência.

3. **Pesquisa**: A pesquisa em uma Árvore Red-Black também tem complexidade O(log n), já que a árvore é balanceada e a altura é mantida logarítmica.

---

## Exemplo de Código

Aqui está um exemplo básico de implementação de uma Árvore Red-Black em Java:

```java
class No {
    int valor;
    No esq, dir, pai;
    boolean cor;  // true para vermelho, false para preto

    public No(int valor) {
        this.valor = valor;
        this.cor = true;  // Inicialmente vermelho
        this.esq = this.dir = this.pai = null;
    }
}

class ArvoreRedBlack {
    private No raiz;
    private No TNULL;

    public ArvoreRedBlack() {
        TNULL = new No(0);
        TNULL.cor = false;
        raiz = TNULL;
    }

    // Rotação à esquerda
    private void rotacaoEsquerda(No x) {
        No y = x.dir;
        x.dir = y.esq;
        if (y.esq != TNULL) {
            y.esq.pai = x;
        }
        y.pai = x.pai;
        if (x.pai == null) {
            raiz = y;
        } else if (x == x.pai.esq) {
            x.pai.esq = y;
        } else {
            x.pai.dir = y;
        }
        y.esq = x;
        x.pai = y;
    }

    // Rotação à direita
    private void rotacaoDireita(No x) {
        No y = x.esq;
        x.esq = y.dir;
        if (y.dir != TNULL) {
            y.dir.pai = x;
        }
        y.pai = x.pai;
        if (x.pai == null) {
            raiz = y;
        } else if (x == x.pai.dir) {
            x.pai.dir = y;
        } else {
            x.pai.esq = y;
        }
        y.dir = x;
        x.pai = y;
    }

    // Inserção
    public void inserir(int valor) {
        No novoNo = new No(valor);
        novoNo.pai = null;
        novoNo.valor = valor;
        novoNo.esq = TNULL;
        novoNo.dir = TNULL;
        novoNo.cor = true;  // Nó novo é sempre vermelho

        No y = null;
        No x = raiz;

        while (x != TNULL) {
            y = x;
            if (novoNo.valor < x.valor) {
                x = x.esq;
            } else {
                x = x.dir;
            }
        }

        novoNo.pai = y;
        if (y == null) {
            raiz = novoNo;
        } else if (novoNo.valor < y.valor) {
            y.esq = novoNo;
        } else {
            y.dir = novoNo;
        }

        if (novoNo.pai == null) {
            novoNo.cor = false;
            return;
        }

        if (novoNo.pai.pai == null) {
            return;
        }

        fixarInsercao(novoNo);
    }

    // Corrige a árvore após a inserção
    private void fixarInsercao(No k) {
        No u;
        while

 (k.pai.cor == true) {
            if (k.pai == k.pai.pai.dir) {
                u = k.pai.pai.esq;
                if (u.cor == true) {
                    u.cor = false;
                    k.pai.cor = false;
                    k.pai.pai.cor = true;
                    k = k.pai.pai;
                } else {
                    if (k == k.pai.esq) {
                        k = k.pai;
                        rotacaoDireita(k);
                    }
                    k.pai.cor = false;
                    k.pai.pai.cor = true;
                    rotacaoEsquerda(k.pai.pai);
                }
            } else {
                u = k.pai.pai.dir;
                if (u.cor == true) {
                    u.cor = false;
                    k.pai.cor = false;
                    k.pai.pai.cor = true;
                    k = k.pai.pai;
                } else {
                    if (k == k.pai.dir) {
                        k = k.pai;
                        rotacaoEsquerda(k);
                    }
                    k.pai.cor = false;
                    k.pai.pai.cor = true;
                    rotacaoDireita(k.pai.pai);
                }
            }
            if (k == raiz) {
                break;
            }
        }
        raiz.cor = false;
    }

    // Outros métodos (exclusão, busca, etc.) podem ser adicionados
}

```

---

## Conclusão

A Árvore Red-Black é uma estrutura de dados eficiente que mantém o balanceamento através de propriedades rigorosas, garantindo que as operações de inserção, remoção e busca sejam realizadas em tempo logarítmico. Ela é amplamente utilizada em implementações de bibliotecas padrão e em sistemas que requerem operações rápidas em grandes conjuntos de dados.

