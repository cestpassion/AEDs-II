/*
Crie uma Lista de registros baseada na de inteiros vista na sala de aula.
Sua lista deve conter todos os atributos e métodos existentes na lista de inteiros, contudo, adaptados para a classe
Pokémon. Lembre-se que, na verdade, temos uma lista de ponteiros (ou referências) e cada um deles aponta para um registo.

Neste exercício, faremos inserções, remoções e mostraremos os elementos de nossa lista. Os métodos de inserir e remover
devem operar conforme descrito a seguir, respeitando parâmetros e retornos:
- Primeiro, o void inserirInicio(Pokemon pokemon) insere um registro na primeira posição da Lista e remaneja os demais.
- Segundo, o void inserir(Pokemon pokemon, int posição) insere um registro na posição p da Lista, onde p < n e n é o
  número de registros cadastrados. Em seguida, esse método remaneja os demais registros.
- O void inserirFim(Pokemon pokemon) insere um registro na última posição da Lista.
- O Pokemon removerInicio() remove e retorna o primeiro registro cadastrado na Lista e remaneja os demais.
- O Pokemon remover(int posição) remove e retorna o registro cadastrado na p-ésima posição da Lista e remaneja os demais.
- O Pokemon removerFim() remove e retorna o último registro cadastrado na lista. 

A entrada padrão é composta por duas partes:
- A primeira é igual a entrada da primeira questão.
- As demais linhas correspondem a segunda parte.
  > A primeira linha da segunda parte tem um número inteiro n indicando a quantidade de registros a serem
    inseridos/removidos.
  > Nas próximas n linhas, tem-se n comandos de inserção/remoção a serem processados neste exercício. Cada uma dessas
    linhas tem uma palavra de comando: 
    • II inserir no início,
    • I* inserir em qualquer posição,
    • IF inserir no fim,
    • RI remover no início,
    • R* remover em qualquer posição e
    • RF remover no fim.

No caso dos comandos de inserir, temos também o nome do arquivo que contém o registro a ser inserido.
No caso dos comandos de “em qualquer posição”, temos também esse nome. 
No Inserir, a posição fica imediatamente após a palavra de comando.

A saída padrão tem uma linha para cada registro removido sendo que essa informação será constituída pela palavra “(R)” e
o atributo name.
No final, a saída mostra os atributos relativos a cada registro cadastrado na lista após as operações de inserção e
remoção.
*/

/*
INFO: 

- As listas são um Tipo Abstrato de Dados (TAD) no qual podemos inserir e remover elementos em qualquer posição

- Variáveis:
    > array (de elementos)
    > n (contador)

- Métodos:
    > Construtores
    > Inserção de elemento
        • void inserirInicio(elemento)
        • void inserirFim(elemento)
        • void inserir(elemento, posição)
    > Remoção de elementos
        • elemento removerInicio()
        • elemento removerFim()
        • elemento remover(posição)
    > Mostrar, pesquisar, ordenar, ...
*/

