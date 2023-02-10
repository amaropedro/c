#include <stdio.h>
#include <stdlib.h>

main()
{
	int *p=NULL, a, cont=0, i;
	
	printf("entre com um numero inteiro, 0 pra parar: \n");
	scanf("%d", &a);
	while(a)
	{
		cont++;
		p = (int*) realloc(p, cont*sizeof(int));
		if(!p) 
		{
		printf("erro!");
		return(1);	
		}
		*(p+(cont-1))=a;
		
		printf("entre com um numero inteiro, 0 pra parar: \n");
		scanf("%d", &a);
	}
	
	for(i=0; i<cont; i++)
	{
		printf("vetor[%d]: %d\n", i+1, *(p+i));
	}
	
	free(p);
	
	
}
