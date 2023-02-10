#include <stdio.h>
#include <stdlib.h>

main()
{
	float M[7][4];
	int i, j;
	
	for(i=0;i<7;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("\ndigite o emelento %d,%d: \n", i+1, j+1);
			setbuf(stdin,NULL);
			scanf("%f", &M[i][j]);
		}
	}
	
	for(i=0;i<7;i++)
	{
		for(j=0;j<4;j++)
		{
			if(j==0) printf("|          %.2f          ", M[i][j]);
			else 
			{
			if(j==3) printf("%.2f          |\n", M[i][j]);
			else printf("%.2f          ", M[i][j] );	
			}
		}
	}
}
