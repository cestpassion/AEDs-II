/*
Refazer a Questão 4 “Fila Circular com Alocação Sequencial”. Lembre-se que essa fila terá tamanho máximo
igual a cinco.
*/

/* INFOS:

- As filas são um Tipo Abstrato de Dados (TAD) no qual o primeiro elemento que entra é o primeiro a sair
    > First In, First Out (FIFO)

- Tem basicamente os métodos de...
    > inserir (enfileirar, enqueue) - I
    > e remover (desenfileirar, dequeue) - R

- Primeira solução IF e RI (REMOÇÃO não é eficiente)
    > Cada remoção: Move todos os elementos já cadastrados
    > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
                                            • Primeira remoção: Retorna o 1 e move todos os demais
       |1| |3| |5| |7|                          P:  3   5   7   X
                                            • Segunda remoção: Retorna o 3 e move todos os demais
                                                S:  5   7   X   X

- Segunda solução II e RF (INSERÇÃO não é eficiente)
    > Cada inserção: Move todos os elementos já cadastrados
    > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
                                            • Primeira remoção: Retorna o 1
       |1|                                      P:  7   5   3   X
       |3|  1                               • Segunda remoção: Retorna o 3
       |5|  3   1                               S:  7   5   X   X
       |7|  5   3   1

*/
/* - Como implementar uma fila sem que uma das operações desloque todos os elementos?
    > Fazendo uma fila circular, ou seja, depois da última posição, retornamos para a primeira
    > IF RI
         ___________________                      0
        |   |   |   |   |   |                    ___
        '---'---'---'---'---'             5  ___|   |___  1
          0   1   2   4   5                 |   |---|   |
                                            |---|   |---|
                                            |   |___|   |
                                          4 '---|   |---' 2
                                                '---'
    > Variáveis:                                  3
        • array (de elementos);
        • int primeiro, ultimo;
    > Métodos:
        • Construtores
            =>  Fila() { ... }
            =>  Fila(int tamanho){ ... }
        • Inserção de elemento
            =>  void inserir(elemento){ ... }
        • Remoção de elementos
            =>  elemento remover(){ ... }
        • Mostrar, pesquisar, ordenar, ...

    > Vamos criar uma fila com tamanho cinco e efetuar as operações I(1), I(3), I(5), I(7), I(9),
      I(2), R(), R(), I(4), I(6), R(), I(8), M()

        class Fila{
            private int[] array;
            private int primeiro, ultimo;

            public Fila(){
                this(5)
            }

            public Fila(int tamanho){
                array = new int[tamanho+1]; // Vamos reservar uma unidade a mais, contudo, nossa
                primeiro = ultimo = 0;      // fila caberá somente a quantidade solicitada
            }
        }
             pu                                  0 pu
             ___________________                ___
            |   |   |   |   |   |        5  ___|   |___  1
            '---'---'---'---'---'          |   |---|   |
              0   1   2   4   5            |---|   |---|
                                           |   |___|   |
                                         4 '---|   |---' 2
                                               '---'
                                                 3
-------------------
        // Método Inserir (final) (1, 3, 5, 7, 9, 2)
        public void inserir(int x) throws Exception{
            if (((ultimo + 1) % array.length) == primeiro)
                throw new Exception("Erro! Fila cheia.");

            array[ultimo] = x;
            ultimo = (ultimo + 1) % array.length;
        }

     (1) p    u                           0 p         (3) p       u                          0 p
        _______________________           ___             _______________________           ___
       | 1 |   |   |   |   |   |   5  ___| 1 |___  1 u   | 1 | 3 |   |   |   |   |   5  ___| 1 |___  1
       '---'---'---'---'---'---'     |   |---|   |       '---'---'---'---'---'---'     |   |---| 3 |
         0   1   2   3   4   5       |---|   |---|         0   1   2   3   4   5       |---|   |---|
                                     |   |___|   |                                     |   |___|   |
                                   4 '---|   |---' 2                                 4 '---|   |---' 2 u
       if: false: 0 + 1 % 6 == 0         '---'           if: false: 1 + 1 % 6 == 0         '---'
                                           3                                                 3

     (5) p           u                     0 p         (7) p                u                 0 p
        _______________________           ___             _______________________           ___
       | 1 | 3 | 5 |   |   |   |   5  ___| 1 |___  1     | 1 | 3 | 5 | 7 |   |   |   5  ___| 1 |___  1
       '---'---'---'---'---'---'     |   |---| 3 |       '---'---'---'---'---'---'     |   |---| 3 |
         0   1   2   3   4   5       |---|   |---|         0   1   2   3   4   5       |---|   |---|
                                     |   |___| 5 |                                     |   |___| 5 |
                                   4 '---|   |---' 2                                 4 '---| 7 |---' 2
       if: false: 2 + 1 % 6 == 0         '---'           if: false: 3 + 1 % 6 == 0   u     '---'
                                           3 u                                               3

     (9) p                   u             0 p        (2)
        _______________________    u      ___             if (((ultimo + 1) % array.length) == primeiro)
       | 1 | 3 | 5 | 7 | 9 |   |   5  ___| 1 |___  1
       '---'---'---'---'---'---'     |   |---| 3 |                  true: 5 + 1 % 6 == 0
         0   1   2   3   4   5       |---|   |---|
                                     | 9 |___| 5 |        Como nossa fila tem tamanho cinco, não conseguimos
                                   4 '---| 7 |---' 2      alocar mais elementos
       if: false: 4 + 1 % 6 == 0         '---'
                                           3
-------------------
        // Método Remover (início) (R, R)
        public int remover() throws Exception{
            if(primeiro == ultimo)
                throw new Exception("Erro, não há elementos para remover!");

            int resp = array[primeiro];
            primeiro = (primeiro + 1) % array.lenght;
            return resp;
        }

     (R)     p               u             0           (R)         p           u             0
        _______________________    u      ___      p      _______________________    u      ___
       | X | 3 | 5 | 7 | 9 |   |   5  ___| X |___  1     | X | X | 5 | 7 | 9 |   |   5  ___| X |___  1
       '---'---'---'---'---'---'     |   |---| X |       '---'---'---'---'---'---'     |   |---| X |
         0   1   2   3   4   5       |---|   |---|         0   1   2   3   4   5       |---|   |---|
              ___                    | 9 |___| 5 |             ___                     | 9 |___| 5 |
       resp: | 1 |                 4 '---| 7 |---' 2     resp | 3 |                  4 '---| 7 |---' 2
             '---'                       '---'                '---'                        '---'     p
       if: false: 1 == 5                   3             if: false: 2 == 5                   3

-------------------
        // Método Inserir (final) (4, 6)

     (4) u       p                         0 u         (6)     u   p                         0
        _______________________           ___             _______________________           ___
       | X | X | 5 | 7 | 9 | 4 |   5  ___| X |___  1     | 6 | X | 5 | 7 | 9 | 4 |   5  ___| 6 |___  1 u
       '---'---'---'---'---'---'     | 4 |---| X |       '---'---'---'---'---'---'     | 4 |---| X |
         0   1   2   3   4   5       |---|   |---|         0   1   2   3   4   5       |---|   |---|
                                     | 9 |___| 5 |                                     | 9 |___| 5 |
                                   4 '---| 7 |---' 2 p                               4 '---| 7 |---' 2 p
       if: false: 5 + 1 % 6 == 2         '---'           if: false: 0 + 1 % 6 == 2         '---'
                                           3                                                 3
-------------------                             -------------------
        // Método Remover (início) (R)                  // Método Inserir (final) (8)

     (R)     u       p                     0 u         (8)         u   p                     0
        _______________________           ___             _______________________           ___
       | 6 | X | X | 7 | 9 | 4 |   5  ___| X |___  1     | 6 | 8 | X | 7 | 9 | 4 |   5  ___| 6 |___  1
       '---'---'---'---'---'---'     | 4 |---| X |       '---'---'---'---'---'---'     | 4 |---| 8 |
         0   1   2   3   4   5       |---|   |---|         0   1   2   3   4   5       |---|   |---|
              ___                    | 9 |___| X |                                     | 9 |___| X |
       resp: | 5 |                 4 '---| 7 |---' 2                                 4 '---| 7 |---' 2 u
             '---'                       '---'           if: false: 1 + 1 % 6 == 3         '---'
       if: false: 1 == 5                   3 p                                               3 p

-------------------
        // Método Mostrar
        public void mostrar(){                  Tela : [7 9 4 6 8]
            int i = primeiro;

            System.out.print("[");
            while(i != iltimo){
                System.out.print(array[i] + " ");
                i = (i + 1) % array.length;
            }
        }
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
#include <math.h>
#include <locale.h>

#define TAMFILA 6

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
    int totalPokemonStorage;
    Pokemon *pokemonStorage;
} PokemonStorage;

// Tipo Celula
typedef struct Celula
{
    Pokemon pokemon;
    struct Celula *prox;

} Celula;

Celula *newCelula(Pokemon pokemon)
{
    Celula *new = (Celula *)malloc(sizeof(Celula));
    new->pokemon = pokemon;
    new->prox = NULL;
    return new;
}

// Definição da estrutura da Fila Circular - CircularQueue
typedef struct FilaFlex
{
    Celula *primeiro;
    Celula *ultimo;
    int tamanho;
} FilaFlex;

/* Fila* newFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    Pokemon emptyPokemon = {0, 0, NULL, NULL, NULL, NULL, 0.0, 0.0, 0, NULL, NULL};

    fila->primeiro = newCelula(emptyPokemon);
    fila->ultimo = fila->primeiro;

    return fila;
} */

