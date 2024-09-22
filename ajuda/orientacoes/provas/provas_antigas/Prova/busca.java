import java.util.Scanner;

class busca{
    //Se no terceiro é t, no segundo é duas*t e o segundo é o primeiro sobre 2
    //Pode-se concluir que o primeiro é 2 vezes o segundo portanto 2*2*t ou 4*t
    //A função então recebe o int designado da linha e retorna 4 vezes ele
    public static int clickPrimeiro(int index){
        return index*4;
    }
    //Na main, o scanner lê linha a linha e então chama a função que retorna o int e o imprime.
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String[] entrada = new String[1000];
    int i=0;
    while(sc.hasNext()){
        entrada[i]=sc.nextLine();
        i++;
    }
    for(int j=0; j<i; j++){
        //Como a entrada é em string, se usa a biblioteca Integer para passar um inteiro
        System.out.println(clickPrimeiro(Integer.parseInt(entrada[j])));
    }
    sc.close();
    }
}