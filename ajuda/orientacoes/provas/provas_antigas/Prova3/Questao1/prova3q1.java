import java.io.*;
import java.util.*;

import javax.sound.midi.SysexMessage;

/*Primeiro Dicionário de Andy
Andy de apenas 8 anos tem um sonho ‐ ele deseja criar o seu próprio
dicionário. Isto não é uma tarefa fácil para ele, pois conhece poucas palavras.
Bem, ao invés de pensar nas palavras que sabe, ele teve uma idéia brilhante.
A partir do seu livro de histórias favorito, ele vai criar um dicionário com todas
as palavras distintas que existem nele. Ordenando estas palavras em ordem
alfabética, o trabalho estará feito. É claro, isso é uma tarefa que toma um
certo tempo e portanto, a ajuda de um programador de computador como
você é muito bemvinda.
Você foi convidado a escrever um programa que liste todas as diferentes palavras que existem em um texto.
Neste caso, uma palavra é definida como uma sequência de letras, maiúsculas ou minúsculas. Palavras com
apenas uma letra também deverão ser consideradas. Portanto, seu programa deverá ser "CaSe InSeNsItIvE". Por
exemplo, palavras como "Apple", "apple" ou "APPLE" deverão ser consideradas como a mesma palavra.
Entrada
A entrada contém no máximo 10000 linhas de texto, cada uma delas com no máximo 200 caracteres. O fim de
entrada é determinado pelo EOF.
Saída
Você deve imprimir uma lista de diferentes palavras que aparecem no texto, uma palavra por linha. Todas as
palavras devem ser impressas com letras minúsculas, em ordem alfabética. Deverá haver no máximo 5000
palavras distintas.*/


class Lista{
    private String[] array;
    private int n;
 
    public Lista() {
       this(10000);
    }
 
    public Lista(int tam){
       array = new String[tam];
       n = 0;
    }

    public void inserir(String elemento) throws Exception {
        if(n >= array.length){
          throw new Exception("Erro ao inserir!");
        }

        array[n] = elemento;
        n++;
        
        for(int i = 0; i < n-1; i++){
            if(elemento.compareTo(array[i]) == 0){
                remover();
            }
        }
    }

    public String remover() throws Exception {
        if (n == 0) {
           throw new Exception("Erro ao remover!");
        }
        return array[--n];
    }

 
    public void mostrar(){
        for(int i = 0; i < n; i++){
            System.out.println(array[i]);
        }
    }
 
    public void swap(int i, int j) {
        String aux = array[i];
        array[i] = array[j];
        array[j] = aux;
     }
 
    public void sort() {
        for (int i = 0; i < (n - 1); i++) {
            int menor = i;
            for (int j = (i + 1); j < n; j++){
                if(array[menor].compareTo(array[j]) > 0){
                    menor = j;
                } 
            }
            swap(menor, i);
        }
    }
 
}


public class prova3q1 {

    public static void ler(String linha, Lista lista) throws Exception{
        String[] aux = new String[10000];

        linha = linha.replace("(", " ");
        linha = linha.replace(".", " ");
        linha = linha.replace("*", " ");
        linha = linha.replace("$", " ");
        linha = linha.replace("#", " ");
        linha = linha.replace("@", " ");
        linha = linha.replace("%", " ");
        linha = linha.replace("&", " ");
        linha = linha.replace(")", " ");
        linha = linha.replace(":", " ");
        linha = linha.replace("\"", " ");

        aux = linha.split("\\s+");

        for(int i = 0; i < aux.length; i++){
            if(aux[i].isEmpty() != true){
                lista.inserir(aux[i].toLowerCase());
            }
        }
        
    }


    public static void main(String args[]) throws Exception{
        Lista lista = new Lista();
        String linha = ""; 
        
        for(int i = 0; i < 7; i++){
            linha = MyIO.readLine();
            if(linha.isEmpty() != true){
                ler(linha, lista);   
            } else{
            }
        }

        lista.sort();
        lista.mostrar();
    }
}
