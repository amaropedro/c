#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main()
{
	char S[101], Maior[101], aux;
	int n=1, i, T[51], *p, maior=0, b=0;
	
	do
	{
	for(p=&T[0], i=0; i<51;*(p+i)=0, i++);
	i=0;
	do
	{
		scanf("%100s%c", S, &aux);
		
		if(S[0]==48) 
		{
			printf("\nThe biggest word: %s\n", Maior);
			exit(0); /* poderia ser return 0*/
		}
		
		T[i]=strlen(S);
		
		if(strlen(S)>=maior)
			{
				maior=strlen(S);
				strcpy(Maior, S);	
			}
		i++;
	}while(aux!=10);
	
	for(i=0;T[i];i++)
	{
		if(T[i+1])
		printf("%d-", T[i]);
		else printf("%d\n", T[i]);
	}
	}while(n);
}
