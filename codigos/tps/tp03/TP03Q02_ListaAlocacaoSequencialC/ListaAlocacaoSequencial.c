/*
Fila Circular com Alocação Sequencial em C

author: Bruna Furtado da Fonseca
version: 2024-07-16
*/

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

// -----------------------------
// HEADER - Início
// -----------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct
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

// Variáveis globais
int totalPokemonStorage;
Pokemon *pokemonStorage;

// Variáveis globais - lista
int tamPokemonList;
Pokemon *pokemonList;
int n;

// Potótipos das funções
void start();
void ler();
char* str(char *);
Pokemon searchIdStorage(int);
void imprimir(Pokemon);
//void clone(int); // NÃO ESTÁ IMPLEMENTADA -----------------------------------------------------

// Potótipos das funções - lista
void inserirInicio(Pokemon);
void inserirFim(Pokemon);
void inserir(Pokemon, int);
Pokemon removerInicio();
Pokemon removerFim();
Pokemon remover(int);
void mostrar();

// -----------------------------
// HEADER - Fim
// -----------------------------

// FUNÇÃO PRINCIPAL
int main() {
    start();
    ler();

    char input[50];

    scanf("%s", input);
    while(strcmp(input, "FIM") != 0){
        inserirFim(searchIdStorage(atoi(input))); 
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

        if(strcmp(subString[0], "II") == 0){
            inserirInicio(searchIdStorage(atoi(subString[1])));
        }
        else if(strcmp(subString[0], "IF") == 0){
            inserirFim(searchIdStorage(atoi(subString[1])));
        }
        else if(strcmp(subString[0], "I*") == 0){
            inserir(searchIdStorage(atoi(subString[2])), atoi(subString[1]));            
        }
        else if(strcmp(subString[0], "RI") == 0){
            printf("(R) %s\n", removerInicio().name);   
        }
        else if(strcmp(subString[0], "RF") == 0){
            printf("(R) %s\n", removerFim().name); 
        }
        else if(strcmp(subString[0], "R*") == 0){
            printf("(R) %s\n", remover(atoi(subString[1])).name); 
        }
        cont++;
    }
    mostrar();

    // Liberação da memória alocada
    free(pokemonStorage);   
    free(pokemonList);
}

// Função para inicializar e alocar os atributos
void start(){
    totalPokemonStorage = 0;
    tamPokemonList = 0;
    n = 0;

    pokemonStorage = (Pokemon*)malloc(1 * sizeof(Pokemon));
    pokemonList = (Pokemon*)malloc(1 * sizeof(Pokemon));
}

