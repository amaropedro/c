#include <stdio.h>
#include <stdlib.h>
#define n 10
#define s 100

main()
{
	int cont;
	char V[n][s], *p;
	
	for(cont=0, p=&V[0][0]; cont<n; cont++, p+=s )
	{
		scanf("%99[^\n]", p);
		setbuf(stdin,NULL);
	}
	
	printf("strings: \n");
	for(cont=0, p=V[0]; cont<n; cont++, p+=s)
	printf("%s\n", p);
}


