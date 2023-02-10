#include <stdio.h>
main()
{
	int x, cont;
	char a[100];
	
	for(cont=0; cont<3; cont++)
	{
	x=0;
	printf("digite: ");
	scanf("%s", a);
	while(a[x]) x++;
	printf("%s tem %d caracteres.\n", a, x);
	}

}
