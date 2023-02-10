#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	int *elementos;
	
}matriz_dg;


void criar_m(int O, matriz_dg* M)
{
	M->ordem = O;
	
	M->elementos = (int*) calloc(O,sizeof(int));
	if(!M) 
	{
		printf("erro na alloc"); exit(0);
	}
	
	inicializar_m(M);
}

void inicializar_m(matriz_dg* M)
{
	int i, n;
	
	for(i=0; i < M->ordem; i++)
	{
		printf("digite o elemento M[%d][%d]: \n", i+1, i+1);
		scanf("%d", &n);
		M->elementos[i]=n;
	}
	
}
void imprimir(matriz_dg* M)
{
	int i, j;
	
	for(i=0; i < M->ordem; i++)
		{
			printf("|");
		for(j=0; j < M->ordem; j++)
		{
			printf(" %04d ", consulta(i, j, M));
		}
		printf("|\n");
		}
}

int consulta(int i, int j, matriz_dg* M)
{
	if(i==j)
	return M->elementos[i];
	else
	return 0;	
}



main()
{
	
	matriz_dg M;
	int ordem;
	
	printf("digite a ordem da matriz: \n");
	scanf("%d", &ordem);
	
	criar_m(ordem, &M);
	
	imprimir(&M);
	
}



