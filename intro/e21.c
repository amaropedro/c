#include <stdio.h>
#include <stdlib.h>

main()
{
	int a, b, aux, q;
	printf("digite um valor: ");
	scanf("%d", &a);	
	printf("digite um outro valor: ");
	scanf("%d", &b);

	if(a==0) 
	{
		if(b) printf("quociente: 0 resto:0"); 		
		else printf("dividindo 0 por 0!"); 	
		exit(0); 
	}
	if(b==0) 
	{
		printf("divisao por 0!");
		exit(1);	
	}
	if(a>0&&b>0) 
	{
		for(q=0;a>=b;a=a-b, q++);	
		printf("quociente: %d resto: %d", q, a);
	}
		else if(a<0&&b<0)
		{
		a=0-a;
		b=0-b;
		for(q=0;a>=b;a=a-b, q++);
		a=0-a;
		printf("quociente: %d resto: %d", q, a);
		}
		else if(b<0)
	{
		b=0-b;	
		for	(q=0;a>=b;a=a-b, q++);
		q=0-q;
		printf("quociente: %d resto: %d", q, a);
	}
			else 
			{
			a=0-a;
			for	(q=0;a>=b;a=a-b, q++);
			q=0-q;
			a=0-a;
			printf("quociente: %d resto: %d", q, a);	
	}	
}
