#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	float *elementos;
}MAS;

void criar_M(MAS*, int );
void inicializar_M(MAS*);
void imprimir_M(MAS*);
float retornar_ele(MAS*, int, int);
int consulta();

main()
{
	MAS M;
	int o;
	
	printf("digite a ordem da matiz:\n");
	scanf("%d", &o);
	
	criar_M(&M, o);
	inicializar_M(&M);
	imprimir_M(&M);
	 
}

void criar_M(MAS *M, int o)
{
	int tam;
	
	M->ordem = o;
	
	tam = (o+1)*o/2;
	
	M->elementos = (float*) malloc(sizeof(float)*tam);
	if(!M->elementos)
	{
		printf("erro na alocacao de memoria\n");
		exit(0);
	}
}

void inicializar_M(MAS* M)
{
	int i, j;
	
	printf("entre com os elementos da matriz: \n");
	for(i=0; i< M->ordem; i++)
	{
		for(j=0; j< M->ordem; j++)
		{
			if(i<=j)
			{
				printf("M[%d][%d]=\n", i+1, j+1);
				scanf("%f", M->elementos+consulta(i, j));
			}
		}
	}
	
}

int consulta(int i, int j)
{
	return i+((j+1)*j/2);
}

void imprimir_M(MAS* M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("| ");
		for(j=0; j< M->ordem; j++)
		{
			printf("%07.2f ", retornar_ele(M, i, j));		
		}
		printf("|\n");
	}
}

float retornar_ele(MAS* M, int i, int j)
{
	if(i<=j)
		return (M->elementos[consulta(i,j)]);
	else
		return (-(M->elementos[consulta(j,i)]));
}

