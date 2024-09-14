public class OpShiftRightLeft {
    public static void main (String[] args){
        int y = 23, x = 23, z = 2, w = 1024;

        x = x >> 1; // 11 - divisão por 2
        y = y << 1; // 46 - multiplicação por 2
        z <<= 9; // 1024 - potencia de 2 elevado a 10
        w >>= 10; // 1 - lg(1024) = 10
        
        System.out.println("[" + x + " - " + y + " - " + z + " - " + w + "]"); // [11 - 46]
    }
}

/*
 * Os operadores shift right e left (>> e <<) deslocam os bits
 * para direita e esquerda e inserem um zero na posição vazia
 * Na prática, temos, uma divisão ou multiplicação por dois
*/