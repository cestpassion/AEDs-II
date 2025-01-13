#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int element;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

typedef struct AVL{
    Node *root;
} AVL;

Node *newNode(int element){
    Node *new = (Node*)malloc(sizeof(Node));
    
    if(new){
        new->element = element;
        new->right = new->left = NULL;
        new->height = 0;
    } else {
        printf("Erro ao alocar o novo no");
    }
    
    return new;
}

int biggestHeight(int leftHeight, int rightHeight){
    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

int getHeight(Node *node){
    if(node == NULL)
        return -1;
    else   
        return node->height;
}

int balancingFactor(Node *node){
    if(node)
        return (getHeight(node->left) - getHeight(node->right));
    else
        return 0;
}

Node *rotateLeft(Node *node){
    Node *nodeR = node->right;
    Node *nodeRL = nodeR->left;

    nodeR->left = node;
    node->right = nodeRL;

    node->height = biggestHeight(getHeight(node->left), getHeight(node->right)) + 1;
    nodeR->height = biggestHeight(getHeight(nodeR->left), getHeight(nodeR->right)) + 1;

    return nodeR;
}

Node *rotateRight(Node *node){
    Node *nodeL = node->left;
    Node *nodeLR = nodeL->right;

    nodeL->right = node;
    node->left = nodeLR;

    node->height = biggestHeight(getHeight(node->left), getHeight(node->right)) + 1;
    nodeL->height = biggestHeight(getHeight(nodeL->left), getHeight(nodeL->right)) + 1;

    return nodeL;
}

Node *rotateRightLeft(Node *node){
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

Node *rotateLeftRight(Node *node){
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node *insert(Node *node, int element){

}
