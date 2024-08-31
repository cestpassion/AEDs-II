public class Algebra {
    public static void main(String[] args) {
        String entrada = MyIO.readLine();
        while(!verificaFim(entrada)){
        String algebraBooleana = tradeLetters(entrada);
        String result = makeAlgebra(algebraBooleana);
        while(result.length() > 1){
        result = makeAlgebra(result);
        }
        MyIO.println(result);
        entrada = MyIO.readLine();
        }
    }

    
    public static String tradeLetters(String texto) {

        char[] charMap = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                'V', 'W', 'X', 'Y', 'Z' };

        int qntVariables = texto.charAt(0) - '0';

        for (int i = 2; i <= qntVariables * 2; i += 2) {
            char numero = texto.charAt(i);
            if (i / 2 - 1 < charMap.length) {
                texto = texto.replace(charMap[i / 2 - 1], numero);
            }
        }
        texto = texto.substring(qntVariables * 2 + 2);
        return texto;
    }

    public static String makeAlgebra(String texto) {
        int posExpression = findExpression(texto);
        int posEndExpression = findEndExpression(texto, posExpression);

        String expression = texto.substring(posExpression, posEndExpression + 1);
        expression = expression.replaceAll("[^0-9]", "");

        int[] numeros = new int[expression.length()];
        for (int i = 0; i < expression.length(); i++) {
            numeros[i] = expression.charAt(i) - '0';
        }

        switch (texto.charAt(posExpression - 1)) {
            case 't':
                numeros[0] = numeros[0] == 1 ? 0 : 1;
                if (posExpression - 3 <= 0)
                    texto = String.valueOf(numeros[0]);
                else
                    texto = texto.substring(0, posExpression - 3) + String.valueOf(numeros[0])
                            + texto.substring(posEndExpression + 1, texto.length());
                break;
            case 'd':
                for (int i = 0; i < numeros.length; i++) {
                    if (numeros[i] == 0)
                        numeros[0] = 0;
                }
                if (posExpression - 3 <= 0)
                    texto = String.valueOf(numeros[0]);
                else
                    texto = texto.substring(0, posExpression - 3) + String.valueOf(numeros[0])
                            + texto.substring(posEndExpression + 1, texto.length());
                break;
            case 'r':
                for (int i = 0; i < numeros.length; i++) {
                    if (numeros[i] == 1)
                        numeros[0] = 1;
                }
                if (posExpression - 3 <= 0)
                    texto = String.valueOf(numeros[0]);
                else
                    texto = texto.substring(0, posExpression - 2) + String.valueOf(numeros[0])
                            + texto.substring(posEndExpression + 1, texto.length());
                break;
            default:
                break;
        }

        return texto;
    }

    public static int findExpression(String texto) {
        int pos = texto.length() - 1;
        int posExpression = 0;

        while (pos > 0) {
            if (texto.charAt(pos) == '(') {
                return pos;
            }
            pos--;
        }

        return posExpression;
    }

    public static int findEndExpression(String texto, int pos) {
        while (pos < texto.length()) {
            if (texto.charAt(pos) == ')') {
                return pos;
            }
            pos++;
        }

        return 0;
    }

    public static boolean verificaFim(String texto) {
        return (texto.charAt(0) == '0');
    }    
}
