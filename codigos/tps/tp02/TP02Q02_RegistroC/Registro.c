/*
Repita a questão anterior criando o registro Pokémon na linguagem C.
*/

/*
 * Crie uma classe Pokémon seguindo todas as regras apresentadas no slide
 * unidade00l_conceitosBasicos_introducaoOO.pdf .
 * 
 * Sua classe terá os atributos privados:
 * 
 * id (int), generation (int), name (String), description (String), types (Lista), abilities (Lista),
 * weight (double), height (double), captureRate (int), isLegendary (boolean), captureDate (Date).
 * 
 * Sua classe também terá pelo menos dois construtores, e os métodos gets, sets, clone, imprimir e ler.
 * O método imprimir mostra os atributos do registro (ver cada linha da saída padrão) e o ler lê os
 * atributos de um registro.
 * 
 * Atenção para o arquivo de entrada, pois em alguns registros faltam valores e esse foi substituído
 * pelo valor 0 (zero) ou vazio.
 * 
 * A entrada padrão é composta por várias linhas e cada uma contém um n ́umero inteiro indicando o id do
 * Pokémon a ser lido. A ́ultima linha da entrada contém a palavra FIM.
 * 
 * A saída padrão também contém várias linhas, uma para cada registro contido em uma linha da entrada
 * padrão, no seguinte formato:
 * 
 * [#id -> name: description - [types] - [abilities] - weight - height - captureRate - isLegendary - generation] - captureDate].
 * 
 * Exemplo: [#181 -> Ampharos: Light Pokémon - [’electric’] - [’Static’, ’Plus’] - 61.5kg - 1.4m - 45% - false - 2 gen] - 25/05/1999
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Registro Pokemon
typedef struct Pokemon{
    // Atributos
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
    char *captureDate;
} Pokemon;

Pokemon *pokemon;
int totalPokemons = 0;


// Protótipos das funções
void ler();
void imprimir(int);
int get(int);
Pokemon set();
void save();
Pokemon clone(int);
char* str(char*);
int sizeStringsArray(char **);

// Função principal --------------------------------------------------------------------------
int main(){
    pokemon = (Pokemon*)malloc(802 * sizeof(Pokemon));
    if (pokemon == NULL) {
        printf(stderr, "Erro ao alocar memória\n");
        return 1;
    }

    ler();
    printf("TESTE");
    char str[4];
    int index;

    /* while(scanf("%s", str) == 1 || strcmp(str, "FIM") != 0){
        index = atoi(str);
        imprimir(index);
    }

    // Liberar memória alocada
    free(pokemon);
    
    return 0; */
}

// Função ler --------------------------------------------------------------------------------
void ler(){
    FILE *file = fopen("pokemon.csv", "r"); // /tmp/pokemon.csv
    int totalPokemons = 0;
    char buffer[1000];

    fgets(buffer, sizeof(buffer), file);
    while(totalPokemons <= 802){
        fscanf(file, "%d%*c %d%*c", &pokemon[totalPokemons].id, &pokemon[totalPokemons].generation); // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        pokemon[totalPokemons].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        pokemon[totalPokemons].description = str(buffer);

        // types
        fscanf(file, "%[^\"]%*c", buffer);
        char *pch = strtok(buffer, ",");
        pokemon[totalPokemons].types = (Pokemon**)malloc(1 * sizeof(Pokemon*));
        if (pokemon[totalPokemons].types == NULL) 
            printf(stderr, "Erro ao alocar memória\n");
        
        int count = 0;
        while(pch != NULL){
            if(count >= 1){
                pokemon[totalPokemons].types = (Pokemon**)realloc(pokemon[totalPokemons].types, (count + 1) * sizeof(Pokemon*));
                if (pokemon[totalPokemons].types == NULL) 
                    printf(stderr, "Erro ao realocar memória\n");
            }

            pokemon[totalPokemons].types[count] = str(pch);
            pch = strtok(NULL, ",");
            count++;
        }

        // abilities
        fscanf(file, "%[^\"]%*c%*c", buffer);
        pch = strtok(buffer, " ,[]'");
        pokemon[totalPokemons].abilities = (Pokemon**)malloc(1 * sizeof(Pokemon*));
        if (pokemon[totalPokemons].abilities == NULL) 
            printf(stderr, "Erro ao alocar memória\n");
 
        
        count = 0;
        while(pch != NULL){
            if(count >= 1){
                pokemon[totalPokemons].abilities = (Pokemon**)realloc(pokemon[totalPokemons].abilities, (count + 1) * sizeof(Pokemon*));
                if (pokemon[totalPokemons].abilities == NULL)
                    printf(stderr, "Erro ao realocar memória\n");
            }

            pokemon[totalPokemons].abilities[count] = str(pch);
            pch = strtok(NULL, " ,[]'");
            count++;
        }

        fscanf(file, "%[^,]%*c", buffer); // weight
        char *endptr;
        pokemon[totalPokemons].weight = buffer != "" ? strtod(buffer, &endptr) : 0;
        fscanf(file, "%[^,]%*c", buffer); // height
        char *endptr;
        pokemon[totalPokemons].height = buffer != "" ? strtod(buffer, &endptr) : 0;
        fscanf(file, "%d%*c", &pokemon[totalPokemons].captureRate); // captureRate
        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        pokemon[totalPokemons].isLegendary = buffer == "0" ? str("false") : str("true");
        fscanf(file, "%[^\n]", buffer); // captureDate
        pokemon[totalPokemons].captureDate = str(buffer);
        
        totalPokemons++;
    }
    fclose(file);
}

