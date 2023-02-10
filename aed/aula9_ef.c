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
void ins(LIST_ENC *, int, int);
int cons(LIST_ENC, int);
void ret(LIST_ENC *, int);
void destruir(LIST_ENC);

main()
{
	LIST_ENC L;
	int ind, val, o;
	
	
	criar_lista(&L);
	
	printf("------------------\n 1 - inserir\n 2 - consultar\n 3 - retirar\n 0 - parar\n------------------\n");
	
	do
	{
		printf("\nDigite a operacao que deseja realizar:\n");
		scanf("%d", &o);
		
		switch(o)
		{
			case 1:
				printf("\nEntre com o valor que deseja inserir:\n");
				scanf("%d", &val);
				printf("Entre com a posicao deste valor:\n");
				scanf("%d", &ind);
				ins(&L, ind, val);
				break;
			case 2:
				printf("\nEntre com a posicao do valor que deseja consultar:\n");
				scanf("%d", &ind);
				printf("	> %d", cons(L, ind));
				break;
			case 3:
				printf("\nEntre com a posicao do valor que deseja retirar:\n");
				scanf("%d", &ind);
				ret(&L, ind);
				break;
			default:
				if(o)
					printf("entre um valor valido!\n");
		}
	}while(o);
	
	if(!vazia(L))
	{
		int i;
		
		for(i=1; i <= tam(L); i++)
		{
			printf("	item %d > %d\n", i, cons(L, i));
		}
	}
	
	
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

void ins(LIST_ENC *L, int pos, int val)
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
		return L->inf;
	}
	
	return cons(L->next, pos-1);
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

