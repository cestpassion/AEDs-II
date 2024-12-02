class Celula{
    public String palavra;
    public Celula prox;

    public Celula(){
        this(null);
    }

    public Celula(String palavra){
        this.palavra = palavra;
        prox = null;
    }
}

class No{
    public char letra;
    public No dir, esq;
    public Celula inicio, fim;

    public No(char letra){
        this.letra = letra;
        dir = null;
        esq = null;   
        inicio = null;
        fim = inicio;
    }
}

class Arvore{
    private No raiz;

    public Arvore(){
        raiz = null;
    }

    public void inserir(String palavra){
        if(raiz == null){
            raiz = new No(palavra.charAt(0));
            raiz.fim.prox = new Celula(palavra);
            raiz.fim = raiz.fim.prox;
        }
        else if(palavra.charAt(0) < raiz.letra){
            inserir(palavra, raiz.esq, raiz);
        }
        else if(palavra.charAt(0) > raiz.letra){
            inserir(palavra, raiz.dir, raiz);
        }
        else{
            System.out.println("Erro!");
        }
    }

    public void inserir(String palavra, No i, No pai){
        if(i == null){
            if(palavra.charAt(0) < pai.letra){
                pai.esq = new No(palavra.charAt(0));
                i.fim.prox = new Celula(palavra);
                i.fim = i.fim.prox;
            }
            else{
                pai.dir = new No(palavra.charAt(0));
                i.fim.prox = new Celula(palavra);
                i.fim = i.fim.prox;
            }
        } else if(palavra.charAt(0) == i.letra)
            for(Celula j = i.inicio.prox; j != null && equals(palavra, j.palavra); j = j.prox){
                
            }
                inserir(palavra, i.esq, i);
            }
        }
    }
}

public class ArvoreLista {
    public static main(String[] args){

    }
}
