#include <stdio.h>
#define MAX 100

typedef struct
{
	float inf;
	int next;
}NODO;

typedef struct
{
	int ind_pri_ele;
	int ind_nodo_livre;
	NODO elementos[MAX];
}LISTA_ENC_EST;

void criar_l(LISTA_ENC_EST*);
int vazia(LISTA_ENC_EST*);
int tam(LISTA_ENC_EST*);
void ins(LISTA_ENC_EST*, int, float);
float consulta(LISTA_ENC_EST*, int);
void ret(LISTA_ENC_EST*, int);

main()
{
	LISTA_ENC_EST L;
	criar_l(L);
}

void criar_l(LISTA_ENC_EST *L)
{
	int i;
	
	L->ind_pri_ele = -1;
	L->ind_nodo_livre = 0;
	
	for(i=0; i < MAX-1; i++)
		L->elementos[i].next = i+1;	
	L->elementos[i].next = -1;
}

int vazia(LISTA_ENC_EST *L)
{
	return (L->ind_pri_ele == -1);
}

int tam(LISTA_ENC_EST *L);
{
	int cont, i;
	
	if(vazia(L))
		return 0;
	
	for(i=L->ind_pri_ele; i != -1; i = L->elementos[i].next)
		cont++
	return cont;
}

void ins(LISTA_ENC_EST* L, int pos, float val)
{
	if(pos<1||pos>tam(L)+1)
	{
		printf("posicao invalida");
		exit(33);
	}
	
	if(L->ind_nodo_livre!=-1)
	{
		int aux;
		
		if(pos==1)
		{
			L->elementos[L->ind_nodo_livre].inf = val;
			aux = L->elementos[L->ind_nodo_livre].next;
			L->elementos[L->ind_nodo_livre].next = L->ind_pri_ele;
			L->ind_pri_ele = L->ind_nodo_livre;
			L->ind_nodo_livre = aux;
		}
		else
		{
			int ind;
			for(ind = L->ind_pri_ele; --pos-1; ind = L->elementos[ind].next);
			L->elementos[L->ind_nodo_livre].inf = val;
			aux = L->elementos[L->ind_nodo_livre].next;
			L->elementos[L->ind_nodo_livre].next = L->elementos[ind].next;
			L->elementos[ind].next = L->ind_nodo_livre;
			L->ind_nodo_livre = aux;
		}
	}
	else
	{
		printf("memoria cheia");
		exit(44);	
	}
}

float consulta(LISTA_ENC_EST* L, int pos)
{
	int ind;
	
	if(pos<1||pos>tam(L))
	{
		printf("posicao invalida");
		exit(33);
	}
	
	for(ind = L->ind_pri_ele; --pos; ind = L->elementos[ind].next);
	return L->elementos[ind].val;
}

void ret(LISTA_ENC_EST *L, int pos)
{
	int aux;
	
	if(pos<1||pos>tam(L))
	{
		printf("posicao invalida");
		exit(33);
	}
	
	if(pos==1)
	{
		aux = L->ind_pri_ele;
		L->ind_pri_ele = L->elementos[pos].next;
		L->elementos[aux].next = L->ind_nodo_livre;
		L->ind_nodo_livre = aux;
	}
	else
	{
		int ind;
		for(ind = L->ind_pri_ele; --pos-1; ind = L->elementos[ind].next);
		aux = L->elementos[ind].next;
		L->elementos[ind].next = L->elementos[aux].next;
		L->elementos[aux].next = L->ind_nodo_livre;
		L->ind_nodo_livre = aux;
	}
}




