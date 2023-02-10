#include <stdio.h>
#include <stdlib.h>
int *V, cont, menor=-1, fim; //cont nao vai da certo pq tem que armazenar varios contadores para ver qual é o menor

int mochila(int blocos,int cmp)
{
	cont++;
	
	if(blocos == 0)
	{
		return 0;
	}
	else if(cmp == 0)
	{
		if(fim == 0)
		menor = cont;
		else if(cont<menor)
		menor = cont;
		
		fim++;
		
		cont=0;
		return 0;
	}
	else if(V[blocos]>cmp)
	{
		mochila(blocos-1, cmp);
	}
	else
	{
		mochila(blocos, cmp-V[blocos]);
		mochila(blocos-1, cmp);
		mochila(blocos-1, cmp-V[blocos]);
	}
	
	return menor;
}

main()
{
	long int cmp;
	int N, blocos, i;
	 
	scanf("%d", &N);
	
	while(N)
	{
		cont = fim = 0; 
		scanf("%d %ld", &blocos, &cmp);
		
		V = (int*) malloc(blocos*sizeof(int));
		if(!V) {printf("erro"); return 1;}
		
		for(i=0; i<blocos; i++)
		{
			scanf("%d", &V[i]);
		}
		
		mochila(blocos-1, cmp);
		
		printf("%d\n", menor);
		
		N--;
	}
}