/* // Função imprimir ---------------------------------------------------------------------------
void imprimir(searchId){
    int index = get(searchId);

    printf("[#%d -> %s: %s - ", pokemon[index].id, pokemon[index].name, pokemon[index].description);

    int numTypes = sizeStringsArray(pokemon[index].types);
    printf("['%s'", pokemon[index].types[0]);
    for(int i = 1; i < numTypes; i++)
        printf(", '%s'", pokemon[index].types[i]);

    printf("] - ");

    int numAbilities = sizeStringsArray(pokemon[index].abilities);
    printf("['%s'", pokemon[index].abilities[0]);
    for(int i = 1; i < numAbilities - 1; i++)
        printf(", '%s', ", pokemon[index].abilities[i]);

    printf("'%s'] - ", pokemon[index].abilities[numAbilities - 1]);

    printf("%1lfkg - %1lfm - %d% - %s - %d gen] - %s\n", pokemon[index].weight, pokemon[index].height,
    pokemon[index].captureRate, pokemon[index].isLegendary, pokemon[index].generation, pokemon[index].captureDate);
}

// Função get --------------------------------------------------------------------------------
int get(int searchId){
    for(int i = 0; i < totalPokemons; i++)
        if(searchId == pokemon[i].id) { return i; }
}

// Função set --------------------------------------------------------------------------------
Pokemon set(){
    char buffer[100];
    pokemon = (Pokemon*)realloc(pokemon, totalPokemons + 1 * sizeof(Pokemon*));

    pokemon[totalPokemons].id = totalPokemons; // set id
    scanf("%[^\n]", buffer); // set name
    pokemon[totalPokemons].name = str(buffer); 
    scanf("%[^\n]", buffer); // set description
    pokemon[totalPokemons].description = str(buffer);    
    
    // set types
    scanf("%[^\n]", buffer);
    char *pch = strtok(buffer, ", ");
    pokemon[totalPokemons].types = (Pokemon**)malloc(1 * sizeof(Pokemon*));
    if (pokemon[totalPokemons].types == NULL) 
            printf(stderr, "Erro ao alocar memória\n");
    
    int count = 0;
    while(pch != NULL){
        if(count >= 1){
            pokemon[totalPokemons].types = (Pokemon**)realloc(pokemon[totalPokemons].types, (count + 1) * sizeof(Pokemon*));
            if (pokemon[totalPokemons].types == NULL) 
                printf(stderr, "Erro ao realocar memória\n");
        }

        pokemon[totalPokemons].types[count] = str(pch);
        pch = strtok(NULL, ", ");
        count++;
    }

    // set abilities
    scanf("%[^\n]", buffer);
    pch = strtok(buffer, " ,");
    pokemon[totalPokemons].abilities = (Pokemon**)malloc(1 * sizeof(Pokemon*));
    if (pokemon[totalPokemons].abilities == NULL) 
            printf(stderr, "Erro ao alocar memória\n");
    
    count = 0;
    while(pch != NULL){
        if(count >= 1){
            pokemon[totalPokemons].abilities = (Pokemon**)realloc(pokemon[totalPokemons].abilities, (count + 1) * sizeof(Pokemon*));
            if (pokemon[totalPokemons].abilities == NULL) 
                printf(stderr, "Erro ao realocar memória\n");
        }

        pokemon[totalPokemons].abilities[count] = str(pch);
        pch = strtok(NULL, " ,");
        count++;
    }

    scanf("%lf", &pokemon[totalPokemons].weight); // set weight
    scanf("%lf", &pokemon[totalPokemons].height); // set height
    scanf("%d", &pokemon[totalPokemons].captureRate); // set captureRate
    scanf("%[^\n]", buffer); // isLegendary
    pokemon[totalPokemons].isLegendary = buffer == "0" ? str("false") : str("true");
    scanf("%d", &pokemon[totalPokemons].generation); // set generation
    scanf("%[^\n]", buffer); // set captureDate
    pokemon[totalPokemons].captureDate = str(buffer);

    save();
    totalPokemons++;
}

// Função salvar novo Pokemon no arquivo -----------------------------------------------------
void save(){
    FILE *file = fopen("pokemon.csv", "a");

    fprintf(file, "%d,%d,%s,%s,", pokemon[totalPokemons].id, pokemon[totalPokemons].generation, pokemon[totalPokemons].name,
    pokemon[totalPokemons].description);
    
    int numTypes = sizeStringsArray(pokemon[totalPokemons].types);
    for(int i = 0; i < numTypes - 1; i++)
        fprintf(file, "\"['%s',]\"", pokemon[totalPokemons].types[i]);

    fprintf(file, "\"['%s']\",", pokemon[totalPokemons].types[numTypes - 1]);

    int numAbilities = sizeStringsArray(pokemon[totalPokemons].abilities);
    for(int i = 0; i < numAbilities - 1; i++)
        fprintf(file, "\"['%s',]\"", pokemon[totalPokemons].abilities[i]);

    fprintf(file, "\"['%s']\",", pokemon[totalPokemons].abilities[numAbilities - 1]);

    fprintf(file, "%1lf,%1lf,%d,%s,%s\n", pokemon[totalPokemons].weight, pokemon[totalPokemons].height, pokemon[totalPokemons].captureRate,
    pokemon[totalPokemons].isLegendary, pokemon[totalPokemons].captureDate);
    
    fclose(file);
}

// Função clone ------------------------------------------------------------------------------
Pokemon clone(int searchId){
    int index = get(searchId);

    pokemon[totalPokemons].id = pokemon[index].id;
    pokemon[totalPokemons].generation = pokemon[index].generation;
    pokemon[totalPokemons].name = pokemon[index].name;
    pokemon[totalPokemons].description = pokemon[index].description;
    pokemon[totalPokemons].types = pokemon[index].types;
    pokemon[totalPokemons].abilities = pokemon[index].abilities;
    pokemon[totalPokemons].weight = pokemon[index].weight;
    pokemon[totalPokemons].height = pokemon[index].height;
    pokemon[totalPokemons].captureRate = pokemon[index].captureRate;
    pokemon[totalPokemons].isLegendary = pokemon[index].isLegendary;
    pokemon[totalPokemons].captureDate = pokemon[index].captureDate;

    save();
    totalPokemons++;
} */

// Função para alocar string -----------------------------------------------------------------
char* str(char *str){
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    if (pokemon[totalPokemons].abilities == NULL) 
            printf(stderr, "Erro ao alocar memória\n");

    strcpy(info, str);

    return info;
}

/* // Função para encontrar o tamanho de um array de strings ------------------------------------
int sizeStringsArray(char **array){
    int size = 0;
    
    while (array[size] != NULL)
        size++;
    
    return size;
} */