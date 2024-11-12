/*
 * Questão 3
 * 
 * Implemente o método public static int[] vetorOrdenado(int[] vetA, int[] vetB) em Java que recebe dois arrays de
 * inteiros (tamanhos m e n) e retorna um terceiro array (tamanho m + n).
 * - O primeiro array (vetA) possui elementos pares, não primos, ordenados de forma decrescente.
 * - O segundo array (vetB) possui elementos ímpares, não primos, ordenados de forma decrescente.
 * - O array que será retornado deve possuir os valores dos dois arrays ordenados de forma CRESCENTE.
 * - A complexidade do método deve ser O(m+n).
 * 
 * Abaixo está um exemplo do problema:
 * 
 *      vetA: | 46 | 38 | 22 | 10 |
 * 
 *      vetB: | 57 | 33 | 21 |
 * 
 *      vetC: | 10 | 21 | 22 | 33 | 38 | 46 | 57 |
 * 
 * Resposta:
 * 
 * public static int[] vetorOrdenado(int[] vetA, int[] vetB){
 *     int[] vetC = new int [vetA.length + vetB.length];
 *      int tamA = vetA.length - 1;
 *      int tamB = vetB.length - 1;
 *        
 *      for(int i = 0; i < vetC.length; ++i){
 *          if(tamA >= 0 && (tamB < 0 || vetA[tamA] <= vetB[tamB])){
 *              vetC[i] = vetA[tamA];
 *              tamA--;
 *          } else {
 *              vetC[i] = vetB[tamB];
 *              tamB--;
 *          }
 *      }
 *      return vetC;
 *  }
 */

/**
 * Terceiro Vetor Ordenado
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

import java.util.Scanner;
import java.util.Random;

public class TerceiroVetOrd{
    /**
     * Método principal que executa o programa.
     */
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        int m, n;

        m = sc.nextInt();
        n = sc.nextInt();

        int[] vetA = new int[m];
        int[] vetB = new int[n];

         // Preenche o vetor A com números pares, não primos, ordenados de forma decrescente.
        vetA[m - 1] = randInt(0, rand);
        for(int i = m - 2; i >= 0; --i){
            do{
                vetA[i] = randInt(vetA[i+1], rand);
            } while(vetA[i] % 2 != 0);
        }

        // Preenche o vetor B com números ímpares, não primos, ordenados de forma decrescente.
        vetB[n - 1] = randInt(0, rand);
        for(int i = n - 2; i >= 0; --i){
            do{
                vetB[i] = randInt(vetB[i+1], rand);
            } while(vetB[i] % 2 == 0);
        }

        // Gera o vetor C combinando vetores A e B em ordem crescente.
        int[] vetC = vetorOrdenado(vetA, vetB);

        // Imprime os vetores A, B e C.
        System.out.print("vetA : | ");
        for(int elementos : vetA){
            System.out.print(elementos + " | ");
        } 
        System.out.println();

        System.out.print("vetB : | ");
        for(int elementos : vetB){
            System.out.print(elementos + " | ");
        } 
        System.out.println();

        System.out.print("vetC : | ");
        for(int elementos : vetC){
            System.out.print(elementos + " | ");
        }
        System.out.println();
          
        sc.close();
    }

    /**
     * Gera um número não primo, maior que o valor fornecido.
     *
     * @param valor O valor mínimo - 1 para o próximo número.
     * @param rand Instância de Random usada para gerar números aleatórios.
     * @return Um número não primo, maior que o valor fornecido.
     */
    public static int randInt(int valor, Random rand){
        int proxValor = 0;
        do{
            proxValor = 1 + valor + rand.nextInt(20);
        } while (isPrimo(proxValor));

        return proxValor;
    }

    /**
     * Verifica se um número é primo.
     *
     * @param num Número a ser verificado.
     * @return true se o número não é primo, false caso contrário.
     */
    public static boolean isPrimo(int num){
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    /**
     * Combina dois vetores ordenados (decrescente) em um terceiro vetor ordenado de forma crescente.
     *
     * @param vetA Vetor A de números pares inteiros ordenado de forma decrescente.
     * @param vetB Vetor B de números impares inteiros ordenado de forma decrescente.
     * @return Um vetor de inteiros contendo os elementos dos vetores A e B, ordenado de forma crescente.
     */
    public static int[] vetorOrdenado(int[] vetA, int[] vetB){
        int[] vetC = new int [vetA.length + vetB.length];
        int tamA = vetA.length - 1;
        int tamB = vetB.length - 1;
        
        for(int i = 0; i < vetC.length; ++i){
            if(tamA >= 0 && (tamB < 0 || vetA[tamA] <= vetB[tamB])){
                vetC[i] = vetA[tamA];
                tamA--;
            } else {
                vetC[i] = vetB[tamB];
                tamB--;
            }
        }
        return vetC;
    }    
}
