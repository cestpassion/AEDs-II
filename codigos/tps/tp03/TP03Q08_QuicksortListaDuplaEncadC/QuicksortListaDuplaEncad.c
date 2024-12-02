/*
Refaça a Questão “Quicksort” 10 do Trabalho Prático II - com lista duplamente encadeada.
O nome do arquivo de log será matrícula_quicksort2.txt.
*/

/*
INFO:

*/

/*
Quicksort com LISTA DINÂMICA DUPLAMENTE ENCADEADA em C

author: Bruna Furtado da Fonseca
version: Ubuntu 13.2.0-23ubuntu4
*/

// -----------------------------
// HEADER - Início
// -----------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Tipo Celula
typedef struct Celula
{
    Pokemon pokemon;     // Elemento inserido na celula.
    struct Celula *prox; // Aponta a celula prox.
} Celula;

Celula *newCelula(Pokemon pokemon)
{
    Celula *new = (Celula *)malloc(sizeof(Celula));
    new->pokemon = pokemon;
    new->prox = NULL;
    return new;
}

// Construtor da classe que cria uma lista sem elementos
typedef struct FlexList
{
    Celula *primeiro;
    Celula *ultimo;
} FlexList;

// Potótipos das funções
void start(PokemonStorage *, FlexList *);     // Função para inicializar e alocar os atributos
void ler(PokemonStorage *);                   // Função para a leitura do csv
char *str(char *);                            // Função para alocação dinâmica de string
Pokemon searchIdStorage(PokemonStorage, int); // Função para pesquisar pokemon por id no armazenamento
void imprimir(Pokemon);                       // Função para imprimir os pokemons
// void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// Potótipos das funções - Lista Flexível
void inserirInicio(FlexList *, Pokemon); // Função para inserir no início da Lista Flexível
void inserirFim(FlexList *, Pokemon);    // Função para inserir no fim da Lista Flexível
int sizeFlexList(FlexList);
void inserir(FlexList *, Pokemon, int);  // Função para inserir na p-ésima posição  da Lista Flexível
Pokemon removerInicio(FlexList *);       // Função para remover no início da Lista Flexível
Pokemon removerFim(FlexList *);          // Função para remover no fim da Lista Flexível
Pokemon remover(FlexList *, int);        // Função para remover na p-ésima posição da Lista Flexível
void mostrar(FlexList);                  // Função para imprimir os pokemon presentes na Lista Flexível

// -----------------------------
// HEADER - Fim
// -----------------------------

// FUNÇÃO PRINCIPAL
int main()
{
    PokemonStorage storage;
    FlexList list;

    start(&storage, &list);
    ler(&storage);

    char input[50];

    scanf("%s", input);
    while (strcmp(input, "FIM") != 0)
    {
        inserirFim(&list, searchIdStorage(storage, atoi(input)));
        scanf("%s", input);
    }

    int operations; // quantidade de registros a serem inseridos/removidos
    int cont = 0;
    int infos = 0;
    char *pch;
    char subString[3][10];

    scanf("%d", &operations);
    getchar();

    while (cont < operations)
    {
        infos = 0;

        scanf("%[^\n]", input);
        getchar();

        pch = strtok(input, " ");
        while (pch != NULL)
        {
            strcpy(subString[infos], pch); // atribui o tipo tokenizado
            pch = strtok(NULL, " ");
            infos++;
        }

        if (strcmp(subString[0], "II") == 0)
        {
            inserirInicio(&list, searchIdStorage(storage, atoi(subString[1])));
        }
        else if (strcmp(subString[0], "IF") == 0)
        {
            inserirFim(&list, searchIdStorage(storage, atoi(subString[1])));
        }
        else if (strcmp(subString[0], "I*") == 0)
        {
            inserir(&list, searchIdStorage(storage, atoi(subString[2])), atoi(subString[1]));
        }
        else if (strcmp(subString[0], "RI") == 0)
        {
            printf("(R) %s\n", removerInicio(&list).name);
        }
        else if (strcmp(subString[0], "RF") == 0)
        {
            printf("(R) %s\n", removerFim(&list).name);
        }
        else if (strcmp(subString[0], "R*") == 0)
        {
            printf("(R) %s\n", remover(&list, atoi(subString[1])).name);
        }
        cont++;
    }
    mostrar(list);

    // Liberação da memória alocada
    free(storage.pokStorage);
    free(list.primeiro);
    free(list.ultimo);
}

// Função para inicializar e alocar os atributos
void start(PokemonStorage *storage, FlexList *list)
{
    storage->tamPokStorage = 0;
    storage->pokStorage = (Pokemon *)malloc(1 * sizeof(Pokemon));

    Pokemon emptyPokemon = {0, 0, NULL, NULL, NULL, NULL, 0.0, 0.0, 0, NULL, NULL};
    list->primeiro = newCelula(emptyPokemon);
    list->ultimo = list->primeiro;
}

