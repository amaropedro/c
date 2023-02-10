#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo *next;
}NODE;

typedef NODE *PILHA_ENC;

void create (PILHA_ENC *);
int empty (PILHA_ENC);
void push (PILHA_ENC *, int);
int top (PILHA_ENC);
void pop (PILHA_ENC *);
int top_pop (PILHA_ENC *);
void destroy (PILHA_ENC);

main()
{

}

void create (PILHA_ENC *P)
{
   *P = NULL;
}

int empty (PILHA_ENC P)
{
    return P==NULL;
}

void push (PILHA_ENC *pP, int v)
{
    PILHA_ENC new;

    new = (NODE*) malloc(sizeof(NODE));
    if(!new)
    {
        puts("erro na alloc");
        return;
    }

    new->inf = v;
    new->next = *pP;

    *pP = new;
}

int top (PILHA_ENC P)
{
    if(!P)
    {
        puts("pilha vazia");
        return 404;
    }

    return P->inf;
}

void pop (PILHA_ENC *pP)
{
    if(!(*pP))
    {
        puts("pilha vazia");
        return;
    }
    else
    {
        PILHA_ENC aux=*pP;
        *pP = (*pP)->next;
        free(aux);
    }
}

int top_pop (PILHA_ENC *pP)
{
    if(!(*pP))
    {
        puts("pilha vazia");
        return 404;
    }
    else
    {
        PILHA_ENC aux=*pP;
        int v=(*pP)->inf;

        *pP = (*pP)->next;
        free(aux);

        return v;
    }
}

/*void destroy (PILHA_ENC P)
{
    while(P)
        destroy(P->next);
    free(P);
}*/

void destroy (PILHA_ENC P)
{
    PILHA_ENC aux;
    while(P)
    {
        aux = P;
        P = P->next;
        free(aux);
    }
}