// Potótipos das funções
void start(PokemonStorage *, FilaFlex *);
void ler(PokemonStorage *);
char *str(char *);
Pokemon searchIdStorage(int, PokemonStorage);
void imprimir(Pokemon);
// void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// Potótipos das funções da Fila Circular - CircularQueue
void inserir(FilaFlex *, Pokemon);
Pokemon remover(FilaFlex *);
void mostrar(FilaFlex);
int mediaCaptureRate(FilaFlex);

// -----------------------------
// HEADER - Fim
// -----------------------------

// FUNÇÃO PRINCIPAL
int main()
{
    // setlocale(LC_ALL, "pt_BR.UTF-8");
    PokemonStorage storage;
    FilaFlex fila;

    start(&storage, &fila);
    ler(&storage);

    char input[50];

    scanf("%s", input);
    while (strcmp(input, "FIM") != 0)
    {
        inserir(&fila, searchIdStorage(atoi(input), storage));
        printf("Média: %d\n", mediaCaptureRate(fila));
        scanf("%s", input);
    }

    int operations; // quantidade de registros a serem inseridos/removidos
    int cont = 0;
    char *pch;
    char subString[6];

    scanf("%d", &operations);
    getchar();

    while (cont < operations)
    {
        scanf("%[^\n]", input);
        getchar();

        pch = strtok(input, " ");
        strcpy(subString, pch); // atribui o tipo tokenizado

        if (strcmp(subString, "I") == 0)
        {
            pch = strtok(NULL, " ");
            strcpy(subString, pch);

            inserir(&fila, searchIdStorage(atoi(subString), storage));
            printf("Média: %d\n", mediaCaptureRate(fila));
        }
        else if (strcmp(subString, "R") == 0)
        {
            printf("(R) %s\n", remover(&fila).name);
        }
        cont++;
    }
    printf("\n");
    mostrar(fila);

    // Liberação da memória alocada
    free(storage.pokemonStorage);
    free(fila.primeiro);
}

