/**
 * Palíndromo Recursivo
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * Refaça a questão Palíndromo de forma recursiva.
 */

 public class PalindromoRecursivo{

    // Identificador a string "FIM"
    public static boolean isFim(String s){
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    // Identificador recursivo de palíndromos
    public static int palindromo(String s, int left, int right){
        int bool = 0;
        
        if(left < right){
            if(s.charAt(left) == s.charAt(right))
                bool = palindromo(s, ++left, --right);
            else
                return bool = 1;
        }
        return bool;
    }

    // Método principal
    public static void main(String[] args){
        String str = "";

        while(!isFim(str = MyIO.readLine())){ // Atribui o valor recebido à variável str e chama o método isFIM        
            if(palindromo(str, 0, (str.length() - 1)) == 0)
                MyIO.println("SIM");
            else
                MyIO.println("NAO");   
        }  
    } 
}