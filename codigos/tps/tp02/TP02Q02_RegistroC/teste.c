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

typedef struct ArrayPokemons {
    int totalPokemon;
    Pokemon *pokemon;
} ArrayPokemons;

void ler(Pokemon*, int*);                               // Leitura do arquivo csv
char* str(char *);                                      // Alocação de strings com o tamanho exato
void searchPokemonId(int, Pokemon*, int);               // Pesquisa Sequêncial por id
void searchPokemonGeneration(int, Pokemon*, int);       // Pesquisa Sequêncial por generation
void searchPokemonName(char*, Pokemon*, int);           // Pesquisa Sequêncial por name
void searchPokemonDescription(char*, Pokemon*, int);    // Pesquisa Sequêncial por description
void searchPokemonTypes(char*, Pokemon*, int);          // Pesquisa Sequêncial por types
void searchPokemonAbilities(char*, Pokemon*, int);      // Pesquisa Sequêncial por abilities
void searchPokemonWeight(double, Pokemon*, int);        // Pesquisa Sequêncial por weight
void searchPokemonHight(double, Pokemon*, int);         // Pesquisa Sequêncial por height
void searchPokemonCaptureRate(int, Pokemon*, int);      // Pesquisa Sequêncial por caotureRate
void searchPokemonIsLegendary(char*, Pokemon*, int);    // Pesquisa Sequêncial por isLegendary
void searchPokemonDate(char*, Pokemon*, int);           // Pesquisa Sequêncial por date
void pritingAllPokemons(Pokemon*, int);                 // Imprimindo todos os Pokemons
void imprimir(int, Pokemon*);                           // Impressão do Pokemon
//void clone(int, Pokemon*);                            // Clonagem do Pokemon

int main() {
    ArrayPokemons arrayP;
    arrayP.pokemon = (Pokemon*)malloc(1 * sizeof(Pokemon));
    arrayP.totalPokemon = 0;
   
    ler(arrayP.pokemon, &arrayP.totalPokemon);

    char str[10];
    int index;

    scanf("%s", str);
    while (strcmp(str, "FIM") != 0) {
        index = atoi(str); 
        imprimir(index, arrayP.pokemon);
        scanf("%s", str);
    }

    int option;
    char optionABC;

    do{
        printf("\t\tLISTA DE POKEMONS\n\n");
        printf("Selecione uma opção:\n");
        printf("1) Cadastrar Pokemon.\n");
        printf("2) Excluir Pokemon.\n");
        printf("3) Editar Pokemon.\n");
        printf("4) Pesquisar Pokemon por Id.\n");
        printf("5) Pesquisar Pokemon por nome.\n");
        printf("6) Listar Pokemons por ordem de Id.\n");
        printf("7) Listar Pokemons por data de captura.\n");
        printf("8) Listar Pokemons por ordem alfabetica.\n");
        printf("9) Filtros.\n");
        printf("0) Encerrar.\n");

        printf("\nResposta: ");
        
        printf("7) Filtrar generation.\n");
        printf("8) Filtrar generation.\n");
        
        switch (option){
            case 1:
                        
                break;

            case 2:
                        
                break;

            case 3:
                        
                break;

            case 4:
                        
                break;

            case 5:
                        
                break;

            case 6:
                printf("a) Listar Pokemons por ordem de Id.\n");
                printf("b) Listar Pokemons por data de captura.\n");
                printf("c) Listar Pokemons por ordem alfabetica.\n"); 

                scanf("%c", &optionABC);

                switch (optionABC){
                    case 'a':
                        
                        break;

                    case 'b':
                        
                        break;

                    case 'c':
                        
                        break;

                    default:
                        break;
                }

                break;
            
            case 7:
                printf("a) Filtrar generation.\n");
                printf("b) Filtrar description.\n");
                printf("c) Filtrar types.\n");
                printf("d) Filtrar abilities.\n");
                printf("e) Filtrar weight.\n");
                printf("e) Filtrar height.\n");
                printf("f) Filtrar captureRate.\n");
                printf("g) Filtrar isLegendary.\n");
                printf("h) Filtrar date.\n");
                printf("i) Voltar.");

                scanf("%c", &optionABC);

                switch (optionABC){
                    case 'a':
                        
                        break;

                    case 'b':
                        
                        break;

                    case 'c':
                        
                        break;

                    case 'd':
                        
                        break;

                    case 'e':
                        
                        break;
                    
                    case 'f':
                        
                        break;

                    case 'g':
                        
                        break;
                    
                    case 'h':
                        
                        break;

                    case 'i':
                        
                        break;
                    
                    default:
                        break;
                }

                break;

            case 8:
                        
                break;

            case 0:
                        
                break;
            
            default:
                break;
        }
    }while(option != 0);

    free(arrayP.pokemon);
}

