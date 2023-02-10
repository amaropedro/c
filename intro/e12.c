#include <stdio.h>
#include <stdlib.h>

main()
{
	int n, d=0, x=0;
	float m;
	printf("digite numeros naturais. sera calculada a media deles. quando quiser parar, digite um negativo\n");
	do 
	{
		printf("digite um numero natural: ");
		scanf("%d", &n);
		if(n>0) 
		{
		x=x+n;
		d++;	
		}	
	}
	while(n>=0);
	if(x>0)
	{
		m=(float)x/d;
	printf("media: %.2f", m);	
	}
	else printf("nenhum numero nao negativo foi digitado");
	
}
