/**
 * Etiquetas de Noel
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/* 
 * Como de costume, neste ano Noel recebeu muitos pedidos de presentes. Só que em função de alguns imprevistos, não terá como 
 * entregar todos os presentes pessoalmente neste ano. Daí então decidiu utilizar o velho e bom correio tradicional, para alguns 
 * pedidos que podem ser entregues por carta.
 * 
 * Para esta tarefa, pediu ajuda ao elfo Evergreen Xadada, para que ele imprimisse etiquetas a todos os envelopes que serão 
 * destinados a algumas destas crianças, cujo pedido pode ser entregue por carta. Cada uma destas etiquetas deverá conter apenas 
 * o nome da criança e a saudação "Feliz Natal" no respectivo idioma desta criança. Para auxiliar nesta tarefa, Noel disponibilizou 
 * uma tabela com vários idiomas e o nome e o país de cada uma das crianças selecionadas, de acordo com o exemplo abaixo. Você 
 * deve ajudar Evergreen fazendo um programa que imprima estas etiquetas.
 * 
 * 
 * Entrada
 * 
 * A entrada é composta por um único caso de teste. A primeira linha de entrada contém um inteiro N (1 < N < 100) que indica 
 * a quantidade de traduções da palavra "Feliz Natal" existentes na entrada. As próximas N * 2 linhas contém respectivamente 
 * o nome de uma língua seguido da tradução de "Feliz Natal" para esta língua. Segue um inteiro M (1 < M < 100) que indica a 
 * quantidade de crianças que receberão as cartas. As próximas M * 2 linhas conterão, respectivamente, o nome da criança e a 
 * língua nativa desta criança.
 * 
 * Obs.: É garantido que nenhuma tradução apareça repetida ou duplicada e os países de todas as crianças estejam presentes na 
 * relação dos países.
 * 
 * 
 * Saída
 * 
 * Seu programa deverá imprimir todas as etiquetas de acordo com a entrada, conforme o exemplo abaixo, sempre com uma linha 
 * em branco após a impressão de cada uma das etiquetas, inclusive após a última etiqueta.
 */

import java.util.Scanner;

public class EtiquetasDeNoel {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        String[][] idioma = new String[N][2];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < 2; j++){
                idioma[i][j] = sc.nextLine();
            }
        }

        int M = sc.nextInt();
        String[][] crianca = new String [M][2];

        for(int i = 0; i < M; i++){
            crianca[i][0] = sc.nextLine();

            for(int j = 0; j < N; j++){
                crianca[i][1] = sc.nextLine();

                if(crianca[i][1] == idioma[j][0]){
                    crianca[i][1] = idioma[j][1];
                    break;
                }
            }
        } 

        for(int i = 0; i < M; i++){
            for(int j = 0; j < 2; j++){
                System.out.println(crianca[i][j]);
            }
            System.out.println();
        }
        
        sc.close();
    }
}
