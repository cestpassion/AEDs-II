/*
Pilha com Alocação Flexível em C

author: Bruna Furtado da Fonseca
version: Ubuntu 13.2.0-23ubuntu4
*/

/*
Refazer a Questão 3 “Pilha com Alocação Sequencial".
*/

/*
INFO:

- As pilhas são um Tipo Abstrato de Dados (TAD) no qual o primeiro elemento que entra é o último a sair
    > First In, Last Out (FILO)

- Tem basicamente os métodos de inserir (empilhar, pop) e remover (desempilhar, push)

- Primeira solução IF e RF
    > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
                    7                               X   X
                5   5                               5   X
            3   3   3                               3   3
        1   1   1   1                               1   1

- Segunda solução II e RI (inserção e remoção não eficientes)
    > Em cada inserção ou remoção, movemos todos os elementos
    > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
                    1                       • Primeira remoção: Retorna o 7 e move todos os demais
                1   3                       • Segunda remoção: Retorna o 5 e move todos os demais
            1   3   5                               X   X
        1   3   5   7                               1   X
                                                    3   1
                                                    5   3
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
    int totalPokemonStorage;
    Pokemon *pokemonStorage;
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

// Definição da estrutura da pilha
typedef struct FlexStack
{
    Celula *top;
} FlexStack;

// Potótipos das funções
void start(PokemonStorage *, FlexStack *);
void ler(PokemonStorage *);
char *str(char *);
Pokemon searchIdStorage(int, PokemonStorage);
void imprimir(Pokemon);
// void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// Potótipos das funções - pilha
void push(FlexStack *, Pokemon);
Pokemon pop(FlexStack *);
void mostrar(FlexStack);
int sizeStack(FlexStack);
void chamaMostrarRecursivo(FlexStack);
void mostrarRecursivo(Celula *, int);
void invertStack(FlexStack *);
void reverseStack(FlexStack *, Pokemon);

// -----------------------------
// HEADER - Fim
// -----------------------------

// FUNÇÃO PRINCIPAL
int main()
{
    PokemonStorage storage;
    FlexStack stack;

    start(&storage, &stack);
    ler(&storage);

    char input[50];

    scanf("%s", input);
    while (strcmp(input, "FIM") != 0)
    {
        push(&stack, searchIdStorage(atoi(input), storage));
        scanf("%s", input);
    }

    int operations; // quantidade de registros a serem inseridos/removidos
    int cont = 0;
    int infos = 0;
    char *pch;
    char subString[2][5];

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

        if (strcmp(subString[0], "I") == 0)
        {
            push(&stack, searchIdStorage(atoi(subString[1]), storage));
        }
        else if (strcmp(subString[0], "R") == 0)
        {
            printf("(R) %s\n", pop(&stack).name);
        }
        cont++;
    }
    chamaMostrarRecursivo(stack);

    // Liberação da memória alocada
    free(storage.pokemonStorage);
    free(stack.top);
}

// Função para inicializar e alocar os atributos
void start(PokemonStorage *storage, FlexStack *stack)
{
    storage->totalPokemonStorage = 0;
    storage->pokemonStorage = (Pokemon *)malloc(1 * sizeof(Pokemon));

    stack->top = NULL;
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
// PILHA: Início
// -----------------------------

// Função para inserir na pilha
void push(FlexStack *stack, Pokemon pokemon)
{
    Celula *tmp = newCelula(pokemon);
    tmp->prox = stack->top;
    stack->top = tmp;

    tmp = NULL;
}

// Função para remover da pilha
Pokemon pop(FlexStack *stack)
{
    if (stack->top == NULL)
    {
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }

    Pokemon removedPokemon = stack->top->pokemon;
    Celula *tmp = stack->top;
    stack->top = stack->top->prox;

    tmp->prox = NULL;
    free(tmp);

    return removedPokemon;
}

// Função para mostrar os pokemon presentes na pilha
void mostrar(FlexStack stack)
{
    int index = 0;
    for (Celula *i = stack.top; i != NULL; i = i->prox)
    {
        printf("[%d] ", index++);
        imprimir(i->pokemon);
    }
}
// Função para encontrar o tamanho da Pilha Flexível
int sizeStack(FlexStack stack)
{
    Celula *i = stack.top;
    int index;

    for (index = 0; i != NULL; i = i->prox, index++);
    free(i);

    return index;
}

/*
Mostra os pokemon numerados por [index], invertendo a impressão. De forma
recursiva.
*/
void chamaMostrarRecursivo(FlexStack stack)
{
    int index = sizeStack(stack);
    mostrarRecursivo(stack.top, index);
}

void mostrarRecursivo(Celula *i, int index)
{
    if (i != NULL)
    {
        mostrarRecursivo(i->prox, --index);
        printf("[%d] ", index);
        imprimir(i->pokemon);
    }
}

// INVERTER A PILHA

// Função para inserir um elemento (pokemon) no fundo da pilha recursivamente
void reverseStack(FlexStack *stack, Pokemon pokemon)
{
    if (stack->top == NULL)
    {
        push(stack, pokemon);
    }
    else
    {
        Pokemon tmp = pop(stack);
        reverseStack(stack, pokemon);
        push(stack, tmp);
    }
}
/*
Caso Base: Se o topo da pilha (stack->top) for NULL (ou seja, a pilha está vazia), ela apenas empilha (push) o
elemento pokemon.

Caso Recursivo: Caso contrário:
- A função desempilha (pop) o elemento do topo e o armazena na variável tmp.
- Chama reverseStack recursivamente para colocar o pokemon no fundo da pilha.
- Após a recursão, reempilha (push) o elemento tmp que foi desempilhado antes.

Essa lógica permite que a função recorra até o final da pilha, insira o pokemon no fundo e depois remonte a pilha
com os elementos que foram desempilhados.
*/

// Função para inverter a pilha usando a função reverseStack como auxiliar
void invertStack(FlexStack *stack)
{
    if (stack->top != NULL)
    {
        Pokemon tmp = pop(stack);
        invertStack(stack);
        reverseStack(stack, tmp);
    }
}
/*
Caso Base: Se a pilha estiver vazia (stack->top == NULL), a função não faz nada e termina a recursão.

Caso Recursivo:
- A função desempilha (pop) o elemento do topo e o armazena na variável tmp.
- Chama invertStack recursivamente para inverter o restante da pilha.
- Após a recursão, chama reverseStack para inserir o elemento tmp no fundo da pilha invertida.
*/

// -----------------------------
// PILHA - Fim
// -----------------------------