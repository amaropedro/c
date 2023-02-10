#include <stdio.h>
#include <math.h>

main()
{
	int cont=7, i, j, v=3, b;
	b = cont-v;
	printf("b=%d\n", b);
	for(i=0; i<cont; i++)
	{
		printf("i=%d\n", i);
		if(i==(v-1))
		{	
			for(j=0; j<b; j++)
			{	
				printf("j=%d\n", j);
			}
			
			break;
		}
	}
}
