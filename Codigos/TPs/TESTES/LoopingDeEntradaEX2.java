import java.util.Scanner;

public class LoopingDeEntradaEX2 {
public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    int n = -1; // Inicializando com um valor padrão

    System.out.println("Digite números inteiros. Pressione Ctrl+D (ou Ctrl+Z no Windows) para finalizar.");

    while (entrada.hasNext()) {
        if (entrada.hasNextInt()) {
            n = entrada.nextInt();
        } else {
            System.out.println("Entrada inválida. Por favor, digite um número inteiro.");
            entrada.next(); // Limpar o token inválido
        }
    }

    if (n != -1) {
        System.out.println("Último número lido: " + n);
    } else {
        System.out.println("Nenhum número foi lido.");
    }

    entrada.close();
}
}
