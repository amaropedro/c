#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int nl;
	int nc;
	int* elementos;
}matriz;

void criar_matriz(int, int, matriz*);
void inicializar(matriz*);
void imprimir(matriz*);
void soma(matriz*, matriz*, matriz*);
void subt(matriz*, matriz*, matriz*);
void mult(matriz*, matriz*, matriz*);

main()
{
	matriz A, B, C;
	int nl, nc;
	char o;
	
	printf("entre com o numero de linhas e colunas da matriz 1: \n"); scanf("%d %d", &nl, &nc);
	criar_matriz(nl, nc, &A);
	inicializar(&A);
	printf("entre com o numero de linhas e colunas da matriz 2: \n"); scanf("%d %d", &nl, &nc);
	criar_matriz(nl, nc, &B);
	inicializar(&B);
	setbuf(stdin,NULL);
	printf("digite a operacao desejada ('+', '-' ou '*'): \n"); scanf("%c", &o);
	
	switch(o)
	{
		case '+': 
			soma(&A, &B, &C);
			imprimir(&C);
			break;
		case '-':
			subt(&A, &B, &C);
			imprimir(&C);
			break;
		case '*':
			mult(&A, &B, &C);
			imprimir(&C);
			break;
	}
			
}

void criar_matriz(int nl, int nc, matriz* M)
{
	M->nl = nl;
	M->nc = nc;
	M->elementos = (int *) calloc(nl*nc, sizeof(int));
	if(!M->elementos) 
	{
		printf("erro na alocacao\n");
		exit (0);
	}
}

void imprimir(matriz* C)
{
	int i, j;
	
	for(i=0; i<C->nl; i++)
	{ 
		printf("|");
		for(j=0; j<C->nc; j++)
		{	
			printf(" %5d ", *(C->elementos+(i*C->nc+j)) );
		}	
		printf("    |\n");
	}
}

void inicializar(matriz* M)
{
	int i, j, *posicao;
	posicao=M->elementos;
	
	for(i=0; i<M->nl; i++)
	{
		for(j=0; j<M->nc; j++)
		{
			printf("digite o elemento M[%d][%d]: \n", i+1, j+1);
			
			scanf("%d", posicao++);
		}	
	} 
}

void soma(matriz* A, matriz* B, matriz* C)
{ 
	int i, j;
	
	if(A->nc==B->nc&&A->nl==B->nl)
	{
		criar_matriz(A->nl, A->nc, C);
		for(i=0;i<C->nl; i++)
			for(j=0; j<C->nc; j++)
			{
				*(C->elementos+(i*C->nc+j)) = *(A->elementos+(i*C->nc+j)) + *(B->elementos+(i*C->nc+j));
			}
	}
	else
	{
		printf("a soma nao eh possivel\n"); exit(0);
	}
}

void subt(matriz* A, matriz* B, matriz* C)
{ 
	int i, j;
	
	if(A->nc==B->nc&&A->nl==B->nl)
	{
		criar_matriz(A->nl, A->nc, C);
		for(i=0;i<C->nl; i++)
			for(j=0; j<C->nc; j++)
			*(C->elementos+(i*C->nc+j)) = *(A->elementos+(i*C->nc+j)) - *(B->elementos+(i*C->nc+j));
	}
	else
	{
		printf("a subtracao nao eh possivel\n"); exit(0);
	}
}

void mult(matriz* A, matriz* B, matriz* C)
{
	int i, j, cont;
	if(A->nc==B->nl)
	{
		criar_matriz(A->nl, B->nc, C);
		for(i=0; i<C->nl; i++)
			for(j=0; j<C->nc; j++)
				for(cont=0; cont<A->nc; cont++)
				{
					*(C->elementos+(i*C->nc+j)) += (*(A->elementos+(i*A->nc+cont)))*(*(B->elementos+(cont*B->nc+j)));
				}
	}
	else 
	{
		printf("a multiplicacao nao eh possivel\n"); exit(0);
	}
	
}




