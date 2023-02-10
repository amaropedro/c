#include <stdio.h>
#define n 5

void inV (int *V, int i, int f)
{
	int aux;
	if(i<f)
	{
		aux=V[i];
		V[i]=V[f];
		V[f]=aux;
		inV(V, i+1,f-1);	
	}
	else
	{
		for(i=0;i<n;i++)
		printf("%d \n", V[i]);
	}

}

main()
{
	int V[n], i;
	for(i=0;i<n;i++)
	{
		printf("digite o elemento %d do vetor: ", i+1);
		scanf("%d", &V[i]);
	}
	inV(V, 0, n-1);
}
