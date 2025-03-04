/*
 * Crie um método iterativo que recebe uma string contendo uma expressão booleana e o valor de suas entradas
 * e retorna um booleano indicando se a expressão é verdadeira ou falsa. Cada string de entrada é composta 
 * por um número inteiro n indicando o número de entradas da expressão booleana corrente. Em seguida, a string
 * contém n valores binários (um para cada entrada) e a expressão booleana. Na saída padrão, para cada linha de
 * entrada, escreva uma linha de saída com 1 / 0 indicando se a expressão corrente é verdadeira ou falsa.
 */

/**
 * Álgebra Booleana
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

public class AlgebraBooleana{

    /**
     * Verificação se a string recebida é "0".
     *
     * @param str string digitada pelo usuário
     * @return true / false
     */
    public static boolean is0(String str){
        return (str.length() == 1 && str.charAt(0) == '0');
    }

    /**
     * Alteração de tipo char para int.
     *
     * @param carac caractere contido na string recebida no método main
     * @return número inteiro
     */
    public static int parseInt(char carac){
        int numInt = carac - 48;
        return numInt;
    }

    /**
     * Formação de uma nova string.
     *
     * @param str string digitada pelo usuário
     * @param inicio indice designado para ser o começo da string 
     * @param fim indice designado para ser o final da string 
     * @return nova string
     */
    public static String subString(String str, int inicio, int fim){
        String newStr = "";

        for(int i = inicio; i < fim; i++)
            newStr += str.charAt(i);

        return newStr;
    }

    /**
     * Alteração de caracteres dentro da string.
     *
     * @param str string digitada pelo usuário
     * @param alvo caractere que será alterado 
     * @param parametro substituto do caractere alvo
     * @return nova string com a alteração dos caracteres
     */
    public static String replace(String str, char alvo, int parametro){
        String newStr = "";
        int tam = str.length();
        boolean bool;

        for(int i = 0; i < tam; i++){
            bool = false;

            if(str.charAt(i) == (alvo)){
                newStr += (parametro == 1 ? '1' : '0');
                bool = true;
            }
            if(bool)
                i += 1;
            if(i == tam)
                break;
            
            newStr += str.charAt(i);
        }

        return newStr;
    }

    /**
     * Coletor de parametros.
     *
     * @param str string digitada pelo usuário
     * @param indice valor designado para ser o começo da string 
     * @param tam tamanho da string recebida
     * @return vetor com os parametros encontrados dentro da expressão booleana selecionada
     */
    public static int[] parametros(String str, int indice, int tam){
        int []param;
        int cont = 0;

        for(int i = indice; str.charAt(i) != ')'; i++){
            if(str.charAt(i) == '0' || str.charAt(i) == '1')
                cont++;
        }
        
        param = new int [cont];
        int j = 0;

        for(int i = indice; str.charAt(i) != ')'; i++){

            if(str.charAt(i) == '0'){
                param[j] = 0;
                j++;
            }
            else if(str.charAt(i) == '1'){
                param[j] = 1;
                j++;
            }
        }
        return param;
    }
    
    /**
     * Expressão Booleana NOT.
     *
     * @param str string digitada pelo usuário
     * @param indice valor designado para ser o começo da string 
     * @param tam tamanho da string recebida
     * @param param[] vetor com os parametros contidos dentro da expressão booleana
     * @return string formada após a realização da Álgebra Booleana
     */
    public static String not(String str, int indice, int tam, int param[]){
        String strStart= "";
        String strEnd= "";
        int qntParam = param.length;

        strStart += subString(str, 0, indice - 3);

        for(int i = indice; i < tam; i++){
            if(str.charAt(i) == ')'){
                strEnd = subString(str, i + 1, tam);
                str = subString(str, indice + 1, i);
                break;
            }
        }

        for(int i = 0; i < qntParam; i++){
            param[i] = param[i] == 1 ? 0 : 1;
            str = replace(str, param[i] == 1 ? '0' : '1', param[i]);
        }        

        return strStart + str + strEnd;
    }

    /**
     * Expressão Booleana OR.
     *
     * @param str string digitada pelo usuário
     * @param indice valor designado para ser o começo da string 
     * @param tam tamanho da string recebida
     * @param param[] vetor com os parametros contidos dentro da expressão booleana
     * @return string formada após a realização da Álgebra Booleana
     */
    public static String or(String str, int indice, int tam, int param[]){
        String strStart= "";
        int qntParam = param.length;
        int bool = 0;

        strStart += subString(str, 0, indice - 2);

        for(int i = indice; i < tam; i++){
            if(str.charAt(i) == ')'){
                str = subString(str, i + 1, tam);
                break;
            }
        }

        for(int i = 0; i < qntParam; i++){
            bool = (param[i] == 1) || (param[0] == 1) ? 1 : 0;
            if(bool == 1)
            break;
        }

        return strStart + bool + str;
    }

    /**
     * Expressão Booleana AND.
     *
     * @param str string digitada pelo usuário
     * @param indice valor designado para ser o começo da string 
     * @param tam tamanho da string recebida
     * @param param[] vetor com os parametros contidos dentro da expressão booleana
     * @return string formada após a realização da Álgebra Booleana
     */
    public static String and(String str, int indice, int tam, int param[]){
        String strStart= "";
        int qntParam = param.length;
        int bool = 0;

        strStart += subString(str, 0, indice - 3);

        for(int i = indice; i < tam; i++){
            if(str.charAt(i) == ')'){
                str = subString(str, i + 1, tam);
                break;
            }
        }
        for(int i = 0; i < qntParam; i++){
            bool = (param[i] == 1) && (param[0] == 1) ? 1 : 0;
            if(bool == 0)
                break;
        }

        return strStart + bool + str;
    }

    /**
     * Indentificação das expressões booleanas.
     *
     * @param str string digitada pelo usuário
     * @return string formada após a realização completa da Álgebra Booleana
     */
    public static char algebraBooleana(String str) throws Exception {
        int[] param;
        char strFinal = 'a';

        for(int i = str.length() - 1; i >= 0 ; i--){
            if(str.charAt(i) == '('){
                switch (str.charAt(i - 1)){
                    case 't':
                        param = parametros(str, i, str.length());                        
                        str = not(str, i, str.length(), param);                        
                        i = str.length();
                        break;

                    case 'r':
                        param = parametros(str, i, str.length());
                        str = or(str, i, str.length(), param);
                        i = str.length(); 
                        break;

                    case 'd':
                        param = parametros(str, i, str.length());
                        str = and(str, i, str.length(), param);
                        i = str.length();
                        break;
                }
            }
        }

        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '0' || str.charAt(i) == '1')
                strFinal = str.charAt(i);
        }
        return (strFinal == '0' ? '0' : '1');
    }

    // Método principal
    public static void main(String[] args) throws Exception{
        String str = "";
        int qntParametros = 0;
        int [] parametros;

        while(!is0(str = MyIO.readLine())){
            qntParametros = parseInt(str.charAt(0));
            parametros = new int[qntParametros];

            for(int i = 0; i < qntParametros; i++)
                parametros[i] = parseInt(str.charAt((i + 1) * 2));

            str = subString(str, (qntParametros * 2 + 2), str.length());
            
            for(int i = 0; i < qntParametros; i++)
                str = replace(str, (char) ('A' + i), parametros[i]);
            
            MyIO.println(algebraBooleana(str));
        }
    }
}