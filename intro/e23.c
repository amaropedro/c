#include <stdio.h>
#include <stdlib.h>

main()
{	
	int cont, menor;
	float vetor [10], m;
	
	for(cont=0; cont<10; cont++)
	{
	printf("digite o valor %d: ", cont+1);
	scanf("%f", &vetor[cont]);	
	if(cont==0) 
	{
		m=vetor[cont]; 
		menor=cont;
	}
	else if(vetor[cont]<m) 
	{
	m=vetor[cont];	
	menor=cont;	
	}	
	}
	printf("o menor numero esta na posicao: %d", menor+1);
	

}
