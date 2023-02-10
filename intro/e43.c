#include <stdio.h>
#include <stdlib.h>

main()
{
	int i, j, cont;
	float *p;
	
	printf("digite o numero de linhas: \n"); scanf("%d", &i);
	printf("digite o numero de colunas: \n"); scanf("%d", &j);
	
	p = (float *) malloc(i*j*sizeof(float));
	if(!p)
	{
		printf("erro na aloc.");
		return(1);
	}
	
	for(cont=0; cont<i*j; cont++)
	{
		printf("digite o elemento da matriz: \n"); 
		scanf("%f", p+cont);
	}
	
	for(cont=0; cont<(i*j); cont++)
	{
		if((cont+1)%j==0) printf("%.2f\n", *(p+cont));
		else printf("%.2f ", *(p+cont));
	}
	
}
