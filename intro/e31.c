#include <stdio.h>
#include <stdlib.h>

main()
{
	int M[5][5], i, j, aux, soma=0;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("digite o elemento %d, %d: ", i+1, j+1);
			scanf("%d", &M[i][j]);
		}
	}
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			for(aux=1; aux<=i; aux++)
			soma+=M[i][j];
		}
	}
	
		
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(j==0) printf("|          %d          ", M[i][j]);
			else 
			{
			if(j==4) printf("%d          |\n", M[i][j]);
			else printf("%d          ", M[i][j] );	
			}
		}
	}
	
	printf("soma dos numeros abaixo da diagonal: %d", soma);

}
