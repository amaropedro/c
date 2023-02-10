#include <stdio.h>
#include <stdlib.h>

main()
{
	int a, b, c, x, n;
	do
	{
	scanf("%d", &n);
	if(n) 
	{	
	a=(n/100);
	x=a*100;
	c=n-((n/10)*10);
	b=n-(x+c);
	b=b/10;
	printf("%d", c);
	printf("%d", b);
	printf("%d \n", a);
	}
    }
	while(n);
}

