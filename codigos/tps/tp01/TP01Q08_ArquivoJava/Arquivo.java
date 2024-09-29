/**
 * Arquivo
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

 import java.io.*;

 class Arquivo {
     public static void main(String[] args) {
         int n = MyIO.readInt();
 
         try (RandomAccessFile arquivo = new RandomAccessFile("valores.txt", "rw")) {
             for (int i = 0; i < n; i++) {
                 double valor = MyIO.readDouble();
                 arquivo.writeDouble(valor); 
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
 
         try (RandomAccessFile arquivo = new RandomAccessFile("valores.txt", "r")) {
             long tamanhoArquivo = arquivo.length(); 
             long posicao = tamanhoArquivo - 8;  

             while (posicao >= 0) {
                 arquivo.seek(posicao); 
                 double valor = arquivo.readDouble(); 
                 MyIO.println(valor);
                 posicao -= 8; 
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
     }
 }
 