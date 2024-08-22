/* Sequência Espelho em Java:
Imprimir números em sequência é uma tarefa relativamente simples. Mas, e quando se trata de uma sequência
espelho? Trata-se de uma sequência que possui um número de início e um número de fim, e todos os números
entre estes, inclusive estes, são dispostos em uma sequência crescente, sem espa¸cos e, em seguida, esta
sequência é projetada de forma invertida, como um reflexo no espelho. Por exemplo, se a sequência for de
7 a 12, o resultado ficaria 789101112211101987
*/

import java.util.Scanner;

public class SequenciaEspelho{
    static int x;
    static int y;

    public static void numeros(int n, int rep){
        if((rep % 2) == 0)
            x = n;
        else
            y = n;
    }

    public static void espelho(){
        int digito;

        for(int i = x; i <= y; i++){
            System.out.print(i);
        }

        for(int i = y; i >= x; i--){
            int num = i;

            while(num > 0){
                digito = num % 10;
                System.out.print(digito);
                num = num / 10;
            }
        }
        System.out.println();
    }

    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
        int n = 0, i = 0;

        while(entrada.hasNext()){
            n = entrada.nextInt();

            numeros(n, i);
            i++;

            if((i % 2) == 0)
                espelho();
        }
        entrada.close();
    }
}