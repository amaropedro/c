#include <stdio.h>
#include <stdlib.h>

main()
{
	int M[3][4], *p, cont, a;
	
	for(a=1, cont=0, p=M[0];cont<12;cont++, p++, a++)
	{
		*(p)=a;
		if(*p==4||*p==8)
		printf("0%d\n", *p);
		else
		if(*p<10)
		printf("0%d ", *(p));
		else printf("%d ", *(p));
	}
	
	
}
