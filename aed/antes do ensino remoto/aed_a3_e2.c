#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	int *ele;
}m_trig_sup;

void criar_m (m_trig_sup *);
int consulta_m (int, int);
void inicializar_m (m_trig_sup *);
void imprimir_m (m_trig_sup *);

main()
{
	m_trig_sup M;
	int i;
	
	printf("digite a ordem da matriz: \n");
	scanf("%d", &M.ordem);
	criar_m(&M);
	inicializar_m(&M);
	imprimir_m(&M);
	
	for(i=0; i < ((M.ordem+1)*M.ordem/2)+2; i++)
	printf("M[%d] = %d\n", i, M.ele[i]);
}

void criar_m (m_trig_sup *M)
{
	int tam;
	
	tam = (M->ordem+1)*M->ordem/2; //printf("tam = %d\n", tam);
	
	M->ele = (int*) calloc(tam,sizeof(int));
	if(!M->ele) exit(1);
}

int consulta_m (int i, int j)
{
	return (i + ((j+1)*j/2));
}

void inicializar_m (m_trig_sup *M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		for(j=0; j< M->ordem; j++)
		{
			if(j>=i)
			{
				printf("entre com o elemento[%d][%d]: \n", i+1, j+1);
				scanf("%d", &M->ele[consulta_m(i, j)]);
			}
		}
	}
}

void imprimir_m (m_trig_sup *M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("|");
		for(j=0; j< M->ordem; j++)
		{
			if(j>=i)
			printf(" %04d ", M->ele[consulta_m(i, j)]);
			else printf(" 0000 ");
		}
		printf("|\n");
	}
}