void ler(Pokemon *pokemon, int *totalPokemon) {
    FILE *file = fopen("pokemon.csv", "r"); // /tmp/pokemon.csv
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char buffer[1000];

    fgets(buffer, sizeof(buffer), file);
    while (fscanf(file, "%d%*c %d%*c", &pokemon[*totalPokemon].id, &pokemon[*totalPokemon].generation) != EOF) { // id, generation
        fscanf(file, "%[^,]%*c", buffer); // name
        pokemon[*totalPokemon].name = str(buffer);
        fscanf(file, "%[^,]%*c", buffer); // description
        pokemon[*totalPokemon].description = str(buffer);

        // types
        int cont = 0;
        char *pch;

        fscanf(file, "%[^\"]%*c", buffer); 
        pokemon[*totalPokemon].types = (char**)malloc(2 * sizeof(char*)); 

        pch = strtok(buffer, ",");  
        while (pch != NULL) {
            pokemon[*totalPokemon].types[cont] = str(pch); 
            cont++;
            pokemon[*totalPokemon].types = (char**)realloc(pokemon[*totalPokemon].types, (cont + 1) * sizeof(char*)); 
            pch = strtok(NULL, ",");
        }
        pokemon[*totalPokemon].types[cont] = NULL; 

        // abilities 
        fscanf(file, "%*c%*c%[^]]%*c%*c%*c", buffer); 
        pokemon[*totalPokemon].abilities = (char**)malloc(2 * sizeof(char*)); 

        pch = strtok(buffer, "'"); 

        pokemon[*totalPokemon].abilities[0] = str(pch);
        pch = strtok(NULL, "'");
        pch = strtok(NULL, "'");

        cont = 1;
        while (pch != NULL) {
            pokemon[*totalPokemon].abilities[cont] = str(pch);

            cont++;
            pokemon[*totalPokemon].abilities = (char**)realloc(pokemon[*totalPokemon].abilities, (cont + 1) * sizeof(char*)); 
            pch = strtok(NULL, "'");
            pch = strtok(NULL, "'");
        }
        pokemon[*totalPokemon].abilities[cont] = NULL; 

        // weight
        cont = 0;
        int comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                pokemon[*totalPokemon].weight = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            pokemon[*totalPokemon].weight = atof(buffer);
        }

        // height
        cont = 0;
        comma = 0;
        while(comma < 1){
            buffer[cont] = fgetc(file);
            if(buffer[cont] == ','){
                comma++;
                pokemon[*totalPokemon].height = 0.0;
                break;
            }else{
                cont++;
            }
        }

        if(cont > 1){
            buffer[cont + 1] = '\0';
            pokemon[*totalPokemon].height = atof(buffer);
        }

        fscanf(file, "%d%*c", &pokemon[*totalPokemon].captureRate); // captureRate

        fscanf(file, "%[^,]%*c", buffer); // isLegendary
        pokemon[*totalPokemon].isLegendary = strcmp(buffer, "0") == 0 ? str("false") : str("true");

        fscanf(file, "%[^\n]", buffer); // date
        pokemon[*totalPokemon].date = str(buffer);

        *totalPokemon++;
        pokemon = (Pokemon*)realloc(pokemon, (*totalPokemon + 1) * sizeof(Pokemon)); 
    }
    fclose(file);  
}

char* str(char *str) {
    char *info = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(info, str);
    return info;
}

void salvarcolab() {
    FILE *arquivo = fopen("ListaColaboradores.txt", "w");

    for (int i = 0; i < totalcolab; i++) {
        fprintf(arquivo, "%d - %s: %s; R$%.2lf\n", colab[i].codigo, colab[i].nome, 
                colab[i].email, colab[i].salario);
    }
    fclose(arquivo);
}

// 1) Cadastrar colaborador:

