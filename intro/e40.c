#include <stdio.h>
#include "C:\Users\Amaro\Documents\linder\headers\func.h"

main()
{
	int a, b;
	printf("digite um valor para a e para b: ");
	scanf("%d %d", &a, &b);
	if(EDivisivel(a,b))
	printf("a eh divisivel por b\n");
	else printf("a nao eh divisivel por b\n");
	printf("o valor maximo eh: %d\n", Max(a,b));
	printf("o valor medio eh: %d\n", VMedio(a,b));
	
}

