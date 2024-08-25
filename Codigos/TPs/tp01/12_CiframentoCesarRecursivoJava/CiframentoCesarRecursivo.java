/* Ciframento de César Recursivo:
 * Refaça a questão Ciframento de César de forma recursiva.
 */

public class CiframentoCesarRecursivo{

   // Identificador a string "FIM"
   public static boolean isFIM(String str){
      return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
   }
 
   // Ciframento recursivo da string recebida
   public static String ciframento(String str, int cont){
      if(cont >= str.length())
         return "";
      
      char caractereCifrado = (char) (str.charAt(cont) + 3);

      return caractereCifrado + ciframento(str, ++cont);
      
      }
 
   // Metodo principal
   public static void main(String[] args){
      String string;
      String stringCifrada;
 
      while(!isFIM(string = MyIO.readLine())){ // Atribui o valor recebido à variável string e chama o método isFIM
         stringCifrada = ciframento(string, 0);

         MyIO.println(stringCifrada);
      }
   }
}