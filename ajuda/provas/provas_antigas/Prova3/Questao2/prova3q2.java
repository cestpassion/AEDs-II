import java.io.*;
import java.util.*;

class Celula {
    public int elemento; 
    public Celula prox; 
    public Celula() {
        this(0);
    }
    public Celula(int elemento) {
      this.elemento = elemento;
      this.prox = null;
    }
    public int has1(int nivel){
        if(elemento == 1){
            return nivel;
        }
        else if(this.prox == null){
            return 0;
        }
        else{
            return this.prox.has1(nivel+1);
        }
    }
}
class Pilha {
    private Celula topo;
    public Pilha() {
        topo = null;
    }
    public void inserir(int x) {
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    }
    public int remover() throws Exception {
        if (topo == null) {
            throw new Exception("Erro ao remover!");
        }
        int resp = topo.elemento;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        return resp;
    }
    public Celula getTopo() {
        return topo;
    }
    public int has1(){
        return topo.has1(0);
    }
}

public class prova3q2 {
    public static int Retirar(Pilha p, int qtdMov) throws Exception{
        if(p.getTopo().elemento == 1){
            return qtdMov;
        }
        else {
            p.remover();
            return Retirar(p, qtdMov+1);
        }
    }
    public static int Movimentos(Pilha[] pilhas, int p, int qtdMov, int[] niveis) throws Exception{
        int lEsq = 0;
        int lDir = 0;
        boolean pastPilha = false;
        int posPil = 0;
        Pilha[] pilhasCopy = pilhas;
        int nivel = 0;
        for(int i = 0;i<p;i++){
            if(pilhas[i].has1() != 0 ){
                nivel = pilhas[i].has1();
                qtdMov = qtdMov + Retirar(pilhas[i], qtdMov);
                pastPilha = true;
                posPil = i;
            }
            else{
                if(pastPilha == false){
                    lEsq++;
                }
                else{
                    lDir++;
                }
            }
        }
        if(lEsq <= lDir){
            if(niveis[lEsq] >= niveis[posPil]-nivel){
                qtdMov += lEsq;
            }
        }
        else{
            if(niveis[lDir] >= niveis[posPil]-nivel){
                qtdMov += lDir;
            }
        }
        return qtdMov;

    }
    public static void main(String[] args) throws Exception{
        int n,p;
        n = MyIO.readInt();
        p = MyIO.readInt();
        do{
            Pilha[] pilhas = new Pilha[p];
            int [] niveis = new int[p];
            for(int i = 0; i<p;i++){
                Pilha pi = new Pilha();
                pilhas[i] = pi;
                int qi = MyIO.readInt();
                niveis[i] = qi;
                for(int j = 0; j<qi; j++){
                    int num = MyIO.readInt();
                    pilhas[i].inserir(num);
                }
            }
            int qtdMov = Movimentos(pilhas,p,0,niveis);
            System.out.println(qtdMov);
            n = MyIO.readInt();
            p = MyIO.readInt();
            if(n == p && n >= 1000){
                n = p = 0;
            }
        } while(n != 0 && p != 0);
    }
}
