#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    char *date;
} Pokemon;

int totalPokemon = 0;
Pokemon *pokemon;

void ler();
char* str(char *);
void imprimir(int);
void clone(int);
int compararPokemon(const void *, const void *);
int buscaBinaria(char *, int *);
void criarLog(int, long);

int main() {
    pokemon = (Pokemon*)malloc(1 * sizeof(Pokemon));
    ler();

    // Ordena os Pokémon pelo nome
    qsort(pokemon, totalPokemon, sizeof(Pokemon), compararPokemon);

    // Verificação de debug: Imprimir todos os Pokémon após ordenação
    printf("Pokémon ordenados:\n");
    for (int i = 0; i < totalPokemon; ++i) {
        printf("%s\n", pokemon[i].name);
    }

    char str[100];
    int comparacoes = 0;
    clock_t start = clock(); // Início da contagem do tempo de execução

    // Loop para receber nomes e realizar busca binária
    scanf("%s", str);
    while (strcmp(str, "FIM") != 0) {
        if (buscaBinaria(str, &comparacoes)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        scanf("%s", str);
    }

    // Fim da contagem do tempo de execução
    clock_t end = clock();
    long executionTime = (end - start) * 1000 / CLOCKS_PER_SEC; // Tempo de execução em milissegundos

    criarLog(comparacoes, executionTime);

    free(pokemon); // Liberação da memória alocada
    return 0;
}

// Função para comparar Pokémon pelo nome (usada no qsort)
int compararPokemon(const void *a, const void *b) {
    Pokemon *p1 = (Pokemon *)a;
    Pokemon *p2 = (Pokemon *)b;
    return strcmp(p1->name, p2->name);
}

// Função para realizar busca binária
int buscaBinaria(char *nome, int *comparacoes) {
    int esquerda = 0;
    int direita = totalPokemon - 1;
    
    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = (esquerda + direita) / 2;
        int cmp = strcmp(nome, pokemon[meio].name);

        printf("Comparando %s com %s\n", nome, pokemon[meio].name); // Debug para mostrar comparações

        if (cmp == 0) {
            return 1; // Encontrado
        } else if (cmp < 0) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return 0; // Não encontrado
}

// Função para criar o log
void criarLog(int comparacoes, long executionTime) {
    FILE *logFile = fopen("847503_binaria.txt", "w"); 
    if (logFile) {
        fprintf(logFile, "847503\t%ldms\t%d\n", executionTime, comparacoes);
        fclose(logFile);
    } else {
        printf("Erro ao criar o arquivo de log!\n");
    }
}

// Função para ler os Pokémon do arquivo CSV
void ler() {
    FILE *file = fopen("/tmp/pokemon.csv", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char buffer[1000];
    fgets(buffer, sizeof(buffer), file);

    while (fscanf(file, "%d%*c %d%*c", &pokemon[totalPokemon].id, &pokemon[totalPokemon].generation) != EOF) {
        fscanf(file, "%[^,]%*c", buffer); // name
        pokemon[totalPokemon].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        pokemon[totalPokemon].description = str(buffer);

        // Types
        int cont = 0;
        char *pch;
        fscanf(file, "%[^\"]%*c", buffer); // captura os tipos
        pokemon[totalPokemon].types = (char**)malloc(2 * sizeof(char*)); // aloca espaço inicial para 2 tipos

        pch = strtok(buffer, ",");  // Primeira tokenização por vírgula
        while (pch != NULL) {
            pokemon[totalPokemon].types[cont] = str(pch); // atribui o tipo tokenizado
            cont++;
            pokemon[totalPokemon].types = (char**)realloc(pokemon[totalPokemon].types, (cont + 1) * sizeof(char*)); // realoca para mais tipos
            pch = strtok(NULL, ",");
        }
        pokemon[totalPokemon].types[cont] = NULL; // finaliza com NULL

        // Abilities
        fscanf(file, "%*c%*c%[^]]%*c%*c%*c", buffer); // captura as habilidades
        pokemon[totalPokemon].abilities = (char**)malloc(2 * sizeof(char*)); // aloca espaço inicial para 2 habilidades

        pch = strtok(buffer, "'");
        pokemon[totalPokemon].abilities[0] = str(pch);
        pch = strtok(NULL, "'");
        pch = strtok(NULL, "'");

        cont = 1;
        while (pch != NULL) {
            pokemon[totalPokemon].abilities[cont] = str(pch);
            cont++;
            pokemon[totalPokemon].abilities = (char**)realloc(pokemon[totalPokemon].abilities, (cont + 1) * sizeof(char*)); // realoca para mais habilidades
            pch = strtok(NULL, "'");
            pch = strtok(NULL, "'");
        }
        pokemon[totalPokemon].abilities[cont] = NULL; // finaliza com NULL
        // weight
        cont = 0;
        int comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                pokemon[totalPokemon].weight = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            pokemon[totalPokemon].weight = atof(buffer);
        }

        // height
        cont = 0;
        comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                pokemon[totalPokemon].height = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            pokemon[totalPokemon].height = atof(buffer);
        }

        fscanf(file, "%d%*c", &pokemon[totalPokemon].captureRate); // captureRate

        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        pokemon[totalPokemon].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");

        fscanf(file, "%[^\n]", buffer); // date
        pokemon[totalPokemon].date = str(buffer);

        totalPokemon++;
        pokemon = (Pokemon*)realloc(pokemon, (totalPokemon + 1) * sizeof(Pokemon)); // realoca memória para o próximo Pokémon
    }
    fclose(file);  
}

// Função auxiliar para criar strings dinamicamente
char* str(char *str) {
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);
    return info;
}
