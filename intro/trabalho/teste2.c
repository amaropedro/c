#include <stdio.h>

unsigned long long int quant(int x)
{ 
	unsigned long long int n=2;
	if(x==1)
	return n;
	else 
	n*=quant(--x);
	return n;
}

main()
{
	int n, x;
	FILE *f = fopen("file.txt", "w");
	scanf("%d", &n);
	do
	{
		scanf("%d", &x);
		if(x==64)
		{
			x=63;
			fprintf(f, "%lld kg\n", quant(x)/6000);
		}
		else
		fprintf(f, "%lld kg\n", quant(x)/12000);
		n--;
	}while(n);
}
