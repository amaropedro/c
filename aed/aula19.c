#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo * next;
}NODO;

typedef struct
{
    NODO *INICIO;
    NODO *FIM;
}DESCRITOR;

typedef DESCRITOR *FILA_ENC;

void cria_fila(FILA_ENC *);
int vazia(FILA_ENC);
void ins(FILA_ENC, int);
int cons(FILA_ENC);
void ret(FILA_ENC);
int cons_ret(FILA_ENC);
void destruir(FILA_ENC);

main()
{

}

void cria_fila(FILA_ENC *pF)
{
    *pF = (DESCRITOR*) malloc(sizeof(DESCRITOR));
    if(!*pF)
    {
        puts("erro na alloc");
        return;
    }

    (*pF)->INICIO = NULL;
    (*pF)->FIM = NULL;
}

int vazia(FILA_ENC F)
{
    return F->INICIO==NULL;
}

void ins(FILA_ENC F, int v)
{
    NODO *novo;

    novo = (NODO*) malloc(sizeof(NODO));

    if(!novo)
    {
        puts("erro na alloc");
        return;
    }

    novo->inf = v;
    novo->next = NULL;

    if(!F->INICIO)
        F->INICIO = novo;
    else
        F->FIM->next = novo;
    
    F->FIM = novo;
}

int cons(FILA_ENC F)
{
    if(!F->INICIO)
    {
        puts("fila vazia");
        return 404;
    }

    return F->INICIO->inf;
}

void ret(FILA_ENC F)
{
    if(!F->INICIO)
    {
        puts("fila vazia");
        return;
    }
    else
    {
        NODO *aux = F->INICIO;

        F->INICIO = F->INICIO->next;

        free(aux);

        if(!F->INICIO)
            F->FIM = NULL;
    }
}

int cons_ret(FILA_ENC F)
{
    if(!F->INICIO)
    {
        puts("fila vazia");
        return;
    }
    else
    {
        NODO *aux = F->INICIO;
        int i = F->INICIO->inf;

        F->INICIO = F->INICIO->next;

        free(aux);

        if(!F->INICIO)
            F->FIM = NULL;

        return i;
    }
}

void destruir(FILA_ENC F)
{
    NODO *aux;

    while(F->INICIO)
    {
        aux = F->INICIO;
        F->INICIO = F->INICIO->next;
        free(aux);
    }
    F->FIM = NULL;
    free(F);
}