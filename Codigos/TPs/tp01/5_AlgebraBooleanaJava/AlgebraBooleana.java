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

    public static boolean isFIM(String str){
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    public static int parseInt(char carac){
        int numInt = carac - 48;
        return numInt;
    }

    public static String subString(String str, int inicio, int fim){
        String newStr = "";

        for(int i = inicio; i < fim; i++)
            newStr += str.charAt(i);

        return newStr;
    }

    public static String replace(String str, char expressao, int parametro){
        String newStr = "";
        int tam = str.length();
        boolean bool;

        for(int i = 0; i < tam; i++){
            bool = false;

            if(str.charAt(i) == (expressao)){
                newStr += (parametro == 1 ? '1' : '0');
                bool = true;
            }

            if(bool)
                i += 1;
            
            newStr += str.charAt(i);
        }
        return newStr;
    }

    public static int[] parametros(String str, int indice, int tam){
        int []param;
        int cont = 0;

        MyIO.println("TESTE");

        for(int i = indice; i < tam; i++){
            if(str.charAt(i) == '0' || str.charAt(i) == '1')
                cont++;
            
            MyIO.println(str.charAt(i));
            MyIO.println("cont" + cont);
        }

        MyIO.println("TESTE");

        param = new int [cont];

        for(int i = indice; i < tam; i++){
            MyIO.println("i" +i);
            if(str.charAt(i) == '0')
                param[i] = 0;
            else if(str.charAt(i) == '1')
                param[i] = 1;
        }
        MyIO.println("TESTE");
        return param;
    }

    /*
    2 0 1 and(not(A) , or(A , B))
    
    public static String not(String str, int indice, int tam, int param[]){
        String newStr1 = subString(str, 0, indice - 4);
        String newStr2;
        int qntParam = param.length;

        str = subString(str, indice - 3, tam - 1);

        param[0] = param[0] == 1 ? 0 : 1;
        newStr2 = replace(str, "not( ", param[0]);

        for(int i = 1; i < qntParam; i++){
            param[i] = param[i] == 1 ? 0 : 1;
            newStr2 = replace(str, param[i] == 1 ? "0" : "1", param[i]);
        }
        return newStr1 + newStr2;
    }

    public static String or(String str, int indice, int tam, int param[]){
        String newStr1 = subString(str, 0, indice - 3);
        String newStr2;
        int qntParam = param.length;
        int or = 0;

        str = subString(str, indice - 2, indice + 1);

        for(int i = 0; i < qntParam; i++){
            for(int j = 0; j < qntParam; j++)
                or = (param[i] == 1) || (param[j] == 1) ? 1 : 0;
        }
        newStr2 = replace(str, "or( ", or);

        return newStr1 + newStr2;
    }

    public static String and(String str, int indice, int tam, int param[]){
        String newStr1 = subString(str, 0, indice - 4);
        String newStr2;
        int qntParam = param.length;
        int and = 0;

        str = subString(str, indice - 2, indice + 1);

        for(int i = 0; i < qntParam; i++){
            for(int j = 0; j < qntParam; j++)
                and = (param[i] == 1) && (param[j] == 1) ? 1 : 0;
        }
        newStr2 = replace(str, "and( ", and);

        return newStr1 + newStr2;
    }*/

    public static char algebraBooleana(String str) throws Exception {
        int[] param;
        char strFinal = 'a';

        for(int i = str.length() - 1; i >= 0 ; i--){
            MyIO.println(i + " " + str.length());
            if(str.charAt(i) == '('){
                switch (str.charAt(i - 1)){
                    case 't':
                        param = parametros(str, i, str.length() + 1);   
                        MyIO.println(param[0] + " " + param[1]);                     
                        /*str = not(str, i, str.length() + 1, param);*/
                        break;

                    case 'r':
                        param = parametros(str, i, str.length() + 1);
                        /*str = or(str, i, str.length() + 1, param);*/
                        MyIO.println(param[0] + " " + param[1]);  
                        break;

                    case 'd':
                        param = parametros(str, i, str.length() + 1);
                        /*str = and(str, i, str.length() + 1, param);*/
                        MyIO.println(param[0] + " " + param[1]);  
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

        while(!isFIM(str = MyIO.readLine())){
            qntParametros = parseInt(str.charAt(0));
            parametros = new int[qntParametros];

            for(int i = 0; i < qntParametros; i++)
                parametros[i] = parseInt(str.charAt((i + 1) * 2));

            str = subString(str, (qntParametros * 2 + 2), str.length());

            
            for(int i = 0; i < qntParametros; i++){
                str = replace(str, (char) ('A' + i), parametros[i]);
                MyIO.println(str);
            }
            
            MyIO.println(algebraBooleana(str));
        }
    }
}