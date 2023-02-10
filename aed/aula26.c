#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
    struct node *father;
} NODE;

typedef NODE * ARV_BIN_ENC;

void maketree(ARV_BIN_ENC *, int);
void setleft(ARV_BIN_ENC, int);
void setright(ARV_BIN_ENC, int);
int info(ARV_BIN_ENC);
ARV_BIN_ENC left(ARV_BIN_ENC);
ARV_BIN_ENC right(ARV_BIN_ENC);
ARV_BIN_ENC father(ARV_BIN_ENC);
ARV_BIN_ENC brother(ARV_BIN_ENC);
int isleft(ARV_BIN_ENC);
int isright(ARV_BIN_ENC);

main()
{

}

void maketree(ARV_BIN_ENC *T, int x)
{
    *T = (NODE*) malloc(sizeof(NODE));
    if(!(*T))
    {
        puts("erro na alloc");
        return;
    }

    (*T)->info = x;
    (*T)->father = (*T)->left = (*T)->left = NULL;
}

void setleft(ARV_BIN_ENC T, int x)
{
    T->left = (NODE*)  malloc(sizeof(NODE));
    if(!T->left)
    {
        puts("erro na alloc");
        return;
    }

    T->left->info = x;
    T->left->father = T;
    T->left->left = T->left->right = NULL;
}

void setright(ARV_BIN_ENC T, int x)
{
    T->right = (NODE*)  malloc(sizeof(NODE));
    if(!T->right)
    {
        puts("erro na alloc");
        return;
    }

    T->right->info = x;
    T->right->father = T;
    T->right->left = T->right->right = NULL;
}

int info(ARV_BIN_ENC T)
{
    return T->info;
}

ARV_BIN_ENC left(ARV_BIN_ENC T)
{
    return T->left;
}

ARV_BIN_ENC right(ARV_BIN_ENC T)
{
    return T->right;
}

ARV_BIN_ENC father(ARV_BIN_ENC T)
{
    return T->father;
}

ARV_BIN_ENC brother(ARV_BIN_ENC T)
{
    if(T->father)
    {
        if(isleft(T))
            return T->father->right;
        return T->father->left;
    }   
    return NULL;
}

int isleft(ARV_BIN_ENC T)
{
    if(T->father)
        return T->father->left == T;
    return 0;
}

int isright(ARV_BIN_ENC T)
{
    if(T->father)
        return T->father->right == T;
    return 0; 
}