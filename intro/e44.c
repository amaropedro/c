#include <stdio.h>
#include <stdlib.h>

main()
{
	int c, n, cont;
	char *p;
	
	printf("digite o tamanho das strings: "); scanf("%d", &c);
	printf("digite a quantidade de strings: "); scanf("%d", &n);
	
	p=(char*) calloc(c*n,sizeof(char));
	if(!p) 
	{
		printf("erro!");
		return 1;
	}
	
	for(cont=0; cont<n; cont++)
	{
		printf("digite a string[%d]:\n", cont+1);
		setbuf(stdin,NULL);
		scanf("%[^\n]", p+cont*c);
	}
	
	for(cont=0; cont<n; cont++)
	printf("vc digitou= %s\n", *(p+(cont*c)));
}
