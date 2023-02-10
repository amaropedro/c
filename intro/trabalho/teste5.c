#include <stdio.h>
#define n 12
main()
{
	int i, j, aux=0;
	float M[n][n], soma=0;
	char O;
	scanf("%c", &O);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%f", &M[i][j]);	
			if(i>j&&i+j<n-1)
			{
				soma+=M[i][j];
				aux++;
			}
		}
	}
	
	switch (O)
	{
	case 'S': printf("%.1f\n", soma);
	break;
	case 'M': printf("%.1f\n", soma/aux);
	break;
	default: break;
	}
}
