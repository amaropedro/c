#include <stdio.h>
#include <stdlib.h>

main()
{
	int *V=NULL, a, i=0;
	
	printf("entre com um numero inteiro, 0 pra parar: \n");
	scanf("%d", &a);
	
	while(a)
	{		
		
		
			do
			{
				i++;
				V= (int*) realloc(V, i*sizeof(int));
				V[i-1]=a;
				
				printf("entre com um numero inteiro, 0 pra novo vetor: \n");
				scanf("%d", &a);
			}while(a);
		
		for(a; a<i; a++)
		{
			if(i==1) printf("Vetor= { %d }\n", *(V+a));
			else if(!a) printf("Vetor= { %d, ", *(V+a));
			else if (a+1==i) printf("%d }\n",*(V+a));
			else printf("%d, ", *(V+a));
		}
		free(V);
		V=NULL;
		i=0;
		printf("entre com um numero inteiro, 0 pra parar: \n");
		scanf("%d", &a); 
	}
}
