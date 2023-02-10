#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int e=0;

void regras();
char* alocar();
int prop(char*, int);
int conect(char);
int extra(char);
void tabela(char *, int);
int interpret(int, char, int);

main()
{ 
	int i, j, a=0, b=0, n=0;
	char *S;
	
	regras();
	
	S = alocar();
	
	for(i=0; S[i]!='\0'; i++)
	{
		
		if(S[i]=='\'' && (S[i-1]<'A'||S[i-1]>'Z'))
		{
			if(S[i-1]!=')' && S[i-1]!='\'')
			{
				printf("Erro na posicao %d. Use a Negacao depois de uma proposicao.\n", i+1);
				e++;
			}
		}

		if(S[i]=='('&&S[i+1]==')')
		{
			printf("Erro na posicao %d. parenteses vasios.\n", i+1);
			e++;
		}
		
		if(prop(S, i))
		{
			n++;
			if(prop(S, i+1))
			{
				printf("Erro na posicao %d. proposicao seguido de proposicao.\n", i+1);
				e++;
			}
		}	
			
		if(conect(S[i])&&conect(S[i+1]))
		{
			printf("Erro na posicao %d. conectivo seguido de conectivo.\n", i+1);
			e++;
		}	
		else if(!i&&conect(S[i]))
		{
			printf("Erro na posicao %d. conectivo sem proposicao anterior.\n", i+1);
			e++;
		}
			
		if (conect(S[i])&&!prop(S, i+1))
		{
			printf("Erro na posicao %d. conectivo sem proposicao posterior.\n", i+1);
			e++;	
		}
			
		if(!conect(S[i])&&!prop(S, i)&&!extra(S[i]))
		{
			printf("Erro na posicao %d. caractere invalido.\n", i+1);
			e++;
		}
	}
	
	if(e)
		printf("Formula Invalida. %d Erros.\n", e);
	else
		{
			printf("Formula Valida.\n");
			tabela(S, n);
		}
	
}

void regras()
{
	FILE *F;
	char c;
	
	F = fopen("regras.txt", "r");
	if(!F)
	{
		printf("Arquivo de regras faltando.\n");
	}
	
	c = fgetc(F);
	while(c!=EOF)
	{
		printf("%c", c);
		c = fgetc(F);
	}
}

char* alocar()
{
	int cont=0;
    char c, *P=NULL;
    
	printf("Entre com a proposicao: \n");
    scanf("%c", &c);

    while(c!='\n')
    {
        cont++;
        P = (char*) realloc(P, cont*sizeof(char));
        if(!P) {printf("erro na alocacao de memoria"); exit(01);}

        P[cont-1] = c;
		
        scanf("%c", &c);
    }
    
    cont++;
    P = (char*) realloc(P, cont*sizeof(char));
    if(!P) {printf("erro na alocacao de memoria"); exit(02);}
	P[cont-1] = '\0';
	
	return P;
}

int prop(char* S, int i)
{	
	if(extra(S[i]))
	{
		return prop(S, i+1);
	}

	if( S[i]>='A'&&S[i]<='Z' )
		return 1;
	else if( S[i]=='t'||S[i]=='f' )
	{
		return 2;
	}
	else if( S[i]>='a'&&S[i]<='z' )
	{
		printf("Erro na posicao %d. utilize letras maiusculas para a preposicao.\n", i+1);
		e++;
	}
	return 0;
}

int conect(char S)
{
	if(S=='&'||S=='|'||S=='>'||S=='=')
		return 1;

	return 0;
}

int extra(char S)
{
	if(S=='\''||S=='('||S==')')
		return 1;
	
	return 0;
}

void tabela(char *S, int n) 
{
	int **M, i, j=0, tam;

	tam = (int) pow(2, n);
	printf("\n tamanho = %d\n\n", tam);
	
	M = (int**) malloc(sizeof(int*)*tam);
	if(!M)
		exit(22);
		
	for(i=0; i< tam ; i++)
	{
		M[i] = (int*) calloc(sizeof(int), n);
		if(!M[i])
		exit(33);	
	}
	

	for(i=0; i < tam; i++)
	{
		for(j = 0; j < n; j++)
			M[i][j] = !!(i & (1 << j));
	}
	
	for(i=0; i < tam; i++)
	{
		if(!i)
		{
			printf(" | ");
			for(j=0; S[j] != '\0'; j++)
			{
				if(prop(S, j))
					printf("%c | ", S[j]);
			}
			printf(" | %c %c %c |\n", S[0], S[1], S[2]);
		}
		printf(" | ");
		for(j=0; j < n; j++)
		{
			printf("%d | ", M[i][j]);
		}
		printf(" | - %d - |\n", interpret(M[i][0], S[1], M[i][1]));
	}
	
}

int interpret(int a, char o, int b)
{
	if(o=='&')
		return a&&b;
	if(o=='|')
		return a||b;
	if(o=='>')
	{
		if(a&&!b)
			return 0;
		return 1;
	}
	if(o=='=')
	{
		if(a==b)
			return 1;
		return 0;
	}
}

