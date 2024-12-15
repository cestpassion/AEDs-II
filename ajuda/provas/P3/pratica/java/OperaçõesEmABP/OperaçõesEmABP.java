/* JAVA [PROVA 03] Operações em ABP
 * 
 * - Descrição:
 * 
 * Marcela recebeu como trabalho de Algoritmos a tarefa de fazer um programa que implemente uma Árvore Binária de
 * Pesquisa (ou Busca). O Programa deve aceitar os seguintes comandos:
 * 
 * • I n: Insere na árvore binária de pesquisa o elemento n.
 * • INFIXA: lista os elementos já cadastrado segundo o percurso infixo
 * • PREFIXA: lista os elementos já cadastrado segundo o percurso prefixo
 * • POSFIXA: lista os elementos já cadastrado segundo o percurso posfixo
 * • P n: pesquisa se o elemento n existe ou não.
 * 
 * A qualquer momento pode-se inserir um elemento, visitar os elementos previamente inseridos na ordem infixa,
 * prefixa ou posfixa ou ainda procurar por um elemento na árvore para saber se o elemento existe ou não.
 * 
 * 
 * - Entrada:
 * 
 * A entrada contém N operações utilizando letras (A-Z,a-z) sobre uma árvore binária de Busca, que inicialmente se
 * encontra vazia.
 * A primeira linha de entrada contém a inserção de algum elemento.
 * As demais linhas de entrada podem conter quaiquer um dos comandos descritos acima.
 * O final da entrada é determinado pelo final de arquivo (EOF).
 * 
 * Obs: Considere que não serão inseridos elementos repetidos na árvore.
 * 
 * 
 * - Saída:
 * 
 * Cada linha de entrada, com exceção das linhas que contém o comando "I", deve produzir uma linha de saída.
 * A saída Não deve haver espaço em branco após o último caractere de cada linha, caso contrário, sua submissão
 * receberá Presentation Error.
 */

/**
 * JAVA [PROVA 03] Operações em ABP
 * 
 * @author Bruna Furtado da Fonseca
 * @version 1.0, 2024-12-12
 */

import java.util.Scanner;

/**
 * Classe que representa um nó de uma árvore binária.
 */
class No {
    public char elemento;
    public No esq, dir;

    /**
     * Construtor padrão que inicializa o nó com um caractere nulo.
     */
    public No() {
        this('\0');
    }

    /**
     * Construtor que inicializa o nó com um caractere específico.
     * 
     * @param elemento o caractere a ser armazenado no nó.
     */
    public No(char elemento) {
        this.elemento = elemento;
        this.dir = null;
        this.esq = null;
    }
}

/**
 * Classe que representa uma árvore binária de caracteres.
 */
class ArvoreBinaria {
    private No raiz;
    private int cont; // Contador para controlar o espaço final na impressão do caminhamento.

    /**
     * Construtor padrão que inicializa a árvore com um nó raiz vazio.
     */
    public ArvoreBinaria() {
        raiz = new No();
        cont = 0;
    }

    /**
     * Método auxiliar para inserção de um caractere na árvore binária.
     * 
     * @param carac o caractere a ser inserido.
     * @throws Exception se o caractere já estiver presente na árvore.
     */
    public void inserir(char carac) throws Exception {
        raiz = inserir(carac, raiz);
        cont++;
    }

    /**
     * Insere um caractere na árvore binária.
     * 
     * @param carac o caractere a ser inserido.
     * @param i     o nó atual da recursão.
     * @return o nó atualizado após a inserção.
     * @throws Exception se o caractere já estiver presente na árvore.
     */
    public No inserir(char carac, No i) throws Exception {
        if (i == null || i.elemento == '\0') {
            i = new No(carac);
        } else if (carac < i.elemento) {
            i.esq = inserir(carac, i.esq);
        } else if (carac > i.elemento) {
            i.dir = inserir(carac, i.dir);
        } else {
            throw new Exception("Erro!");
        }
        return i;
    }

    /**
     * Método auxiliar para pesquisa de um caractere na árvore binária.
     * 
     * @param carac o caractere a ser pesquisado.
     * @return true se o caractere estiver na árvore, false caso contrário.
     */
    public boolean pesquisar(char carac) {
        return pesquisar(carac, raiz);
    }

