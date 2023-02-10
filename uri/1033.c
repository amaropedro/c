#include <stdio.h>
int cont;

unsigned long long int fib(unsigned long long int n)
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
	unsigned long long int n, b;
	int aux=1;
	
	scanf("%lld %lld", &n, &b);
	
	while(n&&b)
	{
		cont=0;
		fib(n);
		
		printf("Case %d: %lld %lld %lld\n", aux++, n, b, b);
		
		scanf("%lld %lld", &n, &b);
	}
}
