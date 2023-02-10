#include <stdio.h>
#include <stdlib.h>

void regras();
char* alocar();
/* lembrar de utilizar uma copia de S para verificar os parenteses e trocar '(' por '1' quando for verificar o caso B ou checar isso em outro for pra evitar possivris erros com a troca*/
main()
{ 
	int i;
	char *S;
	
	regras();
	
	S = alocar();
	
	for(i=0; S[i]!='\0'; i++)
	{
		
		/* caso erro negação */
		if(S[i]=='\'' && (S[i-1]<'A'||S[i-1]>'Z'))
			if(S[i-1]!=')' && S[i-1]!='\'')
				printf("Erro na posicao %d. Use a Negacao depois de uma proposicao.\n", i+1);
				
		/* caso implicando em nada*/
		if(S[i]=='>' && (S[i+1]<'A'||S[i+1]>'Z'))
			if(S[i+1]!='(' || S[i+1]=='\0')
				printf("Erro na posicao %d. Implicando em nada.\n", i+1);
				
		/* caso implicação sem causa*/
		if(S[i]=='>' && (S[i-1]<'A'||S[i-1]>'Z'))
			if(S[i-1]!=')')
				printf("Erro na posicao %d. Implicacao sem causa.\n", i+1);
		
		/* caso parenteses não fechados caso A*/
		if(S[i]=='(')
		{
			int j, t=1;
			
			for(j=i; S[j]!='\0'; j++)
			{
				if(S[j]==')')
				{
					t=0;
					break;
				}
			}
			
			if(t)
				printf("Erro na posicao %d. Parenteses nao fechados A.\n", i+1);
		}
		
		/* caso parenteses não fechados caso B*/
		if(S[i]==')')
		{
			int j, t=1;
			
			for(j=i; j>=0; j--)
			{
				if(S[j]=='(')
				{
					t=0;
					break;
				}
			}
			
			if(t)
				printf("Erro na posicao %d. Parenteses nao fechados B.\n", i+1);
		}
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
