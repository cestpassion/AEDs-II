/* ÁRVORE
 * 
 * - Custo de inserção, remoção e pesquisa PODE ser Θ(lg(n)) comparações 
 *       
 * - Fomada por um conjunto finito de nós (véstices) conectados por arestas 
 * 
 * > O nó 5 é denomidado nó raiz e ele está no nível 0.                                 🠗             _       
 *                                                                           raiz ➔    5             |       
 * > Os nós 3 e 7 são filhos do 5 e esse é pai dos dois primeiros.                   ⬋    ⬊          |       
 *      * Um nó com filho(s) é chamado de NÓ INTERNO e o sem, de FOLHA.            3         7        |   
 *      * Em uma árvore binária, cada nó possui no máximo dois filhos            ⬋  ⬊     ⬋  ⬊      | h=3       
 *                                                                              2     4   6     □     |
 * > Os nós 1, 2 e 4 formam uma subárvore com raiz no nó 3.                   ⬋ ⬊  ⬋ ⬊ ⬋ ⬊         |
 *                                                                           1   □ □   □ □   □        |
 * > Altura (h): maior distância entre um nó e a raiz.                     ⬋ ⬊                       -  
 *                                                                        □   □
 *                   
 * - Arvore Binária de Pesquisa:
 *      > cada nó é maior que todos seus vizinhos à esquerda e menor que todos à direita
 * 
 * - Árvore Binária Completa:                                              
 *      > Cada nó é uma folha OR possui exatamente dois filhos               
 *      > Todos os nós folhas possuem uma altura h                           
 *      > O número de nós internos é 2ʰ – 1                                
 *      > O número de nós folhas é 2ʰ                                  
 *      > O número total de nós é  (2ʰ – 1) + (2ʰ) = 2 ⁽ʰ⁺¹⁾ – 1 
 *           
 *          => Exemplo:            🠗
 *                                 B                   > Cada nó é uma folha OR possui exatamente dois filhos  
 *                             ⬋      ⬊               > Todos os nós folhas possuem uma altura h = 3 (a raiz está no nível zero)
 *                            D         E              > O número de nós internos é 2ʰ – 1 = 2³ – 1 = 7  
 *                        ⬋   ⬊       ⬋   ⬊          > O número de nós folhas é 2ʰ  = 2³ = 8
 *                     1        4      c        6      > O número total de nós é 2⁽ʰ⁺¹⁾ – 1 = 2⁽³⁺¹⁾ – 1 = 15    
 *                   ⬋ ⬊     ⬋ ⬊    ⬋ ⬊     ⬋ ⬊      
 *                 9    2   F    A    7    3   8    5     
 *               ⬋⬊  ⬋⬊  ⬋⬊  ⬋⬊  ⬋⬊  ⬋⬊  ⬋⬊  ⬋⬊    
 *              □  □ □  □ □  □ □  □  □  □ □  □ □  □ □  □  
 * 
 * - Árvore Balanceada:
 *      > Árvore em que para TODOS os nós, a diferença entre a altura de suas árvores da esquerda e da direita sempre
 *        será 0 ou ±1 como, por exemplo:
 * 
 * - Consideração:
 *      > Árvore Binária de Pesquisa (ABP) também é chamada de Árvore Binária de Busca (ABB) ou Binary Search Tree (BST)
 *          * A partir deste ponto, neste material, considera-se que todas as árvores binárias são de pesquisa
 */

