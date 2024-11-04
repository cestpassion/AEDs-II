import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.List;
import java.util.ArrayList;

public class QueueExample {
    public static void main(String[] args) {
        // Cria uma fila de inteiros
        Queue<Integer> queue = new LinkedList<>();
        queue.add(101);
        queue.add(115);
        queue.add(30);
        queue.add(63);
        queue.add(47);
        queue.add(20);

        System.out.println("Fila original: " + queue);

        // Converte a fila para uma lista, ordena e reconverte para fila
        List<Integer> list = new ArrayList<>(queue);
        Collections.sort(list);

        // Limpa a fila original e reinserimos os elementos ordenados
        queue.clear();
        queue.addAll(list);

        System.out.println("Fila ordenada: " + queue);
    }
}
