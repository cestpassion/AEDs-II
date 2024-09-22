import java.util.*;

class Severino {

public static int[] Ordenar(int[] array) {
      //Array para contar o numero de ocorrencias de cada elemento
      int n = array.length;
      
      int[] count = new int[getMaior(array) + 1];
      int[] ordenado = new int[n];

      //Inicializar cada posicao do array de contagem 
		for (int i = 0; i < count.length; count[i] = 0, i++);

      //Agora, o count[i] contem o numero de elemento iguais a i
      for (int i = 0; i < n; count[array[i]]++, i++);

      //Agora, o count[i] contem o numero de elemento menores ou iguais a i
      for(int i = 1; i < count.length; count[i] += count[i-1], i++);

      //Ordenando
      for(int i = n-1; i >= 0; ordenado[count[array[i]]-1] = array[i], count[array[i]]--, i--);

      //Copiando para o array original
      for(int i = 0; i < n; array[i] = ordenado[i], i++);
      
      return array;
   }

	public static int getMaior(int[] array) {
	   int maior = array[0];

		for (int i = 0; i < array.length; i++) {
         if(maior < array[i]){
            maior = array[i];
         }
		}
	   return maior;	
	}

public static void main(String[] args){
Scanner sc = new Scanner(System.in);
while(sc.hasNext()){
	int x = sc.nextInt();	
    	int[] livros = new int[x];
    	for (int i = 0; i < x; i++){
    	livros[i] = sc.nextInt();
    	}
    	//System.out.println("tam"+livros.length);
    	
    	livros = Ordenar(livros);
    	for(int i = 0; i < livros.length; i++){
    		for(int n = 0; n < 4 - (livros[i]+"").length();n++){
    			System.out.print('0');
    		}
    		System.out.println(livros[i]);
    	}
}
sc.close(); //Encerra o programa
}
}
