#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int nl;
	int nc;
	int **coordenadas;
	int *ele;
	int nele;
}me;

void criar_m(int, me*);
void inicializar_m(int, me*);
//int consulta();
//void imprimir(me*);

main()
{
	me M;
	int tam_aprox;
	
	printf("digite o nl da matriz: \n");
	scanf("%d", &M.nl);
	printf("digite o nc da matriz: \n");
	scanf("%d", &M.nc);
	tam_aprox = (3)*(M.nl*M.nc)/10;
	criar_m(tam_aprox, &M);
	inicializar_m(tam_aprox, &M);
//	imprimir(&M);
	
}

criar_m(int ta, me* M)
{
	//printf("enrtou em criar\n");
	M->coordenadas = (int**) calloc(ta*2, sizeof(int));
	if(!M)
	{
		printf("erro na alloc!");
		exit(0);
	}
	
	M->ele = (int*) calloc(ta, sizeof(int));
	if(!M)
	{
		printf("erro na alloc!");
		exit(0);
	}
}

inicializar_m(int ta, me* M)
{
	int cont, n;
	//printf("enrtou em inicializar\n");	
	for(cont=0; cont < ta; cont++)
	{
		printf("digite o numero da linha do ele.: \n");
		scanf("%d", &n);
		M->coordenadas[0][cont] = n;
		printf("digite o numero da coluna do ele.: \n");
		scanf("%d", &n);
		M->coordenadas[1][cont] = n;
		printf("digite o elemento: \n");
		scanf("%d", M->ele);
	}
	for(cont=0; cont < ta; cont++)
	printf("%d ", M->coordenadas[0][cont]);
	printf("\n");
	for(cont=0; cont < ta; cont++)
	printf("%d ", M->coordenadas[cont][1]);
	printf("\n");
	for(cont=0; cont < ta; cont++)
	printf("%d ", M->ele[cont]);
	
}

//imprimir()



