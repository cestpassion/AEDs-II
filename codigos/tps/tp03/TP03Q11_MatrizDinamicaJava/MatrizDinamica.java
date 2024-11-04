/*
 * Complete o código da classe matriz dinâmica visto na sala de aula.
 * 
 * A primeira tarefa consiste em, no construtor da classe Matriz, dados os números de linha e coluna, fazer as devidas
 * alocações de células.
 * 
 * As demais tarefas são as implementações dos métodos:
 *  - Matriz soma(Matriz)
 *  - Matriz multiplicacao(Matriz)
 *  - void mostrarDiagonalPrincipal()
 *  - void mostrarDiagonalSecundaria(). 
 * 
 * ENTRADA:
 * 
 * - A entrada padrão é composta por vários casos de teste sendo que o número de casos é um inteiro contido na primeira
 *   linha da entrada. 
 * 
 * - Em seguida, temos cada um dos casos de teste. Cada caso é composto por duas matrizes.
 * 
 * - Para cada caso de teste, temos que suas duas primeiras linhas contêm um número inteiro cada um representando os
 *   números de linhas e de colunas da primeira matriz, respectivamente.
 * 
 * - Em seguida, temos os elementos da primeira matriz que estão representados nas próximas l linhas onde l é o número de
 *   linhas dessa matriz.
 * 
 * - Cada uma dessas linhas têm c colunas onde c é o número de colunas dessa matriz.
 * 
 * - Nas duas linhas seguintes, temos os números de linhas e colunas da segunda matriz do caso de teste.
 * 
 * - As l2 linhas seguintes têm c2 colunas contendo os elementos da segunda matriz.
 * 
 * - l2 e c2 correspondem aos números de linhas e colunas da segunda matriz do caso de teste, respectivamente.
 * 
 * SAÍDA:
 * 
 * - A saída padrão contém várias linhas para cada caso de teste.
 * 
 *   > As duas primeiras linhas de saída de um caso de teste correspondem às diagonais principal e secundaria da primeira
 *     matriz, respectivamente.
 *
 *   > As demais ls linhas de um caso de teste correspondem as linhas matriz obtida pela soma das duas matrizes do caso
 *     de teste sendo que essas linhas contêm cs colunas referentes às colunas da matriz de soma. Da mesma forma, as
 *     linhas seguintes do caso teste contêm lm linhas com cm colunas representando os elementos da matriz de
 *     multiplicação onde lm e cm são os números de linhas e colunas da matriz de multiplicação.
 */

/*
 * INFO:
 * 
 */

/**
 * Matriz Dinâmica em Java
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

import java.util.Scanner;

/**
 * Classe que representa uma célula da matriz com ponteiros para células
 * adjacentes (cima, baixo, esquerda e direita).
 * Cada célula armazena um valor int.
 */
class Celula {
    public int elemento; // valor armazenado na célula
    public Celula inf; // Ponteiro para a célula inferior
    public Celula sup; // Ponteiro para a célula superior
    public Celula esq; // Ponteiro para a célula à esquerda
    public Celula dir; // Ponteiro para a célula à direita

    /**
     * Construtor padrão que inicializa o elemento da célula como null.
     */
    public Celula() {
        this(0);
    }

    /**
     * Construtor que inicializa o valor da célula com o valor fornecido.
     * 
     * @param elemento valor a ser armazenado na célula.
     */
    public Celula(int elemento) {
        this(elemento, null, null, null, null);
    }

    /**
     * Construtor completo que inicializa todos os valores e os ponteiros da célula.
     * 
     * @param elemento valor a ser armazenado na célula.
     * @param inf      Ponteiro para a célula inferior.
     * @param sup      Ponteiro para a célula superior.
     * @param esq      Ponteiro para a célula à esquerda.
     * @param dir      Ponteiro para a célula à direita.
     */
    public Celula(int elemento, Celula inf, Celula sup, Celula esq, Celula dir) {
        this.elemento = elemento;
        this.inf = inf;
        this.sup = sup;
        this.esq = esq;
        this.dir = dir;
    }
}

/**
 * Classe que representa uma matriz bidimensional utilizando células duplamente
 * encadeadas.
 * Permite operações de soma e multiplicação de matrizes, além de exibir as
 * diagonais principal e secundária.
 */
class DinamicMatriz {
    private Celula start; // Célula inicial da matriz, localizada no canto superior esquerdo
    private int row; // Número de linhas da matriz
    private int column; // Número de colunas da matriz

    /**
     * Construtor padrão que cria uma matriz 3x3 com células inicializadas.
     */
    public DinamicMatriz() {
        this(3, 3);
    }

    /**
     * Construtor que cria uma matriz com o número de linhas e colunas especificado.
     * As células da matriz são duplamente encadeadas em todas as direções.
     * 
     * @param row  Número de linhas da matriz.
     * @param column Número de colunas da matriz.
     */
    public DinamicMatriz(int row, int column) {
        this.row = row;
        this.column = column;

        // Alocar a matriz com this.row linhas e this.column colunas
        // Criação e ligação das células
        start = new Celula(); // Inicializa a célula de início
        Celula rowCurrent = start; // Controla a célula inicial de cada linha

        for (int i = 0; i < row; i++) { // Percorre todas as linhas
            Celula columnCurrent = rowCurrent; // Controla a célula de cada coluna dentro da linha

            for (int j = 1; j < column; j++) { // Cria e liga células na linha
                columnCurrent.dir = new Celula(); // Cria célula à direita
                columnCurrent.dir.esq = columnCurrent; // Liga célula à esquerda
                columnCurrent = columnCurrent.dir; // Avança para a próxima célula na linha
            }
            if (i < row - 1) { // Caso não seja a última linha, cria uma nova linha
                rowCurrent.inf = new Celula(); // Cria célula inferior para a próxima linha
                rowCurrent.inf.sup = rowCurrent; // Liga célula superior
                rowCurrent = rowCurrent.inf; // Avança para a próxima linha
            }
        }
    }

