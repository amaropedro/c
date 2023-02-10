#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	int *elementos;
}MD;

void criar_M(MD*);
void inicializar_M(MD*);
int ele(int, int);
void imprimir_M(MD*);

main()
{
	MD M;
	
	criar_M(&M);
	inicializar_M(&M);
	imprimir_M(&M);
}

void criar_M(MD *M)
{
	printf("Digite a ordem da matriz: \n");
	scanf("%d", &M->ordem);
	
	M->elementos = (int*) malloc(M->ordem*sizeof(int));
	if (!M->elementos)
	{
		printf("erro na alloc");
		exit(1);
	}
}

void inicializar_M(MD* M)
{
	int i;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("Entre com o elemento M[%d][%d]:\n", i+1, i+1);
		scanf("%d", M->elementos+i);
	}
		
}

void imprimir_M(MD* M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("| ");
		
		for(j=0; j< M->ordem; j++)
		{
			if(ele(i,j))
				printf("%03d ", M->elementos[i]);
			else
				printf("000 ");
		}
		printf("|\n");
	}
	
}

int ele(int i, int j)
{
	if(i==j)
		return 1;
	else
		return 0;
}

