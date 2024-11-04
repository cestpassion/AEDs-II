/*
 * Crie um método iterativo que recebe uma string como parâmetro e retorna true
 * se essa é um palíndromo. Na saída padrão, para cada linha de entrada, escreva
 * uma linha de saída com SIM / NAO indicando se a linha é um palíndromo.
 * Destaca-se que uma linha de entrada pode ter caracteres não letras. 
 */

/**
 * Palíndromo
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

public class Palindromo{

    // Identificador a string "FIM"
    public static boolean isFim(String s){
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    // Identificador iterativo de palíndromos
    public static boolean palindromo(String s){
        int tam = s.length();
        
        for(int i = 0; i < (tam/2); i++){
            if(s.charAt(i) != s.charAt(tam - i - 1))
                return false;
        }
        return true;
    }

    // Método principal
    public static void main(String[] args){
        String str = "";

        while(!isFim(str = MyIO.readLine())){ 
            if(palindromo(str))
                MyIO.println("SIM");
            else
                MyIO.println("NAO");   
        }  
    } 
}