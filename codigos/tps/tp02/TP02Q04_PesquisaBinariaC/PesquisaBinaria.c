/*
Repita a questão anterior, contudo, usando a Pesquisa Binária. A entrada e a saída padrão serão iguais as da
questão anterior. O nome do arquivo de log será matrícula binaria.txt. A entrada desta questão não está ordenada
*/

/*
Pesquisa Binária em C

author: Bruna Furtado da Fonseca
version: Ubuntu 13.2.0-23ubuntu4
*/

// -----------------------------
// HEADER - Início
// -----------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para armazenar informações do Pokemon
typedef struct Pokemon
{
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

// Estrutura para armazenar um conjunto de Pokémons
typedef struct PokemonStorage
{
    int tamPokStorage;
    Pokemon *pokStorage;
} PokemonStorage;

// Potótipos das funções
void start(PokemonStorage *);                 // Função para inicializar e alocar os atributos
void ler(PokemonStorage *);                   // Função para a leitura do csv
char *str(char *);                            // Função para alocação dinâmica de string
Pokemon searchIdStorage(PokemonStorage, int); // Função para pesquisar pokemon por id no armazenamento
void imprimir(Pokemon);                       // Função para imprimir os pokemons
// void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// -----------------------------
// HEADER - Fim
// -----------------------------

// Função de comparação para ordenar os nomes em ordem lexicográfica.
int compEord(const void *a, const void *b) {
    const Pokemon *p1 = (const Pokemon *)a;
    const Pokemon *p2 = (const Pokemon *)b;
    return strcmp(p1->name, p2->name);
}

// Algoritmo de pesquisa binária recursivo.
int searchBinRec(Pokemon *pokemonArray, char *name, int left, int right) {
    if (left > right) 
        return 0; // Não encontrado

    int middle = (left + right) / 2;

    if (strcmp(name, pokemonArray[middle].name) == 0)
        return 1; // Encontrado
    else if (strcmp(name, pokemonArray[middle].name) > 0) 
        return searchBinRec(pokemonArray, name, middle + 1, right); // Pesquisar na direita
    else 
        return searchBinRec(pokemonArray, name, left, middle - 1); // Pesquisar na esquerda
}

int main()
{
    PokemonStorage storage;

    start(&storage);
    ler(&storage);

    char str[10];
    Pokemon *pokemonArray = (Pokemon*)malloc(1 * sizeof(Pokemon));
    int tam = 0;

    scanf("%s", str);
    while (strcmp(str, "FIM") != 0)
    {
        pokemonArray[tam] = searchIdStorage(storage, atoi(str));
        tam++;
        pokemonArray = (Pokemon*)realloc(pokemonArray, (tam + 1) * sizeof(Pokemon));
        scanf("%s", str);
    }

    // int tamanho = sizeof(pokemonArray) / sizeof(pokemonArray[0]); // Calcula o número de elementos no pokemonArray

    // Ordena o array de strings usando qsort
    // Parâmetros:
    // 1. Ponteiro para o pokemonArray,
    // 2. Número de elementos,
    // 3. Tamanho de cada elemento (em bytes),
    // 4. Função de comparação.
    qsort(pokemonArray, tam, sizeof(Pokemon), compEord);

    int comp = 0;
    clock_t inicio = clock(); // Medir o tempo de execução

    scanf("%s", str);
    while (strcmp(str, "FIM") != 0)
    {
        comp++;
        if(searchBinRec(pokemonArray, str, 0, (tam-1)) == 1)
            printf("SIM\n");
        else
            printf("NAO\n");

        scanf("%s", str);
    }

    clock_t fim = clock();
    double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0; // Em microssegundos

    // Criar o arquivo de log
    FILE *log = fopen("847503_binaria.txt", "w");
    if (log == NULL) {
        perror("Erro ao criar o arquivo de log");
        return 1;
    }
    fprintf(log, "847503\t%.2lf\t%d\n", tempoExecucao, comp);
    fclose(log);

    // Liberação da memória alocada
    free(storage.pokStorage);
    free(pokemonArray);
}

// Função para inicializar e alocar os atributos
void start(PokemonStorage *storage)
{
    storage->tamPokStorage = 0;
    storage->pokStorage = (Pokemon *)malloc(1 * sizeof(Pokemon));
}

// Função para a leitura do csv
void ler(PokemonStorage *s)
{
    FILE *file = fopen("pokemon.csv", "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char buffer[1000];
    fgets(buffer, sizeof(buffer), file);

    while (fscanf(file, "%d%*c %d%*c", &s->pokStorage[s->tamPokStorage].id, &s->pokStorage[s->tamPokStorage].generation) != EOF)
    {                                     // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        s->pokStorage[s->tamPokStorage].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        s->pokStorage[s->tamPokStorage].description = str(buffer);

        // Types
        int cont = 0;
        char *pch;

        fscanf(file, "%[^\"]%*c", buffer);                                           // captura os tipos
        s->pokStorage[s->tamPokStorage].types = (char **)malloc(2 * sizeof(char *)); // aloca espaço inicial para 2 tipos

        pch = strtok(buffer, ","); // Primeira tokenização por vírgula
        while (pch != NULL)
        {
            s->pokStorage[s->tamPokStorage].types[cont] = str(pch); // atribui o tipo tokenizado
            cont++;
            s->pokStorage[s->tamPokStorage].types = (char **)realloc(s->pokStorage[s->tamPokStorage].types, (cont + 1) * sizeof(char *)); // realoca para mais tipos
            pch = strtok(NULL, ",");
        }
        s->pokStorage[s->tamPokStorage].types[cont] = NULL; // finaliza com NULL

        // Abilities

        fscanf(file, "%*c%*c%[^]]%*c%*c%*c", buffer);                                    // captura as habilidades
        s->pokStorage[s->tamPokStorage].abilities = (char **)malloc(2 * sizeof(char *)); // aloca espaço inicial para 2 habilidades

        pch = strtok(buffer, "'"); // Primeira tokenização por vírgula

        s->pokStorage[s->tamPokStorage].abilities[0] = str(pch);
        pch = strtok(NULL, "'");
        pch = strtok(NULL, "'");

        cont = 1;
        while (pch != NULL)
        {
            s->pokStorage[s->tamPokStorage].abilities[cont] = str(pch);

            cont++;
            s->pokStorage[s->tamPokStorage].abilities = (char **)realloc(s->pokStorage[s->tamPokStorage].abilities, (cont + 1) * sizeof(char *)); // realoca para mais habilidades
            pch = strtok(NULL, "'");
            pch = strtok(NULL, "'");
        }
        s->pokStorage[s->tamPokStorage].abilities[cont] = NULL; // finaliza com NULL

        // weight
        cont = 0;
        int comma = 0;
        while (comma < 1)
        {
            buffer[cont] = fgetc(file);
            if (buffer[cont] == ',')
            {
                comma++;
                s->pokStorage[s->tamPokStorage].weight = 0.0;
                break;
            }
            else
            {
                cont++;
            }
        }

        if (cont > 1)
        {
            buffer[cont + 1] = '\0';
            s->pokStorage[s->tamPokStorage].weight = atof(buffer);
        }

        // height
        cont = 0;
        comma = 0;
        while (comma < 1)
        {
            buffer[cont] = fgetc(file);
            if (buffer[cont] == ',')
            {
                comma++;
                s->pokStorage[s->tamPokStorage].height = 0.0;
                break;
            }
            else
            {
                cont++;
            }
        }

        if (cont > 1)
        {
            buffer[cont + 1] = '\0';
            s->pokStorage[s->tamPokStorage].height = atof(buffer);
        }

        fscanf(file, "%d%*c", &s->pokStorage[s->tamPokStorage].captureRate); // captureRate

        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        s->pokStorage[s->tamPokStorage].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");

        fscanf(file, "%[^\n]", buffer); // date
        s->pokStorage[s->tamPokStorage].date = str(buffer);

        s->tamPokStorage++;
        s->pokStorage = (Pokemon *)realloc(s->pokStorage, (s->tamPokStorage + 1) * sizeof(Pokemon)); // realoca memória para o próximo Pokémon
    }
    fclose(file);
}

// Função para alocação dinâmica de string
char *str(char *str)
{
    char *info = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);
    return info;
}

// Função para pesquisar pokemon por id no armazenamento
Pokemon searchIdStorage(PokemonStorage s, int id)
{
    for (int i = 0; i < s.tamPokStorage; ++i)
    {
        if (id == s.pokStorage[i].id)
        {
            return s.pokStorage[i];
        }
    }
    printf("Pokemon com o id = %d não encontrado no armazenamento\n", id);
    exit(1);
}

// Função para imprimir os pokemons
void imprimir(Pokemon pokemon)
{
    printf("[#%d -> %s: %s - ", pokemon.id, pokemon.name, pokemon.description);

    // Types
    int cont = 0;
    printf("[");
    while (pokemon.types[cont] != NULL)
    {
        if (cont > 0)
            printf(", ");
        printf("'%s'", pokemon.types[cont]);
        cont++;
    }
    printf("] - [");

    // Abilities
    cont = 0;
    while (pokemon.abilities[cont] != NULL)
    {
        if (cont > 0)
            printf(", ");
        printf("'%s'", pokemon.abilities[cont]);
        cont++;
    }
    printf("] - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", pokemon.weight, pokemon.height, pokemon.captureRate,
           pokemon.isLegendary, pokemon.generation, pokemon.date);
}