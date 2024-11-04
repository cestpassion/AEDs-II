import java.util.Arrays;

public class BubbleSortExample {
    public static void main(String[] args) {
        int[] array = {101, 115, 30, 63, 47, 20};  // Define o array a ser ordenado

        // Usa o método `Arrays.sort()` para ordenar o array em ordem crescente
        Arrays.sort(array);

        // Imprime o array ordenado
        System.out.print("Array ordenado: ");
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();  // Pula para a próxima linha após imprimir todos os elementos
    }
}
