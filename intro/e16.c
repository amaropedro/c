#include <stdio.h>
#include <stdlib.h>

main()
{
	int C, V, N, cont=1, aux=0;
	do
	{
    	do
		{
		printf("\ndigite o numero de diferentes componentes de varetas: ");
		scanf("%d", &N);
		if(aux==0&&N==0)	
		printf("nenhum valor nao nulo foi apresentado");
		}
		while(aux==0&&N==0); 
			if(N==0) break;
			 aux=0;
			 cont=1;
			  do
			  {
			  	printf("\ndigite o %dº comprimeimento e numero de varetas: ", cont);
			  	scanf("%d %d", &C, &V);
			  	aux=aux+V/2;
			  	cont++;
			  	}while(cont<=N);
			  	aux=aux/2;
			  	printf("\nnumero de retangulos formados: %d", aux);			
	}
	while(N);
	
}
