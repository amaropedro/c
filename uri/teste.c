#include <stdio.h>

main()
{
	char aux, c,A[10], B[10];
	int cont, i, j, carry;
	FILE *F;
	
	F = fopen("output1212.txt", "w");
	
	while(1)
	{
		i=carry = 0;
		
		scanf("%c", &c);
		while(c!=32) //32 == espaço na tebala ascii
		{
			i++;
			A[i-1] = c;
			scanf("%c", &c);
		}
		if(i>1)
		for(cont=0; cont<i/2; cont++)
		{
			aux = A[cont];
			A[cont] = A[i-cont-1];
			A[i-cont-1] = aux;
		}
		//printf("A = %s\n", A);
		j=0;
		scanf("%c", &c);
		while(c!='\n')
		{
			j++;
			B[j-1] = c;
			scanf("%c", &c);
		}
		if(j>1)
		for(cont=0; cont<j/2; cont++)
		{
			aux = B[cont];
			B[cont] = B[j-cont-1];
			B[j-cont-1] = aux;
		}
		//printf("B = %s\n", B);
		if(A[0]=='0'&&B[0]=='0') return 2;
		
		if(i>j)
		{
			for(; j<i; j++)
			{
				B[j] = '0';
			}
		}
		else if(j>i)
		{
			for(; i<j; i++)
			{
				A[i] = '0';
			}
		}
		
		for(cont=0; cont<i; cont++)
		{
			if((A[cont]-'0')+(B[cont]-'0')>9) 
			{
				carry++;
				if(cont<i-1)
				{
					A[cont+1]++;
					/*if(A[cont+1]>9)
					{
						printf("cont+1 = %d\n", cont=1);
						if(cont+1>=min)
						carry++;
					}*/
				}
			}
		}
		
		if(carry==1) fprintf(F, "%d carry operation.\n", carry);
		else if(carry) fprintf(F, "%d carry operations.\n", carry);
		else fprintf(F, "No carry operation.\n");
	}
}
