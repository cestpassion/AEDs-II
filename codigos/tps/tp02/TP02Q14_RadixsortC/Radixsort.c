/*
Repita a questão de Ordenação por Seleção, contudo, usando o algoritmo Radixsort, fazendo com que a chave de
pesquisa seja o atributo abilities.
O nome do arquivo de log será matrícula radixsort.txt.
(Lembre-se: em caso de empate, o critério de ordenação deverá ser o nome do Pokémon)
*/

/* INFO:

*/

/*
Radixsort em C

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
void swap(Pokemon *, int, int);
void selecao(Pokemon *, int, int *, int *);
void selecaoRecursivo(Pokemon *, int, int, int *, int *);
void shellsort(Pokemon *, int, int *, int *);
void quicksort(Pokemon *, int, int *, int *);
void quicksortImpl(Pokemon *, int *, int *, int, int);
void bubble(Pokemon *, int, int *, int *);
void radixsort(Pokemon *, int, int *, int *);
int getMaxLengthAbilities(Pokemon *, int, int *);
void countingsortRadix(Pokemon *, int, int, int *, int *);
char getCharAtPos(char *, int);

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

    radixsort(pokemonArray, tam, &comparacoes, &movimentacoes);

    clock_t fim = clock();
    double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0; // Em microssegundos

    for (int i = 0; i < tam; i++)
        imprimir(pokemonArray[i]);

    // Criar o arquivo de log
    FILE *log = fopen("files/847503_radixsort.txt", "w");
    if (log == NULL)
    {
        perror("Erro ao criar o arquivo de log");
        return 1;
    }
    fprintf(log, "847503\t%d\t%d\t%.6lf\n", comparacoes, movimentacoes, tempoExecucao);
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
    FILE *file = fopen("files/pokemon.csv", "r");
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
void swap(Pokemon *pokemonArray, int i, int j)
{
    Pokemon temp = pokemonArray[i];
    pokemonArray[i] = pokemonArray[j];
    pokemonArray[j] = temp;
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
        swap(pokemonArray, menor, i);
        (*movimentacoes)++;
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
    swap(pokemonArray, menor, i);
    (*movimentacoes)++;

    // Chama recursivamente para o próximo índice
    selecaoRecursivo(pokemonArray, tam, i + 1, comparacoes, movimentacoes);
}

void insercao(Pokemon *pokemonArray, int tam, int *comparacoes, int *movimentacoes)
{
    for (int i = 1; i < tam; i++)
    {
        Pokemon tmp = pokemonArray[i];
        int j = i - 1;

        (*comparacoes)++;
        while ((j >= 0) && pokemonArray[j].captureRate > tmp.captureRate)
        {
            (*movimentacoes)++;
            pokemonArray[j + 1] = pokemonArray[j];
            j--;
        }
        pokemonArray[j + 1] = tmp;
    }
}

void shellsort(Pokemon *pokemonArray, int tam, int *comparacoes, int *movimentacoes)
{
    int i, j, h;
    Pokemon tmp;

    for (h = 1; h < tam; h = (3 * h) + 1)
        ; // Calcula o h inicial a partir da geração da sequência de lacunas Knuth

    while (h > 0)
    {
        h = (h - 1) / 3; // Atualiza o valor de h

        for (i = h; i < tam; i++)
        {
            tmp = pokemonArray[i];
            j = i;

            // Efetua comparações entre elementos com distância h
            while (j >= h)
            {
                (*comparacoes)++;

                if (pokemonArray[j - h].weight > tmp.weight ||
                    (pokemonArray[j - h].weight == tmp.weight && strcmp(pokemonArray[j - h].name, tmp.name) > 0))
                {
                    pokemonArray[j] = pokemonArray[j - h];
                    j -= h;

                    (*movimentacoes)++;
                }
                else
                {
                    break; // Caso o critério de ordenação seja satisfeito, não é necessário mais comparações
                }
            }
            pokemonArray[j] = tmp;
        }
    }
}

void quicksort(Pokemon *pokemonArray, int tam, int *comparacoes, int *movimentacoes)
{
    quicksortImpl(pokemonArray, comparacoes, movimentacoes, 0, tam - 1);
}

void quicksortImpl(Pokemon *pokemonArray, int *comparacoes, int *movimentacoes, int esq, int dir)
{
    int i = esq;
    int j = dir;
    Pokemon pivo = pokemonArray[(dir + esq) / 2];

    while (i <= j)
    {
        while (pokemonArray[i].generation < pivo.generation ||
               (pokemonArray[i].generation == pivo.generation && strcmp(pokemonArray[i].name, pivo.name) < 0))
        {
            i++;
            (*comparacoes)++;
        }
        while (pokemonArray[j].generation > pivo.generation ||
               (pokemonArray[j].generation == pivo.generation && strcmp(pokemonArray[j].name, pivo.name) > 0))
        {
            j--;
            (*comparacoes)++;
        }

        if (i <= j)
        {
            swap(pokemonArray, i, j);
            i++;
            j--;
            (*movimentacoes)++;
        }
    }
    if (esq < j)
        quicksortImpl(pokemonArray, comparacoes, movimentacoes, esq, j);
    if (i < dir)
        quicksortImpl(pokemonArray, comparacoes, movimentacoes, i, dir);
}

void bubble(Pokemon *pokemonArray, int tam, int *comparacoes, int *movimentacoes)
{
    for (int i = (tam - 1); i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            (*comparacoes)++;

            if (pokemonArray[j].id > pokemonArray[j + 1].id) // Não há necessidade de critério de desempate pois o id é único
            {
                swap(pokemonArray, j, j + 1);
                (*movimentacoes)++;
            }
        }
    }
}

void radixsort(Pokemon *pokemonArray, int tam, int *comparacoes, int *movimentacoes)
{
    int maxLength = getMaxLengthAbilities(pokemonArray, tam, comparacoes);

    // Realiza o counting sort para cada posição de caractere, começando da última posição
    for (int pos = maxLength - 1; pos >= 0; pos--)
    {
        countingsortRadix(pokemonArray, tam, pos, comparacoes, movimentacoes);
    }

    // Desempate por nome
    for (int i = (tam - 1); i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            (*comparacoes)++;

            if (strcmp(pokemonArray[j].abilities[0], pokemonArray[j + 1].abilities[0]) == 0)
            {
                (*comparacoes)++;

                if (strcmp(pokemonArray[j].name, pokemonArray[j + 1].name) > 0)
                {
                    swap(pokemonArray, j, j + 1);
                    (*movimentacoes)++;
                }
            }
        }
    }
}

int getMaxLengthAbilities(Pokemon *pokemonArray, int tam, int *comparacoes)
{
    int maxLength = 0;

    for (int i = 0; i < tam; i++)
    {
        (*comparacoes)++;
        int len = strlen(pokemonArray[i].abilities[0]);

        if (len > maxLength)
        {
            maxLength = len;
        }
    }
    return maxLength;
}

// Função auxiliar para realizar a ordenação pelo dígito (caractere) especificado
void countingsortRadix(Pokemon *pokemonArray, int tam, int pos, int *comparacoes, int *movimentacoes)
{
    int count[256] = {0}; // Para caracteres ASCII (256 possíveis valores).
                          // {0}: O valor 0 na inicialização significa que você está inicializando o primeiro elemento com 0.
                          // Para arrays em C, quando você usa essa forma de inicialização, o compilador automaticamente
                          // preenche o resto do array com zeros.

    Pokemon *output = (Pokemon *)malloc(tam * sizeof(Pokemon));

    // Contagem das ocorrências do caractere na posição 'pos'
    for (int i = 0; i < tam; i++)
    {
        count[getCharAtPos(pokemonArray[i].abilities[0], pos)]++;
    }

    // Transformação da contagem em índice de posição
    for (int i = 1; i < 256; i++)
    {
        count[i] += count[i - 1];
    }

    // Montagem do vetor de saída
    for (int i = tam - 1; i >= 0; i--)
    {
        char ch = getCharAtPos(pokemonArray[i].abilities[0], pos);
        output[count[ch] - 1] = pokemonArray[i];
        count[ch]--;

        (*movimentacoes)++;
    }

    // Copia os elementos ordenados de volta para o vetor original
    for (int i = 0; i < tam; i++)
    {
        pokemonArray[i] = output[i];
        (*movimentacoes)++;
    }

    free(output); // Libera a memória alocada
}

// Função para pegar o caractere na posição 'pos' de uma string
char getCharAtPos(char *str, int pos)
{
    int len = strlen(str);
    if (pos >= len)
    {
        return '\0'; // Retorna '\0' se a posição estiver fora do tamanho da string
    }
    return str[pos];
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