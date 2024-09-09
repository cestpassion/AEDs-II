import java.util.Arrays;
import java.util.Comparator;

public class SortSortSort {

    // Comparator to sort the numbers according to the given rules
    static class CustomComparator implements Comparator<Integer> {
        private int M;

        public CustomComparator(int M) {
            this.M = M;
        }

        @Override
        public int compare(Integer a, Integer b) {
            int modA = a % M;
            int modB = b % M;

            if (modA != modB) {
                return Integer.compare(modA, modB);
            }

            boolean isOddA = Math.abs(a) % 2 != 0;
            boolean isOddB = Math.abs(b) % 2 != 0;

            if (isOddA && isOddB) {
                return Integer.compare(b, a); 
            }
            if (isOddA) {
                return -1; 
            }
            if (isOddB) {
                return 1;
            }

            return Integer.compare(a, b); 
        }
    }

    public static void main(String[] args) {

        while (true) {
            int N = MyIO.readInt();
            int M = MyIO.readInt();

            if (N == 0 && M == 0) {
                break;
            }

            Integer[] vetor = new Integer[N];

            for (int i = 0; i < N; i++) {
                vetor[i] = MyIO.readInt();
            }

            Arrays.sort(vetor, new CustomComparator(M));

            MyIO.println(N + " " + M);
            for (int num : vetor) {
                MyIO.println(num);
            }
        }

        MyIO.println("0 0");
    }
}
