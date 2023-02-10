#include <stdio.h>
#define n 10

void scanV(int *v)
 {	
	int i; 
	for(i=0;i<n;i++)
	{
		printf("digite o valor %d do vetor: ", i+1);
		scanf("%d", v+i);
	}
		
 }
 
void printV(int *v)
 {	
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n", *(v+i));
	}
 }
 
 main()
{
	int V[n];
	scanV(V);
	printV(V);
	
}
