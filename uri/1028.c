#include <stdio.h>

main()
{
	int N, a, b, resto;
	
	scanf("%d", &N);
	
	while(N)
	{
		scanf("%d %d", &a, &b);
		
		do
		{
			resto = a%b;
			a = b;
			b = resto;
			
		}while(resto);
		
		printf("%d\n", a);
		
		N--;
	}
}
