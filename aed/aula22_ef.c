#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo* next
}NODO;

typedef NODO * LISTA_ENC_NC;

void cria_lista (LISTA_ENC_NC *);
int vazia (LISTA_ENC_NC);
int tam (LISTA_ENC_NC);
void ins (LISTA_ENC_NC, int);
int cons (LISTA_ENC_NC);
void ret (LISTA_ENC_NC);
void destruir (LISTA_ENC_NC);

main()
{
}

void cria_lista (LISTA_ENC_NC *C)
{
    *C = (NODO*) malloc(sizeof(NODO));
    if(!*C)
    {
        printf("erro na alloc");
        exit(0);
    }

    (*C)->inf = -1;
    (*C)->next = NULL; 
}

int vazia (LISTA_ENC_NC C)
{
    return C->inf==-1;
}

int tam (LISTA_ENC_NC C)
{
    return C->inf;
}

void ins (LISTA_ENC_NC C, int val)
{
    LISTA_ENC_NC novo;

    novo = (NODO*) malloc(sizeof(NODO));
    if(!novo)
    {
        printf("erro na alloc");
        return;
    }

    novo->inf = val;

    novo->next = C->next;
    C->next = novo;
    C->inf++;
}

int cons (LISTA_ENC_NC C)
{
    if( vazia(C))
    {
        printf("pos invalida!");
        return 404;
    }

    return C->inf;
}

void ret (LISTA_ENC_NC C, int pos)
{
    LISTA_ENC_NC aux, aux2;

    if( vazia(C))
    {
        printf("pos invalida!");
        return;
    }

    aux = C->next;
    C->next = aux->next;
    
    free(aux);

    C->inf--;
}

void destruir (LISTA_ENC_NC C)
{
    while(C)
    {
        free(C);
        C = C->next; 
    }
}