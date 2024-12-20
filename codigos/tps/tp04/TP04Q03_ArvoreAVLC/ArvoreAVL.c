/*
Refaça a primeira questão deste trabalho com árvore AVL em C.
O nome do arquivo de log será matrícula avl.txt.
*/

/* INFO:
 
*/

/*
Arvore AVL em C

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

// -----------------------------
// HEADER - Fim
// -----------------------------

typedef struct No{
    Pokemon pokemon;
    struct No* dir;
    struct No* esq;
}No;

No* newNo(Pokemon pokemon){
    No* new = (No*) malloc(sizeof(No));
    new->pokemon = pokemon;
    new->dir = new->esq = NULL;

    return new;
}

typedef struct ArvoreAVL{
    No* raiz;
}ArvoreAVL;

ArvoreAVL* newArvoreAVL(){
    ArvoreAVL* new = (ArvoreAVL*) malloc(sizeof(ArvoreAVL));
    new->raiz = NULL;

    return new;
}

int compararNomeComPokemonPokemon(Pokemon a, Pokemon b){
    return strcmp(a.name, b.name);
} 

int compararNomeComPokemon(char *name, Pokemon b){
    return strcmp(name, b.name);
} 

No* rotacionarDir(No* i){
        No* tmp = i->esq;
        i->esq = tmp->dir;
        tmp->dir = i;

        return tmp;
    }

No* rotacionarEsq(No* i){
        No* tmp = i->dir;
        i->dir = tmp->esq;
        tmp->esq = i;

        return tmp;
    }

int getAltura(No* i){
    if(i == NULL){
        return -1;
    }
    int alturaEsq = getAltura(i->esq) + 1;
    int alturaDir = getAltura(i->dir) + 1;

    int altura = (alturaEsq > alturaDir ? alturaEsq : alturaDir);
    return altura; 
}

int getFator(No* i){
        int alturaEsq = getAltura(i->esq) + 1;
        int alturaDir = getAltura(i->dir) + 1;

        return (alturaDir - alturaEsq);

}

No* inserir(No* i, Pokemon pokemon){
    if(i == NULL) {
        i = newNo(pokemon);
    } else if (compararNomeComPokemonPokemon(pokemon, i->pokemon) > 0){
        i->dir = inserir(i->dir, pokemon);
    } else if (compararNomeComPokemonPokemon(pokemon, i->pokemon) < 0){
        i->esq = inserir(i->esq, pokemon);
    } else {
        printf("Erro!");
    }

    if(getFator(i) == -2) {
            if(getFator(i->esq) == 1){
                i->esq = rotacionarEsq(i->esq); 
            }
            i = rotacionarDir(i);

        } else if(getFator(i) == 2) {
            if(getFator(i->dir) == -1){
                i->dir = rotacionarDir(i->dir);
            }
            i = rotacionarEsq(i);
        }

    return i;
}

void pesquisa(No* i, char *name){
    if(i == NULL){
        printf(" NAO\n");
    }else if(compararNomeComPokemon(name, i->pokemon) > 0){
        printf(" dir");
        pesquisa(i->dir, name);
    }else if(compararNomeComPokemon(name, i->pokemon) < 0){
        printf(" esq");
        pesquisa(i->esq, name);
    }else{
        printf(" SIM\n");
    }
}

// FUNÇÃO PRINCIPAL
int main()
{
    PokemonStorage storage;
    Pokemon pokemon;
    ArvoreAVL *avl = newArvoreAVL();

    start(&storage);
    ler(&storage);

    char str[50];

    scanf("%s", str);
    while (strcmp(str, "FIM") != 0)
    {
        avl->raiz = inserir(avl->raiz, searchIdStorage(storage, atoi(str)));
        scanf("%s", str);
    }

    scanf("%s", str);
    while (strcmp(str, "FIM") != 0)
    {
        printf("%s\nraiz", str);
        pesquisa(avl->raiz, str);
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