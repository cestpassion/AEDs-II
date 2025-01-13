public class Teste{
    static public void main(String[] args){
        String str = "oscar";
        int soma = 0;

        for(int i = 0; i < str.length(); i++){
            soma += (int)str.charAt(i);
        }

        System.out.println(soma);
    }
}