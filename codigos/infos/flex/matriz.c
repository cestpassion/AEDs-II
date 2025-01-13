#include <stdio.h>
#include <stdlib.h>

typedef struct Cell{
    int element;
    struct Cell *left;
    struct Cell *right;
    struct Cell *upper;
    struct Cell *lower;
} Cell;

Cell *newEmptyCell(){
    Cell *new = (Cell*)malloc(sizeof(Cell));

    new->element = 0;
    new->left = new->right = new->upper = new->lower = NULL;

    return new;
}

typedef struct Matrix{
    Cell *start;
    int numRows;
    int numColuns;
} Matrix;

void addRow(Cell *upperRow){
    upperRow->lower = newEmptyCell();
    Cell *back = upperRow->lower;
    back->upper = upperRow;
    Cell *front = NULL;
    upperRow = upperRow->right;

    while(upperRow != NULL){
        front = newEmptyCell();

        back->right = front;
        front->left = back;

        upperRow->lower = front;
        front->upper = upperRow;

        upperRow = upperRow->right;
        back = back->right;
        front = NULL;
    }
}

void addColun(Cell *leftColun){
    leftColun->right = newEmptyCell();
    Cell *top = leftColun->right;
    top->left = leftColun;
    Cell *below = NULL;
    leftColun = leftColun->lower;

    while(leftColun != NULL){
        below = newEmptyCell();

        top->lower = below;
        below->upper = top;

        leftColun->right = below;
        below->left = leftColun;

        leftColun = leftColun->lower;
        top = top->lower;
        below = NULL;
    }
}

void initEmptyMatrix(Matrix *matrix, int numRows, int numColuns){
    matrix->start = newEmptyCell();
    matrix->numColuns = numColuns;
    matrix->numRows = numRows;

    Cell *back = matrix->start;
    Cell *front = NULL;
    for(int i = 1; i < numColuns; i++, back = back->right, front = front->right){
        front = newEmptyCell();
        back->right = front;
        front->left = back;
    }
    
    for(int i = 1; i < numRows; i++){
        Cell *tmp = matrix->start;
        while(tmp->lower != NULL)
            tmp = tmp->lower;

        addRow(tmp);
    }
}

void fillMatrix(Matrix *matrix){
    int index = 1;

    for(Cell *i = matrix->start; i != NULL; i = i->lower){
        //printf("Linha %d: ", index++);

        for(Cell *j = i; j != NULL; j = j->right)
            scanf("%d%*c", &j->element);
    }
}

void showMatrix(Matrix matrix){
    int index = 1;

    for(Cell *i = matrix.start; i != NULL; i = i->lower){
        //printf("\nLinha %d:", index++);

        for(Cell *j = i; j != NULL; j = j->right)
            printf("  %d", j->element);
    }
    printf("\n");
}

void sumMatrix(Matrix matrix1, Matrix matrix2, Matrix *matrix3){
    Cell *tmp = matrix3->start;
    
    for(Cell *i1 = matrix1.start, *i2 = matrix2.start; i1 != NULL; i1 = i1->lower, i2 = i2->lower){
        for(Cell *j1 = i1, *j2 = i2; j2 != NULL; j1 = j1->right, j2 = j2->right){
            tmp->element = j1->element + j2->element;
            tmp = tmp->right;
        }
        tmp = tmp->lower;
    }
}

void multMatrix(Matrix matrix1, Matrix matrix2, Matrix *matrix3){
    Cell *tmp = matrix3->start;
    
    for(Cell *i1 = matrix1.start, *i2 = matrix2.start; i1 != NULL; i1 = i1->lower, i2 = i2->lower){
        for(Cell *j1 = i1, *j2 = i2; j1 != NULL; j1 = j1->right, j2 = j2->right){
            tmp->element = j1->element * j2->element;
            tmp = tmp->right;
        }
        tmp = tmp->lower;
    }
}

void showDiagonalPrincpal(Matrix matrix){  
    int space = 0;

    for(Cell *i = matrix.start; i != NULL; i = i->lower->right, space++){
        for(int j = 0; j < space; j++)
            printf("   ");

        printf("%d\n", i->element);
    }
}

void showDiagonalSecundaria(Matrix matrix){  
    int space = 0;
    Cell *i;
    for(i = matrix.start; i->right != NULL; i = i->right, space++);

    
    while(i != NULL){
        for(int j = space - 1; j >= 0; j--)
            printf("   ");

        printf("%d\n", i->element);
        i = i->lower->left;
        space--;
    }
}

int main(){
    int tests, rows, coluns;
    Matrix matrix1, matrix2, matrix3;

    // printf("Digite o numero de casos de teste: ");
    scanf("%d%*c", &tests); 
    
    tests *= 2;

    for(int i = 0; i < tests; i++){
        // PRIMEIRA MATRIZ
        //printf("\nDigite o numero de linhas da primeira matriz: ");
        scanf("%d%*c", &rows);

        //printf("Digite o numero de colunas da primeira matriz: ");
        scanf("%d%*c", &coluns);

        initEmptyMatrix(&matrix3, rows, coluns);
        initEmptyMatrix(&matrix1, rows, coluns);

        //printf("\nPreencha a primeira matriz:\n");
        fillMatrix(&matrix1);

        //printf("\nPrimeira matriz preenchida:");
        showMatrix(matrix1);

        // SEGUNDA MATRIZ
        //printf("\nDigite o numero de linhas da segunda matriz: ");
        scanf("%d%*c", &rows);

        //printf("Digite o numero de colunas da segunda matriz: ");
        scanf("%d%*c", &coluns);

        initEmptyMatrix(&matrix2, rows, coluns);

        //printf("\nPreencha a segunda matriz:\n");
        fillMatrix(&matrix2);

        //printf("\nSegunda matriz preenchida:");
        showMatrix(matrix2);

        //SOMA
        printf("\nSoma das matrizes: ");
        sumMatrix(matrix1, matrix2, &matrix3);
        showMatrix(matrix3);

        // MULTIPLICAÇÃO
        printf("\nMultiplicacao das matrizes: ");
        multMatrix(matrix1, matrix2, &matrix3);
        showMatrix(matrix3);

        // DIAGONAL PRINCIPAL
        printf("\nDiagonal principal das matrizes:\n");
        showDiagonalPrincpal(matrix1);
        showDiagonalPrincpal(matrix2);

        // DIAGONAL SECUNDÁRIA
        printf("\nDiagonal secundária das matrizes:\n");
        showDiagonalSecundaria(matrix1);
        showDiagonalSecundaria(matrix2);
    }
}
