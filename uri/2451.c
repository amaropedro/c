#include <stdio.h>
#include <stdlib.h>

main()
{
	int i, T, cont=1, comida=0,maior=0; 
	char *V;
	
	scanf("%d", &T);
	
	V = (char*) malloc(T*sizeof(char));
	if(!V) return 1;
	
	while(cont<=T)
	{
		setbuf(stdin,NULL);
		scanf("%s", V);
		
		if(cont%2)
		for(i=0; i<T; i++)
		{
			if(V[i]=='o') comida++;
			else if(V[i]=='A')
			{
				if(comida>maior) maior = comida;
				comida = 0;
			}
		}
		else
		for(i=T; i>=0; i--)
		{
			if(V[i]=='o') comida++;
			else if(V[i]=='A')
			{
				if(comida>maior) maior = comida;
				comida = 0;
			}
		}
		
		cont++;
	}
	
	if(comida>maior) maior = comida;
	
	printf("%d\n", maior);
}
