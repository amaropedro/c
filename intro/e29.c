#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{	int cont, n, compx, compy;
	char x[101], y[101];
	printf("digite: ");
	scanf("%100[^\n]", x);
	setbuf(stdin,NULL);
	printf("digite novamente: ");
	scanf("%100[^\n]", y);
	
	compx=strlen (x);
	compy=strlen (y);
	
	for(n=0,cont=compx-compy;x[cont]!=0;cont++, n++)
	{
		if(x[cont]==y[n])
		compx=1;
		else
		{ compx=0;
			break;
		}
	}
	if(compx) printf("esta contida no final");
	else printf("nao esta contida no final");
		

}
