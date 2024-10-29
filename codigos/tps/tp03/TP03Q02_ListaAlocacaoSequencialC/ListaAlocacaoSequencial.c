/*
Lista com Alocação Sequencial em C

author: Bruna Furtado da Fonseca
version: 2024-07-16
*/

/*
Crie uma Lista de registros baseada na de inteiros vista na sala de aula. Sua lista deve conter todos os atributos e
métodos existentes na lista de inteiros, contudo, adaptados para a classe Pokémon. Lembre-se que, na verdade, temos uma
lista de ponteiros (ou referências) e cada um deles aponta para um registo.

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
    - II inserir no início,
    - I* inserir em qualquer posição,
    - IF inserir no fim,
    - RI remover no início,
    - R* remover em qualquer posição e
    - RF remover no fim.

No caso dos comandos de inserir, temos também o nome do arquivo que contém o registro a ser inserido.
No caso dos comandos de “em qualquer posição”, temos também esse nome. 
No Inserir, a posição fica imediatamente após a palavra de comando.

A saída padrão tem uma linha para cada registro removido sendo que essa informação será constituída pela palavra “(R)” e
o atributo name.
No final, a saída mostra os atributos relativos a cada registro cadastrado na lista após as operações de inserção e
remoção.
*/

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
int totalPokemon = 0;
Pokemon *pokemon;

// Potótipos das funões
void ler();
char* str(char *);
void imprimir(int);
void clone(int);

// Função principal
int main() {
    pokemon = (Pokemon*)malloc(1 * sizeof(Pokemon));
   
    ler();

    char str[10];
    int index;

    scanf("%s", str);

    while (strcmp(str, "FIM") != 0) {
        index = atoi(str); 
        imprimir(index); 
        scanf("%s", str);  
    }

    free(pokemon); // Liberação da memória alocada
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

    while (fscanf(file, "%d%*c %d%*c", &pokemon[totalPokemon].id, &pokemon[totalPokemon].generation) != EOF) { // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        pokemon[totalPokemon].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        pokemon[totalPokemon].description = str(buffer);

        // Types
        int cont = 0;
        char *pch;

        fscanf(file, "%[^\"]%*c", buffer); // captura os tipos
        pokemon[totalPokemon].types = (char**)malloc(2 * sizeof(char*)); // aloca espaço inicial para 2 tipos

        pch = strtok(buffer, ",");  // Primeira tokenização por vírgula
        while (pch != NULL) {
            pokemon[totalPokemon].types[cont] = str(pch); // atribui o tipo tokenizado
            cont++;
            pokemon[totalPokemon].types = (char**)realloc(pokemon[totalPokemon].types, (cont + 1) * sizeof(char*)); // realoca para mais tipos
            pch = strtok(NULL, ",");
        }
        pokemon[totalPokemon].types[cont] = NULL; // finaliza com NULL

        // Abilities
        
        fscanf(file, "%*c%*c%[^]]%*c%*c%*c", buffer); // captura as habilidades
        pokemon[totalPokemon].abilities = (char**)malloc(2 * sizeof(char*)); // aloca espaço inicial para 2 habilidades

        pch = strtok(buffer, "'"); // Primeira tokenização por vírgula

        pokemon[totalPokemon].abilities[0] = str(pch);
        pch = strtok(NULL, "'");
        pch = strtok(NULL, "'");

        cont = 1;
        while (pch != NULL) {
            pokemon[totalPokemon].abilities[cont] = str(pch);

            cont++;
            pokemon[totalPokemon].abilities = (char**)realloc(pokemon[totalPokemon].abilities, (cont + 1) * sizeof(char*)); // realoca para mais habilidades
            pch = strtok(NULL, "'");
            pch = strtok(NULL, "'");
        }
        pokemon[totalPokemon].abilities[cont] = NULL; // finaliza com NULL

        // weight
        cont = 0;
        int comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                pokemon[totalPokemon].weight = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            pokemon[totalPokemon].weight = atof(buffer);
        }

        // height
        cont = 0;
        comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                pokemon[totalPokemon].height = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            pokemon[totalPokemon].height = atof(buffer);
        }

        fscanf(file, "%d%*c", &pokemon[totalPokemon].captureRate); // captureRate

        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        pokemon[totalPokemon].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");

        fscanf(file, "%[^\n]", buffer); // date
        pokemon[totalPokemon].date = str(buffer);

        totalPokemon++;
        pokemon = (Pokemon*)realloc(pokemon, (totalPokemon + 1) * sizeof(Pokemon)); // realoca memória para o próximo Pokémon
    }
    fclose(file);  
}

// Função para alocação dinâmica de string
char* str(char *str) {
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);
    return info;
}

// Função para imprimir os pokemons
void imprimir(int searchId) {
    for (int i = 0; i < totalPokemon; ++i) {
        if (searchId == pokemon[i].id) {
            printf("[#%d -> %s: %s ", pokemon[i].id, pokemon[i].name, pokemon[i].description);

            // Types
            int cont = 0;
            printf("[");
            while (pokemon[i].types[cont] != NULL) {
                if (cont > 0) printf(", ");
                printf("'%s'", pokemon[i].types[cont]);
                cont++;
            }
            printf("] - [");

            // Abilities
            cont = 0;
            while (pokemon[i].abilities[cont] != NULL) {
                if (cont > 0) printf(", ");
                printf("'%s'", pokemon[i].abilities[cont]);
                cont++;
            }
            printf("] - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", pokemon[i].weight, pokemon[i].height, pokemon[i].captureRate, pokemon[i].isLegendary, pokemon[i].generation, pokemon[i].date);

            break;
        }
    }
}

// FUNÇÕES DA LISTA: Início

