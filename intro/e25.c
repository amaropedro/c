#include <stdio.h>
main()
{
	int cont=0;
	char s[100];
	printf("digite: ");
	scanf("%s", s);
	while(s[cont]) cont++;
	printf("%s tem %d caracteres", s, cont);
}
