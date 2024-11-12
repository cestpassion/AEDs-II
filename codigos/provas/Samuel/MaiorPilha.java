/*
 * Q1
 * 
 * Considere uma estrutura Lista de Pilhas (ilustrada e codificada abaixo). Crie método CelulaLista maiorPilha()
 * na classe Lista, que retorna a Célula da Lista que aponta para a pilha com o maior número de elementos. Caso
 * tenham pilhas do mesmo tamanho, retornar a primeira que aparece.
 */

import java.util.Scanner;
import java.util.Random;

class CelulaPilha{
    public int elemento;
    public CelulaPilha prox;

    public CelulaPilha(){
        this(-1);
    }

    public CelulaPilha(int elemento){
        this.elemento = elemento;
        this.prox = null;
    }
}

class Pilha{
    private CelulaPilha topo;

    public Pilha(){
        topo = null;
    }

    public void push(int novoElemento){
        CelulaPilha tmp = new CelulaPilha(novoElemento);
        tmp.prox = topo;
        topo = tmp;

        tmp = null;
    }

    public int pop() throws Exception{
        if(topo == null)
            throw new Exception("Erro! A pilha está vazia.");
        
        CelulaPilha tmp = topo;
        int elementoRemov = tmp.elemento;
        topo = topo.prox;

        tmp.prox = null;
        tmp = null;

        return elementoRemov;
    }

    public void mostrar(){
        for(CelulaPilha i = topo; i != null; i = i.prox){
            System.out.print(i.elemento + " | ");
        }
    }

    public void mostrarRecursivo(CelulaPilha i){
        if(i != null){
            mostrarRecursivo(i.prox);
            System.out.print(i.elemento + " | ");
        }
    }

    public int tamPilha(){
        int tam = 0;
        for(CelulaPilha i = topo; i != null; i = i.prox, tam++);

        return tam;
    }

    public int somaPilha(){
        int soma = 0;

        for(CelulaPilha i = topo; i != null; i = i.prox)
            soma += i.elemento;
        
        return soma;
    }
}

class CelulaLista{
    public Pilha pilha;
    public CelulaLista prox;

    public CelulaLista(){
        this(null);
    } 

    public CelulaLista(Pilha pilha){
        this.pilha = pilha;
        this.prox = null;
    }
}

class Lista{
    private CelulaLista inicio;
    private CelulaLista fim;

    public Lista(){
        inicio = new CelulaLista();
        fim = inicio;
    }

    public void inserirInicio(Pilha novaPilha){
        CelulaLista tmp = new CelulaLista(novaPilha);
        tmp.prox = inicio.prox;
        inicio.prox = tmp;

        if(inicio == fim)
            fim = tmp;
        
        tmp = null;
    }

    public void inserirFim(Pilha novaPilha){
        fim.prox = new CelulaLista(novaPilha);
        fim = fim.prox;
    }

    public void inserir(Pilha novaPilha, int pos) throws Exception{
        int tam = tamLista();

        if(pos < 0 || pos >= tam){
            throw new Exception("Erro! Posição " + pos + " inválida. Tamanho da lista: " + tam + ".");
        } else if(pos == 0){
            inserirInicio(novaPilha);
        } else if(pos == tam - 1){
            inserirFim(novaPilha);
        } else {
            CelulaLista i = inicio;
            for(int j = 0; j < pos; j++, i = i.prox );

            CelulaLista tmp = new CelulaLista(novaPilha);
            tmp.prox = i.prox;
            i.prox =  tmp.prox;

            tmp = i = null;
        }
    }

    public Pilha removerInicio() throws Exception{
        if(inicio == fim)
            throw new Exception("Erro! A lista está vazia.");

        CelulaLista tmp = inicio;
        inicio = inicio.prox;
        Pilha pilhaRemov = inicio.pilha;

        tmp.prox = null;
        tmp = null;

        return pilhaRemov;
    }

    public Pilha removerFim() throws Exception{
        if(inicio == fim)
            throw new Exception("Erro! A lista está vazia");
        
        CelulaLista i;
        for(i = inicio; i.prox != fim; i = i.prox);

        Pilha pilhaRemov = fim.pilha;
        fim = i;
        i = fim.prox = null;

        return pilhaRemov;
    }

    public Pilha remover(int pos) throws Exception{
        int tam = tamLista();

        if(inicio == fim){
            throw new Exception("Erro! A lista está vazia.");
        } else if(pos < 0 || pos >= tam){
            throw new Exception("Erro! Posição " + pos + " inválida. Tamanho da lista: " + tam + ".");
        } else if(pos == 0){
            removerInicio();
        } else if(pos == tam - 1){
            removerFim();
        }
        
        CelulaLista i = inicio;
        for(int j = 0; j < pos; j++, i = i.prox);

        CelulaLista tmp = i.prox;
        Pilha pilhaRemov = tmp.pilha;
        i.prox = tmp.prox;

        i = tmp = tmp.prox =null;

        return pilhaRemov;
    }

    public void mostrar(){
        int indice = 0;
        for(CelulaLista i = inicio.prox; i != null; i = i.prox){
            System.out.print("\n\nPosicao " + indice++ + " da Lista:\n| ");
            i.pilha.mostrar();
        }
    }

    public void mostrarNo(CelulaLista noPilha){
        System.out.println("| ");
        noPilha.pilha.mostrar();;
    }

    public int tamLista(){
        int tam = 0;
        for(CelulaLista i = inicio.prox; i != null; i = i.prox, tam++);

        return tam;
    }

    public CelulaLista maiorPilha(){
        int maior = inicio.prox.pilha.tamPilha();
        int atual;
        CelulaLista maiorCelula = new CelulaLista();

        CelulaLista i;
        for(i = inicio.prox; i != null; i = i.prox){
            atual = i.pilha.tamPilha();

            if(atual > maior){
                maior = atual;
                maiorCelula = i;
            }
        }

        return maiorCelula;
    }
}

public class MaiorPilha {
    public static Random rand = new Random();

    public static void addPilhaNaLista(int qnt, Lista lista){
        Pilha pilha;
        int limit;

        for(int i = 0; i < qnt; i++){
            pilha = new Pilha();
            limit = rand.nextInt(10) + 5;
            
            for(int j = 0; j < limit; j++){
                pilha.push(rand.nextInt(100));
            }
            lista.inserirFim(pilha);
        }
    }
    public static void main(String[] args){
        Lista lista = new Lista();
        Scanner sc = new Scanner(System.in);

        System.out.println("\nInsira a quantidade de pilhas deseja inserir na lista: ");
        int qnt = sc.nextInt(); sc.nextLine();
        
        addPilhaNaLista(qnt, lista);

        System.out.print("\nLISTA:");
        lista.mostrar();

        System.out.println("\nMAIOR PILHA PRESENTE NA LISTA: ");
        lista.mostrarNo(lista.maiorPilha());

        sc.close();
    }
}
