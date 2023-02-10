#include <stdio.h>
#include <string.h>

main()
{
	int n, i;
	char S1[51], S2[51], S[101], aux;
	
	scanf("%d", &n);
	do
	{
		scanf("%c%s %s", &aux, S1, S2);
		printf("s1=%s s2=%s\n", S1, S2);
		for(i=0;S1[i]||S2[i]; i++)
		{
			if(!(i%2)) S[i]=S1[i];
			else S[i]=S2[i-1];
			printf("%s\n", S);
		}
		sprintf(&S[i+1], "%s", S2[i]);
		printf("S=%s\n", S);
		n--;
	}while(n);
}
