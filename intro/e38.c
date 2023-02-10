#include <stdio.h>
#include <stdlib.h>

void troca (int *a, int*b)
{
	int x, y;
	x=*a;
	y=*b;
	*a=y;
	*b=x;
}

main()
{
	int a, b;
	
	printf("digite um valor para a e para b: ");
	scanf("%d %d", &a, &b);
	printf("antes: a= %d e b= %d\n", a, b);
	troca(&a,&b);
	printf("depois: a= %d e b= %d\n", a, b);
}