/* ÁRVORE - NOTAS
 *
 * - Custo de inserção, remoção e pesquisa PODE ser Θ(lg(n)) comparações.
 * 
 * - Formada por um conjunto finito de nós (vértices) conectados por arestas.
 * 
 * - O nó no nível zero é denomidado raiz.
 * 
 * - O nó superior é denomidado pai e os seguintes são denomidados filhos.
 *      > NÓ INTERNO: nó com filho(s).
 *      > FOLHA: nó sem filho(s).
 *      > Em uma Árvore Binária, cada nó possui no máximo dois filhos.
 * 
 * - Um conjunto de nós após a raiz são formam uma subárvore com a raiz sendo o primeiro nó desse conjunto.
 * 
 * - ALTURA: maior distância entre um nó e a raiz.
 * 
 * - ÁRVORE BINÁRIA DE PESQUISA: Cada nó é maior que todos seus vizinhos à esquerda e menor que todos à direita.
 *      > Os nós vizinhos à ESQUERDA são MENORES
 *      > Os nós vizinhos à DIREITA são MAIORES
 *          * ESQUERDA < DIREITA
 * 
 * - ÁRVORE BINÁRIA COMPLETA:
 *      > Cada nó é uma folha OR possui exatamente dois filhos               
 *      > Todos os nós folhas possuem uma altura h                           
 *      > O número de nós internos é 2ʰ – 1                                
 *      > O número de nós folhas é 2ʰ                                  
 *      > O número total de nós é  (2ʰ – 1) + (2ʰ) = 2 ⁽ʰ⁺¹⁾ – 1  
 * 
 * - ÁRVORE BALANCEADA: Árvore em que para TODOS os nós, a diferença entre a altura de suas árvores da esquerda e da direita
 *                      sempre será 0 ou ±1.
 * 
 * - CONSIDERAÇÃO: Árvore Binária de Pesquisa (ABP) também é chamada de Árvore Binária de Busca (ABB) ou Binary Search Tree (BST)
 *                      * A partir deste ponto, neste material, considera-se que todas as árvores binárias são de pesquisa
 */

/* CLASSE NÓ EM JAVA
 * 
 *      class No{                      elemento
 *          public int elemento;                 〇
 *          public No esq;                 esq ⬋   ⬊ dir
 *          public No dir;                 
 *  
 *          public No(int elemento){
 *              this(elemento, null, null);
 *          }
 * 
 *          public No(int elemento, No esq, No dir){
 *              this.elemento = elemento;
 *              this.esq = esq;
 *              this.dir = dir;
 *          }
 *      }
 */
/* CLASSE ÁRVORE BINÁRIA EM JAVA
 * 
 *      class ArvoreBinaria{
 *          private No raiz;
 * 
 *          public ArvoreBinaria(){
 *              raiz = null;
 *          }
 * 
 *          public void inserir(int x) { ... }
 *          public void inserir(int x, No i) { ... }
 * 
 *          public void inserirPai(int x) { ... }
 *          public void inserirPai(int x, No i, No pai) { ... }
 * 
 *          public boolean pesquisar(int x) { ... }
 *          public boolean pesquisar(int x, No i) { ... }
 * 
 *          public void caminharCentral() { ... }
 *          public void caminharPre() { ... }
 *          public void caminharPos() { ... }
 * 
 *          public void remover(int x) { ... }
 *      }
 */

/* MÉTODO DE INSERÇÃO - Funcionamento Básico
 * 
 *      1. Se a raiz estiver vazia, insere-se o elemento nela
 *      2. Senão, se o novo elemento for MENOR que o da raiz, chama-se recursivamente a inserção para a subárvore da ESQUERDA
 *      3. Senão, se o novo elemento for MAIOR que o da raiz, chama-se recursivamente a inserção para a subárvore da DIREITA
 *      4. Senão, se o novo elemento for IGUAL ao da raiz, não inserir um elemento repetido
 */
