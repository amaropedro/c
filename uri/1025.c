#include <stdio.h>
#include <stdlib.h>

main()
{
	FILE *F;
	
	int cont=1, i, j, aux, q, N, Q, *V=NULL, notfound;
	
	F = fopen("output1025.txt", "w");
	if(!F)
	return 1;
	
	scanf("%d %d", &N, &Q);
	
	while(N&&Q)
	{
		V = (int*) realloc(V, N*sizeof(int));
		if(!V)
		return 1;
		
		for(i=0; i<N; i++)
		{
			scanf("%d", &V[i]);
		}
		
		for(i=0; i<N; i++)
		{
			for(j=i+1; j<N; j++)
			{
				if(V[i]>V[j])
				{
					aux = V[i];
					V[i] = V[j];
					V[j] = aux;
				}
			}
		}	
		
		fprintf(F, "CASE# %d:\n", cont);
		
		while(Q)
		{
			scanf("%d", &q);
			
			for(i=0; i<N; i++)
			{
				notfound = 1;
				if(q==V[i])
				{
					fprintf(F, "%d found at %d\n", q, i+1);
					notfound=0;
					break;	
				}
			}
			
			Q--;
			
			if(notfound)
			fprintf(F, "%d not found\n", q);
		}
		 
		cont++;
		scanf("%d %d", &N, &Q);
	}
	
}
