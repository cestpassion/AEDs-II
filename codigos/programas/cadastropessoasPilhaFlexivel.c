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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
    char *name;
    int age;
} Person;

typedef struct Celula {
	Person pessoa;       
	struct Celula* prox; 
} Celula;

Celula* newCelula(Person newPessoa) {
    Celula* new = (Celula*) malloc(sizeof(Celula));
    new->pessoa = newPessoa;
    new->prox = NULL;

    return new;
}

typedef struct FlexStack{
    Celula *top;
} FlexStack;

void start(FlexStack *stack){
    stack->top = NULL;
}

void inserir(FlexStack *stack, Person pessoa){
    Celula *tmp = newCelula(pessoa);

    tmp->prox = stack->top;
    stack->top = tmp;

    tmp = NULL;
}

Person remover(FlexStack *stack){
    if(stack->top == NULL){
        printf("Erro! Nao ha datas para remover");
        exit(1);
    }

    Person removedData = stack->top->pessoa;
    Celula *tmp = stack->top;
    stack->top = stack->top->prox;
    
    tmp->prox = NULL;

    return removedData;
}

int sizeStack(FlexStack stack){
    Celula *i = stack.top;
    int j;

    for(j = 0; i != NULL; i = i->prox, j++);
    free(i);
    
    return j;
}

void mostrar(FlexStack stack){
    if(stack.top != NULL){
        int size = sizeStack(stack) - 1;

        printf("\nPeossas cadastradas na pilha:\n\n");

        for(Celula *i = stack.top; i != NULL; i = i->prox)
            printf("[Pessoa %d]:\nNome: %s\nIdade: %d\n\n", size--, i->pessoa.name,
                    i->pessoa.age);
    }
    else{
        printf("Nao ha pessoas.\n");
    }
}

char *strAloc(char *str){
    char *str2 = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(str2, str);
    return str2;
}

int main(){
    FlexStack stack;

    start(&stack);

    char input[50];
    int cadastros = 0;

    printf("-------------------------------------------------------------\n");
    printf("Preencha os dados das pessoas e digite \"FIM\" para finalizar\n");
    printf("-------------------------------------------------------------\n");
    printf("\n 0 Pessoas\nNome ou FIM: ");
    scanf("%[^\n]", input);

    while(strcmp(input, "FIM") != 0){
        getchar();

        Person newPessoa;
        newPessoa.name = strAloc(input);
        
        printf("Idade: ");
        while(scanf("%d", &newPessoa.age) != 1){
            printf("\nDigite uma idade valida: ");
            while (getchar() != '\n'); 
        }
        getchar();

        inserir(&stack, newPessoa);

        printf("\n%d Pessoas\nNome ou FIM: ", cadastros);
        scanf("%[^\n]", input);
        cadastros++;
    }

    int removes;
    printf("\nDigite quantas pessoas deseja remover: ");
    while(scanf("%d", &removes) != 1){
            printf("\nDigite um numero valido: ");
            while (getchar() != '\n'); 
    }

    while(removes > cadastros && cadastros > 0){
        printf("Nao e possivel remover %d pessoas, pois ha apenas %d.\nTente novamente: ", removes, cadastros);
        while(scanf("%d", &removes) != 1){
            printf("\nDigite um numero valido: ");
            while (getchar() != '\n'); 
        }
    }

    for(int i = 0; i < removes; ++i, remover(&stack));

    mostrar(stack);
}

