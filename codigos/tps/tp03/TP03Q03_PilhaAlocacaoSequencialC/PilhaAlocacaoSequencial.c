/*
Pilha com Alocação Sequencial em C

author: Bruna Furtado da Fonseca
version: 2024-07-16
*/

/*
Crie uma Pilha de registros baseada na pilha de inteiros vista na sala de aula.
Neste exercício, faremos inserções, remoções e mostraremos os elementos de nossa pilha.

A entrada e a saída padrão serão como as da questão anterior, contudo, teremos apenas os comandos I para inserir na
pilha (empilhar) e R para remover (desempilhar).
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

// Estrutura para armazenar um conjunto de Pokémons
typedef struct PokemonStorage{
    int totalPokemonStorage;
    Pokemon *pokemonStorage;
} PokemonStorage;

// Definição da estrutura da pilha
typedef struct Stack {
    int tamPokemonStack;
    Pokemon *pokemonStack;
    int top;
} Stack;

// Potótipos das funções
void start(PokemonStorage*, Stack*);
void ler(PokemonStorage*);
char* str(char *);
Pokemon searchIdStorage(int, PokemonStorage);
void imprimir(Pokemon);
//void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// Potótipos das funções - pilha
void push(Stack*, Pokemon);
Pokemon pop(Stack*);
void mostrar(Stack);

// -----------------------------
// HEADER - Fim
// -----------------------------

// FUNÇÃO PRINCIPAL
int main() {
    PokemonStorage storage;
    Pokemon pokemon;
    Stack stack;
    
    start(&storage, &stack);
    ler(&storage);

    char input[50];

    scanf("%s", input);
    while(strcmp(input, "FIM") != 0){
        push(&stack, searchIdStorage(atoi(input), storage));
        scanf("%s", input);
    }

    int operations; // quantidade de registros a serem inseridos/removidos
    int cont = 0;
    int infos = 0;
    char *pch;
    char subString[3][10];

    scanf("%d", &operations);
    getchar();

    while(cont < operations){
        infos = 0;

        scanf("%[^\n]", input);
        getchar();

        pch = strtok(input, " ");
        while (pch != NULL) {
            strcpy(subString[infos], pch); // atribui o tipo tokenizado
            pch = strtok(NULL, " ");
            infos++;
        }

        if(strcmp(subString[0], "I") == 0){
            push(&stack, searchIdStorage(atoi(subString[1]), storage));
        }
        else if(strcmp(subString[0], "R") == 0){
            printf("(R) %s\n", pop(&stack).name);   
        }
        cont++;
    }
    mostrar(stack);

    // Liberação da memória alocada
    free(storage.pokemonStorage);   
    free(stack.pokemonStack);
}

// Função para inicializar e alocar os atributos
void start(PokemonStorage *storage, Stack *stack){
    storage->totalPokemonStorage = 0;
    storage->pokemonStorage = (Pokemon*)malloc(1 * sizeof(Pokemon));

    stack->top = 0;
    stack->top = -1;
    stack->pokemonStack = (Pokemon*)malloc(1 * sizeof(Pokemon));
}

// Função para a leitura do csv
void ler(PokemonStorage *s) {
    FILE *file = fopen("pokemon.csv", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char buffer[1000];
    fgets(buffer, sizeof(buffer), file);

    while (fscanf(file, "%d%*c %d%*c", &s->pokemonStorage[s->totalPokemonStorage].id, &s->pokemonStorage[s->totalPokemonStorage].generation) != EOF) { // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        s->pokemonStorage[s->totalPokemonStorage].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        s->pokemonStorage[s->totalPokemonStorage].description = str(buffer);

        // Types
        int cont = 0;
        char *pch;

        fscanf(file, "%[^\"]%*c", buffer); // captura os tipos
        s->pokemonStorage[s->totalPokemonStorage].types = (char**)malloc(2 * sizeof(char*)); // aloca espaço inicial para 2 tipos

        pch = strtok(buffer, ",");  // Primeira tokenização por vírgula
        while (pch != NULL) {
            s->pokemonStorage[s->totalPokemonStorage].types[cont] = str(pch); // atribui o tipo tokenizado
            cont++;
            s->pokemonStorage[s->totalPokemonStorage].types = (char**)realloc(s->pokemonStorage[s->totalPokemonStorage].types, (cont + 1) * sizeof(char*)); // realoca para mais tipos
            pch = strtok(NULL, ",");
        }
        s->pokemonStorage[s->totalPokemonStorage].types[cont] = NULL; // finaliza com NULL

        // Abilities
        
        fscanf(file, "%*c%*c%[^]]%*c%*c%*c", buffer); // captura as habilidades
        s->pokemonStorage[s->totalPokemonStorage].abilities = (char**)malloc(2 * sizeof(char*)); // aloca espaço inicial para 2 habilidades

        pch = strtok(buffer, "'"); // Primeira tokenização por vírgula

        s->pokemonStorage[s->totalPokemonStorage].abilities[0] = str(pch);
        pch = strtok(NULL, "'");
        pch = strtok(NULL, "'");

        cont = 1;
        while (pch != NULL) {
            s->pokemonStorage[s->totalPokemonStorage].abilities[cont] = str(pch);

            cont++;
            s->pokemonStorage[s->totalPokemonStorage].abilities = (char**)realloc(s->pokemonStorage[s->totalPokemonStorage].abilities, (cont + 1) * sizeof(char*)); // realoca para mais habilidades
            pch = strtok(NULL, "'");
            pch = strtok(NULL, "'");
        }
        s->pokemonStorage[s->totalPokemonStorage].abilities[cont] = NULL; // finaliza com NULL

        // weight
        cont = 0;
        int comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                s->pokemonStorage[s->totalPokemonStorage].weight = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            s->pokemonStorage[s->totalPokemonStorage].weight = atof(buffer);
        }

        // height
        cont = 0;
        comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                s->pokemonStorage[s->totalPokemonStorage].height = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            s->pokemonStorage[s->totalPokemonStorage].height = atof(buffer);
        }

        fscanf(file, "%d%*c", &s->pokemonStorage[s->totalPokemonStorage].captureRate); // captureRate

        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        s->pokemonStorage[s->totalPokemonStorage].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");

        fscanf(file, "%[^\n]", buffer); // date
        s->pokemonStorage[s->totalPokemonStorage].date = str(buffer);

        s->totalPokemonStorage++;
        s->pokemonStorage = (Pokemon*)realloc(s->pokemonStorage, (s->totalPokemonStorage + 1) * sizeof(Pokemon)); // realoca memória para o próximo Pokémon
    }
    fclose(file);  
}

// Função para alocação dinâmica de string
char* str(char *str) {
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);
    return info;
}

// Função para pesquisar pokemon por id no armazenamento
Pokemon searchIdStorage(int id, PokemonStorage s){
    for(int i = 0; i < s.totalPokemonStorage; ++i){
        if(id == s.pokemonStorage[i].id){
            return s.pokemonStorage[i];
        }
    }
    printf("Pokemon com o id = %d não encontrado no armazenamento\n", id);
    exit(1);
}

// Função para imprimir os pokemons
void imprimir(Pokemon pokemon) {
    printf("[#%d -> %s: %s - ", pokemon.id, pokemon.name, pokemon.description);

    // Types
    int cont = 0;
    printf("[");
    while (pokemon.types[cont] != NULL) {
        if (cont > 0) printf(", ");
        printf("'%s'", pokemon.types[cont]);
        cont++;
    }
    printf("] - [");

    // Abilities
    cont = 0;
    while (pokemon.abilities[cont] != NULL) {
        if (cont > 0) printf(", ");
        printf("'%s'", pokemon.abilities[cont]);
        cont++;
    }
    printf("] - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", pokemon.weight, pokemon.height, pokemon.captureRate, pokemon.isLegendary, pokemon.generation, pokemon.date);
}

// -----------------------------
// PILHA: Início
// -----------------------------

// Função para inserir na pilha
void push(Stack *stack, Pokemon pokemon) {
    if(stack->top >= stack->tamPokemonStack){
        stack->tamPokemonStack++;
        stack->pokemonStack = (Pokemon*)realloc(stack->pokemonStack, (stack->tamPokemonStack + 1) * sizeof(Pokemon));

        if (!stack->pokemonStack) {
            printf("Erro de memória na realocação\n");
            stack->tamPokemonStack--;
            exit(1);
        }
    }
    stack->pokemonStack[++stack->top] = pokemon;
}

// Função para remover da pilha
Pokemon pop(Stack *stack) {
    if(stack->top == -1){
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }
    
    return stack->pokemonStack[stack->top--];
}

// Função para imprimir os pokemon presentes na pilha
void mostrar(Stack stack){
    for(int i = 0; i <= stack.top; ++i){
        printf("[%d] ", i);
        imprimir(stack.pokemonStack[i]);
    }
}

// -----------------------------
// PILHA - Fim
// -----------------------------

