#include <stdio.h>
#include <stdlib.h>
main()
{
	float x, n;
	int aux;
	printf("esse programa calcula a raiz quadrada com 2 casas decimais.\n");
	printf("digite um numero: ");
	scanf("%f", &n);
	for(x=0;(x*x)<n;x=x+0.01);
	aux=x*10;
	if(aux%10==0) 
	{
	printf("raiz: %.2f", x);
	exit(0);
	}
	else 
		x=x-0.01;
		printf("raiz: %.2f", x);

	
}
