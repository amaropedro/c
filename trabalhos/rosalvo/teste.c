#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
	int n, **M, i, j=0, tam, aux;
	
	printf("digite n: \n");
	scanf("%d", &n);
	
	tam = (int) pow(2, n);
	printf("tam = %d\n", tam);
	
	M = (int**) malloc(sizeof(int*)*tam);
	if(!M)
		return 22;
		
	for(i=0; i< tam ; i++)
	{
		M[i] = (int*) calloc(sizeof(int), n);
		if(!M[i])
		return 33;	
	}
	

	for(i=0; i < tam; i++)
	{
		for(j = 0; j < n; j++)
			M[i][j] = !!(i & (1 << j));
	}
	
	for(i=0; i < tam; i++)
	{
		printf("| ");
		for(j=0; j < n; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("|\n");
	}
}
