#include <stdio.h>

int fib(int n, int *cont)
{
	if(n==1) 
	{
		(*cont)++;
		return 1;	
	}
	else if(n==0)
	{
		(*cont)++;
		return 0;
	}
	(*cont)++;
	return (fib(n-1, cont) + fib(n-2, cont));
	
}

main()
{
	int N, num, cont, result;
	
	scanf("%d", &N);
	
	while(N)
	{	
		cont = -1;
		scanf("%d", &num);
		result = fib(num, &cont);
		printf("fib(%d) = %d calls = %d\n", num, cont, result);
		N--;
	}
}
