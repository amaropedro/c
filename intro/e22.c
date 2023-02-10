#include <stdio.h>
#include <stdlib.h>

main()
{	
	int cont;
	float vetor [10];
	
	for(cont=0; cont<10; cont++)
	{
	printf("digite o valor %d: ", cont+1);	
	scanf("%f", &vetor[cont]);	
	}
	printf("digite o valor que quer visualizar: ");
	scanf("%d", &cont);
	cont--;
	printf("%.2f", vetor[cont]);
	

}
