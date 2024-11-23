/*
Fila Circular com Alocação Sequencial em C

author: Bruna Furtado da Fonseca
version: Ubuntu 13.2.0-23ubuntu4
*/

/*
Crie uma classe Fila Circular de Pokémon.
- Essa fila deve ter tamanho cinco. 
- Em seguida, faça um programa que leia vários registros e insira seus atributos na fila.
- Quando o programa tiver que inserir um registro e a fila estiver cheia, antes, ele deve fazer uma remoção.

ENTRADA: 
- A entrada padrão será igual à da questão anterior.

SAÍDA:
- A saída padrão será um número inteiro para cada registro inserido na fila. Esse número corresponde à média
  arredondada do captureRate dos registros contidos na fila após cada inserção.
- Além disso, para cada registro removido da fila, a saída padrão também apresenta a palavra “(R)” e alguns atributos
  desse registro.
- Por último, a saída padrão mostra os registros existentes na fila seguindo o padrão da questão anterior.
*/

/*
INFOS:

- As filas são um Tipo Abstrato de Dados (TAD) no qual o primeiro elemento que entra é o primeiro a sair
    > First In, First Out (FIFO)

- Tem basicamente os métodos de inserir (enfileirar, enqueue) e remover (desenfileirar, dequeue)
    > II, IF, I, RI, RF e R

- Primeira solução IF e RI (remoção não é eficiente)
    > Por exemplo, inserindo o 1, 3, 5 e 7 e efetuando duas remoções teremos:
                                        Primeira remoção: Retorna o 1 e move todos os demais
        1 2 3 4 5                                   

- Segunda solução II e RF (inserção não é eficiente)


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

// Definição da estrutura da Fila Circular CircularQueue
typedef struct Celula{
    Pokemon pokemon;
    struct Celula* prox;

}Celula;

Celula* construtorCelulaCabeca(){
    Celula* tmp = (Celula*) malloc(sizeof(Celula));
    tmp->prox = NULL;

    return tmp;
}

Celula* construtorCelula(Pokemon pokemon){
    Celula* tmp = (Celula*) malloc(sizeof(Celula));
    tmp->pokemon = pokemon;
    tmp->prox = NULL;

    return tmp;
}

typedef struct Fila{
    Celula* cabeca;
    Celula* ultimo;
    int tamanho;

}Fila;

Fila* construtorFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    fila->cabeca = construtorCelulaCabeca();
    fila->ultimo = fila->cabeca;
    fila->tamanho = 0;

    return fila;
}

// Potótipos das funções
void start(PokemonStorage*, Fila*);
void ler(PokemonStorage*);
char* str(char *);
Pokemon searchIdStorage(int, PokemonStorage);
void imprimir(Pokemon);
//void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// -----------------------------
// HEADER - Fim
// -----------------------------

// -----------------------------
// FILA CIRCULAR: Início
// -----------------------------

// Função para calcular a média do captureRate
int calcularMediaCaptureRate(Fila* fila) {
    int soma = 0;
    int contador = 0;
    
    for (Celula* i = fila->cabeca->prox; i != NULL; i = i->prox) {
        soma += i->pokemon.captureRate;
        contador++;
    }
    
    if (contador == 0) return 0;
    return (int)round((double)soma / contador);
}




// Função para remover da Fila Circular


Pokemon remover(Fila* fila){
    Pokemon pokemon;
    if(fila->tamanho <= 0){
        printf("Fila Vazia");
    }else{
        Celula* tmp = fila->cabeca;
        fila->cabeca = fila->cabeca->prox;

        tmp->prox = NULL;
        tmp = NULL;
        free(tmp);

        pokemon = fila->cabeca->pokemon;
        fila->tamanho--;
    }

    return pokemon;
}

void inserir(Fila* fila, Pokemon pokemon){
    if(fila->tamanho >= 5){
        remover(fila);
    }
        fila->ultimo->prox = construtorCelula(pokemon);
        fila->ultimo = fila->ultimo->prox;
        //imprimir(fila->ultimo->pokemon);
        fila->tamanho++;
    
}

// Função para imprimir os pokemon presentes na Fila Circular

void mostrar(Fila* fila){
    int contador = 0;

    for(Celula* i = fila->cabeca->prox; i != NULL; i = i->prox){
        printf("[%d] ", contador);
        imprimir(i->pokemon);
        contador++;
    }

}

/*void mostrar(Fila fila) {
    if (fila.primeiro == fila.ultimo) { // Fila vazia
        printf("Fila está vazia.\n");
        return;
    }

    int contador = 0;
    int i = fila.primeiro;
    while (i != fila.ultimo) { // Iterar pelos elementos ativos na fila
        printf("[%d] ", contador);
        imprimir(fila.pokemonFila[i]); // Imprimir o Pokémon
        i = (i + 1) % TAMFILA;   // Avançar no índice circular
        contador++;
    }
    printf("\n");
}*/


// -----------------------------
// FILA CIRCULAR: - Fim
// -----------------------------

// FUNÇÃO PRINCIPAL
int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");
    PokemonStorage storage;
    Pokemon pokemon;
    Fila* fila = construtorFila();
    
    start(&storage, fila);
    ler(&storage);


    /*imprimir(searchIdStorage(181, storage));
    imprimir(searchIdStorage(791, storage));
    imprimir(searchIdStorage(453, storage));
    imprimir(searchIdStorage(46, storage));
    imprimir(searchIdStorage(137, storage));*/

    char input[50];

    scanf("%s", input);
    while(strcmp(input, "FIM") != 0){
        inserir(fila, searchIdStorage(atoi(input), storage));
        //imprimir(searchIdStorage(atoi(input), storage));
        printf("Média: %d\n", calcularMediaCaptureRate(fila));
        scanf("%s", input);
    }

    //mostrar(fila);

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
            inserir(fila, searchIdStorage(atoi(subString[1]), storage));
            printf("Média: %d\n", calcularMediaCaptureRate(fila));
        }
        else if(strcmp(subString[0], "R") == 0){
            printf("(R) %s\n", remover(fila).name);   
        }
        cont++;
    }
    printf("\n");
    mostrar(fila);

    // Liberação da memória alocada
    free(storage.pokemonStorage);   
    //free(fila.pokemonFila);
}

// Função para inicializar e alocar os atributos
void start(PokemonStorage *storage, Fila *fila) {
    storage->totalPokemonStorage = 0;
    storage->pokemonStorage = (Pokemon*)malloc(1 * sizeof(Pokemon));

    Pokemon emptyPokemon = {0, 0, NULL, NULL, NULL, NULL, 0.0, 0.0, 0, NULL, NULL};
    //fila->cabeca = 0;
    //fila->ultimo = 0;
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

