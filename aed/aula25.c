#include <stdio.h>
#define NUMNODES 100

typedef struct
{
    int info;
    int left;
    int right;
    int father;
} NODE;

typedef struct
{
    int root;
    int freeNode;
    NODE nodes[NUMNODES];
}ARV_BIN_SEQ;

void maketree(ARV_BIN_SEQ *, int);
void setleft(ARV_BIN_SEQ *, int, int);
void setright(ARV_BIN_SEQ *, int, int);
int info(ARV_BIN_SEQ *, int);
int left(ARV_BIN_SEQ *, int);
int right(ARV_BIN_SEQ *, int);
int father(ARV_BIN_SEQ *, int);
int brother(ARV_BIN_SEQ *, int);
int isleft(ARV_BIN_SEQ *, int);
int isright(ARV_BIN_SEQ *, int);
int getNode(ARV_BIN_SEQ *);
void freeNode(ARV_BIN_SEQ *, int);

main()
{

}

void maketree(ARV_BIN_SEQ *T, int x)
{
    int i, ind;

    for(i=0; i<NUMNODES-1; i++)
        T->nodes[i].left = i+1;
    T->nodes[i].left = -1;
    T->freeNode = 0;
    
    ind = getNode(T);
    if( ind != -1)
    {
        T->nodes[ind].info = x;
        T->nodes[ind].left = -1;
        T->nodes[ind].right = -1;
        T->nodes[ind].father = -1;
        T->root = ind;
    }
    else
    {
        puts("impossivel contruir arvore");
        exit(0);
    }
}

int getNode(ARV_BIN_SEQ *T)
{
    if(T->freeNode != -1)
    {
        int i = T->freeNode;
        T->freeNode = T->nodes[i].left;
        return i;
    }
    else
        return -1;
}

void freeNode(ARV_BIN_SEQ *T, int node)
{
    T->nodes[node].left = T->freeNode;
    T->freeNode = node;
}

void setleft(ARV_BIN_SEQ *T, int node, int x)
{
    int i = getNode(T);

    if(i !=-1)
    {
        T->nodes[node].left = i;
        T->nodes[i].info = x;
        T->nodes[i].father = node;
        T->nodes[i].right = -1;
        T->nodes[i].left = -1;
    }
    else
    {
        puts("arvore cheira");
        return;
    }
}

void setright(ARV_BIN_SEQ *T, int node, int x)
{
    int i = getNode(T);

    if(i !=-1)
    {
        T->nodes[node].right = i;
        T->nodes[i].info = x;
        T->nodes[i].father = node;
        T->nodes[i].right = -1;
        T->nodes[i].left = -1;
    }
    else
    {
        puts("arvore cheira");
        return;
    }
}

int info(ARV_BIN_SEQ *T, int node)
{
    return T->nodes[node].info;
}

int left(ARV_BIN_SEQ *T, int node)
{
    return T->nodes[node].left;
}

int right(ARV_BIN_SEQ *T, int node)
{
    return T->nodes[node].right;
}

int father(ARV_BIN_SEQ *T, int node) 
{
    return T->nodes[node].father;
}

int brother(ARV_BIN_SEQ *T, int node)
{
    if(father(T, node)!= -1)
        if(isleft(T, node))
            return right(T, father(T, node));
        else
            return left(T, father(T, node));
    else
      return -1;  
}

int isleft(ARV_BIN_SEQ *T, int node)
{
    int i = T->nodes[node].father;

    if(i!=-1)
        return T->nodes[i].left == i;
        
    return 0;
}

int isright(ARV_BIN_SEQ *T, int node)
{
    int i = T->nodes[node].father;

    if(i!=-1)
        return T->nodes[i].right == i;

    return 0;
}