// Função para a leitura do csv
void ler() {
    FILE *file = fopen("pokemon.csv", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char buffer[1000];
    fgets(buffer, sizeof(buffer), file);

    while (fscanf(file, "%d%*c %d%*c", &pokemonStorage[totalPokemonStorage].id, &pokemonStorage[totalPokemonStorage].generation) != EOF) { // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        pokemonStorage[totalPokemonStorage].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        pokemonStorage[totalPokemonStorage].description = str(buffer);

        // Types
        int cont = 0;
        char *pch;

        fscanf(file, "%[^\"]%*c", buffer); // captura os tipos
        pokemonStorage[totalPokemonStorage].types = (char**)malloc(2 * sizeof(char*)); // aloca espaço inicial para 2 tipos

        pch = strtok(buffer, ",");  // Primeira tokenização por vírgula
        while (pch != NULL) {
            pokemonStorage[totalPokemonStorage].types[cont] = str(pch); // atribui o tipo tokenizado
            cont++;
            pokemonStorage[totalPokemonStorage].types = (char**)realloc(pokemonStorage[totalPokemonStorage].types, (cont + 1) * sizeof(char*)); // realoca para mais tipos
            pch = strtok(NULL, ",");
        }
        pokemonStorage[totalPokemonStorage].types[cont] = NULL; // finaliza com NULL

        // Abilities
        
        fscanf(file, "%*c%*c%[^]]%*c%*c%*c", buffer); // captura as habilidades
        pokemonStorage[totalPokemonStorage].abilities = (char**)malloc(2 * sizeof(char*)); // aloca espaço inicial para 2 habilidades

        pch = strtok(buffer, "'"); // Primeira tokenização por vírgula

        pokemonStorage[totalPokemonStorage].abilities[0] = str(pch);
        pch = strtok(NULL, "'");
        pch = strtok(NULL, "'");

        cont = 1;
        while (pch != NULL) {
            pokemonStorage[totalPokemonStorage].abilities[cont] = str(pch);

            cont++;
            pokemonStorage[totalPokemonStorage].abilities = (char**)realloc(pokemonStorage[totalPokemonStorage].abilities, (cont + 1) * sizeof(char*)); // realoca para mais habilidades
            pch = strtok(NULL, "'");
            pch = strtok(NULL, "'");
        }
        pokemonStorage[totalPokemonStorage].abilities[cont] = NULL; // finaliza com NULL

        // weight
        cont = 0;
        int comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                pokemonStorage[totalPokemonStorage].weight = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            pokemonStorage[totalPokemonStorage].weight = atof(buffer);
        }

        // height
        cont = 0;
        comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                pokemonStorage[totalPokemonStorage].height = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            pokemonStorage[totalPokemonStorage].height = atof(buffer);
        }

        fscanf(file, "%d%*c", &pokemonStorage[totalPokemonStorage].captureRate); // captureRate

        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        pokemonStorage[totalPokemonStorage].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");

        fscanf(file, "%[^\n]", buffer); // date
        pokemonStorage[totalPokemonStorage].date = str(buffer);

        totalPokemonStorage++;
        pokemonStorage = (Pokemon*)realloc(pokemonStorage, (totalPokemonStorage + 1) * sizeof(Pokemon)); // realoca memória para o próximo Pokémon
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
Pokemon searchIdStorage(int id){
    for(int i = 0; i < totalPokemonStorage; ++i){
        if(id == pokemonStorage[i].id){
            return pokemonStorage[i];
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
// LISTA: Início
// -----------------------------

// INSERIR:
// Função para inserir no início da lista
void inserirInicio(Pokemon pokemon) {
    if(n >= tamPokemonList){
        tamPokemonList++;
        pokemonList = (Pokemon*)realloc(pokemonList, (tamPokemonList + 1) * sizeof(Pokemon));
        if (!pokemonList) {
            printf("Erro de memória na realocação\n");
            tamPokemonList--;
            exit(1);
        }
    }

    // Realoca os elementos para o fim do array
    for(int i = n; i > 0; --i)
        pokemonList[i] = pokemonList[i - 1];
    
    pokemonList[0] = pokemon;
    n++;
}

// Função para inserir no fim da lista
void inserirFim(Pokemon pokemon) {
    if(n >= tamPokemonList){
        tamPokemonList++;
        pokemonList = (Pokemon*)realloc(pokemonList, (tamPokemonList + 1) * sizeof(Pokemon));
        if (!pokemonList) {
            printf("Erro de memória na realocação\n");
            tamPokemonList--;
            exit(1);
        }
    }
    
    pokemonList[n] = pokemon;
    n++;
}

// Função para inserir na p-ésima posição  da lista
void inserir(Pokemon pokemon, int pos) {
    if(n >= tamPokemonList){
        tamPokemonList++;
        pokemonList = (Pokemon*)realloc(pokemonList, (tamPokemonList + 1) * sizeof(Pokemon));
        if (!pokemonList) {
            printf("Erro de memória na realocação\n");
            tamPokemonList--;
            exit(1);
        }
    }
    if(pos < 0 || pos > n){
        printf("Erro! Posição inválida.\nPosicoes validas = 0 a %d\nPosicao inserida = %d\n", n, pos);
        exit(1);
    }

    // Realoca os elementos para o fim do array
    for(int i = n; i > pos; --i)
        pokemonList[i] = pokemonList[i - 1];
    
    pokemonList[pos] = pokemon;
    n++;
    tamPokemonList++;
}

// REMOVER:
// Função para remover no início da lista
Pokemon removerInicio() {
    if(n == 0){
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }
    
    Pokemon removedPokemon = pokemonList[0];
    n--;
    
    for(int i = 0; i < n; ++i)
        pokemonList[i] = pokemonList[i + 1];
    
    return removedPokemon;
}

// Função para remover no fim da lista
Pokemon removerFim() {
    if(n == 0){
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }

    return pokemonList[--n];
}

// Função para remover na p-ésima posição da lista
Pokemon remover(int pos) {
    if(n == 0){
        printf("Erro! Não há pokemons para remover.\n");
        exit(1);
    }
    if(pos < 0 || pos > n){
        printf("Erro! Posição inválida.\n");
        exit(1);
    }   
    
    Pokemon removedPokemon = pokemonList[pos];
    n--;
    
    for(int i = pos; i < n; ++i)
        pokemonList[i] = pokemonList[i + 1];
    
    return removedPokemon;
}

// MOSTRAR:
// Função para imprimir os pokemon presentes na lista
void mostrar(){
    for(int i = 0; i < n; ++i){
        printf("[%d] ", i);
        imprimir(pokemonList[i]);
    }
}

// -----------------------------
// LISTA - Fim
// -----------------------------