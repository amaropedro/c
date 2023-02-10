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
	}
	menor=0;
	m=vetor[0];
	for(cont=1; cont<10; cont++)
	{
		if(vetor[cont]<m)
		{
			menor=cont;
			m=vetor[cont];
		}
		else if(vetor[cont]==m)
		menor=cont>menor?cont:menor;
	}
	printf("o menor numero esta na posicao: %d", menor+1);
	

}
