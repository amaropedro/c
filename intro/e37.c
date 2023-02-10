#include <stdio.h>
#define n 10

int mvetor (int V[n])
{	
	int cont, m=0;
	
	for(cont=0; cont<n; cont++)
	{
		if (V[cont]>m)
		m=V[cont];
	}
	
	return m;
}

main()
{
	int V[n], cont;
	
	for(cont=0;cont<n;cont++)
	{
		printf("digite o elemento %d: ", cont+1);
		scanf("%d", V+cont);
	}
	
	printf("maior valor: %d", mvetor(V));
	
}
