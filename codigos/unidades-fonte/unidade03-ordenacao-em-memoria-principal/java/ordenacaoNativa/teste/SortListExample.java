import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class SortListExample {
    public static void main(String[] args) {
        // Define uma lista com valores desordenados
        List<Integer> list = new ArrayList<>();
        list.add(101);
        list.add(115);
        list.add(30);
        list.add(63);
        list.add(47);
        list.add(20);

        // Usa o método Collections.sort() para ordenar a lista em ordem crescente
        Collections.sort(list);

        // Imprime a lista ordenada
        System.out.println("Lista ordenada: " + list);
    }
}