    /**
     * Soma esta matriz com outra matriz fornecida.
     * Ambas as matrizes devem ter as mesmas dimensões para que a operação seja realizada.
     * 
     * @param otheMatriz Matriz a ser somada com a matriz atual.
     * @return Matriz resultante da soma ou null se as matrizes tiverem dimensões incompatíveis.
     */
    public DinamicMatriz sum(DinamicMatriz otheMatriz){
        // Verifica se as dimensões das duas matrizes são compatíveis para soma
        if (this.row != otheMatriz.row || this.column != otheMatriz.column) return null;

        // Cria uma nova matriz para armazenar o resultado
        DinamicMatriz result = new DinamicMatriz(this.row, this.column);
        Celula aRow = this.start, bRow = otheMatriz.start, cRow = result.start;

        // Percorre todas as células da matriz
        for (int i = 0; i < row; i++) {
            Celula a = aRow, b = bRow, c = cRow;
            for (int j = 0; j < column; j++) {
                c.elemento = a.elemento + b.elemento; // Soma os elementos correspondentes
                a = a.dir; // Move para a próxima célula na linha de `this`
                b = b.dir; // Move para a próxima célula na linha de `otherMatriz`
                c = c.dir; // Move para a próxima célula na linha da matriz resposta
            }
            aRow = aRow.inf; // Move para a próxima linha de `this`
            bRow = bRow.inf; // Move para a próxima linha de `otherMatriz`
            cRow = cRow.inf; // Move para a próxima linha da matriz resposta
        }
        return result; // Retorna a matriz com o resultado da soma
    }

    /**
     * Multiplica esta matriz por outra matriz fornecida.
     * A multiplicação só é possível se o número de colunas da matriz atual for igual ao número de linhas da matriz fornecida.
     * 
     * @param otheMatriz Matriz a ser multiplicada pela matriz atual.
     * @return Matriz resultante da multiplicação ou null se as dimensões forem incompatíveis.
     */
    public DinamicMatriz multiplication(DinamicMatriz otheMatriz) {
        // Verifica se as dimensões são compatíveis para multiplicação (coluna de `this` == linha de `otherMatriz`)
        if (this.column != otheMatriz.row) return null;

        // Cria uma nova matriz para armazenar o resultado da multiplicação
        DinamicMatriz result = new DinamicMatriz(this.row, otheMatriz.row);
        Celula rowA = this.start;

        // Percorre todas as linhas da matriz `this`
        for (int i = 0; i < row; i++) {
            Celula columnB = otheMatriz.start; // Inicia a multiplicação da linha de `this` com cada coluna de `m`
            Celula resultLinha = result.start;
            for (int j = 0; j < otheMatriz.column; j++) {
                Celula a = rowA, b = columnB;
                int sum = 0;
                for (int k = 0; k < this.column; k++) { // Calcula o produto escalar
                    sum += a.elemento * b.elemento;
                    a = a.dir; // Avança para o próximo elemento na linha de `this`
                    b = b.inf; // Avança para o próximo elemento na coluna de `otherMatriz`
                }
                resultLinha.elemento = sum; // Atribui o resultado à célula correspondente em resp
                resultLinha = resultLinha.dir; // Avança para a próxima célula em resp
                columnB = columnB.dir; // Avança para a próxima coluna em `otherMatriz`
            }
            rowA = rowA.inf; // Avança para a próxima linha de `this`
        }
        return result; // Retorna a matriz resultante da multiplicação
}
    
    /**
     * Verifica se a matriz é quadrada.
     * 
     * @return true se a matriz for quadrada (número de linhas igual ao de colunas), false caso contrário.
     */
    public boolean isSquare() {
        return this.row == this.column;
    }

    /**
     * Exibe os elementos da diagonal principal da matriz.
     * Só é possível para matrizes quadradas.
     */
    public void showMainDiagonal() {
        if (isSquare()) { // Verifica se a matriz é quadrada
            Celula current = start; // Inicia a partir da célula no canto superior esquerdo
            while (current != null) {
                System.out.print(current.elemento + " "); // Imprime o elemento da diagonal
                if (current.inf != null) current = current.inf.dir; // Avança para o próximo elemento na diagonal
                else break;
            }
            System.out.println();
        }
    }

    /**
     * Exibe os elementos da diagonal secundária da matriz.
     * Só é possível para matrizes quadradas.
     */
    public void showSecondaryDiagonal() {
        if (isSquare()) { // Verifica se a matriz é quadrada
            Celula current = start;
            while (current.dir != null) current = current.dir; // Move para a célula mais à direita da primeira linha
            
            while (current != null) {
                System.out.print(current.elemento + " "); // Imprime o elemento da diagonal secundária
                if (current.inf != null) current = current.inf.esq; // Move para o próximo elemento na diagonal secundária
                else break;
            }
            System.out.println();
        }
    }
}

public class MatrizDinamica {
    public static void main(String[] args) throws NumberFormatException, Exception {
        Scanner sc = new Scanner(System.in);
        
        sc.close();
    }
}