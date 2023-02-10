#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	int *elemento;
}matriz_t;


int elementos(int i, int j) 
{
	return (i + ((j+1)*j/2));
}

void criar_m(matriz_t *M)
{
	int o, e;
	o = M->ordem;
	e=(1+o)*o/2;
	M->elemento = (int *) malloc( e*sizeof(int) );
	if(!M->elemento) 
	{
		printf("erro na alocacao!");
		exit(0);
	}
}

void inicializar (matriz_t* M)
{
	int i, j, n;
	
	for(i=0; i < M->ordem; i++)
	{
		for(j=0; j < M->ordem; j++)
		{
			if(j>=i)
			{
				printf("digite o elemento M[%d][%d]: \n", i+1, j+1);
				scanf("%d", &M->elemento[elementos(i, j)]); 
			}
		}
	}
	
}

void imprimir (matriz_t *M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("|");
		for(j=0; j<M->ordem; j++)
		{
			if(j>=i)
			printf(" %04d ", M->elemento[elementos(i, j)]);
			else printf(" 0000 ");
		}
		printf("|\n");
	}
}

main()
{
	matriz_t M;

	printf("(mt) digire a ordem da matriz: \n");
	scanf("%d", &M.ordem);
	criar_m(&M);
	inicializar(&M);
	imprimir(&M);
}


