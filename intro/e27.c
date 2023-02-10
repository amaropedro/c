#include <stdio.h>
main()
{
	int n=21;
	char string1[n], string2[n];
	printf("digite: ");
	scanf("%s", string1);
	for(n=0; n<21; n++)
	{
		if(string1[n]!=0)
		string2[n]=string1[n]+1;
	}
	printf("%s", string2);
}
