#include <stdio.h>
#define MAX 10

typedef struct
{
    int TOPO;
    int val[MAX];
}PILHA_SEQ;

void cria_pilha (PILHA_SEQ *);
int vazia (PILHA_SEQ *);
void push (PILHA_SEQ *, int);
int top (PILHA_SEQ *);
void pop (PILHA_SEQ *);
int top_pop (PILHA_SEQ*);

main()
{

}

void cria_pilha (PILHA_SEQ *P)
{
    P->TOPO = -1;
}

int vazia (PILHA_SEQ *P)
{
    return P->TOPO==-1;
}

void push (PILHA_SEQ *P, int v)
{
    if(P->TOPO==MAX-1)
    {
        puts("pilha cheia");
        return;
    }

    P->val[++(P->TOPO)]=v;
}

int top (PILHA_SEQ *P)
{
    if(P->TOPO==-1)
    {
        puts("pilha vazia");
        return 404;
    }

    return P->val[P->TOPO];
}

void pop (PILHA_SEQ *P)
{
    if(P->TOPO==-1)
    {
        puts("pilha vazia");
        return;
    }

    P->TOPO--;
}

int top_pop (PILHA_SEQ *P)
{
    if(P->TOPO==-1)
    {
        puts("pilha vazia");
        return 404;
    }

    return P->val[P->TOPO--];
}