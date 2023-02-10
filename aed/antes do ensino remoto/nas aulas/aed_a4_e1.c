#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	char *ele;	
}ms;

void criar_m(ms* M)
{	
	int o, e;
	o = M->ordem;
	e=(1+o)*o/2;
	M->ele = (char *) calloc(e,sizeof(char));
	if(!M->ele)
	{
		printf("erro na alloc");
		exit(0);
	}
}

int elementos(int i, int j) 
{
	return (i + (j+1)*j/2);
}

void inicializar(ms* M)
{
	int i, j;
	
	for(i=0; i < M->ordem; i++)
	{
		for(j=0; j < M->ordem; j++)
		{
			if(j>=i)
			{
				setbuf(stdin,NULL);
				printf("digite o elemento M[%d][%d]: \n", i+1, j+1);
				scanf("%c", &M->ele[elementos(i, j)]); 
			}
		}
	}
	
}

int consulta(int i, int j)
{
	if(j>=i) 
	return 1;
	else return 0;
}

void imprimir(ms* M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("|");
		for(j=0; j<M->ordem; j++)
		{
			if(consulta(i,j))
			printf(" %c ", M->ele[elementos(i, j)]);
			else printf(" %c ", M->ele[elementos(j, i)]);
		}
		printf("|\n");
	}
}


main()
{
	ms M;
	
	printf("digite a ordem da matriz: \n");
	scanf("%d", &M.ordem);
	criar_m(&M);
	inicializar(&M);	
	imprimir(&M);
}



