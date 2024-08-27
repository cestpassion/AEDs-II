/**
 * Alteração Aleatória
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * Crie um método iterativo que recebe uma string, sorteia duas letras minúsculas
 * aleatórias (código ASCII ≥ ’a’ e ≤ ’z’), substitui todas as ocorrências da primeira
 * letra na string pela segunda e retorna a string com as alteraç˜oes efetuadas. Na
 * saída padrão, para cada linha de entrada, execute o método desenvolvido nesta
 * questão e mostre a string retornada como uma linha de saída. Abaixo, observamos um
 * exemplo de entrada supondo que para a primeira linha as letras sorteados foram o ’a’
 * e o ’q’. Para a segunda linha, foram o ’e’ e o ’k’.
 */

import java.util.Random;

public class AlteracaoAleatoria{

    /**
     * Verifica se a string recebida é FIM.
     *
     * @param str a string digitada pelo usuário
     * @return true / false
     */
    public static boolean isFIM(String string){
        return (string.length() == 3 && string.charAt(0) == 'F' && string.charAt(1) == 'I' && string.charAt(2) == 'M');
    }

    /**
     * Alteração das letras de forma "aleatória".
     *
     * @param string string digitada pelo usuário
     * @param letra1 "primeira" letra gerada por Random
     * @param letra2 "segunda" letra gerada por Random
     * @return true / false
     */
    public static String alteracaoAleatoria(String string, char letra1, char letra2){
        String stringAlterada = "";
        int tam = string.length();

        for(int i = 0; i < tam; i++){
            if (string.charAt(i) == letra1)
                stringAlterada += letra2;
            else
                stringAlterada += string.charAt(i);
        }
        return stringAlterada;
    }

    // Método principal   
    public static void main(String[] args){
        String str;
        String strAlterada;
        Random gerador = new Random() ;
        gerador.setSeed(4);

        while(!isFIM(str = MyIO.readLine())){ // Atribui o valor recebido à variável string e chama o método isFIM
            // Desloca o caractere 'a' a partir de um número aleatório entre 0 e 25 e converte para char
            char letra01 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
            char letra02 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));

            strAlterada = alteracaoAleatoria(str, letra01, letra02);        
            
            MyIO.println(strAlterada);
        }
    }
}