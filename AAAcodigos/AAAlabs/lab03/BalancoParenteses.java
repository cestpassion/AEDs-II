/**
 * Balanço Parênteses
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/*
 * Dada uma expressão qualquer com parênteses, indique se a quantidade de
 * parênteses está correta ou não, sem levar em conta o restante da expressão.
 * 
 * Por exemplo:
 * 
 * a+(b*c)-2-a        está correto
 * (a+b*(2-c)-2+a)*2  está correto
 * 
 * enquanto
 * 
 * (a*b-(2+c)         está incorreto
 * 2*(3-a))           está incorreto
 * )3+b*(2-c)(        está incorreto
 * 
 * Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre
 * correspondente e não pode haver parênteses que fecha sem um previo parenteses
 * que abre e a quantidade total de parenteses que abre e fecha deve ser igual.
 * 
 * Escreva um programa que dado uma expressão imprima na tela se a mesma está ou
 * não correta.
 */

public class BalancoParenteses {

    // Verifica se a string digitada é "FIM"
    public static boolean isFIM(String str){
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    // Verifica o balanço 
    public static boolean parenteses(String str){
        int tam = str.length();
        int left = 0;
        int right = 0;

        for(int i = 0; i < tam; i++){
            if(str.charAt(i) == '(')
                left++;
            else if(str.charAt(i) == ')'){
                right++;
                if(right > left)
                    return false;
            }
        }
        return (left == right);
    }

    // Metodo principal:
    public static void main(String[] args){
        String str;

        while(!isFIM(str = MyIO.readLine())){
            if(parenteses(str))
                MyIO.println("correto");
            else
                MyIO.println("incorreto");
        }
    }
}