/*
Fila Circular com Alocação Sequencial em C

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

// Definição da estrutura da Lista
typedef struct Lista
{
    int tamPokemonList;
    Pokemon *pokemonList;
    int n;
} Lista;

// Potótipos das funções
void start(PokemonStorage *, Lista *);        // Função para inicializar e alocar os atributos
void ler(PokemonStorage *);                   // Função para a leitura do csv
char *str(char *);                            // Função para alocação dinâmica de string
Pokemon searchIdStorage(PokemonStorage, int); // Função para pesquisar pokemon por id no armazenamento
void imprimir(Pokemon);                       // Função para imprimir os pokemons
// void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// Potótipos das funções - Lista
void inserirInicio(Lista *, Pokemon); // Função para inserir no início da Lista
void inserirFim(Lista *, Pokemon);    // Função para inserir no fim da Lista
void inserir(Lista *, Pokemon, int);  // Função para inserir na p-ésima posição  da Lista
Pokemon removerInicio(Lista *);       // Função para remover no início da Lista
Pokemon removerFim(Lista *);          // Função para remover no fim da Lista
Pokemon remover(Lista *, int);        // Função para remover na p-ésima posição da Lista
void mostrar(Lista);                  // Função para imprimir os pokemon presentes na Lista

// -----------------------------
// HEADER - Fim
// -----------------------------

// FUNÇÃO PRINCIPAL
int main()
{
    PokemonStorage storage;
    Pokemon pokemon;
    Lista list;

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
    free(list.pokemonList);
}

// Função para inicializar e alocar os atributos
void start(PokemonStorage *storage, Lista *list)
{
    storage->tamPokStorage = 0;
    storage->pokStorage = (Pokemon *)malloc(1 * sizeof(Pokemon));

    list->tamPokemonList = 0;
    list->n = 0;
    list->pokemonList = (Pokemon *)malloc(1 * sizeof(Pokemon));
}

// -----------------------------
// POKÉMON: Início
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
// POKÉMON: Fim
// -----------------------------

// -----------------------------
// LISTA: Início
// -----------------------------

// INSERIR:
// Função para inserir no início da Lista
void inserirInicio(Lista *list, Pokemon pokemon)
{
    if (list->n >= list->tamPokemonList)
    {
        list->tamPokemonList++;
        list->pokemonList = (Pokemon *)realloc(list->pokemonList, (list->tamPokemonList + 1) * sizeof(Pokemon));

        if (!list->pokemonList)
        {
            printf("Erro de memória na realocação\n");
            list->tamPokemonList--;
            exit(1);
        }
    }

    // Realoca os elementos para o fim do array
    for (int i = list->n; i > 0; --i)
        list->pokemonList[i] = list->pokemonList[i - 1];

    list->pokemonList[0] = pokemon;
    list->n++;
}

// Função para inserir no fim da Lista
void inserirFim(Lista *list, Pokemon pokemon)
{
    if (list->n >= list->tamPokemonList)
    {
        list->tamPokemonList++;
        list->pokemonList = (Pokemon *)realloc(list->pokemonList, (list->tamPokemonList + 1) * sizeof(Pokemon));

        if (!list->pokemonList)
        {
            printf("Erro de memória na realocação\n");
            list->tamPokemonList--;
            exit(1);
        }
    }

    list->pokemonList[list->n] = pokemon;
    list->n++;
}

// Função para inserir na p-ésima posição  da Lista
void inserir(Lista *list, Pokemon pokemon, int pos)
{
    if (list->n >= list->tamPokemonList)
    {
        list->tamPokemonList++;

        list->pokemonList = (Pokemon *)realloc(list->pokemonList, (list->tamPokemonList + 1) * sizeof(Pokemon));
        if (!list->pokemonList)
        {
            printf("Erro de memória na realocação\n");
            list->tamPokemonList--;
            exit(1);
        }
    }
    if (pos < 0 || pos > list->n)
    {
        printf("Erro! Posição inválida.\nPosicoes validas = 0 a %d\nPosicao inserida = %d\n", list->n, pos);
        exit(1);
    }

    // Realoca os elementos para o fim do array
    for (int i = list->n; i > pos; --i)
        list->pokemonList[i] = list->pokemonList[i - 1];

    list->pokemonList[pos] = pokemon;
    list->n++;
}

// REMOVER:
// Função para remover no início da Lista
Pokemon removerInicio(Lista *list)
{
    if (list->n == 0)
    {
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }

    Pokemon removedPokemon = list->pokemonList[0];
    list->n--;

    for (int i = 0; i < list->n; ++i)
        list->pokemonList[i] = list->pokemonList[i + 1];

    return removedPokemon;
}

// Função para remover no fim da Lista
Pokemon removerFim(Lista *list)
{
    if (list->n == 0)
    {
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }

    return list->pokemonList[--list->n];
}

// Função para remover na p-ésima posição da Lista
Pokemon remover(Lista *list, int pos)
{
    if (list->n == 0)
    {
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }
    if (pos < 0 || pos > list->n)
    {
        printf("Erro! Posição inválida.\n");
        exit(1);
    }

    Pokemon removedPokemon = list->pokemonList[pos];
    list->n--;

    for (int i = pos; i < list->n; ++i)
        list->pokemonList[i] = list->pokemonList[i + 1];

    return removedPokemon;
}

// MOSTRAR:
// Função para imprimir os pokemon presentes na Lista
void mostrar(Lista list)
{
    for (int i = 0; i < list.n; ++i)
    {
        printf("[%d] ", i);
        imprimir(list.pokemonList[i]);
    }
}

// -----------------------------
// LISTA: Fim
// -----------------------------