#include <stdio.h>

int rec(int num)
{
	if(num==1)
	return 1;
	else if(num==2)
	return 2;
	else
	return num*rec(num-1);
	
}

main()
{
	int p;
	do
	{
		do
		{
			printf("ente com a posicao que quer checar: ");
			scanf("%d", &p);
			if(p<0) printf("digite somente naturais\n");
		}while(p<0);

		if(!p) break;
		printf("numero correspondente: %d\n", rec(p));
	}while(p);
	printf("fim do programa");
}