    /**
     * Pesquisa um caractere na árvore binária.
     * 
     * @param carac o caractere a ser pesquisado.
     * @param i     o nó atual da recursão.
     * @return true se o caractere estiver no nó ou seus descendentes, false caso contrário.
     */
    public boolean pesquisar(char carac, No i) {
        boolean resp;

        if (i == null || i.elemento == '\0') {
            resp = false;
        } else if (carac == i.elemento) {
            resp = true;
        } else if (carac < i.elemento) {
            resp = pesquisar(carac, i.esq);
        } else {
            resp = pesquisar(carac, i.dir);
        }
        return resp;
    }

    /**
     * Método auxiliar para o caminhamento central.
     */
    public void caminharCentral() {
        caminharCentral(raiz, 0); // O '0' será o contador das impressões do já caminhar para  
    }                                           // verificar se todos elementos foram impressos, e assim,
                                                // tratar o espaço no final das impressões.

    /**
     * Realiza o caminhamento central na árvore binária.
     * 
     * @param i             o nó atual da recursão.
     * @param numImpressoes contador de elementos já impressos.
     */
    public void caminharCentral(No i, int numImpressoes) {
        if (i != null) {
            caminharCentral(i.esq, ++numImpressoes);
            if (numImpressoes == cont)
                System.out.print(i.elemento);
            else
                System.out.print(i.elemento + " ");

            caminharCentral(i.dir, ++numImpressoes);
        }
    }

    /**
     * Método auxiliar para o caminhamento pré-ordem.
     */
    public void caminharPre() {
        caminharPre(raiz, 0); // O '0' será o contador das impressões do já caminhar para 
    }                                       // verificar se todos elementos foram impressos, e assim, assim,
                                            // tratar o espaço no final das impressões.

    /**
     * Realiza o caminhamento pré-ordem na árvore binária.
     * 
     * @param i             o nó atual da recursão.
     * @param numImpressoes contador de elementos já impressos.
     */
    public void caminharPre(No i, int numImpressoes) {
        if (i != null) {
            if (numImpressoes == cont)
                System.out.print(i.elemento);
            else
                System.out.print(i.elemento + " ");

            caminharPre(i.esq, ++numImpressoes);
            caminharPre(i.dir, ++numImpressoes);
        }
    }

    /**
     * Método auxiliar para o caminhamento pós-ordem.
     */
    public void caminharPos() {
        caminharPos(raiz, 0); // O '0' será o contador das impressões do já caminhar para 
    }                                       // verificar se todos elementos foram impressos, e assim, assim,
                                            // tratar o espaço no final das impressões.

    /**
     * Realiza o caminhamento pós-ordem na árvore binária.
     * 
     * @param i             o nó atual da recursão.
     * @param numImpressoes contador de elementos já impressos.
     */
    public void caminharPos(No i, int numImpressoes) {
        if (i != null) {
            caminharPos(i.esq, ++numImpressoes);
            caminharPos(i.dir, ++numImpressoes);
            if (numImpressoes == cont + 1)
                System.out.print(i.elemento);
            else
                System.out.print(i.elemento + " ");
        }
    }
}

/**
 * Classe principal que realiza operações em uma árvore binária de pesquisa.
 */
public class OperaçõesEmABP {
    /**
     * Método principal que lê comandos e realiza operações na árvore binária.
     * 
     * @param args argumentos de linha de comando.
     * @throws Exception se ocorrer algum erro durante a execução.
     */
    static public void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        ArvoreBinaria ab = new ArvoreBinaria();
        String entrada;

        while (sc.hasNext()) {
            entrada = sc.nextLine();

            if (entrada.charAt(0) == 'I' && entrada.charAt(1) == ' ') {
                ab.inserir(entrada.charAt(2));
            } else if (entrada.equals("INFIXA")) {
                ab.caminharCentral();
                System.out.println();
            } else if (entrada.equals("PREFIXA")) {
                ab.caminharPre();
                System.out.println();
            } else if (entrada.equals("POSFIXA")) {
                ab.caminharPos();
                System.out.println();
            } else { // if (entrada.charAt(0) == 'P' && entrada.charAt(1) == ' ')
                if (ab.pesquisar(entrada.charAt(2))) {
                    System.out.println(entrada.charAt(2) + " existe");
                } else {
                    System.out.println(entrada.charAt(2) + " nao existe");
                }
            }
        }
        sc.close();
    }
}