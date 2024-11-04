import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ListExample {
    public static void main(String[] args) {
        // Cria uma lista de inteiros
        List<Integer> list = new ArrayList<>();
        list.add(101);
        list.add(115);
        list.add(30);
        list.add(63);
        list.add(47);
        list.add(20);

        System.out.println("Lista original: " + list);

        // Ordena a lista em ordem crescente
        Collections.sort(list);

        System.out.println("Lista ordenada: " + list);
    }
}
