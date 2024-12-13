/*
Refaça a questão anterior com Tabela Hash Indireta com Lista Simples. A função de transformação será
(ASCII name) mod tamTab onde tamTab (tamanho da tabela) é 21. O nome do arquivo de log será matrícula
hashIndireta.txt.
*/

/* INFO:
 
*/

/*
Tabela Hash Indireta com Lista Simples em C

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

// Potótipos das funções
void start(PokemonStorage *);                 // Função para inicializar e alocar os atributos
void ler(PokemonStorage *);                   // Função para a leitura do csv
char *str(char *);                            // Função para alocação dinâmica de string
Pokemon searchIdStorage(PokemonStorage, int); // Função para pesquisar pokemon por id no armazenamento
void imprimir(Pokemon);                       // Função para imprimir os pokemons
// void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

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

FlexList* newFlexList() {
    FlexList* list = (FlexList*)malloc(sizeof(FlexList));
    list->primeiro = newCelula((Pokemon){0});
    list->ultimo = list->primeiro;
    return list;
}

// -----------------------------
// HEADER - Fim
// -----------------------------

// -----------------------------
// LISTA FLEXÍVEL: Início
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

int sizeFlexList(FlexList *list)
{
    int size = 0;
    for (Celula *i = list->primeiro->prox; i != NULL; i = i->prox, size++);
    return size;
}

// Função para inserir na p-ésima posição da Lista Flexível
void inserir(FlexList *list, Pokemon pokemon, int pos)
{
    int size = sizeFlexList(list); // A alteração aqui foi para passar o ponteiro corretamente para sizeFlexList

    if (pos < 0 || pos > size) // Corrigido o limite para incluir o último elemento válido
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
        // Caminhar até a posição anterior à inserção
        Celula *i = list->primeiro;
        for (int j = 0; j < pos; j++, i = i->prox);

        Celula *tmp = newCelula(pokemon);

        tmp->prox = i->prox;
        i->prox = tmp;
        tmp = i = NULL;
    }
}

// MOSTRAR:
// Função para imprimir os pokemons presentes na Lista Flexível
void mostrar(FlexList *list)
{
    int index = 0;
    for (Celula *i = list->primeiro->prox; i != NULL; i = i->prox)
    {
        printf("[%d] ", index++);
        imprimir(i->pokemon); // Supondo que a função 'imprimir' exista
    }
}

// -----------------------------
// LISTA FLEXÍVEL: Fim
// -----------------------------

typedef struct Tabela{
    FlexList* list[21];
} Tabela;

Tabela* construtorTabela(){
    Tabela* tabela = (Tabela*)malloc(sizeof(Tabela));
    Pokemon emptyPokemon = {0, 0, NULL, NULL, NULL, NULL, 0.0, 0.0, 0, NULL, NULL};

    for(int i = 0; i < 21; i++){
        tabela->list[i] = newFlexList();  // Modificado para usar newFlexList() e não newCelula
    }

    return tabela;
}

int hash(char name[]){
    int soma = 0;

    for(int i = 0; i < strlen(name); i++){
        soma += name[i];
    }

    return soma % 21;
}

void inserirTabela(Tabela* table, Pokemon pokemon){
    int pos = hash(pokemon.name);
    inserir(table->list[pos], pokemon, sizeFlexList(table->list[pos]));  // Modificado para chamar 'inserir'
}

void mostra(Tabela *table) {
    for (int i = 0; i < 21; i++) {
        if (table->list[i]->primeiro->prox != NULL) {
            mostrar(table->list[i]); // Modificado para passar corretamente a lista
        }
    }
}

int compara(char nome[], Pokemon a){
    return strcmp(nome, a.name);
}

int pesquisaLista(FlexList* list, char nome[]){
    for(Celula* i = list->primeiro->prox; i != NULL; i = i->prox){
        if(compara(nome, i->pokemon) == 0){
            return 1;  // Retorna 1 caso encontrado
        }
    }
    return 0;  // Retorna 0 caso não encontrado
}

void pesquisa(Tabela* table, char *name){
    if(pesquisaLista(table->list[hash(name)], name)){
        printf(" (Posicao: %d) SIM\n", hash(name));
    }
    else {
        printf(" NAO\n");
    }
}

// FUNÇÃO PRINCIPAL
int main()
{
    PokemonStorage storage;
    Pokemon pokemon;
    Tabela* tabela = construtorTabela();

    start(&storage);
    ler(&storage);

    char str[10];

    scanf("%s", str);
    while (strcmp(str, "FIM") != 0)
    {
        inserirTabela(tabela, searchIdStorage(storage, atoi(str)));
        scanf("%s", str);
    }

    scanf("%s", str);
    while (strcmp(str, "FIM") != 0)
    {
        printf("=> %s:", str);
        pesquisa(tabela, str);
        scanf("%s", str);
    }

    free(storage.pokStorage); // Liberação da memória alocada
}

// Função para inicializar e alocar os atributos
void start(PokemonStorage *storage)
{
    storage->tamPokStorage = 0;
    storage->pokStorage = (Pokemon *)malloc(1 * sizeof(Pokemon));
}

// -----------------------------
// POKÉMON - Início
// -----------------------------

// Função para a leitura do csv
void ler(PokemonStorage *s)
{
    FILE *file = fopen("/tmp/pokemon.csv", "r");
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
// POKÉMON - Fim
// -----------------------------