/**
 * Álgebra Booleana
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * Crie um método iterativo que recebe uma string contendo uma expressão booleana e o
 * valor de suas entradas e retorna um booleano indicando se a expressão é verdadeira
 * ou falsa.
 * 
 * Cada string de entrada é composta por um número inteiro n indicando o número de
 * entradas da expressão booleana corrente.
 * 
 * Em seguida, a string contém n valores binários (um para cada entrada) e a expressão
 * booleana.
 * 
 * Na saída padrão, para cada linha de entrada, escreva uma linha de saída com 1 / 0
 * indicando se a expressão corrente é verdadeira ou falsa.
 */

public class AlgebraBooleana{

    /**
     * Verifica se a string recebida é FIM.
     *
     * @param str string digitada pelo usuário
     * @return true / false
     */
    public static boolean isFIM(String str){
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(20) == 'M');
    }

    /**
     * Método iterativo no qual verifica uma expressão booleana.
     *
     * @param str string digitada pelo usuário
     * @return true / false
     */
    public static boolean algebraBooleana(String str){
        

        return;
    }

    // Método principal
    public static void main(String[] args){
        String str = "";

        while(!isFIM(str = MyIO.readLine())){
            
        }
    }
}