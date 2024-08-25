import java.util.Scanner;

public class LoopingDeEntrada {
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
    
        System.out.print("Digite um texto: ");
        while(entrada.hasNext()){
            System.out.println("Token: "+entrada.next());
        }
        entrada.close(); //Encerra o programa
    }
}
