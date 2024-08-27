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
 * Se Xi for verdadeiro, seu valor será SIM, caso contrário, NÃO. */

public class Is{

    public static boolean isFIM(String str){
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    public static booelan is(String str){
        int tam = str.length();
        for(int i = 0; i < tam; i++){
            if(str.charAt(i) > 'a' && str.charAt(i) < 'Z'){
                if(str.charAt(i) == ' ' && str.charAt(i) == 'a' || str.charAt(i) == 'A' || str.charAt(i) == 'e' || str.charAt(i) == 'E' && str.charAt(i) == 'i' && )
            }
        }
    }

    public static void main(String[] args){
 
    }
}