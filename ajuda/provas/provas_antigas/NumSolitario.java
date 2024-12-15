import java.util.*;

class NumSolitario {


public static int Count(int[] baile, int x){
	int count = 0;
	for (int n = 0; n < baile.length;n++){
			if(x == baile[n]){
			count++;
		}
		//System.out.print("(" + count + ") ");
		
	}

return count;
}

public static void main(String[] args){
Scanner sc = new Scanner(System.in);
int x = sc.nextInt();
do {
int i = 0;
int sozinho = 0;
int pares = 0;
	int[] baile = new int[x];
	//System.out.println(x);
    for(i = 0; i < x; i++){
    	baile[i] = sc.nextInt();
    	//System.out.print(baile[i] + " ");
	}
	
	for(i = 0; i < baile.length; i++){
		int y = baile[i];
		if (Count(baile, y) % 2 != 0){
			sozinho = y;
		}
	}

	System.out.println(sozinho);
	
	x = sc.nextInt();
} while(x != 0);
sc.close(); //Encerra o programa
}
}
