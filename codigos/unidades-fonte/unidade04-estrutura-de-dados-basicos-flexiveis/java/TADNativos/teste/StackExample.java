import java.util.Collections;
import java.util.Stack;

public class StackExample {
    public static void main(String[] args) {
        // Cria uma pilha de inteiros
        Stack<Integer> stack = new Stack<>();
        stack.push(101);
        stack.push(115);
        stack.push(30);
        stack.push(63);
        stack.push(47);
        stack.push(20);

        System.out.println("Pilha original: " + stack);

        // Ordena a pilha em ordem crescente
        Collections.sort(stack);

        System.out.println("Pilha ordenada: " + stack);
    }
}
