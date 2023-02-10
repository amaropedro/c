#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo *next;
    
}NODO;

typedef NODO *LIST_ENC_ORD;

void cria_lista (LIST_ENC_ORD*);
int vazia (LIST_ENC_ORD);
int tam (LIST_ENC_ORD);
void ins (LIST_ENC_ORD *, int);
int cons (LIST_ENC_ORD, int);
void ret (LIST_ENC_ORD *, int);
int ret_com_base_no_valor (LIST_ENC_ORD*, int);
void destruir (LIST_ENC_ORD);

main()
{

}

void cria_lista (LIST_ENC_ORD *L)
{
    *L = NULL;
}

int vazia (LIST_ENC_ORD L)
{
    return L == NULL;
}

int tam (LIST_ENC_ORD L)
{
    int i;
    for(i=0; L!=NULL; i++)
        L = L->next;
    return i;
}

void ins (LIST_ENC_ORD *L, int val)
{
    LIST_ENC_ORD novo, aux = *L;

    novo = (NODO*) malloc(sizeof(NODO));
    if(!novo)
    {
        printf("erro na alloc");
        return;
    }

    novo->inf = val;

    if(*L == NULL || val < (*L)->inf)
    {
        novo->next = *L;
        *L = novo;
    }
    else
    {
        while(aux->next != NULL)
        {
            if(val <= (aux->next)->inf) 
                break;

            aux = aux->next;
        }

        novo->next = aux->next;
        aux->next = novo;
    }
}

int cons(LIST_ENC_ORD L, int pos)
{
	if(pos<1||pos>tam(L))
	{
		printf("pos invalida");
		exit(0);
	}
	
	if(pos==1)
	{
		return L->inf;
	}
	
	return cons(L->next, pos-1);
}

void ret(LIST_ENC_ORD *L, int pos)
{
	if(pos<1||pos>tam(*L))
	{
		printf("pos invalida");
		exit(0);
	}
	
	if(pos==1)
	{
		NODO *aux;
		
		aux = *L;
		
		*L = aux->next;
		
		free(aux);
	}
	else
		ret( &((*L)->next), pos-1);
} 

void destruir(LIST_ENC_ORD L)
{
	NODO *aux;
	
	while(L)
	{
		aux = L;
		L = L->next;
		free(aux);
	}
}

/* 
int ret_com_base_no_valor (LIST_ENC_ORD *L, int val)
{
    if(*L == NULL)
        return 0;

    if((*L)->inf == val)
    {
        LIST_ENC_ORD aux = *L;
        *L = aux->next;
        free(aux);
        return 1;
    }

    while((*L)->next != NULL)
    {
        LIST_ENC_ORD aux = (*L)->next;

        if( aux->inf == val)
        {
            *L = aux->next;
            free(aux);
            return 1;
        }

        *L = (*L)->next;
    }

    return 0;
} 
*/

int ret_com_base_no_valor (LIST_ENC_ORD *L, int val)
{
    LIST_ENC_ORD aux = *L;
    int k, b=0;

    for(k=1; aux && aux->inf <= val; aux = aux->next, k++)
        if (aux->inf == val)
        {
            ret(L, k);
            k--;
            b=1;
        }
    return b;
}