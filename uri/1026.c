#include <stdio.h>


main()
{
	unsigned long long int a, b, c;
	
	while(scanf("%lu %lu", &a, &b)!=EOF)
	{	
		c=a^b;
		printf("%lu\n", c);
	}
}

