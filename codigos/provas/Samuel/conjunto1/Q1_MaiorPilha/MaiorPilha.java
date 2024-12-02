/*
 * Questão 1
 * 
 * Considere uma estrutura Lista de Pilhas (ilustrada e codificada abaixo). Crie método CelulaLista maiorPilha()
 * na classe Lista, que retorna a Célula da Lista que aponta para a pilha com o maior número de elementos. Caso
 * tenham pilhas do mesmo tamanho, retornar a primeira que aparece.
 * 
 *  class Lista{                        inicio
 *      CelulaLista inicio;               ↓
 *      CelulaLista fim;                _______     _______     _______     _______ 
 *  }                                  | topo ||⟼ | topo ||⟼ | topo ||⟼ | topo ||⟼ ☰
 *                                      -------     -------     -------     -------
 *  class CelulaLista{                    ↓           ↓           ↓           ↓
 *      CelulaPilha topo;               _______     _______     _______     _______ 
 *      CelulaLista prox;              |      ||⟼ |      ||⟼ |      ||⟼ |      ||
 *  }                                   -------     -------     -------     -------
 *                                      _______↧    _______↧    _______↧           ↧                        
 *  class CelulaPilha{                 |      ||⟼ |      ||⟼ |      ||          ☰
 *      int elemento;                   -------     -------     -------           
 *      CelulaPilha prox;               _______↧                       ↧
 *  }                                  |      ||                      ☰
 *                                      -------                   
 *                                             ↧
 *                                            ☰
 * 
 * Resposta:
 * 
 * public CelulaLista maiorPilha(){
 *     CelulaLista celulaAtual;
 *     CelulaLista maiorP = inicio.prox;
 *
 *     for(celulaAtual = inicio.prox.prox; celulaAtual != null; celulaAtual = celulaAtual.prox){
 *         if(tamPilha(celulaAtual) > tamPilha(maiorP))
 *             maiorP = celulaAtual;
 *     }
 *     return maiorP;
 * }
 * 
 */

/**
 * Maior Pilha em uma Lista
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

import java.util.Scanner;
import java.util.Random;

/**
 * Classe que representa uma célula de uma pilha.
 */
class CelulaPilha{
    public int elemento;
    public CelulaPilha prox;

    /**
     * Construtor padrão que inicializa a célula com o elemento -1.
     */
    public CelulaPilha(){
        this(-1);
    }

    /**
     * Construtor que inicializa a célula com o elemento fornecido.
     * @param elemento Elemento a ser armazenado na célula.
     */
    public CelulaPilha(int elemento){
        this.elemento = elemento;
        this.prox = null;
    }
}

/**
 * Classe que representa uma célula de uma lista contendo uma pilha.
 */
class CelulaLista{
    public CelulaPilha topo;
    public CelulaLista prox;

    /**
     * Construtor padrão que inicializa a célula da lista com uma pilha vazia.
     */
    public CelulaLista(){
        this(null);
    }

    /**
     * Construtor que inicializa a célula com uma pilha fornecida.
     * @param topo Pilha a ser armazenada na célula da lista.
     */
    public CelulaLista(CelulaPilha topo){
        this.topo = topo;
        this.prox = null;
    }
}

/**
 * Classe que representa uma lista de pilhas.
 */
class Lista{
    private CelulaLista inicio;
    private CelulaLista fim;

    /**
     * Construtor que inicializa uma lista vazia.
     */
    public Lista(){
       inicio = new CelulaLista();
       fim = inicio; 
    }

    /**
     * Insere uma pilha no início da lista.
     * @param topo A pilha a ser inserida no início.
     */
    public void inserirInicio(CelulaPilha topo){
        CelulaLista tmp = new CelulaLista(topo);
        tmp.prox = inicio.prox;
        inicio.prox = tmp;

        if(inicio == fim)
            fim = tmp;

        tmp = null;
    }

    /**
     * Insere uma pilha no fim da lista.
     * @param topo A pilha a ser inserida no fim.
     */
    public void inserirFim(CelulaPilha topo){
        fim.prox = new CelulaLista(topo);
        fim = fim.prox; 
    }

    /**
     * Insere uma pilha em uma posição específica da lista.
     * @param topo A pilha a ser inserida.
     * @param pos A posição onde a pilha deve ser inserida.
     * @throws Exception Se a posição for inválida.
     */
    public void inserir(CelulaPilha topo, int pos) throws Exception{
        int tam = tamLista();

        if(pos < 0 || pos >= tam){
            throw new Exception("Erro! posição invalida");
        } else if(pos == 0){
            inserirInicio(topo);
        } else if(pos == tam - 1){
            inserirFim(topo);
        } else{
            CelulaLista i = inicio.prox;
            for(int j = 0; j < pos; j++, i = i.prox);

            CelulaLista tmp = new CelulaLista(topo);
            tmp.prox = i.prox;
            i.prox = tmp;

            tmp = i = null;
        }
    }

    /**
     * Remove a pilha do início da lista.
     * @return A pilha removida.
     * @throws Exception Se a lista estiver vazia.
     */
    public CelulaPilha removerInicio() throws Exception{
        if(inicio == fim)
            throw new Exception("Erro! Não há pilhas para remover.");

        CelulaLista tmp = inicio;
        inicio = inicio.prox;
        CelulaPilha topoRemov = inicio.topo;

        inicio.topo = null;
        tmp.prox = null;
        tmp = null;
        
        return topoRemov;
    }