void registerPokemon(Pokemon *pokemon, int *totalPokemon) {
    int newGeneration;
    char *newName;
    char *newDescription;
    char **newTypes;
    char **newAbilities;
    double newWeight;
    double newHeight;
    int newCaptureRate;
    char *newIsLegendary;
    char *newDate;

    printf("Generation: ");
    printf("\nName: ");
    printf("\nTypes: ");
    printf("\nAbilities: ");
    printf("\nWeight: ");
    printf("\nHeight: ");
    printf("\nCaptureRate: ");
    printf("\nIsLegendary: ");
    printf("\nDate: ");
    scanf("%d %[^\n] %[^\n]")

    

    pokemon[*totalPokemon].id =


        colab[totalcolab].codigo = criarcodigo();
        strcpy(colab[totalcolab].nome, nome);
        strcpy(colab[totalcolab].email, email);
        colab[totalcolab].salario = salario;
    
        consultColabPorCodigo(colab[totalcolab].codigo);
        totalcolab++;
        salvarcolab();
        printf("Limite de colab atingido.\n\n");
        
        pressioneEnter();

}

// PESQUISAS SEQUENCIAIS:
void searchPokemonId(int searchId, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){ if (searchId == pokemon[i].id){ imprimir(i, pokemon); break; } }
}

void searchPokemonGeneration(int searchGeneration, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){ if (searchGeneration == pokemon[i].generation) imprimir(i, pokemon); }
}

void searchPokemonName(char *searchName, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){ if (strcmp(searchName, pokemon[i].name) == 0) imprimir(i, pokemon); }
}

void searchPokemonDescription(char *searchDescription, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){ if (strcmp(searchDescription, pokemon[i].description) == 0) imprimir(i, pokemon); }
}

void searchPokemonTypes(char *searchTypes, Pokemon *pokemon, int totalPokemon){
    int j;
    for (int i = 0; i < totalPokemon; ++i){
        j = 0;
        while(pokemon[i].types[j] != NULL){ if (strcmp(searchTypes, pokemon[i].types[j]) == 0) imprimir(i, pokemon); }
    }
}

void searchPokemonAbilities(char *searchAbilities, Pokemon *pokemon, int totalPokemon){
    int j;
    for (int i = 0; i < totalPokemon; ++i){
        j = 0;
        while(pokemon[i].abilities[j] != NULL){ if (strcmp(searchAbilities, pokemon[i].abilities[j]) == 0) imprimir(i, pokemon); }
    }
}

void searchPokemonWeight(double searchWeight, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){
        if (searchWeight == pokemon[i].weight)
            imprimir(i, pokemon);
    }
}

void searchPokemonHeight(double searchHeight, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){
        if (searchHeight == pokemon[i].height)
            imprimir(i, pokemon);
    }
}

void searchPokemonCaptureRate(int searchCaptureRate, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){
        if (searchCaptureRate == pokemon[i].captureRate)
            imprimir(i, pokemon);
    }
}

void searchPokemonIsLegendary(char *searchIsLegendary, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){
        if (strcmp(searchIsLegendary, pokemon[i].isLegendary) == 0)
            imprimir(i, pokemon);
    }
}

void searchPokemonDate(char *searchDate, Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i){
        if (strcmp(searchDate, pokemon[i].date) == 0)
            imprimir(i, pokemon);
    }
}

// Imprimir todos os Pokemons
void printingAllPokemons(Pokemon *pokemon, int totalPokemon){
    for (int i = 0; i < totalPokemon; ++i)
        imprimir(i, pokemon);
}

// Impressão do Pokemon
void imprimir(int index, Pokemon *pokemon){
    printf("[#%d -> %s: %s ", pokemon[index].id, pokemon[index].name, pokemon[index].description);

    // Types
    int cont = 0;
    printf("[");
    while (pokemon[index].types[cont] != NULL) {
        if (cont > 0) printf(", ");
        printf("'%s'", pokemon[index].types[cont]);
        cont++;
    }
    printf("] - [");

    // Abilities
    cont = 0;
    while (pokemon[index].abilities[cont] != NULL) {
        if (cont > 0) printf(", ");
        printf("'%s'", pokemon[index].abilities[cont]);
        cont++;
    }
    printf("] - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", pokemon[index].weight, pokemon[index].height, pokemon[index].captureRate,
           pokemon[index].isLegendary, pokemon[index].generation, pokemon[index].date);
}
