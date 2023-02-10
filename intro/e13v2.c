#include <stdio.h>

main()
{
	int n, a;
	printf("esse programa calcula e exibe os divisores de um numero natural\n");
	do
	{
	printf("digite um numero natural: ");
	scanf("%d", &n);
	if(n<0) printf("vc digitou um valor negativo\n");
	}
	while(n<0);
	if(n==0) a=1;
	else a=n;
	while(a>0)
	{
		if(n%a==0) printf("%d ", a);
		a--;	
	}
	
}
