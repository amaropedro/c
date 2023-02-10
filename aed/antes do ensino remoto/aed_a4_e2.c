#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ordem;
	float *ele;
}m_sim;

void criar_m (m_sim *);
void inicializar_m (m_sim *);
void imprimir_m (m_sim *);
int consulta (int, int);

main()
{
	m_sim M;
	criar_m(&M);
	inicializar_m(&M);
	imprimir_m(&M);
}

void criar_m(m_sim *M)
{
	int tam;
	
	printf("digite a ordem da matriz: \n");
	scanf("%d", &M->ordem);
	
	tam = (M->ordem+1)*M->ordem/2;
	
	M->ele = (float *) calloc(tam,sizeof(float));
	if(!M->ele) exit(1);
}

void inicializar_m (m_sim *M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		for(j=0; j< M->ordem; j++)
		{
			if(j>=i)
			{
				setbuf(stdin,NULL);
				printf("entre com o elemento M[%d][%d]: \n", i+1, j+1);
				scanf("%f", &M->ele[consulta(i, j)]);
			}
		}
	}
	
}

int consulta (int i, int j)
{
	return (i + ((j+1)*j/2));
}

void imprimir_m (m_sim *M)
{
	int i, j;
	
	for(i=0; i< M->ordem; i++)
	{
		printf("| ");
		for(j=0; j< M->ordem; j++)
		{
			if(j>=i)
			printf("%.0f ", M->ele[consulta(i, j)]);
			else
			printf("%.0f ", -1*M->ele[consulta(j, i)]);
		}
		printf("|\n");
	}
}
