#include <stdio.h>
#include <stdlib.h>

main()
{
	char S[10][100] ;
	int V[10], i, j;
	
	for(i=0; i<10; i++)
	{
		printf("digite a string %d: ", i+1);
		scanf("%10[^\n]", S[i]);
		setbuf(stdin,NULL);
		printf("digite o numero na posicao %d: ", i+1);
		scanf("%d", &V[i]);
		setbuf(stdin,NULL);
	}
	
	for(i=0; i<10; i++)
	{
		for(j=0; j<100; j++)
		{
			if(S[i][j]==0)
			{
			sprintf(&S[i][j], "%d", V[i]);
			printf("string %d: %s\n", i+1, S[i]);
			break;	
			}
		}
	}	
}
