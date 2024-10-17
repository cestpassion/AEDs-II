#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pokemon{
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
}Pokemon;

int totalPokemon = 0;
Pokemon *pokemon;

void ler();
char* str(char *);
void imprimir(int);
void clone(int);

int main(){
    pokemon = (Pokemon*)malloc(1 * sizeof(Pokemon));
   
    ler();

    char str[4];
    int index;

    while(scanf("%s", str) == 1 || strcmp(str, "FIM") != 0){
        index = atoi(str);
        imprimir(index);
    }
}

void ler(){
    FILE *file = fopen("pokemon.txt", "r");
    char buffer[1000];

    while(fscanf(file, "%d%*c %d%*c", &pokemon[totalPokemon].id, &pokemon[totalPokemon].generation) != EOF){ // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        pokemon[totalPokemon].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer);
        pokemon[totalPokemon].description = str(buffer);

        // types
        /* pokemon[totalPokemon].types = (char**)malloc(2 * sizeof(char*));
        for(int i = 0; i < 2; ++i){
          fscanf(file, "%[^,]%*c", buffer);
          if(strcmp(buffer, "") != 0)
        pokemon[totalPokemon].types[i] = str(buffer);
          else
        pokemon[totalPokemon].types[i] = NULL;
        }
        pokemon[totalPokemon].types[2] = NULL; */

        int cont = 0;
        char *pch;

        fscanf(file, "[^\"]%*c", buffer);
        pokemon[totalPokemon].types = (char**)malloc(2 * sizeof(char*));

        pch = (buffer, ",");
        pokemon[totalPokemon].types[cont] = str(pch);
        pch = strtok(NULL, ",");

        while(pch != NULL){
            pokemon[totalPokemon].types = (char**)realloc(pokemon[totalPokemon].types, (cont + 2) * sizeof(char*));
            cont++;

            pokemon[totalPokemon].types[cont] = str(pch);
            pch = strtok(NULL, ",");
        }
        pokemon[totalPokemon].types[cont + 2] = NULL;


        // abilities
        cont = 0;

        fscanf(file, "%*c%*c%[^\]]%*c%*c", buffer);
        pokemon[totalPokemon].abilities = (char**)malloc(2 * sizeof(char*));

        pch = (buffer, "',");
        pokemon[totalPokemon].abilities[cont] = str(pch);
        pch = strtok(NULL, "',");

        while(pch != NULL){
            pokemon[totalPokemon].abilities = (char**)realloc(pokemon[totalPokemon].abilities, (cont + 2) * sizeof(char*));
            cont++;
            
            pch = strtok(NULL, "',");
            pokemon[totalPokemon].abilities[cont] = str(pch);
            pch = strtok(NULL, "',");
        }
        pokemon[totalPokemon].abilities[cont + 2] = NULL;

        fscanf(file, "%[^,]%*c", buffer); // weight
        pokemon[totalPokemon].weight = strcmp(buffer, "") != 0 ? atof(buffer) : 0;
        fscanf(file, "%[^,]%*c", buffer); // height
        pokemon[totalPokemon].height = strcmp(buffer, "") != 0 ? atof(buffer) : 0;
        fscanf(file, "%d%*c", pokemon[totalPokemon].captureRate); // captureRate
        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        pokemon[totalPokemon].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");
        fscanf(file, "%[^\n]", buffer); // date
        pokemon[totalPokemon].date = str(buffer);

        totalPokemon++;
        pokemon = (Pokemon*)realloc(pokemon, totalPokemon + 1 * sizeof(Pokemon));
    }
    fclose(file);  
}

char* str(char *str){
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);
   
    return info;
}

void imprimir(int searchId){
    for(int i = 0; i < totalPokemon; ++i){
        if(searchId == pokemon[i].id){
            printf("[#%d -> %s: %s ", pokemon[i].id, pokemon[i].name, pokemon[i].description);

            //types
            int cont = 0;

            printf("[");
            do{
                if(cont > 0) printf(", ");
                printf("'%s'", pokemon[i].types[cont]);
                cont++;
            }while(pokemon[i].types[cont] != NULL);
            printf("] - [");

            //abilities
            cont = 0;

            do{
            if(cont > 0) printf(", ");
                printf("'%s'", pokemon[i].abilities[cont]);
                cont++;
            }while(pokemon[i].abilities[cont] != NULL);
            printf("] - %fl - %fl - %d - %s - %d] - %s", pokemon[i].weight, pokemon[i].height, pokemon[i].captureRate, pokemon[i].isLegendary, pokemon[i].generation, pokemon[i].date);

            break;
        }
    }
}

void clone(int searchId){
    for(int i = 0; i < totalPokemon; ++i){
        if(searchId == pokemon[i].id){
            totalPokemon++;
            pokemon[totalPokemon].id = pokemon[i].id;
            pokemon[totalPokemon].generation = pokemon[i].generation;
            pokemon[totalPokemon].name = str(pokemon[i].name);
            pokemon[totalPokemon].description = str(pokemon[i].description);

            // types
            int cont = 0;
            pokemon[totalPokemon].types = (char**)malloc(2 * sizeof(char*));

            while(pokemon[i].types[cont] != NULL){
                if(cont > 0) pokemon[totalPokemon].types = (char**)realloc(pokemon[totalPokemon].types, (cont + 2) * sizeof(char*));
                pokemon[totalPokemon].types[cont] = str(pokemon[i].types[cont]);
                cont++;
            }
            pokemon[totalPokemon].types[cont + 1] = NULL;

            // abilities
            cont = 0;
            pokemon[totalPokemon].abilities = (char**)malloc(2 * sizeof(char*));

            while(pokemon[i].abilities[cont] != NULL){
                if(cont > 0) pokemon[totalPokemon].abilities = (char**)realloc(pokemon[totalPokemon].abilities, (cont + 2) * sizeof(char*));
                pokemon[totalPokemon].abilities[cont] = str(pokemon[i].abilities[cont]);
                cont++;
            }
            pokemon[totalPokemon].types[cont + 1] = NULL;

            pokemon[totalPokemon].weight = pokemon[i].weight;
            pokemon[totalPokemon].height = pokemon[i].height;
            pokemon[totalPokemon].captureRate = pokemon[i].captureRate;
            pokemon[totalPokemon].isLegendary = str(pokemon[i].isLegendary);
            pokemon[totalPokemon].date = str(pokemon[i].date);

            break;
        }
    }
}