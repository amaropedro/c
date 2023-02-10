#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	int *ele;
}MTS;

void criar_M(MTS*);
void inicializar_M(MTS*);
void imprimir_M(MTS*);
int fm(int, int);

main()
{
	MTS M;
	
	criar_M(&M);
	inicializar_M(&M);
	imprimir_M(&M);
}

void criar_M(MTS *M)
{
	int tam;
	
	printf("Entre com a ordem da matriz: \n");
	scanf("%d", &M->ordem);
	
	tam = (M->ordem+1)*M->ordem/2;
	
	M->ele = (int*) malloc(tam*sizeof(int));
	if(!M->ele)
	{
		printf("erro na alloc!");
		exit(1);
	}
}

void inicializar_M(MTS *M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		for(j=0; j< M->ordem; j++)
		{
			if(i<=j)
			{
				printf("Entre com o elemento M[%d][%d]: \n", i+1, j+1);
				scanf("%d", M->ele+fm(i,j));
			}
		}
	}
	
}

void imprimir_M(MTS *M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("| ");
		
		for(j=0; j< M->ordem; j++)
		{
			if(i<=j)
				printf("%03d ", M->ele[fm(i,j)]);
			else
				printf("000 ");
		}
		printf("|\n");
	}
	
}

int fm(int i, int j)
{
	return i + (j+1)*(j)/2;
}

