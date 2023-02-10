#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define b 10
#define d 4

typedef struct nodo
{
    int inf;
    struct nodo * next;
}NODO;

typedef struct
{
    NODO *INICIO;
    NODO *FIM;
    int N;
}DESCRITOR;

typedef DESCRITOR *FILA_ENC;

void cria_fila(FILA_ENC *);
int vazia(FILA_ENC);
void ins(FILA_ENC, int);
int cons(FILA_ENC);
void ret(FILA_ENC);
int cons_ret(FILA_ENC);
void destruir(FILA_ENC);
int tam(FILA_ENC);

typedef NODO *LIST_ENC;

void criar_lista(LIST_ENC *);
int vazia_l(LIST_ENC);
int tam_l(LIST_ENC);
void ins_l(LIST_ENC *, int, int);
int cons_l(LIST_ENC, int);
void ret_l(LIST_ENC *, int);
void destruir_l(LIST_ENC);
void ord_por_dist(LIST_ENC);

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
    (*pF)->N = 0;
}

int vazia(FILA_ENC F)
{
    return !F->N;
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
    F->N++;
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

        F->N--;
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
        
        F->N--;
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
    F->N = 0;
    free(F);
}

int tam(FILA_ENC F)
{
    return F->N;
}

void ord_por_dist(LIST_ENC *pL)
{
    int i, j;
    FILA_ENC vf[b];

    for(i=0; i<b; i++)
        cria_fila(&vf[i]);

    for(i=0; i<d; i++)
    {
        while(!vazia_l(*pL))
        {
            int v=cons_l(*pL, 1), p;

            p = (v / (int)(pow(b, i)) )%b;

            ins(vf[p], v);
            ret_l(*pL, 1);
        }

        for(j=0; j<b; j++)
            while(!vazia(vf[j]))
                ins_l(*pL, cons_ret(vf[j]), tam_l(*pL)+1);
    }

}

void criar_lista(LIST_ENC *L)
{
	*L = NULL;
}

int vazia_l(LIST_ENC L)
{
	return (L==NULL);
}

int tam_l(LIST_ENC L)
{
	int cont;
	
	for(cont=0; L!= NULL; cont++)
		L = L->next;
	return cont;
}

void ins_l(LIST_ENC *L, int pos, int val)
{
	
	NODO *novo;
	
	if(pos<1||pos>tam(*L)+1)
	{
		printf("pos invalida");
		exit(0);
	}
	
	if(pos==1)
	{
		novo = (NODO *) malloc(sizeof(NODO));
		if(!novo)
		{
			printf("erro na alloc");
			exit(0);
		}
		
		novo->inf = val;
		novo->next = *L;
		*L = novo;
	}
	else
	{
		ins( &((*L)->next), pos-1, val);
	}
}

int cons_l(LIST_ENC L, int pos)
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

void ret_l(LIST_ENC *L, int pos)
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

void destruir_l(LIST_ENC L)
{
	NODO *aux;
	
	while(L)
	{
		aux = L;
		L = L->next;
		free(aux);
	}
}