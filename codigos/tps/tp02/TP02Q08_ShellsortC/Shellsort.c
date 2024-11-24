/*
Repita a questão de Ordenação por Seleção, contudo, usando o algoritmo Shellsort, fazendo com que a
chave de pesquisa seja o atributo weight.
O nome do arquivo de log será matrícula shellsort.txt.
(Lembre-se: em caso de empate, o critério de ordenação deverá ser o nome do Pokémon
*/

/* INFO:

*/

/*
Shellsort em C

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

// Potótipos das funções Pokémon
void start(PokemonStorage *);                 // Função para inicializar e alocar os atributos
void ler(PokemonStorage *);                   // Função para a leitura do csv
char *str(char *);                            // Função para alocação dinâmica de string
Pokemon searchIdStorage(PokemonStorage, int); // Função para pesquisar pokemon por id no armazenamento
void imprimir(Pokemon);                       // Função para imprimir os pokemons
// void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// Potótipos das funções de Ordenação
void swap(Pokemon *, int, int, int *);
void selecao(Pokemon *, int, int *, int *);
void selecaoRecursivo(Pokemon *, int, int, int *, int *);

// Potótipos das funções de Pesquisa
int searchSeq(Pokemon *, int, char *);
int searchBin(Pokemon *, int, char *);
int searchSeqRec(Pokemon *, int, char *, int);
int searchBinRec(Pokemon *, char *, int, int);

// -----------------------------
// HEADER - Fim
// -----------------------------

// FUNÇÃO PRINCIPAL
int main()
{
    PokemonStorage storage;

    start(&storage);
    ler(&storage);

    char str[10];
    Pokemon *pokemonArray = (Pokemon *)malloc(1 * sizeof(Pokemon));
    int tam = 0;

    scanf("%s", str);
    while (strcmp(str, "FIM") != 0)
    {
        pokemonArray[tam] = searchIdStorage(storage, atoi(str));
        tam++;
        pokemonArray = (Pokemon *)realloc(pokemonArray, (tam + 1) * sizeof(Pokemon));
        scanf("%s", str);
    }

    int comparacoes = 0;
    int movimentacoes = 0;

    clock_t inicio = clock(); // Medir o tempo de execução

    selecaoRecursivo(pokemonArray, tam, 0, &comparacoes, &movimentacoes);

    clock_t fim = clock();
    double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0; // Em microssegundos

    for (int i = 0; i < tam; i++)
        imprimir(pokemonArray[i]);

    // Criar o arquivo de log
    FILE *log = fopen("847503_shellsort", "w");
    if (log == NULL)
    {
        perror("Erro ao criar o arquivo de log");
        return 1;
    }
    fprintf(log, "847503\t%d\t%d\t%.2lf\n", comparacoes, movimentacoes, tempoExecucao);
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

// -----------------------------
// ORDENAÇÃO - Início
// -----------------------------

// Troca o conteudo de duas posicoes do array
void swap(Pokemon *pokemonArray, int i, int j, int *movimentacoes)
{
    Pokemon temp = pokemonArray[i];
    pokemonArray[i] = pokemonArray[j];
    pokemonArray[j] = temp;
    (*movimentacoes)++;
}

void selecao(Pokemon *pokemonArray, int tam, int *comparacoes, int *movimentacoes)
{
    for (int i = 0; i < (tam - 1); i++)
    {
        int menor = i;
        for (int j = (i + 1); j < tam; j++)
        {
            (*comparacoes)++;
            if (strcmp(pokemonArray[menor].name, pokemonArray[j].name) > 0)
            {
                menor = j;
            }
        }
        swap(pokemonArray, menor, i, movimentacoes);
    }
}

// Função recursiva para ordenar o array usando Selection Sort
void selecaoRecursivo(Pokemon *pokemonArray, int tam, int i, int *comparacoes, int *movimentacoes)
{
    if (i >= tam - 1)
        return;

    // Encontrar o menor elemento no restante do array
    int menor = i;
    for (int j = i + 1; j < tam; j++)
    {
        (*comparacoes)++;
        if (strcmp(pokemonArray[menor].name, pokemonArray[j].name) > 0)
            menor = j;
    }

    // Troca o elemento atual com o menor encontrado
    swap(pokemonArray, menor, i, movimentacoes);

    // Chama recursivamente para o próximo índice
    selecaoRecursivo(pokemonArray, tam, i + 1, comparacoes, movimentacoes);
}

// -----------------------------
// ORDENAÇÃO - Fim
// -----------------------------

// -----------------------------
// PESQUISA - Início
// -----------------------------

// Algoritmo de pesquisa sequencial interativo.
int searchSeq(Pokemon *pokemonArray, int tam, char *name)
{
    int answer = 0;

    for (int i = 0; i < tam; i++)
    {
        if (strcmp(pokemonArray[i].name, name) == 0)
        {
            answer = 1;
            i = tam; // ou break;
        }
    }
    return answer;
}

// Algoritmo de pesquisa binária interativo.
int searchBin(Pokemon *pokemonArray, int tam, char *name)
{
    int answer = 0;
    int right = (tam - 1), left = 0, middle;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (strcmp(name, pokemonArray[middle].name) == 0)
        {
            answer = 1;
            left = right + 1; // ou break;
        }
        else if (strcmp(name, pokemonArray[middle].name) > 0)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return answer;
}

// Algoritmo de pesquisa sequencial recursivo.
int searchSeqRec(Pokemon *pokemonArray, int tam, char *name, int index)
{
    if (index == tam)
        return 0;

    if (strcmp(pokemonArray[index].name, name) == 0)
        return 1;

    return searchSeqRec(pokemonArray, tam, name, ++index);
}

// Algoritmo de pesquisa binária recursivo.
int searchBinRec(Pokemon *pokemonArray, char *name, int left, int right)
{
    int answer;
    int middle = (left + right) / 2;

    if (left > right)
        answer = 0;
    else if (strcmp(name, pokemonArray[middle].name) == 0)
        answer = 1;
    else if (strcmp(name, pokemonArray[middle].name) > 0)
        answer = searchBinRec(pokemonArray, name, ++middle, right);
    else
        answer = searchBinRec(pokemonArray, name, left, --middle);

    return answer;
}

// -----------------------------
// PESQUISA - Fim
// -----------------------------