/**
 * Ciframento de César
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * O Imperador Júlio César foi um dos principais nomes do Império Romano. Entre suas
 * contribuições, temos um algoritmo de criptografia chamado “Ciframento de César”.
 * Segundo os historiadores, César utilizava esse algoritmo para criptografar as mensagens
 * que enviava aos seus generais durante as batalhas. A ideia básica é um simples
 * deslocamento de caracteres. Assim, por exemplo, se a chave utilizada para criptografar
 * as mensagens for 3, todas as ocorrências do caractere ’a’ são substituídas pelo caractere
 * ’d’, as do ’b’ por ’e’, e assim sucessivamente. Crie um método iterativo que recebe uma
 * string como parâmetro e retorna outra contendo a entrada de forma cifrada. Neste exercício,
 * suponha a chave de ciframento três. Na saída padrão, para cada linha de entrada, escreva
 * uma linha com a mensagem criptografada. */

public class CiframentoCesar{

   // Identificador a string "FIM"
   public static boolean isFIM(String str){
      return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
   }

   // Ciframento iterativo da string recebida
   public static String ciframento(String str){
      int tam = str.length();
      String strCifrada = "";

      for(int i = 0; i < tam; i++)
         strCifrada += (char) (str.charAt(i) + 3);
      
      return strCifrada;
   }

   // Metodo principal
   public static void main(String[] args){
      String string = "";
      String stringCifrada = "";

      while(!isFIM(string = MyIO.readLine())){ // Atribui o valor recebido à variável string e chama o método isFIM
         stringCifrada = ciframento(string);

         MyIO.println(stringCifrada);
      }
   }
}