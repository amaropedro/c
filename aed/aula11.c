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
void ins (LISTA_ENC_NC, int, int);
int cons (LISTA_ENC_NC, int);
void ret (LISTA_ENC_NC, int);
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

    (*C)->inf = 0;
    (*C)->next = NULL; 
}

int vazia (LISTA_ENC_NC C)
{
    return !C->inf;
}

int tam (LISTA_ENC_NC C)
{
    return C->inf;
}

void ins (LISTA_ENC_NC C, int val, int pos)
{
    LISTA_ENC_NC novo, aux;
    if(pos < 1 || pos > C->inf+1)
    {
        printf("posicao invalida!");
        return;
    }

    novo = (NODO*) malloc(sizeof(NODO));
    if(!novo)
    {
        printf("erro na alloc");
        return;
    }

    novo->inf = val;

    for(aux = C; pos>1; aux = aux->next, pos--);

    novo->next = aux->next;
    aux->next = novo;
    C->inf++;
}

int cons (LISTA_ENC_NC C, int pos)
{
    if(pos<1 || pos>C->inf)
    {
        printf("pos invalida!");
        return 404;
    }

    for(C = C->next; pos>1; C = C->next, pos--);

    return C->inf;
}

void ret (LISTA_ENC_NC C, int pos)
{
    LISTA_ENC_NC aux, aux2;

    if(pos<1 || pos>C->inf)
    {
        printf("pos invalida!");
        return;
    }

    for(aux = C; pos>1; aux = aux->next, pos--);
    aux2 = aux->next;
    aux->next = aux2->next;
    free(aux2);

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