#include <stdio.h>

main()
{
	FILE *F;
	unsigned int tam, i, j, N, metade, cont=0;
	char M[1000], aux;
	
	F = fopen("output1024.txt", "w");
		
	scanf("%ud", &N);
	
	while(cont<N)
	{
		if(!cont)
		scanf("%c%[^\n]%c", &aux, M, &aux);
		else
		scanf("%[^\n]%c", M, &aux); /*lendo um char ao invez de setbuf(STDIN, null) por causa do uri*/
		
		//printf("lido = %s\n", M);
		
		for(i=0; M[i]!='\0'; i++);
		
		tam = i;
		
		for(i=0; i<tam; i++)
		{
			if((M[i]>='A'&&M[i]<='Z')||(M[i]>='a'&&M[i]<='z'))
			M[i] += 3;
		}
		
		//printf("passo 1 = %s\n", M);
		
		for(i=0, j=tam-1; i<j; i++, j--)
		{
			aux = M[i];
			M[i] = M[j];
			M[j] = aux;
		}
		
		//printf("passo 2 = %s\n", M);
		
		metade = tam/2;
		
		for(i=metade; i<tam; i++)
		{
			M[i]--;
		}
		
		fprintf(F, "%s\n", M);
		
		cont++;
	}
}
