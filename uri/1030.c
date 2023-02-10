#include <stdio.h>
#include <stdlib.h>

main()
{
	int *H, N, tam, passo, j, i, cont=0, sum=0;
	
	scanf("%d", &N);
	
	while(cont<N)
	{
		scanf("%d %d", &tam, &passo);
		if(tam==1)
		{
			printf("case %d: 1\n", cont+1); cont++;
		}
		else if(passo==1)
		{
			printf("case %d: %d\n", cont+1, tam); cont++;
		}
		else
		{
			H = (int*) calloc(tam,sizeof(int));
			if(!H) return 1; 
			
			while(sum+1<tam)
			{
				sum=0;
				for(j=0; j<tam; j++)
				{
					printf("H[%d] = %d\n", j, H[j]);
				}
				for(i=0; i<tam; i++)
				{
					if(H[i]==1) 
					i++;
					else if(i+passo-1>=tam)
					H[tam-i+passo-1] = 1;
					else
					H[i+passo-1] = 1;
				}
				for(j=0; j<tam; sum+=H[j], j++);
			}
			for(i=0; i<tam; i++)
			{
				if(H[i]==0) 
				{
					printf("case %d: %d\n", cont+1, i+1);
					break;
				}	
			}
			cont++;	
		}
	}
}
