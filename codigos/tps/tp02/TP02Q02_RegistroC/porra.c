
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void ler();
void imprimir(int);
int get(int);
// Pokemon set();
// void save();
// Pokemon clone(int);
char* str(char*);
int sizeStringsArray(char **);

// Função principal --------------------------------------------------------------------------
int main(){
    pokemon = (Pokemon*)malloc(802 * sizeof(Pokemon));

    ler();

    char str[4];
    int index;

    while(scanf("%s", str) == 1 || strcmp(str, "FIM") != 0){
        index = atoi(str);
        imprimir(index);
    }

    // Liberar memória alocada
    free(pokemon);
    
    return 0;
}

void ler(){
    FILE *file = fopen("pokemon.csv", "r"); // /tmp/pokemon.csv
    char buffer[1000];

    fgets(buffer, sizeof(buffer), file);
    while(totalPokemons <= 801){
        fscanf(file, "%d%*c %d%*c", &pokemon[totalPokemons].id, &pokemon[totalPokemons].generation); // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        pokemon[totalPokemons].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        pokemon[totalPokemons].description = str(buffer);

        // types
        fscanf(file, "%[^\"]%*c", buffer);
        char *pch = strtok(buffer, ",");
        pokemon[totalPokemons].types = (char**)malloc(2 * sizeof(char*));

        printf("TESTE 1");
        
        int count = 1;
        while(pch != NULL){
            if(count >= 2)
                pokemon[totalPokemons].types = (char**)realloc(pokemon[totalPokemons].types, (count + 1) * sizeof(char*));

            pokemon[totalPokemons].types[count] = str(pch);
            pch = strtok(NULL, ",");
            count++;
        }
        pokemon[totalPokemons].types[--count] = NULL;

        printf("TESTE 2");

        // abilities
        fscanf(file, "%[^\"]%*c%*c", buffer);
        pch = strtok(buffer, " ,[]'");
        pokemon[totalPokemons].abilities = (char**)malloc(2 * sizeof(char*)); 
        
        count = 1;
        while(pch != NULL){
            if(count >= 2)
                pokemon[totalPokemons].abilities = (char**)realloc(pokemon[totalPokemons].abilities, (count + 1) * sizeof(char*));

            pokemon[totalPokemons].abilities[count] = str(pch);
            pch = strtok(NULL, " ,[]'");
            count++;
        }
        pokemon[totalPokemons].abilities[--count] = NULL;

        fscanf(file, "%[^,]%*c", buffer); // weight
        char *endptr;
        pokemon[totalPokemons].weight = buffer != "" ? strtod(buffer, &endptr) : 0;
        fscanf(file, "%[^,]%*c", buffer); // height
        pokemon[totalPokemons].height = buffer != "" ? strtod(buffer, &endptr) : 0;
        fscanf(file, "%d%*c", &pokemon[totalPokemons].captureRate); // captureRate
        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        pokemon[totalPokemons].isLegendary = buffer == "0" ? str("false") : str("true");
        fscanf(file, "%[^\n]", buffer); // captureDate
        pokemon[totalPokemons].captureDate = str(buffer);

        totalPokemons++;
    }
}

// Função imprimir ---------------------------------------------------------------------------
void imprimir(int searchId){
    int index = get(searchId);

    printf("TESTE1");

    printf("[#%d -> %s: %s - ", pokemon[index].id, pokemon[index].name, pokemon[index].description);

    printf("TESTE2");

    int numTypes = sizeStringsArray(pokemon[index].types);
    //printf("%d\n", numTypes);
    printf("['%s'", pokemon[index].types[0]);
    for(int i = 1; i < numTypes; i++)
        printf(", '%s'", pokemon[index].types[i]);

    printf("] - ");

    int numAbilities = sizeStringsArray(pokemon[index].abilities);
    printf("['%s'", pokemon[index].abilities[0]);
    for(int i = 1; i < numAbilities - 1; i++)
        printf(", '%s', ", pokemon[index].abilities[i]);

    printf("'%s'] - ", pokemon[index].abilities[numAbilities - 1]);

    printf("%.1lfkg - %.1lfm - %d - %s - %d gen] - %s\n", pokemon[index].weight, pokemon[index].height,
    pokemon[index].captureRate, pokemon[index].isLegendary, pokemon[index].generation, pokemon[index].captureDate);
}

// Função get --------------------------------------------------------------------------------
int get(int searchId){
    for(int i = 0; i < totalPokemons; i++)
        if(searchId == pokemon[i].id) { return i; }
}

// Função para alocar string -----------------------------------------------------------------
char* str(char *str){
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);

    return info;
}

// Função para encontrar o tamanho de um array de strings ------------------------------------
int sizeStringsArray(char *array[]){
    int size = 0;
    
    while (array[size] != NULL){     
        size++;
    }    

    return size;
}
