#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	int *ele;
}MTD;

void criar_M(MTD *);
void inicializar_M(MTD *);
void imprimir_M(MTD *);
int consulta(MTD *, int, int );

main()
{
	MTD M;
	
	criar_M(&M);
	inicializar_M(&M);
	imprimir_M(&M);	
}

void criar_M(MTD* M)
{
	int tam;
	
	printf("Entre com a ordem da matirz: \n");
	scanf("%d", &M->ordem);
	
	tam = M->ordem + (M->ordem-1)*2;
	
	M->ele = (int*) malloc(tam*sizeof(int));
	if(!M->ele)
	{
		printf("erro na alloc.");
		exit(0);
	}
}

void inicializar_M(MTD *M)
{
	int i, j;
	
	for(i=0; i < M->ordem; i++)
	{
		for(j=0; j < M->ordem; j++)
		{
			if(i==j)
			{
				printf("entre com o elemento M[%d][%d]: \n", i+1, j+1);
				scanf("%d", M->ele+i);
			}
			else if((i+1)==j)
			{
				printf("entre com o elemento M[%d][%d]: \n", i+1, j+1);
				scanf("%d", M->ele+(M->ordem)+i);
			}
			else if((j+1)==i)
			{
				printf("entre com o elemento M[%d][%d]: \n", i+1, j+1);
				scanf("%d", M->ele+(M->ordem)+(M->ordem-1)+j);
			}
		}
	}
}

void imprimir_M(MTD *M)
{
	int i, j;
	
	for(i=0; i < M->ordem; i++)
	{
		printf("| ");
		for(j=0; j< M->ordem; j++)
		{
			if(consulta(M, i, j)!=-1)
			{
				printf("%04d ", M->ele[consulta(M, i, j)]);
			}
			else
				printf("0000 ");
		}
		printf("|\n");
	}
	
}

int consulta(MTD *M, int i, int j)
{
	if(i==j)
		return i;
	if((i+1)==j)
		return M->ordem+i;
	if((j+1)==i)
		return M->ordem+(M->ordem-1)+j;
	return -1;
}

