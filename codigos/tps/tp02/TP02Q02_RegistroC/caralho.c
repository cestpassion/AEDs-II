#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura Pokemon
typedef struct Pokemon {
    int id;
    int generation;
    char *name;
    char *description;
    char **types;
    char **abilities;
    double weight;
    double height;
    int captureRate;
    char *isLegendary;
    char *captureDate;
} Pokemon;

Pokemon *pokemon;
int totalPokemons = 0;

void ler();
void imprimir(int);
int get(int);
char* str(char*);
int sizeStringsArray(char **);

// Função principal --------------------------------------------------------------------------
int main() {
    pokemon = (Pokemon*)malloc(802 * sizeof(Pokemon));

    ler();

    char str[10];
    int index;

    while (scanf("%s", str) == 1 && strcmp(str, "FIM") != 0) {
        index = atoi(str);
        imprimir(index);
    }

    // Liberar memória alocada
    for (int i = 0; i < totalPokemons; i++) {
        free(pokemon[i].name);
        free(pokemon[i].description);
        free(pokemon[i].types);
        free(pokemon[i].abilities);
        free(pokemon[i].isLegendary);
        free(pokemon[i].captureDate);
    }

    free(pokemon);

    return 0;
}

// Função para ler o arquivo CSV e popular a estrutura Pokemon
void ler() {
    FILE *file = fopen("pokemon.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char buffer[1000];
    fgets(buffer, sizeof(buffer), file);  // Ignora o cabeçalho

    while (totalPokemons < 802 && fgets(buffer, sizeof(buffer), file)) {
        // Leitura dos campos no CSV
        fscanf(file, "%d%*c %d%*c", &pokemon[totalPokemons].id, &pokemon[totalPokemons].generation);

        fscanf(file, "%[^,]%*c", buffer);  // name
        pokemon[totalPokemons].name = str(buffer);

        fscanf(file, "%[^,]%*c", buffer);  // description
        pokemon[totalPokemons].description = str(buffer);

        // types
        fscanf(file, "%[^\"]%*c", buffer);
        char *pch = strtok(buffer, ",");
        pokemon[totalPokemons].types = (char**)malloc(2 * sizeof(char*));

        int count = 0;
        while (pch != NULL) {
            pokemon[totalPokemons].types = (char**)realloc(pokemon[totalPokemons].types, (count + 1) * sizeof(char*));
            pokemon[totalPokemons].types[count++] = str(pch);
            pch = strtok(NULL, ",");
        }
        pokemon[totalPokemons].types = (char**)realloc(pokemon[totalPokemons].types, (count + 1) * sizeof(char*));
        pokemon[totalPokemons].types[count] = NULL;

        // abilities
        fscanf(file, "%[^\"]%*c%*c", buffer);
        pch = strtok(buffer, " ,[]'");
        pokemon[totalPokemons].abilities = (char**)malloc(2 * sizeof(char*));

        count = 0;
        while (pch != NULL) {
            pokemon[totalPokemons].abilities = (char**)realloc(pokemon[totalPokemons].abilities, (count + 1) * sizeof(char*));
            pokemon[totalPokemons].abilities[count++] = str(pch);
            pch = strtok(NULL, " ,[]'");
        }
        pokemon[totalPokemons].abilities = (char**)realloc(pokemon[totalPokemons].abilities, (count + 1) * sizeof(char*));
        pokemon[totalPokemons].abilities[count] = NULL;

        fscanf(file, "%[^,]%*c", buffer);  // weight
        pokemon[totalPokemons].weight = strtod(buffer, NULL);

        fscanf(file, "%[^,]%*c", buffer);  // height
        pokemon[totalPokemons].height = strtod(buffer, NULL);

        fscanf(file, "%d%*c", &pokemon[totalPokemons].captureRate);  // captureRate

        fscanf(file, "%[^,]%*c", buffer);  // isLegendary
        pokemon[totalPokemons].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");

        fscanf(file, "%[^\n]", buffer);  // captureDate
        pokemon[totalPokemons].captureDate = str(buffer);

        totalPokemons++;
    }

    fclose(file);
}

// Função para imprimir os dados de um Pokémon
void imprimir(int searchId) {
    int index = get(searchId);

    printf("[#%d -> %s: %s - ", pokemon[index].id, pokemon[index].name, pokemon[index].description);

    // Imprimir tipos
    int numTypes = sizeStringsArray(pokemon[index].types);
    printf("['%s'", pokemon[index].types[0]);
    for (int i = 1; i < numTypes; i++) {
        printf(", '%s'", pokemon[index].types[i]);
    }
    printf("] - ");

    // Imprimir habilidades
    int numAbilities = sizeStringsArray(pokemon[index].abilities);
    printf("['%s'", pokemon[index].abilities[0]);
    for (int i = 1; i < numAbilities - 1; i++) {
        printf(", '%s'", pokemon[index].abilities[i]);
    }
    printf("'%s'] - ", pokemon[index].abilities[numAbilities - 1]);

    // Imprimir outros atributos
    printf("%.1lfkg - %.1lfm - %d - %s - %d gen] - %s\n",
           pokemon[index].weight, pokemon[index].height,
           pokemon[index].captureRate, pokemon[index].isLegendary,
           pokemon[index].generation, pokemon[index].captureDate);
}

// Função para buscar o índice de um Pokémon por ID
int get(int searchId) {
    for (int i = 0; i < totalPokemons; i++) {
        if (searchId == pokemon[i].id) {
            return i;
        }
    }
    return -1; // Retorna -1 se o Pokémon não for encontrado
}

// Função para alocar uma string dinamicamente
char* str(char *str) {
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);
    return info;
}

// Função para calcular o tamanho de um array de strings
int sizeStringsArray(char *array[]) {
    int size = 0;
    while (array[size] != NULL) {
        size++;
    }
    return size;
}