/* MÉTODO DE INSERÇÃO - Exemplo
 *
 *      > Inserir, na ordem, os elementos 3, 5, 1, 8, 2, 4, 7 e 6
 * 
 *      1)   🠗          2)   🠗         3)               🠗               4)        🠗                   5)        🠗                                        
 *          |3|              3                          3                         3                             3
 *        ⬋    ⬊         ⬋    ⬊                     ⬋  ⬊                     ⬋  ⬊                         ⬋  ⬊               
 *                               |5|               |1|      5                 1       5                     1       5     
 *                               ⬋  ⬊           ⬋  ⬊     ⬋  ⬊           ⬋  ⬊     ⬋  ⬊               ⬋  ⬊     ⬋  ⬊
 *                                                                                        |8|               |2|         8 
 *                                                                                        ⬋ ⬊             ⬋ ⬊        ⬋ ⬊                                                                          
 *      6)        🠗                      7)        🠗                    8)       🠗                                                  
 *                3                                3                             3               
 *              ⬋  ⬊                            ⬋  ⬊                         ⬋  ⬊                   
 *            1       5                        1       5                     1       5      
 *         ⬋  ⬊     ⬋  ⬊                  ⬋  ⬊     ⬋  ⬊               ⬋  ⬊     ⬋  ⬊                                    
 *             2   |4|    8                     2    4     8                  2    4     8  
 *           ⬋ ⬊  ⬋ ⬊  ⬋ ⬊                 ⬋ ⬊  ⬋ ⬊  ⬋ ⬊              ⬋ ⬊  ⬋ ⬊  ⬋ ⬊   
 *                                                       |7|                            7
 *                                                       ⬋⬊                           ⬋⬊
 *                                                                                   |6|
 */
/* MÉTODO DE INSERÇÃO - IMPLEMENTAÇÃO: Inserção em Java com retorno de referência
 *      
 *      public void inserir(int x) throws Exception{
 *          raiz = inserir(x, raiz);
 *      }
 * 
 *      public No inserir(int x, No i) throws Exception{
 *          if(i == null){
 *              i = new No(x);
 *          } else if(x < i.elemento){
 *              i.esq = inserir(x, i.esq);
 *          } else if(x > i.elemento){
 *              i.dir = inserir(x, i.dir);
 *          } else{
 *              throw new Exception("Erro!");
 *          }
 *          return i;
 *      }
 */
/* MÉTODO DE INSERÇÃO - IMPLEMENTAÇÃO: Inserção em Java com passagem de pai
 * 
 *      public void inserirPai(int x) throws Exception{
 *          if(raiz == null){
 *              raiz = new No(x);
 *          } else if(x < raiz.elemento){
 *              inserirPai(x, raiz.esq, raiz);
 *          } else if(x > raiz.elemento){
 *              inserirPai(x, raiz.dir, raiz);
 *          } else{
 *              throw new Exception("Erro!");
 *          }
 *      }
 * 
 *      public void inserirPai(int x, No i, No pai){
 *          if(i == null){
 *              if(x < pai.elemento){
 *                  pai.esq = new No(x);
 *              } else{
 *                  pai.dir = new No(x);
 *              }
 *          } else if(x < i.elemento){
 *              inserirPai(x, i.esq, i);
 *          } else if(x > i.elemento){
 *              inserirPai(x, i.dir, i);
 *          } else{
 *              throw new Exception("Erro!");
 *          }
 *      }
 */
/* MÉTODO DE INSERÇÃO - Análise de Complexidade da Inserção
 *
 * - Melhor Caso: Θ(1) comparações e acontece, por exemplo, inserindo na raiz
 * 
 * - Pior Caso: Θ(n) comparações e acontece, por exemplo, quando inserimos os elementos na ordem crescente ou decrescente
 * 
 * - Caso Médio: Θ(lg(n)) comparações e acontece, por exemplo, quando inserimos um elemento na folha de uma árvore balanceada.
 *               Lembrando que a altura da árvore balanceada é Θ(lg(n))
 * 
 * OBS: 1. Depende do formato da árvore
 *      2. Na inserção aleatória ≈ 1,39 x lg(n) comparações
 */

/* MÉTODO DE PESQUISA - Funcionamento Básico
 * 
 *      1. Se a raiz estiver vazia, retornar uma PESQUISA NEGATIVA.
 *      2. Senão, se o elemento procurado for IGUAL ao da raiz, retornar uma PESQUISA POSITIVA.
 *      3. Senão, se o elemento procurado for MENOR que o da raiz, char o método de pesquisa para a subárvore da ESQUERDA
 *      4. Senão (elemento procurado é MAIOR que o da raiz), chamar o método de pesquisa para a subárvore da DIREITA
 */
/* MÉTODO DE PESQUISA - Exemplo
 * 
 */
