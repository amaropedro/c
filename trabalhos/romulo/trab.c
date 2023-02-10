#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char intochar(int x)
{
	int aux;
	
	aux = x-10;
	
	return ('A'+aux);
	
}

int letra(int x, char* N)
{
	int i;
	
	for(i=0; i<=25; i++)
	{
		if((N[x]=='A'+i)||(N[x]=='a'+i))
		{
			return (10+i);	
		}
	}
	return 0;
}

main()
{
	long long int div, mult=-1;
	int cont=0, aux=0, auxp=0,i, j, b1=2, b2=2, l, BL, ml=0, v=-1, p=0;
	double base10=0, afterp=0, n;
	char  c, *N=NULL, *V=NULL, *BN=NULL, *BV=NULL;
	
	printf("este programa transforma qualquer numero, fornecida sua base, em sua respectiva representacao em outra base  de escolha do usuario.\nas bases vao de 2 a 25, considerando as letras do alfabeto. este programa tambem transforma numeros reais.\nOBS1: use '.' para reprensetar ',';\nOBS2:este programa ira imprimir o numero na base 10, independente da escolha da mesma, para fins de comparacao;\n");
	
	printf("digite o numero: \n");
	scanf("%c", &c);
	
	while(c!='\n')
	{
		cont++;
		
		if(c=='.'||c==',')
		{	
			if(c==',')
			{
				printf("digite '.' ao invez de ','!\n");
				return 0;
			}
			
			cont--;
			v = cont;
			if(cont==0)
			{
				printf("iniciou com virgula ou ponto!");
				return(1);
			}
			
			scanf("%c", &c);
			
			while(c!='\n')
			{
				p++;
				
				V = (char*) realloc(V, p*sizeof(char));
				if(!V) {printf("erro na alocação"); exit(0);}
				
				V[p-1] = c;
				
				if(c=='.'||c==',')
				{
					printf("mais de uma ponto!");
					return(1);	
				}
				
				scanf("%c", &c);
			}
			break;
		}
		
		N = (char*) realloc(N, cont*sizeof(char));
		if(!N) {printf("erro na alocação"); exit(0);}
		
		N[cont-1] = c;
		
		l = letra(cont-1, N);
		if(l)
			if(l>ml)
				ml = l;	
		
		scanf("%c", &c);
	}
	if(cont==0) {printf("nenhum numero digitado\n"); return 0;}
	
	do
	{
		BL=0;
		printf("digite a base na qual o numero foi escrito: \n"); scanf("%d", &b1);
		if(b1<2) printf("base menor que 2, digite novamente. \n");
		else if(b1<=ml)
		{
			BL=1;
			printf("sua base nao vai ate a maior letra digitada, tente novamente. \n");
		}
	}while((b1<2)||BL);
	
	do
	{
		printf("digite a base na qual deseja transformar: \n"); scanf("%d", &b2);
		if(b2<2) printf("base menor que 2, digite novamente. \n");
		if(b2==b1) printf("transformando para a mesma base, digite novamente. \n");
	}while(b2<2||b2==b1);
	
	if(b1!=10)
	{
		for(i=0; i<cont; i++)
		{
			l = letra(i, N);
			
			if(l) 
			n = (float) l;
			else
			n = (float) N[i]-'0'; 
			
			base10 += n*pow(b1,cont-i-1);
		}
		
		if(i==v)
		{	
			for(j=0; j<(p); j++)
			{	
				l = letra(j, V);
				
				if(l)
				n = (float) l;
				else
				n = (float) V[j]-'0';
				
				afterp += n/pow(b1, 1+j);
			}
		}
	}
	else
	{
		sscanf(N, "%lf", &base10);
		if(v!=-1)
		{
			sscanf(V, "%lf", &afterp);
			//printf("afterp = %.2lf base10 = %.2lf ...", afterp, base10);
			afterp = afterp/pow(10, p);	
		}
		//printf("afterp = %.2lf base10 = %.2lf\n", afterp, base10);
	}

	div = (long long int) base10;
	//printf("div = %d\n", div);
	do
	{
		//printf("div = %d\n", div);
		aux++;
		BN = (char*) realloc(BN, aux*sizeof(char));
		if(!BN) {printf("erro na alocação"); exit(0);}
		//printf("div%%b2 = %d\n", div%b2);
		if(div%b2>=10)
		{
			BN[aux-1] = intochar(div%b2);
		}
		else BN[aux-1] = (char)div%b2+'0';
		
		div = div/b2;
	}while(div/b2>=b2);
	BN = (char*) realloc(BN, (aux+2)*sizeof(char));
	if(!BN) {printf("erro na alocação"); exit(0);}
	
	BN[aux] = (char)div%b2+'0'; 
	BN[aux+1] = (char)div/b2+'0';
	
	if(v!=-1)
	{	n=afterp;
		while(n)
		{	
			auxp++;
			
			BV = (char*) realloc(BV, auxp*sizeof(char));
			if(!BV) {printf("erro na alocação"); exit(0);}
			
			n = n*(float)b2;
			mult = (long long int) n;
			n -= (float)mult;
			//printf("afterp = %.2lf n= %.2lf mult = %d\n", afterp,n,mult);
			if(mult>=10)
			{
				BV[auxp-1] = intochar(mult);
			}
			else BV[auxp-1] = (char) mult + '0';
		}
	}
	
	printf("numero na base%d = ", b1);
	for(i=0; i<cont; i++)
	{
		printf("%c", N[i]);
	}
	
	if(i==v)
	{
		printf(".");
		for(j=0; j<p; j++)
		{
			printf("%c", V[j]);
		}
	}
	
	if(b1!=10)
	printf("\nnumero na base10 = %.4lf", base10+afterp);
	if(b2!=10)
	{
		printf("\nnumero na base%d = ", b2);
		for(j=0; j<aux+2; j++)
		{
			printf("%c", BN[aux+1-j]);
		}
		
		if(i==v)
		{
			printf(".");
			for(j=0; j<auxp; j++)
			{
				printf("%c", BV[j]);
			}
		}
	}
}


