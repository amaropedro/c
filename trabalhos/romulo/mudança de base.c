#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int letra2(char m)
{
	int i;
	
	for(i=0; i<=25; i++)
	{
		if((m=='A'+i)||(m=='a'+i))
		{
			return (10+i);	
		}
	}
	return 0;
}

char intochar(int x)
{
	int aux;
	
	aux = x-10;
	//printf("aux = %d\n", aux);
	return ('A'+aux);
	
}

int letra(int x, char* N)
{
	int i;
	
	for(i=0; i<26; i++)
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
	int cont=0, aux=0, auxp=0,i, j, b1=2, b2=2, l, BL, ml=0, v=-1, p=0, maiornum=0, negativo=0;
	double base10=0, afterp=0, n;
	char  c, *N=NULL, *V=NULL, *BN=NULL, *BV=NULL, teste;
	
	printf("este programa transforma qualquer numero, fornecida sua base, em sua respectiva representacao em outra base  de escolha do usuario.\nas bases vao de 2 a 36, considerando as letras do alfabeto. este programa tambem transforma numeros reais.\nOBS1: use '.' para reprensetar ',';\nOBS2: este programa ira imprimir o numero na base 10, independente da escolha da mesma, para fins de comparacao;\n");
	
	printf("\ndigite o numero: \n");
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
			
			if(c<'0'||c>'9')
			{
				if(!letra2(c))
				{
					printf("not a number! problema = %c", c);
					return (1);
				}
			}
			
			while(c!='\n')
			{
				p++;
				
				V = (char*) realloc(V, p*sizeof(char));
				if(!V) {printf("erro na alocação"); exit(0);}
				
				V[p-1] = c;
				
				l = letra(p-1, V);
				if(l)
				{
					if(l>ml)
					ml = l;	
				}
				else if((c-'0')>maiornum)
				maiornum = c - '0';
		
				scanf("%c", &c);
			}
			break;
		}
		
		if(cont==1)
		{
			if(c=='-')
			{
				negativo = 1;
				scanf("%c", &c);
			}
			else if (c=='+')
			scanf("%c", &c);
		}
		if(c<'0'||c>'9')
		{
			if(!letra2(c))
			{
				printf("not a number! problema = %c", c);
				return (1);
			}
		}
		
		N = (char*) realloc(N, cont*sizeof(char));
		if(!N) {printf("erro na alocação"); exit(0);}
		
		N[cont-1] = c;
	
		l = letra(cont-1, N);
		if(l)
		{
			if(l>ml)
			ml = l;
		}
		else if((c-'0')>maiornum)
		maiornum = c - '0';
		
		scanf("%c", &c);
	}
	if(cont==0) {printf("nenhum numero digitado\n"); return 0;}
	
	

	do
	{	teste=0;
		BL=0;
		printf("digite a base na qual o numero foi escrito: \n"); scanf("%d%c", &b1, &teste); setbuf(stdin,NULL);
		if(teste != '\n')
		{
			printf("digite um numero! \n");
		}
		else if(b1<2) printf("base menor que 2, digite novamente. \n");
		else if(b1<=ml)
		{
			BL=1;
			printf("sua base nao vai ate a maior letra digitada, tente novamente. (maior letra = %c)\n", intochar(ml));
		}
		else if(b1<=maiornum)
		{
			BL=1;
			printf("sua base nao vai ate o maior numero digitado, tente novamente. (maior numero = %d)\n", maiornum);
		}
		else if(b1>36)
		{
			printf("base maior que 36, digite novamente\n");
		}
	}while((b1>36)||(b1<2)||BL||(teste != '\n'));
	
	do
	{	teste=0;
		printf("digite a base na qual deseja transformar: \n"); scanf("%d%c", &b2, &teste); setbuf(stdin,NULL);
		if(teste != '\n')
		{
			printf("digite um numero! \n");
		}
		else if(b2<2) printf("base menor que 2, digite novamente. \n");
		else if(b2>36)
		{
			printf("base maior que 36, digite novamente\n");
		}
		else if(b2==b1) printf("transformando para a mesma base, digite novamente. \n");
	}while((b2>36)||b2<2||b2==b1||(teste != '\n'));
	
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
		else BN[aux-1] = (char) (div%b2)+'0';
		
		div = div/b2;
	}while(div/b2>=b2);
	BN = (char*) realloc(BN, (aux+2)*sizeof(char));
	if(!BN) {printf("erro na alocação"); exit(0);}
	
	if(div%b2>=10)
	{
		BN[aux] = intochar(div%b2);
	}
	else
	BN[aux] = (char)div%b2+'0';
	 
	if(div/b2>=10)
	{
		BN[aux+1] = intochar(div/b2);
	}
	else
	BN[aux+1] = (char)div/b2+'0';
	
	if(v!=-1)
	{	n=afterp;
		while((n)&&auxp<11)
		{	
			auxp++;
			//printf("auxp = %d\n", auxp);
			BV = (char*) realloc(BV, auxp*sizeof(char));
			if(!BV) {printf("erro na alocação"); exit(0);}
			
			n = n*(float)b2;
			mult = (long long int) n;
			n -= (float)mult;
			//printf("afterp = %.2lf n= %.2lf mult = %d\n", afterp,n,mult);
			if(mult>=b2)
			{
				mult-=b2;
				if(auxp==1)
				BN[0]++;
				else
				BV[aux-2]++;
			}
			if(mult>=10)
			{
				BV[auxp-1] = intochar(mult);
			}
			else BV[auxp-1] = (char) mult + '0';
		}
	}
	
	printf("numero na base%d = ", b1); if(negativo) printf("-");
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
	{
		printf("\nnumero na base10 = "); if(negativo) printf("-"); printf("%.4lf", base10+afterp);
	}
	
	if(b2!=10)
	{
		printf("\nnumero na base%d = ", b2); if(negativo) printf("-");
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
			if(auxp==11)
			printf("...");
		}
	}
}
