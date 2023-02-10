#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	char V[5][100], S[100];
	int aux;
	
	for(aux=0; aux<5; aux++)
	{
		printf("digite a string %d: ", aux+1);
		scanf("%99[^\n]", V[aux]);
		setbuf(stdin,NULL);
	}
	
	printf("digite a string que deseja verificar: ");
	scanf("%99[^\n]", S);
	
	for(aux=0; aux<5; aux++)
	{
		if(strcmp(V[aux],S)==0)
		{
		printf("a string pertence e esta na posicao: %d", aux+1);
		exit(0);	
		}
	}
	printf("a string nao pertence");
	
}
