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

typedef struct
{
    int N;
    int INICIO;
    int FIM;
    int val[MAX];
}FILA_SEQ;

void cria_fila(FILA_SEQ *);
int vazia_f(FILA_SEQ *);
int tam (FILA_SEQ *);
void ins(FILA_SEQ *, int);
int cons(FILA_SEQ *);
void ret(FILA_SEQ *);
int cons_ret(FILA_SEQ *);
void gera_fila(FILA_SEQ *, int, int);
void inverte_fila(FILA_SEQ *);

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

void cria_fila(FILA_SEQ *F)
{
   F->INICIO=0;
   F->FIM=-1;
   F->N=0; 
}

int vazia_f(FILA_SEQ *F)
{
    return F->N==0;
}

int tam(FILA_SEQ *F)
{
    return F->N;
}

void ins(FILA_SEQ *F, int v)
{
    if(F->N==MAX)
    {
        puts("lista cheia");
        return;
    }

    F->FIM = (F->FIM+1)%MAX;
    F->val[F->FIM]=v;
    F->N++;
}

int cons(FILA_SEQ *F)
{
    if(!F->N)
    {
        puts("lista vazia");
        return 404;
    }
    return F->val[F->INICIO];
}

void ret(FILA_SEQ *F)
{
    if(!F->N)
    {
        puts("lista vazia");
        return;
    }

    F->INICIO = (F->INICIO+1)%MAX;
    F->N--;
}

int cons_ret(FILA_SEQ *F)
{
    if(!F->N)
    {
        puts("lista vazia");
        return 404;
    }
    else
    {
        int v = F->val[F->INICIO];
        F->INICIO = (F->INICIO+1)%MAX;
        F->N--;
        return v;
    }
}

void gera_fila(FILA_SEQ *F, int m, int n)
{
    if(m>n)
    {
        puts("intervalo invalido");
        return;
    }
    else
    {
        if(m==n)
        {
            cria_fila(F);
            ins(F, m);
        }
        else
        {   
            gera_fila(F, m, n-1);
            ins(F, n);
        }
    }
}

void inverte_fila(FILA_SEQ *F)
{
    PILHA_SEQ P;

    cria_pilha(&P);

    while(F->N!=0)
        push(&P, cons_ret(F));

    while(P.TOPO!=-1)
        ins(F, top_pop(&P));
}