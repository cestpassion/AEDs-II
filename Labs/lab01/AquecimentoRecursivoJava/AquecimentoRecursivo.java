/* 2. Aquecimento Recursivo:
 * Refa¸ca a questão anterior de forma recursiva. Atente-se para os detalhes dos retornos de cada um dos métodos.
 */

import java.util.Scanner;

public class AquecimentoRecursivo{

    public static boolean isFIM(String str){
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    public static int contMaiusculo(String str, int indice){
        int cont = 0;
        if(indice < str.length()){
            if(str.charAt(indice) >= 'A' && str.charAt(indice) <= 'Z'){
                cont = 1 + contMaiusculo(str, ++indice);
            }
            else{
                cont = contMaiusculo(str, ++indice);
            }
        }
        return cont;
    }

    public static void main (String[] args){
        String[] strings = new String[1000];
        int numStrings = 0;
        Scanner entrada = new Scanner(System.in);

        do{
            strings[numStrings] = entrada.nextLine();
        } while ((isFIM(strings[numStrings++])) == false);
        numStrings--;

        for(int i = 0; i < numStrings; i++){
            System.out.println(contMaiusculo(strings[i], 0));
        }

        entrada.close();
    }
}
