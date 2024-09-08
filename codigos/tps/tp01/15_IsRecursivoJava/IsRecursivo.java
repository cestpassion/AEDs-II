/**
 * Is Recursivo
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

 /*
  * Refaça a questão Is de forma recursiva.
  */

  public class IsRecursivo{
    
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

        result = (vowel(str, 0) == true ? "SIM " : "NAO ");
        result += (consonant(str, 0) == true ? "SIM " : "NAO ");
        result += (integer(str, 0) == true ? "SIM " : "NAO ");
        result += (real(str, 0, 0) == true ? "SIM" : "NAO");

        return result;
    }

    /**
     * Verifica se o caractere é uma vogal.
     *
     * @param c caractere a ser verificado
     * @return true se for uma vogal, false caso contrário
     */
    private static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    /**
     * Reconhece se a string é composta apenas por vogais.
     *
     * @param str string recebida pela entrada padrão
     * @param index índice atual da string
     * @return true / false
     */
    public static boolean vowel(String str, int index) {
        if (index == str.length()) 
            return true;
        
        char c = str.charAt(index);
        if (!isVowel(c)) 
            return false;
        
        return vowel(str, ++index);
    }

    /**
     * Verifica se o caractere é uma consoante.
     *
     * @param c caractere a ser verificado
     * @return true se for uma consoante, false caso contrário
     */
    private static boolean isConsonant(char c) {
        return (c >= 'a' && c <= 'z' && !isVowel(c)) ||
               (c >= 'A' && c <= 'Z' && !isVowel(c));
    }

    /**
     * Reconhece se a string é composta apenas por consoantes.
     *
     * @param str string recebida pela entrada padrão
     * @param index índice atual da string
     * @return true / false
     */
    public static boolean consonant(String str, int index) {
        if (index == str.length()) 
            return true;

        if (!isConsonant(str.charAt(index))) 
            return false;

        return consonant(str, ++index);
    }

    /**
     * Reconhece se a string é composta por um número inteiro.
     *
     * @param str string recebida pela entrada padrão
     * @param index índice atual da string
     * @return true / false
     */
    public static boolean integer(String str, int index){
        if (index == str.length())
            return true;

        char c = str.charAt(index);

        if (c < '0' || c > '9')
            return false;

        return integer(str, ++index);
    }

    /**
     * Reconhece se a string é composta por um número real.
     *
     * @param str string recebida pela entrada padrão
     * @param index índice atual da string
     * @param dotCount contador de pontos ou vírgulas
     * @return true / false
     */
    public static boolean real(String str, int index, int count) {
        if (index == str.length()) 
            return true;
        
        char c = str.charAt(index);
        if ((c < '0' || c > '9') && c != '.' && c != ',') 
            return false;
        
        if (c == '.' || c == ',') {
            count++;
            if (count > 1) 
                return false;
        }
        return real(str, index + 1, count);
    }

    // Método principal
    public static void main(String[] args){
        String str;

        while(!isFIM(str = MyIO.readLine()))
           MyIO.println(recognition(str));
    }
  }