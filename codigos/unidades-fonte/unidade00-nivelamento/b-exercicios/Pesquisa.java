/**
 * Algoritmo de Pesquisa
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * Faça um método que receba um array de inteiros e um número inteiro x e retorne um valor booleano informando se o elemento
 * x está contido no array
 */

//import java.util.Random;
import java.util.Scanner;

public class Pesquisa{

    /**
     * Algoritmo de pesquisa sequencial interativo.
     *
     * @param array array onde será feita a pesquisa
     * @param x alvo da pesquisa
     * @return true (se encontou)/ false (se nao encontrou)
     */
    public static boolean searchSeq(int[] array, int x){
        boolean answer = false;
        int n = array.length;

        for(int i = 0; i < n; i++){
            if(array[i] == x){
                answer = true;
                i = n; // ou break;
            }
        }
        return answer;
    }

    /**
     * Algoritmo de pesquisa binária interativo.
     *
     * @param array array onde será feita a pesquisa
     * @param x alvo da pesquisa
     * @return true (se encontou)/ false (se nao encontrou)
     */
    public static boolean searchBin(int[] array, int x){
        boolean answer = false;
        int right = (array.length - 1), left = 0, middle;

        while(left <= right){
            middle = (left + right) / 2;

            if(x == array[middle]){
                answer = true;
                left = right + 1; // ou break;
            } else if(x > array[middle]){
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return answer;
    }

    /**
     * Algoritmo de pesquisa sequencial recursivo.
     *
     * @param array array onde será feita a pesquisa
     * @param x alvo da pesquisa
     * @param index indice atual da pesquisa
     * @return true (se encontou)/ false (se nao encontrou)
     */
    public static boolean searchSeqRec(int[] array, int x, int index){
        if(index == array.length)
            return false;

        if(array[index] == x)
            return true; 
        
        return searchSeqRec(array, x, ++index);
    }

    /**
     * Algoritmo de pesquisa binária recursivo.
     *
     * @param array array onde será feita a pesquisa
     * @param x alvo da pesquisa
     * @param left início do sub-array
     * @param right fim do sub-array
     * @return true (se encontou)/ false (se nao encontrou)
     */
    public static boolean searchBinRec(int[] array, int x, int left, int right){
        boolean answer;
        int middle = (left + right) / 2;

        if(left > right) 
            answer = false;
        else if(x == array[middle])
            answer = true;
        else if (x > array[middle]) 
            answer = searchBinRec(array, x, ++middle, right);
        else 
            answer = searchBinRec(array, x, left, --middle);
        
        return answer;
    }

    // Método Principal
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // Random rnd = new Random();
        // rnd.setSeed(System.currentTimeMillis());

        // int SIZE = rnd.nextInt(10) + 10;
        // int[] array = new int[SIZE];

        // // Preenche e imprime o vetor
        // System.out.print("array = [");

        // for(int i = 0; i < SIZE; i++){
        //     array[i] = rnd.nextInt(10);

        //     if(i < SIZE - 1)
        //         System.out.print(array[i] + ", ");
        // }

        // System.out.println("]");

        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int SIZE = array.length;

        System.out.print("Digite um numero: ");
        int x = sc.nextInt();

        // PESQUISA ITERATIVA
        System.out.println("\nPESQUISA ITERATIVA");
        // Sequencial
        if(searchSeq(array, x))
            System.out.println("Sequencial: o elemento " + x + " esta contido no array");
        else
            System.out.println("Sequencial: o elemento " + x + " NAO esta contido no array");
        
        // Binária
        if(searchBin(array, x))
            System.out.println("Binaria: o elemento " + x + " esta contido no array");
        else
            System.out.println("Binaria: o elemento " + x + " NAO esta contido no array");

        // PESQUISA RECURSIVA
        System.out.println("\nPESQUISA RECURSIVA");
        // Sequencial
        if(searchSeqRec(array, x, 0))
            System.out.println("Sequencial: o elemento " + x + " esta contido no array");
        else
            System.out.println("Sequencial: o elemento " + x + " NAO esta contido no array");
        
        // Binária
        if(searchBinRec(array, x, 0, (SIZE - 1)))
            System.out.println("Binaria: o elemento " + x + " esta contido no array\n");
        else
            System.out.println("Binaria: o elemento " + x + " NAO esta contido no array\n");

        sc.close();
    }
}