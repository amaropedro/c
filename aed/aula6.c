#include <stdio.h>
#define MAX 11

typedef struct
{
	int n;
	int Val[MAX];
}LISTA;

void criar_lista(LISTA*);
int vazia(LISTA*);
int tam(LISTA*);
void inserir(LISTA*, int, int);
int consultar(LISTA*, int);
void retirar(LISTA*, int);
int pertence(LISTA*, int);
int ordenada(LISTA*);
void gera_lista(LISTA*, int, int);

main()
{
	LISTA L;
	int o, val, ind;
	
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
				inserir(&L, val, ind);
				break;
			case 2:
				printf("\nEntre com a posicao do valor que deseja consultar:\n");
				scanf("%d", &ind);
				consultar(&L, ind);
				break;
			case 3:
				printf("\nEntre com a posicao do valor que deseja retirar:\n");
				scanf("%d", &ind);
				retirar(&L, ind);
				break;
			default:
				if(o)
					printf("entre um valor valido!\n");
		}
	}while(o);
	
}

void criar_lista(LISTA *L)
{
	L->n=0;
}

int vazia(LISTA *L)
{
	return (!L->n);
}

int tam(LISTA *L)
{
	return L->n;
	
}

void inserir(LISTA *L, int val, int ind)
{
	if(tam(L)==MAX)
	{
		printf("\n > Lista ja esta na capacidade maxima, favor retire um valor\n");
	}
	else if(ind<1||ind>L->n+1)
	{
		printf("\n > %d eh invalido. Favor entre um indice valido\n", ind);
	}
	else
	{
			if(!vazia(L))
		{
			int i;
	
			for(i=tam(L); i >= ind-1; i--)
			{
				L->Val[i+1] = L->Val[i];
			}
		}
	
		L->Val[ind-1] = val; 
		L->n++;	
	}
}

int consultar(LISTA *L, int ind)
{
	if(ind>tam(L))
		printf("\n > Nenhum valor atribuido a esta posicao\n");
	else
		printf("\n > Lsita[%d] = %d\n", ind, L->Val[ind-1]);
}

void retirar(LISTA *L, int ind)
{
	if(!vazia(L))
	{
		int i;
		
		L->n--;
		
		for(i=ind-1; i < tam(L); i++)
		{
			L->Val[i] = L->Val[i+1];
		}
	}
	else
	{
		printf("\n > A lista ja esta vazia\n");
	}
}

int pertence (LISTA* L, int val)
{
	int i;
	
	for(i=0; i<tam(L); i++)
		if(L->Val[i]==val)
			return 1;
	return 0;
}

int ordenada(LISTA *L)
{
	int i;
	
	for(i=0; i<tam(L)-1; i++)
		if(L->Val[i]>L->Val[i+1])
			return 0;
	return 1;
}

void gera_lista(LISTA* L, int m, int n)
{	
	if(n-m+1>MAX||m>n)
	{
		printf("intervalo invalido");
		exit(0);
	}
	
	if(m==n)
	{
		criar_lista(L);
		inserir(L, m, 1);
	}
	else
	{
		gera_lista(L, m+1, n);
		inserir(L, m, 1);
	}
}

