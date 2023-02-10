#include <stdio.h>

main()
{	
	int i;
	char S1[10], S2[10];
	scanf("%s", S1);
	for(i=0;S1[i];i++)
	{
		S2[i]=S1[i];
	}
	printf("%s %d %d", S2, 0%2, 1%2);
	
}