/* MÉTODO DE PESQUISA - IMPLEMENTAÇÃO: Algoritmo em Java
 *
 *      boolean pesquisar(int x){
 *          return pesquisar(x, raiz);
 *      }
 * 
 *      boolean pesquisar(int x, No i){
 *          boolean resp;
 * 
 *          if(i == null){
 *              resp = false
 *          } else if(x == i.elemento){
 *              rest = true;    
 *          } else if(x < i.elemento){
 *              resp = pesquisar(x, i.esq);
 *          } else{
 *              resp = pesquisar(x, i.dir);
 *          }
 *          return resp;
 *      }
 */
/* MÉTODO DE PESQUISA - Análise de complexidade da Pesquisa
 * 
 * - Melhor Caso: Θ(1) comparações e aconetece, por exemplo, na raiz
 * 
 * - Pior Caso: Θ(n) comparações e acontece, por exemplo, quando inserimos os elementos em ordem e o elemento desejado está
 *              na folha
 * 
 * - Médio Caso: Θ(lg(n)) comparações e acontece, por exemplo, quando a árvore está balanceada e procuramos um elemento
 *               localizado em uma das folhas.
 */

/* MÉTODOS DE CAMINHAMENTO
 *                                                                               
 * - Consiste em "caminhar" por todos os nós da árvore                           
 * - Também chamado de percorrer, buscar, visitar, mostrar...                  
 * - Análise de complexidade: Θ(n) visitas                                 
 *                                   
 *                      🠗
 *                      6
 *                  ⬋      ⬊
 *               3             9
 *            ⬋   ⬊         ⬋   ⬊        
 *          1       5       8       10 
 *        ⬋ ⬊     ⬋ ⬊    ⬋ ⬊     ⬋ ⬊      
 *           2     4       7           11
 *          ⬋⬊   ⬋⬊     ⬋⬊          ⬋⬊ 
 * 
 *   => Caminhamento Central ou Em Ordem:            SAÍDA: 1  2  3  4  5  6  7  8  9  10  11             
 *                                                                    
 *      public void caminharCentral(No i){                                
 *          if(i != null){                                              
 *              caminharCentral(i.esq);                                 
 *              System.out.print(i.elemento + " ");             
 *              caminharCentral(i.dir);
 *          }
 *      }
 * 
 *   => Caminhamento Pós-fixado ou Pós-ordem:        SAÍDA: 2  1  4  5  3  7  8  11  10  9  6
 * 
 *      public void caminharPos(No i){
 *          if(i != null){
 *              caminharPos(i.esq);
 *              caminharPos(i.dir);
 *              System.out.print(i.elemento + " ");
 *          }
 *      } 
 * 
 *   => Caminhamento Pré-fixado ou Pré-ordem         SAÍDA: 6  3  1  2  5  4  9  8  7  10 11
 * 
 *      public void caminharPos(No i){
 *          if(i != null){
 *              System.out.print(i.elemento + " ");
 *          }
 *      }
 */

/* MÉTODO DE REMOÇÃO - Funcionamento básico
 * 
 *      1. Se o elemento estiver em uma FOLHA, removê-la
 *      2. Senão, se o elemento estiver em um NÓ INTERMEDIÁRIO COM UM ÚNICO FILHO, remover o nó e fazer que seu pai aponte para seu filho
 *      3. Senão, se o elemento estiver em um NÓ INTERMEDIÁRIO COM DOIS FILHOS, o elemento a ser removido deve ser substituído OU pelo
 *         MAIOR NÓ DA SUBÁRVORE À ESQUERDA OU pelo MENOR NÓ DA SUBÁRVORE À DIREITA
 */
/* MÉTODO MAIOR ELEMENTO
 * 
 * Faça o método int getMaior() que retorna o maior elemento de uma Árvore Binária
 */
/* MÉTODO MENOR ELEMENTO
 * 
 * Faça o método int getMenor() que retorna o maior elemento de uma Árvore Binária
 */
 /* MÉTODO DE REMOÇÃO - IMPLEMENTAÇÃO: Algoritmo em Java
 * 
 *      void remover(int x) throws Exception{
 *          raiz = remover(x, raiz);
 *      }
 * 
 *      void remover(int x, No i) throws Exception{
 *          if(i == null){
 *              throw new Exception("Erro!");
 *          } else if(x < i.elemento){
 *              i.esq = remover(x, i.esq);
 *          }
 *      }
 */
