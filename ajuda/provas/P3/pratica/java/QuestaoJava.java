/*
Marcela recebeu como trabalho de Algoritmos a tarefa de fazer um programa que implemente uma
Árvore Binária de Pesquisa (ou Busca). O Programa deve aceitar os seguintes comandos:

I n: Insere na árvore binária de pesquisa o elemento n.
INFIXA: lista os elementos já cadastrado segundo o percurso infixo
PREFIXA: lista os elementos já cadastrado segundo o percurso prefixo
POSFIXA: lista os elementos já cadastrado segundo o percurso posfixo
P n: pesquisa se o elemento n existe ou não.

A qualquer momento pode-se inserir um elemento, visitar os elementos previamente inseridos na
ordem infixa, prefixa ou posfixa ou ainda procurar por um elemento na árvore para saber se o
elemento existe ou não.


Entrada
A entrada contém N operações utilizando letras (A-Z,a-z) sobre uma árvore binária de Busca,
que inicialmente se encontra vazia. A primeira linha de entrada contém a inserção de algum
elemento. As demais linhas de entrada podem conter quaiquer um dos comandos descritos acima,
conforme exemplo abaixo. O final da entrada é determinado pelo final de arquivo (EOF).

Obs: Considere que não serão inseridos elementos repetidos na árvore.


Saída
Cada linha de entrada, com exceção das linhas que contém o comando "I", deve produzir uma
linha de saída. A saída deve ser de acordo com o exemplo fornecido abaixo. Não deve haver
espaço em branco após o último caractere de cada linha, caso contrário, sua submissão receberá
Presentation Error.
*/

import java.util.Scanner;

class No{
    public char elemento;
    public No esq, dir;

    public No(){
        this('\0');
    }

    public No(char elemento){
        this.elemento = elemento;
        this.dir = null;
        this.esq = null;
    }
}

class Arvore{
    private No raiz;
    private int cont;   // Contador para tratar o espaço no final da impressao do caminhar que
                        // está dando erro no verde

    public Arvore(){
        raiz = new No();
        cont = 0;
    }

    // Inserção
    public void inserir(char carac) throws Exception {
        raiz = inserir(carac, raiz);
        cont++;
    }

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

    // Pesquisa
    public boolean pesquisar(char carac) {
        return pesquisar(carac, raiz);
    }

    public boolean pesquisar(char carac, No i) {
        boolean resp;

        if (i == null) {
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

    // Caminhamento Central
    public void caminharCentral(){
        caminharCentral(raiz, 0);   // O '0' será o contador das impressões do caminhar para
    }                               // verificar se todos elementos já foram impressos para
                                    // assim, tratar o espaço no final das impressões

    public void caminharCentral(No i, int numImpressoes) {
        if (i != null) {
            caminharCentral(i.esq, ++numImpressoes);
            if(numImpressoes == cont)
                System.out.print(i.elemento);
            else
                System.out.print(i.elemento + " ");

            caminharCentral(i.dir, ++numImpressoes);
        }
    }

    // Caminhamento Pré-incremento
    public void caminharPre(){
        caminharPre(raiz, 0);   // O '0' será o contador das impressões do caminhar para
    }                               // verificar se todos elementos já foram impressos para
                                    // assim, tratar o espaço no final das impressões

    public void caminharPre(No i, int numImpressoes) {
        if (i != null) {
            if(numImpressoes == cont)
                System.out.print(i.elemento);
            else
                System.out.print(i.elemento + " ");
                
            caminharPre(i.esq, ++numImpressoes);
            caminharPre(i.dir, ++numImpressoes);
        }
    }

    // Caminhamento Pós-incremento
    public void caminharPos(){
        caminharPos(raiz, 0);   // O '0' será o contador das impressões do caminhar para
    }                               // verificar se todos elementos já foram impressos para
                                    // assim, tratar o espaço no final das impressões

    public void caminharPos(No i, int numImpressoes) {
        if (i != null) {
            caminharPos(i.esq, ++numImpressoes);
            caminharPos(i.dir, ++numImpressoes);
            if(numImpressoes == cont + 1)
                System.out.print(i.elemento);
            else
                System.out.print(i.elemento + " ");
        }
    }
}

public class QuestaoJava{
    static public void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Arvore ab = new Arvore();

        String entrada;

        while(sc.hasNext()){
            entrada = sc.nextLine();

            if(entrada.charAt(0) == 'I' && entrada.charAt(1) == ' '){
                ab.inserir(entrada.charAt(2));
            } else if(entrada.equals("INFIXA")){
                ab.caminharCentral();
                System.out.println();
            } else if(entrada.equals("PREFIXA")){
                ab.caminharPre();
                System.out.println();
            } else if(entrada.equals("POSFIXA")){
                ab.caminharPos();
                System.out.println();
            } else { // if (entrada.charAt(0) == 'P' && entrada.charAt(1) == ' ')
                if(ab.pesquisar(entrada.charAt(2))){
                    System.out.println(entrada.charAt(2) + " existe");
                } else {
                    System.out.println(entrada.charAt(2) + " nao existe");
                }
            }
        }

        sc.close();
    }
}