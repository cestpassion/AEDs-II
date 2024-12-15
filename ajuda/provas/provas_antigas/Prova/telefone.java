import java.util.Scanner;

public class telefone {
    //Retorna true caso a string seja "FIM" e false caso contrario
    public static boolean isFim(String s){
        return (s.length()==3 && s.charAt(0)=='F' && s.charAt(1)=='I' && s.charAt(2)=='M');
    }
    //recebe o caracter e retorna o numero (em char) corresponde aquela letra, caso nao seja nenhuma das letras, retorna o proprio caracter
    public static char letraParaNumero(char c){
        char resp=c;
        if(c == 'A' || c == 'B' || c == 'C')
            resp='2';
        if(c == 'D' || c == 'E' || c == 'F')
            resp='3';
        if(c == 'G' || c == 'H' || c == 'I')
            resp='4';
        if(c == 'J' || c == 'K' || c == 'L')
            resp='5';
        if(c == 'M' || c == 'N' || c == 'O')
            resp='6';
        if(c == 'P' || c == 'Q' || c == 'R' || c == 'S')
            resp='7';
        if(c == 'T' || c == 'U' || c == 'V')
            resp='8';
        if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
            resp='9';
        return resp;
    }
    //Transforma a linha em um vetor de caracteres que pode ser mudado, visto que o tipo string e imutável, e caracter por caracter chama
    //a funcao que transforma letra em numero, no final retornando uma string montada pelo vetor de caracter
    public static String telReader(String s){
        char[] linha = s.toCharArray();
        for(int i=0; i<linha.length; i++){
            linha[i] = letraParaNumero(linha[i]);
        }
        String resp = new String(linha);
        return resp;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String[] entrada = new String[1000];
        int i=-1;
        //leitura e contagem de linhas
        do{
            i++;
            entrada[i]=sc.nextLine();
        }while(!isFim(entrada[i]));
        //loop que imprime a saídas
        for(int j=0; j<i; j++){
            System.out.println(telReader(entrada[j]));
        }
        sc.close();
    }
}