/* MÉTODO DE REMOÇÃO - Funcionamento básico
 * 
 */

/* MÉTODO GET ALTURA DA ÁRVORE
 * 
 * Faça um método que retorna a altura da árvore
 * 
 *      public static getAltura(No i, int altura){
 *          if(i == null){
 *              altura--;
 *          } else{
 *              int alturaEsq = getAçtura(i.esq, altura + 1);
 *              int alturaDir = getAltura(i.dir, altura + 1);
 *              altura = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
 *          }
 *          return altura;
 *      }
 */

/* MÉTODO SOMA
 * 
 * Faça um método que retorne a soma dos elementos existentes na árvore
 */

/* MÉTODO NÚMERO DE ELEMENTOS PARES
 * 
 * Faça um método que retorne o número de elementos pares existentes na árvore
 */

/* MÉTODO VERIFICA SE DUAS ÁRVORES SÃO IGUAIS
 * 
 * Faça um método estático que recebe dois objetos do tipo árvore binária e retorne um booleano indicando se as duas árvores são iguais
 */

/* MÉTODO VERIFICA SE HÁ ALGUM NÚMERO DIVIZIVEL POR 11
 * 
 * Faça um método que retorna true se a árvore contém algum número divisível por onze
 */

/* MÉTODO 
 * 
 * 
 */

/* MÉTODO 
 * 
 * 
 */

/* MÉTODO ALGORITMO DE ORDENAÇÃO TREESORT
 * 
 * Um algoritmo de ordenação é o TreeSort que insere os elementos do array em uma árvore binária e utiliza um "caminhar"
 * para ordenar os elementos do array. Implemente o TreeSort e faça a análise de complexidade do mesmO
 */

/*
 * 
 * Faça o método No toAB(Celula p1, CelulaDupla p2) que recebe o nó cabeça de uma lista simples e o de outra dupla.
 * Em seguida, crie uma árvore binária contendo os elementos intercalados das duas listas e retorne o endereço do nó raiz da árvore criada
 */

/* EXERCÍCIO:
 * 
 * Insira 100000 elementos de forma aleatória.
 * Para cada inserção, mostre na tela:
 *      > o número de elementos da árvore
 *      > o logaritmo (base 2) desse número
 *      > A altura da árvore
 * 
 */

 class No{
    public int elemento;
    public No esq;
    public No dir;

    public No(int elemento){
        this(elemento, null, null);
    }

    public No(int elemento, No esq, No dir){
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
}

class ArvoreBinaria{
    private No raiz;

    public ArvoreBinaria(){
        raiz = null;
    }

    // Inserção em Java com Retorno de Referência
    void inserir(int x) throws Exception{
        raiz = inserir(x, raiz);
    }    

    No inserir(int x, No i) throws Exception{
        if(i == null){
            i = new No(x);
        } else if(x < i.elemento){
            i.esq = inserir(x, i.esq);
        } else if(x > i.elemento){
            i.dir = inserir(x, i.dir);
        } else {
            throw new Exception("Erro!");
        }

        return i;
    }

    // Inserção em Java com passagem de pai
    void inserirPai(int x) throws Exception{
        if(raiz == null){
            raiz = new No(x);
        } else if(x < raiz.elemento){
            inserirPai(x, raiz.esq, raiz);
        } else if(x > raiz.elemento){
            inserirPai(x, raiz.dir, raiz);
        } else{
            throw new Exception("Erro!");
        }
    }

    void inserirPai(int x, No i, No pai) throws Exception{
        if(i == null){
            if(x < pai.elemento){
                pai.esq = new No(x);
            } else{
                pai.dir = new No(x);
            }
        } else if(x < i.elemento){
            inserirPai(x, i.esq, i);
        } else if(x > i.elemento){
            inserirPai(x, i.dir, i);
        } else{
            throw new Exception("Erro!");
        }
    }
}

public class Arvore {
    
}
