class ExemploArq01Escrita{
    public static void main(String[] args){
        //Abrir o arquivo texto
        Arq.openWrite("exemplo.txt");

        //Escrever no arquivo texto
        Arq.println(1);
        Arq.println(5.3);
        Arq.println('X');
        Arq.println(true);
        Arq.println("Algoritmos");

        Arq.close(); //Fechar o arquivo texto
    } // Fim main()
} // Fim class
