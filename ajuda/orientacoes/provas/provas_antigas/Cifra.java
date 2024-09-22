class Cifra{
	public static int key = 3; // Deslocation to encrypt
	
	public static char char_replace(char c){
		for(int sum = 1; sum <= key; sum++){
			switch(c){
				case 'Z': c = 'A'; break;
				case 'z': c = 'a'; break;
				default : c += 1 ; break; 
			}
				
		}
		return c;
	}

	public static String deslocation(String text){
		char char_array[] = text.toCharArray();
		for(int index = 0; index < char_array.length; index++){
			if(char_array[index] == 'á'){
				char_array[index] = "\uFFFD";
			}else
				char_array[index] = char_replace(char_array[index]);
		}
		
		return String.valueOf(char_array);	
	}
	
	public static void main(String args[]){
		boolean correct = true;
		System.out.println("\uFFFD");
		do{
			String text = MyIO.readLine("");
			correct = text.equals("FIM");
			
			if( ! correct ){
				text = deslocation(text);
				System.out.println(text);
			}
			
		} while( ! correct );
	}
}
