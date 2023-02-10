#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	int *ele;
}m_dig;

void criar_m (m_dig *);
void inicializar_m (m_dig *);
void imprimir_m (m_dig *);
int eletemento (int , int);

main()
{
	m_dig M;
	criar_m(&M);
	inicializar_m(&M);
	imprimir_m(&M);
}

void criar_m (m_dig *M)
{
	printf("digite a ordem da matriz: \n");
	scanf("%d", &M->ordem);
	
	M->ele = (int*) calloc(M->ordem,sizeof(int));
	if(!M->ele) exit(1);
}

void inicializar_m (m_dig *M)
{
	int i;
	for(i=0; i< M->ordem; i++)
	{
		printf("entre com o elemento M[%d][%d]: \n", i+1, i+1);
		scanf("%d", &M->ele[i]);
	}
}

void imprimir_m (m_dig *M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("| ");
		for(j=0; j< M->ordem; j++)
		{
			if(elemento(i,j))
			printf("%04d ", M->ele[i]);
			else printf("0000 ");
		}
		printf("|\n");
	}
		
}

int elemento (int i, int j)
{
	if (i==j) return 1;
	else return 0;
}
