/* Uma empresa deseja fazer o cadastro dos colaboradores. Os dados que deverão ser persistidos (arquivo) são: código, nome, email e salário.

O programa permite as seguintes funcionalidades:

1) Cadastrar colaborador
2) Consultar colaborador por nome
3) Consultar colaborador por codigo
4) Alterar salario
5) Remover colaborador
6) Mostrar soma dos salarios
7) Mostrar todos os colaboradores
0) Sair
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define maxcolab 100

typedef struct {
    int codigo;
    char nome[50];
    char email[50];
    double salario;
} Colaborador;

Colaborador colab[maxcolab];
int totalcolab = 0;

void carregarMenu();
void salvarcolab();
void cadastrarColab(char*, char*, double);
int criarcodigo();
int verificaRepeticao(int);
void consultColabPorNome(char*);
void consultColabPorCodigo(int);
void alterarSalario(int);
void removColab(int);
void mostrarSomaSal();
void mostrarcolab(int);
void str(char **);
void mostrarTodosColab();
void pressioneparaVoltar();
void pressioneEnter();

//Principal:

int main() {
    int codigo, opcao;
    double salario;
    char *nome, *email;

    carregarMenu();           

    do {
        printf("CONTROLE DE COLABORADORES:\n\n\n");
        printf("Total de colaboradores atuais: %d\n\n", totalcolab);
        printf("Escolha uma opcao:\n\n");
        printf("1) Cadastrar colaborador\n");
        printf("2) Consultar colaborador por nome\n");
        printf("3) Consultar colaborador por codigo\n");
        printf("4) Alterar salario\n");
        printf("5) Remover colaborador\n");
        printf("6) Mostrar soma dos salarios\n");
        printf("7) Mostrar todos os colaboradores\n");
        printf("0) Sair\n\n");
        printf("Resposta: ");
        scanf("%d", &opcao);

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");

        switch (opcao) {
            case 0:
                return 0;

            case 1:
                printf("\nDigite o nome do colaborador: ");
                str(&nome);
                printf("\nDigite o email do colaborador: ");
                str(&email);
                printf("\nDigite o salario do colaborador: ");
                scanf("%lf", &salario);
                printf("\n");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");

                cadastrarColab(nome, email, salario);
                break;

            case 2:
                printf("\nDigite o nome do colaborador: ");
                str(&nome);

                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");
                consultColabPorNome(nome);
                break;
            
            case 3:
                printf("\nDigite o codigo do colaborador: ");
                scanf("%d", &codigo);

                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");
                consultColabPorCodigo(codigo);
                break;

            case 4:
                printf("\nDigite o codigo do colaborador: ");
                scanf("%d", &codigo);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");

                alterarSalario(codigo);
                break;

            case 5:
                printf("\nDigite o codigo do colaborador: ");
                scanf("%d", &codigo);

                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");
                removColab(codigo);
                break;

            case 6:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");
                mostrarSomaSal();
                break;

            case 7:
                mostrarTodosColab();
                break;

            default:
                printf("\nopcaocao invalida! Tente novamente...\n\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

//Arquivo:

void carregarMenu() {
    FILE *arquivo = fopen("ListaColaboradores.txt", "r");
    if (arquivo != NULL) {
        while (fscanf(arquivo, "%d - %[^:]: %[^;]; R$%lf \n", &colab[totalcolab].codigo, 
                      colab[totalcolab].nome, colab[totalcolab].email, 
                      &colab[totalcolab].salario) != EOF) {
            totalcolab++;
        }
        fclose(arquivo);
    }
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

void cadastrarColab(char *nome, char *email, double salario) {
    if (totalcolab < maxcolab) {
        colab[totalcolab].codigo = criarcodigo();
        strcpy(colab[totalcolab].nome, nome);
        strcpy(colab[totalcolab].email, email);
        colab[totalcolab].salario = salario;
    
        consultColabPorCodigo(colab[totalcolab].codigo);
        totalcolab++;
        salvarcolab();
    } 
    else {
        printf("Limite de colab atingido.\n\n");
        
        pressioneEnter();
    }
    
}

int criarcodigo(){
    int codigo;

    srand(time(NULL));

    do{
        codigo = rand() % 90000 + 10000;      
    }while(verificaRepeticao(codigo) == 1);
    
    return codigo;
}

int verificaRepeticao(int codigo){
    for(int i = 0; i < totalcolab; i++){
        if(codigo == colab[i].codigo)
            return 1;
    }
    return 0;
}

// 2) Consultar colaborador por nome:

void consultColabPorNome(char *nome) {
    for (int i = 0; i < totalcolab; i++) {
        if (strcmp(nome, colab[i].nome) == 0) { // if (stricmp(nome, colab[i].nome) == 0) {
            mostrarcolab(i);
            
            pressioneparaVoltar();
            return;
        }
    }
    printf("Colaborador nao encontrado.\n\n");
    
    pressioneparaVoltar();
}

// 3) Consultar colaborador por codigo:

void consultColabPorCodigo(int codigo) {
    for (int i = 0; i <= totalcolab; i++) {
        if (codigo == colab[i].codigo) {
            mostrarcolab(i);
            
            pressioneparaVoltar();
            return;
        }
    }
    printf("Colaborador nao encontrado.\n\n");
    
    pressioneparaVoltar();
}

// 4) Alterar salario:

void alterarSalario(int codigo) {
    double novoSalario;

    for (int i = 0; i < totalcolab; i++) {
        if (colab[i].codigo == codigo) {
            mostrarcolab(i);
            printf("Digite o novo salario: ");
            scanf("%lf", &novoSalario);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");

            colab[i].salario = novoSalario;
            salvarcolab();
            mostrarcolab(i);
            
            pressioneparaVoltar();
            return;
        }
    }
    printf("Colaborador nao encontrado.\n\n");
    
    pressioneparaVoltar();
}

// 5) Remover colaborador:

void removColab(int codigo) {
    char *confirmacao;

    for (int i = 0; i < totalcolab; i++) {
        if (colab[i].codigo == codigo) {
            mostrarcolab(i);
            printf("Voce tem certeza? (Digite 'sim' ou 'nao'): ");
            str(&confirmacao);

            if((strcmp(confirmacao, "nao\0")) == 0){ // if((stricmp(confirmacao, "nao\0")) == 0){
                printf("\n");
                pressioneparaVoltar();
                return;
            }
            else if((strcmp(confirmacao, "sim\0")) == 0){ // else if((stricmp(confirmacao, "sim\0")) == 0){
                for (int j = i; j < totalcolab - 1; j++) {
                    colab[j] = colab[j + 1];
                }
                totalcolab--;
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");

                printf("Colaborador %s removido.\n\n", colab[i].nome);
                salvarcolab();
                
                pressioneparaVoltar();
                return;
            }
            else{
                getchar();
                printf("\nInvalido.\n");
                pressioneparaVoltar();
                return;
            }
        }
    }
    printf("Colaborador nao encontrado.\n\n");
    
    pressioneparaVoltar();
}

// 6) Mostrar soma dos salarios:

void mostrarSomaSal() {
    double soma = 0;
    for (int i = 0; i < totalcolab; i++) {
        soma += colab[i].salario;
    }
    printf("Soma dos salarios: %.2lf\n\n", soma);
    
    pressioneparaVoltar();
}

// 7) Mostrar todos os colaboradores:

void mostrarTodosColab(){
    for(int i = 0; i < totalcolab; i++){
        printf("\nColaborador %d:\n\n", i + 1);
        mostrarcolab(i);
        i != (totalcolab - 1) ? printf("_____________________________________________________\n") : 0;
    }
    
    pressioneparaVoltar();
}

// Demais funções:

void str(char **info){
    char buffer[100];

    getchar();
    scanf("%[^\n]", buffer);

    *info = (char*)malloc((strlen(buffer) + 1) * sizeof(char));

    strcpy(*info, buffer);
}

void mostrarcolab(int i){
        printf("Codigo: %d\n", colab[i].codigo);
        printf("Nome: %s\n", colab[i].nome);
        printf("Email: %s\n", colab[i].email);
        printf("Salario: %.2lf\n\n", colab[i].salario);
}

void pressioneparaVoltar(){
    getchar();
    printf("\t\tPressione enter para voltar!\n");
    while(getchar() != '\n');
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");
}

void pressioneEnter(){
    getchar();
    printf("\t\tPressione enter!\n");
    while(getchar() != '\n');
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // system("cls");
}