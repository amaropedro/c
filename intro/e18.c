#include <stdio.h>
#include <stdlib.h>

main()
{
	int a, b, d;
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
		
	for(d=1;(d%a!=0)||(d%b!=0);d++);
	printf("mmc: %d", d);

}
