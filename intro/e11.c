#include <stdio.h>
#include <stdlib.h>

main()
{
	float n1, n2, na, m, M;
	int n, p=1;
	printf("digite o numero de alunos: ");
	scanf("%f", &na);
	while(p<=na)
	{
		printf("digite a primeira nota do aluno %d: ", p);
		scanf("%f", &n1);
		printf("digite a segunda nota do aluno %d: ", p);
		scanf("%f", &n2);
		if(p==1)
		M=(n1+n2)/2;
		else 
		{ 
		  m=(n1+n2)/2;
		  if(M<m) 
		  {
		  	M=m;
		  	n=p;
		  }
		  	
	    }
	    p++;
	}
	printf("a maior nota %.2f foi do aluno: %d", M, n);
}