// -----------------------------
// POKÉMON: Início
// -----------------------------

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
// POKÉMON: Fim
// -----------------------------

// -----------------------------
// LISTA DUPLA ENCADEADA: Início
// -----------------------------

// INSERIR:
// Função para inserir no início da Lista Flexível
void inserirInicio(FlexList *list, Pokemon pokemon)
{
    Celula *tmp = newCelula(pokemon);

    tmp->prox = list->primeiro->prox;
    list->primeiro->prox = tmp;

    if (list->primeiro == list->ultimo)
        list->ultimo = tmp;

    tmp = NULL;
}

// Função para inserir no fim da Lista Flexível
void inserirFim(FlexList *list, Pokemon pokemon)
{
    list->ultimo->prox = newCelula(pokemon);
    list->ultimo = list->ultimo->prox;
}

int sizeFlexList(FlexList list)
{
    int size = 0;
    for (Celula *i = list.primeiro; i != list.ultimo; i = i->prox, size++);

    return size;
}

// Função para inserir na p-ésima posição  da Lista Flexível
void inserir(FlexList *list, Pokemon pokemon, int pos)
{
    int size = sizeFlexList(*list); /* O ponteiro (*) na chamada da função serve para desreferenciar
                                    o ponteiro list, convertendo-o de um ponteiro para uma estrutura
                                    FlexList em uma estrutura FlexList direta. */
    if (pos < 0 || pos >= size)
    {
        printf("Erro! Posição inválida.\nPosicoes validas = 0 a %d\nPosicao inserida = %d\n", size, pos);
        exit(1);
    }
    else if (pos == 0)
    {
        inserirInicio(list, pokemon);
    }
    else if (pos == size)
    {
        inserirFim(list, pokemon);
    }
    else
    {
        // Caminhar ate a posicao anterior a insercao
        Celula *i = list->primeiro;
        for (int j = 0; j < pos; j++, i = i->prox);

        Celula *tmp = newCelula(pokemon);

        tmp->prox = i->prox;
        i->prox = tmp;
        tmp = i = NULL;
    }
}

// REMOVER:
// Função para remover no início da Lista Flexível
Pokemon removerInicio(FlexList *list)
{
    if (list->primeiro == list->ultimo)
    {
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }

    Celula *tmp = list->primeiro;
    list->primeiro = list->primeiro->prox;
    Pokemon removedPokemon = list->primeiro->pokemon;

    tmp->prox = NULL;
    free(tmp);

    return removedPokemon;
}

// Função para remover no fim da Lista Flexível
Pokemon removerFim(FlexList *list)
{
    if (list->primeiro == list->ultimo)
    {
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }

    Celula *i;
    for (i = list->primeiro; i->prox != list->ultimo; i = i->prox);
    
    Pokemon removedPokemon = list->ultimo->pokemon;
    list->ultimo = i;

    free(list->ultimo->prox);
    i = list->ultimo->prox = NULL;  

    return removedPokemon;
}

// Função para remover na p-ésima posição da Lista Flexível
Pokemon remover(FlexList *list, int pos)
{
    int size = sizeFlexList(*list);
    Pokemon removedPokemon;

    if (list->primeiro == list->ultimo)
    {
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }
    else if (pos < 0 || pos >= size)
    {
        printf("Erro! Posição inválida.\nPosicoes validas = 0 a %d\nPosicao inserida = %d\n", size, pos);
        exit(1);
    }
    else if (pos == 0)
    {
        removedPokemon = removerInicio(list);
    }
    else if (pos == size - 1)
    {
        removedPokemon = removerFim(list);
    }
    else
    {
        // Caminhar ate a posicao anterior a insercao
        Celula *i = list->primeiro;
        int j;
        for (j = 0; j < pos; j++, i = i->prox);

        Celula *tmp = i->prox;
        removedPokemon = tmp->pokemon;
        i->prox = tmp->prox;

        tmp->prox = NULL;
        free(tmp);
        i = NULL;
    }
    return removedPokemon;
}

// MOSTRAR:
// Função para imprimir os pokemon presentes na Lista Flexível
void mostrar(FlexList list)
{
    int index = 0;
    for (Celula *i = list.primeiro->prox; i != NULL; i = i->prox)
    {
        printf("[%d] ", index++);
        imprimir(i->pokemon);
    }
}
// -----------------------------
// LISTA DUPLA ENCADEADA: Início
// -----------------------------

// -----------------------------
// ORDENAÇÃO QUICKSORT: Início
// -----------------------------



// -----------------------------
// ORDENAÇÃO - QUICKSORT: Fim
// -----------------------------