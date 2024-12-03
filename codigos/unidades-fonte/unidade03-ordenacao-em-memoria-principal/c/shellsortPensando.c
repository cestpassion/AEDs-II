void shellsort(Pokemon *pokemonArray, int tam, int *comparacoes, int *movimentacoes) {
    // Inicializando o gap
    for (int gap = tam / 2; gap > 0; gap /= 2) {
        // Aplicando inserção com gap
        for (int i = gap; i < tam; i++) {
            Pokemon temp = pokemonArray[i];
            int j;

            // Mover os elementos até encontrar a posição correta
            for (j = i; j >= gap; j -= gap) {
                (*comparacoes)++;
                
                // Se o peso for maior ou se o peso for igual e o nome for lexicograficamente maior
                if (pokemonArray[j - gap].weight > temp.weight || 
                    (pokemonArray[j - gap].weight == temp.weight && strcmp(pokemonArray[j - gap].name, temp.name) > 0)) {
                    pokemonArray[j] = pokemonArray[j - gap];
                    (*movimentacoes)++;
                } else {
                    break; // Caso o critério de ordenação seja satisfeito, não é necessário mais comparações
                }
            }

            pokemonArray[j] = temp;
            (*movimentacoes)++;
        }
    }
}