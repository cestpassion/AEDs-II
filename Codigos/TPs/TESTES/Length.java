import java.util.Scanner;

public class Length { // Nome da classe começa com letra maiúscula
    public static void main(String[] args) {
        String str;
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite uma string: ");
        str = sc.nextLine();

        int tam = str.length();

        System.out.println("Tamanho = " + tam); // Usando println para adicionar uma nova linha

        sc.close();
    }
}
