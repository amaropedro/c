#include<stdio.h>
#include<string.h>

main()
{
	int S, *p;
	
	scanf("%d", &S);
	p=&S;
	printf("p=%d\n*p=%d\ni=%d", p, *p, S);

	
}
