#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int totalPokemon = 0;
Pokemon *pokemon;

void ler();
char* str(char *);
void imprimir(int);
void clone(int);

int main() {
    pokemon = (Pokemon*)malloc(1 * sizeof(Pokemon));
   
    ler();

    char str[10];
    int index;

    // Corrigir a condição de parada
    while (1) {
        scanf("%s", str);
        if (strcmp(str, "FIM") == 0) break; // Se "FIM", sair do loop
        index = atoi(str);  // Converte a string lida em um número
        imprimir(index);    // Chama a função imprimir
    }

    free(pokemon); // Liberação da memória alocada
}

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

char* str(char *str) {
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);
    return info;
}

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