// Função para inicializar e alocar os atributos
void start(PokemonStorage *storage, FilaFlex *fila)
{
    storage->totalPokemonStorage = 0;
    storage->pokemonStorage = (Pokemon *)malloc(1 * sizeof(Pokemon));

    Pokemon emptyPokemon = {0, 0, NULL, NULL, NULL, NULL, 0.0, 0.0, 0, NULL, NULL};
    fila->primeiro = newCelula(emptyPokemon);
    fila->ultimo = fila->primeiro;
    fila->tamanho = 0;
}

// -----------------------------
// POKÉMON - Início
// -----------------------------

// Função para a leitura do csv
void ler(PokemonStorage *s)
{
    FILE *file = fopen("pokemon.csv", "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    char buffer[1000];
    fgets(buffer, sizeof(buffer), file);

    while (fscanf(file, "%d%*c %d%*c", &s->pokemonStorage[s->totalPokemonStorage].id, &s->pokemonStorage[s->totalPokemonStorage].generation) != EOF)
    {                                     // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        s->pokemonStorage[s->totalPokemonStorage].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        s->pokemonStorage[s->totalPokemonStorage].description = str(buffer);

        // Types
        int cont = 0;
        char *pch;

        fscanf(file, "%[^\"]%*c", buffer);                                                     // captura os tipos
        s->pokemonStorage[s->totalPokemonStorage].types = (char **)malloc(2 * sizeof(char *)); // aloca espaço inicial para 2 tipos

        pch = strtok(buffer, ","); // Primeira tokenização por vírgula
        while (pch != NULL)
        {
            s->pokemonStorage[s->totalPokemonStorage].types[cont] = str(pch); // atribui o tipo tokenizado
            cont++;
            s->pokemonStorage[s->totalPokemonStorage].types = (char **)realloc(s->pokemonStorage[s->totalPokemonStorage].types, (cont + 1) * sizeof(char *)); // realoca para mais tipos
            pch = strtok(NULL, ",");
        }
        s->pokemonStorage[s->totalPokemonStorage].types[cont] = NULL; // finaliza com NULL

        // Abilities

        fscanf(file, "%*c%*c%[^]]%*c%*c%*c", buffer);                                              // captura as habilidades
        s->pokemonStorage[s->totalPokemonStorage].abilities = (char **)malloc(2 * sizeof(char *)); // aloca espaço inicial para 2 habilidades

        pch = strtok(buffer, "'"); // Primeira tokenização por vírgula

        s->pokemonStorage[s->totalPokemonStorage].abilities[0] = str(pch);
        pch = strtok(NULL, "'");
        pch = strtok(NULL, "'");

        cont = 1;
        while (pch != NULL)
        {
            s->pokemonStorage[s->totalPokemonStorage].abilities[cont] = str(pch);

            cont++;
            s->pokemonStorage[s->totalPokemonStorage].abilities = (char **)realloc(s->pokemonStorage[s->totalPokemonStorage].abilities, (cont + 1) * sizeof(char *)); // realoca para mais habilidades
            pch = strtok(NULL, "'");
            pch = strtok(NULL, "'");
        }
        s->pokemonStorage[s->totalPokemonStorage].abilities[cont] = NULL; // finaliza com NULL

        // weight
        cont = 0;
        int comma = 0;
        while (comma < 1)
        {
            buffer[cont] = fgetc(file);
            if (buffer[cont] == ',')
            {
                comma++;
                s->pokemonStorage[s->totalPokemonStorage].weight = 0.0;
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
            s->pokemonStorage[s->totalPokemonStorage].weight = atof(buffer);
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
                s->pokemonStorage[s->totalPokemonStorage].height = 0.0;
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
            s->pokemonStorage[s->totalPokemonStorage].height = atof(buffer);
        }

        fscanf(file, "%d%*c", &s->pokemonStorage[s->totalPokemonStorage].captureRate); // captureRate

        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        s->pokemonStorage[s->totalPokemonStorage].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");

        fscanf(file, "%[^\n]", buffer); // date
        s->pokemonStorage[s->totalPokemonStorage].date = str(buffer);

        s->totalPokemonStorage++;
        s->pokemonStorage = (Pokemon *)realloc(s->pokemonStorage, (s->totalPokemonStorage + 1) * sizeof(Pokemon)); // realoca memória para o próximo Pokémon
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
Pokemon searchIdStorage(int id, PokemonStorage s)
{
    for (int i = 0; i < s.totalPokemonStorage; ++i)
    {
        if (id == s.pokemonStorage[i].id)
        {
            return s.pokemonStorage[i];
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
    printf("] - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", pokemon.weight, pokemon.height, pokemon.captureRate, pokemon.isLegendary, pokemon.generation, pokemon.date);
}

// -----------------------------
// POKÉMON - Fim
// -----------------------------

// -----------------------------
// FILA CIRCULAR FLEXÍVEL: Início
// -----------------------------

// Função para remover (no início) da Fila Circular
Pokemon remover(FilaFlex *fila)
{
    if (fila->tamanho <= 0)
    {
        printf("Erro! Fila Vazia.");
        exit(1);
    }

    Celula *tmp = fila->primeiro;
    fila->primeiro = fila->primeiro->prox;
    Pokemon pokemon = fila->primeiro->pokemon;

    tmp->prox = NULL;
    free(tmp);
    fila->tamanho--;

    return pokemon;
}

// Função para inserir (no fim) da Fila Circular
void inserir(FilaFlex *fila, Pokemon pokemon)
{
    if (fila->tamanho >= 5) // Validar inserção
    {
        remover(fila);

        /* printf("Erro! A Fila está cheia.");
        exit(1); */
    }

    fila->ultimo->prox = newCelula(pokemon);
    fila->ultimo = fila->ultimo->prox;
    fila->tamanho++;
}

// Função para imprimir os pokemon presentes na Fila Circular
void mostrar(FilaFlex fila)
{
    if (fila.primeiro == fila.ultimo) // Fila vazia
    {
        printf("Fila está vazia.\n");
        return;
    }

    int index = 0;
    for (Celula *i = fila.primeiro->prox; i != NULL; i = i->prox)
    {
        printf("[%d] ", index++);
        imprimir(i->pokemon);
    }
}

// Função para calcular a média do captureRate
int mediaCaptureRate(FilaFlex fila)
{
    int soma = 0;
    for (Celula *i = fila.primeiro->prox; i != NULL; i = i->prox)
        soma += i->pokemon.captureRate;

    if (fila.tamanho == 0)
        return 0;

    return (int)round((double)soma / fila.tamanho);
}

// -----------------------------
// FILA CIRCULAR FLEXÍVEL - Fim
// -----------------------------