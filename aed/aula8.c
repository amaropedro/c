#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	int inf;
	struct nodo *next;
}NODO;

typedef NODO *LIST_ENC;

void criar_lista(LIST_ENC *);
int vazia(LIST_ENC);
int tam(LIST_ENC);
void ins(LISTA_ENC *, int, int);
int cons(LIST_ENC, int);
void ret(LIST_ENC *, int);
void destruir(LIST_ENC*);

main()
{
	LIST_ENC = L;
	criar_lista(&L);
	ins(&L, 1, 2);
	
	
}

void criar_lista(LIST_ENC *L)
{
	*L = NULL;
}

int vazia(LIST_ENC L)
{
	return (L==NULL);
}

int tam(LIST_ENC L)
{
	int cont;
	
	for(cont=0; L!= NULL; cont++)
		L = L->next;
	return cont;
}

/*void ins(LISTA_ENC *L, int pos, int val)
{
	NODO *aux;
	
	if(pos<1||pos>tam(*L)+1)
	{
		printf("pos invalida");
		exit(0);
	}
	
	aux = (NODO *) malloc(sizeof(NODO));
	if(!aux)
	{
		printf("erro na alloc");
		exit(0);
	}
	
	aux->inf = val;
	
	if(pos==1)
	{		
		aux->next = *L;
		*L = aux;
	}
	else
	{	
		NODO *ind;
		
		for( ind = *L ; --pos-1; ind = ind->next);
		
		aux->next = ind->next;
		ind->next = aux;
	}
}*/

void ins(LISTA_ENC *L, int pos, int val)
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

int cons(LIST_ENC L, int pos)
{
	if(pos<1||pos>tam(L))
	{
		printf("pos invalida");
		exit(0);
	}
	
	if(pos==1)
	{
		return L->inf
	}
	
	return cons(L->next), pos-1);
}

void ret(LIST_ENC *L, int pos)
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

void ret(LIST_ENC *L, int pos)
{
	NODO *aux;
	
	if(pos<1||pos>tam(*L))
	{
		printf("pos invalida");
		exit(0);
	}
	
	if(pos==1)
	{	
		aux = *L;
		
		*L = aux->next;
		
		free(aux);
	}
	else
	{
		NODO *f;
		
		for(aux = *L; --pos-1; aux = aux->next);
		
		f = aux->next;
		
		aux->next = f->next;
		
		free(f);
	}	
}

void destruir(LIST_ENC L)
{
	NODO *aux;
	
	while(L)
	{
		aux = L;
		L = L->next;
		free(aux);
	}
}

