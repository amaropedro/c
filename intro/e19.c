#include <stdio.h>
#include <stdlib.h>

main()
{
	int a, b, d, aux;
	do
	{
	printf("entre com um valor: ");
	scanf("%d", &a);	
	}while(a<0);
	
	do
	{
	printf("entre com outro valor: ");
	scanf("%d", &b);	
	}while(b<0);
	
	if(b>a) 
	{
	aux=a; 
	a=b;
	b=aux;	
	}
	if(b==0)
	{
		if(a) printf("mdc: %d", a);
		else printf("mdc: +infinito");
		exit(0);
	}
	for(d=a;(a%d!=0)||(b%d!=0);d--);
	printf("mdc: %d", d);

}