    /**
     * Remove a pilha do fim da lista.
     * @return A pilha removida.
     * @throws Exception Se a lista estiver vazia.
     */
    public CelulaPilha removerFim() throws Exception{
        if(inicio == fim)
            throw new Exception("Erro! Não há pilhas para remover.");

        CelulaLista i;
        for(i = inicio; i != fim; i = i.prox);

        CelulaPilha topoRemov = fim.topo;
        fim = i;
        i = fim.prox = null;

        return topoRemov;
    }

    /**
     * Remove a pilha na posição especificada da lista.
     * 
     * @param pos A posição da pilha a ser removida.
     * @return A pilha removida da posição especificada.
     * @throws Exception Se a lista estiver vazia ou a posição for inválida.
     */
    public CelulaPilha remover(int pos) throws Exception{
        CelulaPilha topoRemov;
        int tam = tamLista();

        if(inicio == fim){
            throw new Exception("Erro! Não há pilhas para remover.");
        } else if(pos < 0 || pos > tam-1){
            throw new Exception("Erro! Posição inválida");
        } else if(pos == 0){
            topoRemov = removerInicio();
        }else if(pos == tam-1){
            topoRemov = removerFim();
        } else{
            CelulaLista i = inicio.prox;
            for(int j = 0; j < pos; j++, i = i.prox);

            CelulaLista tmp = i.prox;
            topoRemov = tmp.topo;
            i.prox = tmp.prox;

            tmp.prox = null;
            i = tmp = null;
        }

        return topoRemov;
    }

    /**
     * Exibe todas as pilhas na lista.
     */
    public void mostrar(){
        int index = 1;
        CelulaLista l;
        for(l = inicio.prox; l != null; l = l.prox){
            System.out.print("\n\n-> Celula " + index++ + " da lista: | ");
            mostrarPilha(l);
        }
    }

    /**
     * Exibe os elementos da pilha associada a uma célula da lista.
     * 
     * @param l A célula da lista cujos elementos da pilha serão exibidos.
     */
    public void mostrarPilha(CelulaLista l){
        CelulaPilha p;
        for(p = l.topo; p != null; p = p.prox){
            System.out.print(p.elemento + " | ");
        }
    }

    /**
     * Exibe todas as pilhas da lista de forma recursiva.
     */
    public void mostrarRecursivo(){
        mostrarFilaRec(1, inicio.prox, inicio.prox.topo);
    }

    /**
     * Método recursivo auxiliar para exibir todas as pilhas da lista.
     * 
     * @param index O índice atual da célula na lista.
     * @param l     A célula atual da lista.
     * @param p     A pilha atual associada à célula.
     */
    public void mostrarFilaRec(int index, CelulaLista l, CelulaPilha p){
        if(l != null){
            mostrarFilaRec(++index, l.prox, p);
            System.out.print("\n\n-> Celula " + index + " da lista: | ");
            mostrarPilhaRec(p);
        }
    }

    /**
     * Exibe os elementos da pilha de forma recursiva.
     * 
     * @param p A célula atual da pilha.
     */
    public void mostrarPilhaRec(CelulaPilha p){
        if(p != null){
            mostrarPilhaRec(p.prox);
            System.out.print(p.elemento + " | ");
        }
    }

    /**
     * Retorna o tamanho da lista.
     * @return O tamanho da lista.
     */
    public int tamLista(){
        int tam = 0;
        for(CelulaLista i = inicio; i != fim; i = i.prox, tam++);

        return tam;
    }

    /**
     * Retorna o tamanho da pilha.
     * @return O tamanho da pilha.
     */
    public int tamPilha(CelulaLista l){
        int tam = 0;
        for(CelulaPilha i = l.topo; i != null; i = i.prox, tam++);

        return tam;
    }

    /**
     * Retorna o tamanho da lista.
     * @return O tamanho da lista.
     */
    public CelulaLista maiorPilha(){
        CelulaLista celulaAtual;
        CelulaLista maiorP = inicio.prox;

        for(celulaAtual = inicio.prox.prox; celulaAtual != null; celulaAtual = celulaAtual.prox){
            if(tamPilha(celulaAtual) > tamPilha(maiorP))
                maiorP = celulaAtual;
        }
        return maiorP;
    }

    /**
     * Adiciona uma pilha aleatória na lista.
     * @param rand Objeto para geração de números aleatórios.
     */
    public void addPilhaNaLista(Random rand){
        int limit = rand.nextInt(20) + 5;

        CelulaPilha novaPilha = new CelulaPilha(rand.nextInt(100));
        inserirFim(novaPilha);
        
        for(int j = 0; j < limit; j++){
            novaPilha = new CelulaPilha(rand.nextInt(100));
            novaPilha.prox = fim.topo;
            fim.topo = novaPilha;

            novaPilha = null;
        }
    }
}

/**
 * Classe principal que contém o método main para execução do programa.
 */
public class MaiorPilha {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        Lista lista = new Lista();

        System.out.print("\nInsira a quantidade de pilhas deseja inserir na lista: ");
        int qnt = sc.nextInt(); sc.nextLine();

        for(int i = 0; i < qnt; i++)
            lista.addPilhaNaLista(rand);

        System.out.println("\n==============================================");
        System.out.print("\nLISTAS:");
        lista.mostrar();

        System.out.println("\n\n==============================================\n");
        System.out.print("Pilha com o maior numero de elementos:\n\n| ");
        lista.mostrarPilha(lista.maiorPilha());

        sc.close();
    }
}
