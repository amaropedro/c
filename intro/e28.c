#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main()
{	int cont1, cont2;
	char str1[202], str2[101];
	
	printf("digite: ");
	scanf("%101[^\n]", str1);
	setbuf(stdin,NULL);
	printf("digite novamente: ");
	scanf("%101[^\n]", str2);
	
	if(strlen(str1)==strlen(str2))
	{
		if(strcmp(str1,str2)==0) printf("strings iguais\n");
			else printf("strings diferentes\n");
	}
	else printf("%s", strcat(str1,str2));
}
