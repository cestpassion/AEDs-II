/**
 * Leitura de Página HTML
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

/* 
 * Leia duas strings sendo que a primeira é o nome de uma página web e a segunda, seu endereço.
 * Por exemplo, “Pontifícia Universidade Católica de Minas Gerais” e “www.pucminas.br”. Em seguida,
 * mostre na tela o número de vogais (sem e com acento), consoantes e dos padrões “< br >” e
 * “< table >” que aparecem no código dessa página. A entrada padrão é composta por várias linhas.
 * Cada uma contém várias strings sendo que a primeira é um endereço web e as demais o nome dessa
 * página web. A última linha da entrada padrão contém a palavra “FIM”. A saída padrão contém várias
 * linhas sendo que cada uma apresenta o número de ocorrência (valor xi entre parênteses) de cada
 * caractere ou string solicitado. Cada linha de saída será da seguinte forma: a(x1) e(x2) i(x3) o(x4)
 * u(x5) á(x6) é(x7) í(x8) ó(x9) ú(x10) à(x11) è(x12) ì(x13) ò(x14) ù(x15) ã(x16) õ(x17) â(x19) ê(x19)
 * î(x20) ô(x21) û(x22) consoante(x23) < br >(x24) < table >(x25) nomepágina(x26). */
import java.io.*;
import java.net.*;

public class LeituraPaginaHTML{

    /**
     * Verificação se a string recebida é FIM.
     *
     * @param str string digitada pelo usuário
     * @return true / false
     */
    public static boolean isFIM(String str){
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    public static String getHtml(String endereco){
        URL url;
        InputStream is = null;
        BufferedReader br;
        String resp = "", line;

        try {
            url = new URL(endereco);
            is = url.openStream();  // throws an IOException
            br = new BufferedReader(new InputStreamReader(is));

            while ((line = br.readLine()) != null) {
                resp += line + "\n";
            }
        } catch (MalformedURLException mue) {
            mue.printStackTrace();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } 

        try {
            is.close();
        } catch (IOException ioe) {
            // nothing to see here
        }
        
        return resp;
    }

    public static int[] contVogais(String html){
        int[] vogais = {-1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int i = 0; i < html.length(); i++){
            char c = html.charAt(i);
            vogais[0] += c == 'a' ? 1 : 0;
            vogais[1] += c == 'e' ? 1 : 0;
            vogais[2] += c == 'i' ? 1 : 0;
            vogais[3] += c == 'o' ? 1 : 0;
            vogais[4] += c == 'u' ? 1 : 0;
            vogais[5] += c == 225 ? 1 : 0;  // á ou Á
            vogais[6] += c == 233 ? 1 : 0;  // é ou É
            vogais[7] += c == 237 ? 1 : 0;  // í ou Í
            vogais[8] += c == 243 ? 1 : 0;  // ó ou Ó
            vogais[9] += c == 250 ? 1 : 0;  // ú ou Ú
            vogais[10] += c == 224 ? 1 : 0;  // à ou À
            vogais[11] += c == 232 ? 1 : 0;  // è ou È
            vogais[12] += c == 236 ? 1 : 0;  // ì ou Ì
            vogais[13] += c == 242 ? 1 : 0;  // ò ou Ò
            vogais[14] += c == 249 ? 1 : 0;  // ù ou Ù
            vogais[15] += c == 227 ? 1 : 0;  // ã ou Ã
            vogais[16] += c == 245 ? 1 : 0;  // õ ou Õ
            vogais[17] += c == 226 ? 1 : 0;  // â ou Â
            vogais[18] += c == 234 ? 1 : 0;  // ê ou Ê
            vogais[19] += c == 238 ? 1 : 0;  // î ou Î
            vogais[20] += c == 244 ? 1 : 0;  // ô ou Ô
            vogais[21] += c == 251 ? 1 : 0;  // û ou Û            
        }
        return vogais;
    }

    /**
     * Verifica se o caractere é uma consoante.
     *
     * @param c caractere a ser verificado
     * @return true se for uma consoante, false caso contrário
     */
    private static boolean isConsoante(char c) {
        return (c >= 'b' && c <= 'z' && (c != 'e' && c != 'i' && c != 'o' && c != 'u'));
    }

    public static int contConsoantes(String html){
        int consoantes = 0;

        for (int i = 0; i < html.length(); i++)
            consoantes += isConsoante(html.charAt(i)) == true ? 1 : 0;

        return consoantes;
    }

    public static int contBr(String html){
        int br = 0;

        for (int i = 0; i < html.length(); i++){
            if(html.charAt(i) == '<' && html.charAt(i + 1) == 'b' && html.charAt(i + 3) == '>'){
                br++;
                i += 4;
            }
        }
        return br;
    }

    public static int contTable(String html){
        int table = 0;

        for (int i = 0; i < html.length(); i++){
            if(html.charAt(i) == '<' && html.charAt(i + 1) == 't' && html.charAt(i + 6) == '>'){
                table++;
                i += 7;
            }
        }
        return table;
    }

    public static void main(String[] args){
        String nome = "", html = "";

        while (!isFIM(nome = MyIO.readLine())){
            html = getHtml(MyIO.readLine());

            int[] vogais = contVogais(html);
            int consoantes = contConsoantes(html);
            int br = contBr(html);
            int table = contTable(html);

            MyIO.println("a(" + vogais[0] + ") e(" + vogais[1] + ") i(" + vogais[2] + ") o(" + vogais[3] + ") u(" + vogais[4] + ") á(" + vogais[5] +
                        ") é(" + vogais[6] + ") í(" + vogais[7] + ") ó(" + vogais[8] + ") ú(" + vogais[9] + ") à(" + vogais[10] + ") è(" +
                        vogais[11] + ") ì(" + vogais[12] + ") ò(" + vogais[13] + ") ù(" + vogais[14] + ") ã(" + vogais[15] + ") õ(" + vogais[16] +
                        ") â(" + vogais[17] + ") ê(" + vogais[18] + ") î(" + vogais[19] + ") ô(" + vogais[20] + ") û(" + vogais[21] +
                        ") consoante(" + consoantes + ") <br>(" + br + ") <table>(" + table + ") " + nome);
        }
    }
}