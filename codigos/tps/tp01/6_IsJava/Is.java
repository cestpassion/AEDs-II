/**
 * Is
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/* 
 * Crie um método iterativo que recebe uma string e retorna true se a mesma é composta somente por vogais.
 * Crie outro método iterativo que recebe uma string e retorna true se a mesma é composta somente por
 * consoantes. Crie um terceiro método iterativo que recebe uma string e retorna true se a mesma corresponde
 * a um número inteiro. Crie um quarto método iterativo que recebe uma string e retorna true se a mesma
 * corresponde a um número real. Na saída padrão, para cada linha de entrada, escreva outra de saída da
 * seguinte forma X1 X2 X3 X4 onde cada Xi é um booleano indicando se a é entrada é: composta somente por
 * vogais (X1); composta somente somente por consoantes (X2); um número inteiro (X3); um número real (X4).
 * Se Xi for verdadeiro, seu valor será SIM, caso contrário, NÃO.
 */


public class Is{

    /**
     * Verificação se a string recebida é FIM.
     *
     * @param str string digitada pelo usuário
     * @return true / false
     */
    public static boolean isFIM(String str){
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    /**
     * Reconhecimento da string; atribui a chamada dos métodos à string result.
     *
     * @param str string recebida pela entrada padrão
     * @return string result indicando a composição da string recebida na forma X1 X2 X3 X4
     */
    public static String recognition(String str){
        String result = null;

        result = (vowel(str) == true ? "SIM " : "NAO ");
        result += (consonant(str) == true ? "SIM " : "NAO ");
        result += (integer(str) == true ? "SIM " : "NAO ");
        result += (real(str) == true ? "SIM" : "NAO");

        return result;
    }

    /**
     * Reconhece se a string é composta apenas por vogais.
     *
     * @param str string recebida pela entrada padrão
     * @return true / false
     */
    public static boolean vowel(String str){
        String vowelLower = "aeiou"; 
        String vowelUpper = "AEIOU";
        int tam = str.length();
        boolean bool = false;

        for(int i = 0; i < tam; i++){
            bool = false;
            for(int j = 0; j < 5; j++){
                if(str.charAt(i) == vowelLower.charAt(j) || str.charAt(i) == vowelUpper.charAt(j))
                    bool = true;
            }
            if(!bool)
                return bool;
        }
        return bool;
    }

    /**
     * Reconhece se a string é composta apenas por consoantes.
     *
     * @param str string recebida pela entrada padrão
     * @return true / false
     */
    public static boolean consonant(String str){
        String consonantLower = "cdfghjklmnpqrstvwxyz"; 
        String consonantUpper = "CDFGHJKLMNPQRSTVWXYZ";
        int tam = str.length();
        boolean bool = false;

        for(int i = 0; i < tam; i++){
            bool = false;
            for(int j = 0; j < 20; j++){
                if(str.charAt(i) == consonantLower.charAt(j) || str.charAt(i) == consonantUpper.charAt(j))
                    bool = true;
            }
            if(!bool)
                return bool;
        }
        return bool;
    }

    /**
     * Reconhece se a string é composta por um número inteiro.
     *
     * @param str string recebida pela entrada padrão
     * @return true / false
     */
    public static boolean integer(String str){
        int tam = str.length();
        boolean bool = false;

        for(int i = 0; i < tam; i++){
            bool = false;
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9')
                bool = true;
            if(!bool)
                return bool;
        }
        return bool;
    }

    /**
     * Reconhece se a string é composta por um número real.
     *
     * @param str string recebida pela entrada padrão
     * @return true / false
     */
    public static boolean real(String str){
        int tam = str.length();
        boolean bool = false;
        int cont = 0;

        for(int i = 0; i < tam; i++){
            bool = false;
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9' || (str.charAt(i) == '.' || str.charAt(i) == ',')){
                cont += (str.charAt(i) == '.' || str.charAt(i) == ',') ? 1 : 0;
                if(cont > 1)
                    return bool;
                bool = true;
            }
            if(!bool)
                return bool;
        }
        return bool;
    }

    // Método principal
    public static void main(String[] args){
        String str;

        while(!isFIM(str = MyIO.readLine())){
           MyIO.println(recognition (str));
        }
    }
}