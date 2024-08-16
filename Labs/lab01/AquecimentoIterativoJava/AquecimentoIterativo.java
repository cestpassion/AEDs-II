/* 1. Aquecimento Iterativo:
 * Crie um método iterativo em Java que receba como parâmetro uma string e retorne
 * seu número de caracteres maiúsculos. Em seguida, teste o método anterior usando
 * redirecionamento de entrada e saída. A entrada padrão é composta por várias linhas
 * sendo que a última contém a palavra "FIM1". A saída padrão contém um número inteiro
 * para cada linha de entrada.
 */

import java.util.Scanner;

public class AquecimentoIterativo {
    
    public static boolean isFIM (String str){
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    public static int contMaiusculo (String str, int tam){
        int cont = 0;
        
        for(int i = 0; i < tam; i++){
            cont += (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') ?  1 : 0;
        }
        
        return cont;
    }

    public static void main (String[] args){
        String[] strings = new String[1000];
        int numStrings = 0;
        Scanner entrada = new Scanner(System.in);

        do{
            strings[numStrings] = entrada.nextLine();
        } while (isFIM(strings[numStrings++]) == false);
        numStrings--;

        for(int i = 0; i < numStrings; i++){
            System.out.println(contMaiusculo(strings[i], strings[i].length()));
        }
        entrada.close();
    }
}
