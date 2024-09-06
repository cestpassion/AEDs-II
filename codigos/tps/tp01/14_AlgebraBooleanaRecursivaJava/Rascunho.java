/**
 * Álgebra Booleana
 * @author Bruna Furtado da Fonseca
 * @version 2024-07-16
 */

 public class Rascunho {

    public static boolean isFIM(String str) {
        return (str.length() == 1 && str.charAt(0) == '0');
    }

    public static int parseInt(char carac) {
        return carac - 48;
    }

    public static String subString(String str, int inicio, int fim) {
        return inicio < fim ? str.charAt(inicio) + subString(str, inicio + 1, fim) : "";
    }

    public static String replace(String str, char alvo, int parametro) {
        if (str.isEmpty()) return "";
        char primeiro = str.charAt(0);
        String restante = replace(str.substring(1), alvo, parametro);
        return (primeiro == alvo ? (parametro == 1 ? '1' : '0') : primeiro) + restante;
    }

    public static int[] parametros(String str, int indice, int tam) {
        return parametrosAux(str, indice, tam, new int[0], 0);
    }

    private static int[] parametrosAux(String str, int indice, int tam, int[] param, int cont) {
        if (indice >= tam || str.charAt(indice) == ')') return param;

        if (str.charAt(indice) == '0' || str.charAt(indice) == '1') {
            int[] novoParam = new int[cont + 1];
            System.arraycopy(param, 0, novoParam, 0, cont);
            novoParam[cont] = parseInt(str.charAt(indice));
            return parametrosAux(str, indice + 1, tam, novoParam, cont + 1);
        }

        return parametrosAux(str, indice + 1, tam, param, cont);
    }

    public static String not(String str, int indice, int tam, int[] param) {
        String strStart = subString(str, 0, indice - 3);
        int fim = findClosingParen(str, indice, tam);
        String strEnd = subString(str, fim + 1, tam);
        String meio = subString(str, indice + 1, fim);

        for (int i = 0; i < param.length; i++) {
            param[i] = param[i] == 1 ? 0 : 1;
            meio = replace(meio, param[i] == 1 ? '0' : '1', param[i]);
        }

        return strStart + meio + strEnd;
    }

    public static String or(String str, int indice, int tam, int[] param) {
        String strStart = subString(str, 0, indice - 2);
        int fim = findClosingParen(str, indice, tam);
        String strEnd = subString(str, fim + 1, tam);
        int bool = 0;

        for (int p : param) {
            bool |= p;
            if (bool == 1) break;
        }

        return strStart + bool + strEnd;
    }

    public static String and(String str, int indice, int tam, int[] param) {
        String strStart = subString(str, 0, indice - 3);
        int fim = findClosingParen(str, indice, tam);
        String strEnd = subString(str, fim + 1, tam);
        int bool = 1;

        for (int p : param) {
            bool &= p;
            if (bool == 0) break;
        }

        return strStart + bool + strEnd;
    }

    private static int findClosingParen(String str, int indice, int tam) {
        if (indice >= tam || str.charAt(indice) == ')') return indice;
        return findClosingParen(str, indice + 1, tam);
    }

    public static char algebraBooleana(String str) throws Exception {
        if (str.isEmpty()) return '0';

        for (int i = str.length() - 1; i >= 0; i--) {
            if (str.charAt(i) == '(') {
                int[] param;
                switch (str.charAt(i - 1)) {
                    case 't':
                        param = parametros(str, i, str.length());
                        str = not(str, i, str.length(), param);
                        break;
                    case 'r':
                        param = parametros(str, i, str.length());
                        str = or(str, i, str.length(), param);
                        break;
                    case 'd':
                        param = parametros(str, i, str.length());
                        str = and(str, i, str.length(), param);
                        break;
                }
                return algebraBooleana(str);
            }
        }

        return str.indexOf('1') != -1 ? '1' : '0';
    }

    public static void main(String[] args) throws Exception {
        String str;
        while (!isFIM(str = MyIO.readLine())) {
            int qntParametros = parseInt(str.charAt(0));
            int[] parametros = new int[qntParametros];

            for (int i = 0; i < qntParametros; i++) {
                parametros[i] = parseInt(str.charAt((i + 1) * 2));
            }

            str = subString(str, (qntParametros * 2 + 2), str.length());

            for (int i = 0; i < qntParametros; i++) {
                str = replace(str, (char) ('A' + i), parametros[i]);
            }

            MyIO.println(algebraBooleana(str));
        }
    }
}
