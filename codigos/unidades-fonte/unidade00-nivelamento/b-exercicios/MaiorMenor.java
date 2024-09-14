/**
 * Encontra o maoir e o menor elento do array
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * Faça um método que receba um array de inteiros e mostre na tela o maior e o menor elementos do array.
 */

import java.util.Random;

public class MaiorMenor {

    /**
     * Encontra o maior e o menor elementos.
     *
     * @param vet vetor onde será feita a pesquisa
     * @return um vetor de tamanho 2 contendo na posição 0 o menor elemento e na posição 1 o maior
     */
    public static int[] maiorMenorElems(int vet[]){
        int[] mm = new int[2];
        int tam = vet.length -1;
        mm[0] = vet[0];
        mm[1] = vet[0];

        for(int i = 1; i < tam; i++){
            if(vet[i] < mm[0])
                mm[0] = vet[i];
            else if (vet[i] > mm[1])
                mm[1] = vet[i];
        }
        return mm;
    }

    // Método Principal
    public static void main(String[] args){
        Random rnd = new Random();
        rnd.setSeed(System.currentTimeMillis());

        int tam = rnd.nextInt(11) + 10; // Define o tamanho do vetor
        int[] vet = new int[tam];

        // Preenche e imprime o vetor
        System.out.print("vet = [");
        for(int i = 0; i < tam; i++){
            vet[i] = rnd.nextInt(11);
            System.out.print(vet[i]);

            if(i < tam - 1)
                System.out.print(", ");
        }
        System.out.println("]");

        int[]mm = maiorMenorElems(vet);

        System.out.println("Menor elemento: " + mm[0] + "\nMaior elemento: " + mm[1]);
    }
}
