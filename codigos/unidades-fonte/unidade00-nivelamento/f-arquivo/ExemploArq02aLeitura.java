class ExemploArq02aLeitura{
    public static void main(String[] args){
        //Abrir o arquivo texto
        Arq.openRead("exemplo.txt");

        //Ler o arquivo texto
        int inteiro = Arq.readInt();
        double real = Arq.readDouble();
        char caractere = Arq.readChar();
        boolean boleano = Arq.readBoolean();
        String str = Arq.readString();

        Arq.close(); //Fechar o arquivo texto

        //Mostrar os valores lidos na tela
        MyIO.println("inteiro: " + inteiro);
        MyIO.println("real: " + real);
        MyIO.println("caractere: " + caractere);
        MyIO.println("boleano: " + boleano);
        MyIO.println("str: " + str);
    } // Fim main()
} // Fim class
