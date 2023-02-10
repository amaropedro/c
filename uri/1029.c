#include <stdio.h>
int cont;

int fib(int n)
{
	if(n==1) 
	{
		cont++;
		return 1;	
	}
	else if(n==0)
	{
		cont++;
		return 0;
	}
	cont++;
	return (fib(n-1) + fib(n-2));
	
}

main()
{
	int N, num, result;
	
	scanf("%d", &N);
	
	while(N)
	{
		cont=0;
		scanf("%d", &num);
		result = fib(num);
		printf("fib(%d) = %d calls = %d\n", num, cont-1, result);
		N--;
	}
}
