#include <stdio.h>

int Edivisivel(int a, int b)
{
	if(a%b==0)
	return 1;
	else
	return 0;
}

main()
{
	int x, y;
	printf("digite 2 numeros: ");
	scanf("%d %d", &x, &y);
	if(Edivisivel(x,y))
	printf("eh divisivel");
	else printf("nao eh divisivel");
}
