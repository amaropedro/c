#include <stdio.h>
#include <string.h>
#include <math.h>

main()
{
	char S[1001];
	int i;
	unsigned long int exp;
	double aux, saida;
	
	while(scanf("%s", S)!=EOF)
	{
		saida=0;
		
		exp = strlen(S)-1; printf("exp = %ld\n", exp);
		
		for(i=0; S[i]!='\0'; i++)
		{
			saida += fmod((S[i] - 'A')*pow(26, exp-i), 1000000007);
		}
		printf("%.0lf\n", saida);
	}
	
}

/*

for(i=0; V[i]!=-1; i++)
		{
			printf("V[%d] = %d\n", i, V[i]);
		}

#include <stdio.h>
int N;

void intochar(char *S)
{
	int i, j;
	N=0;
	for(i=0; S[i]!='\0'; i++)
	{
		for(j=0; j<26; j++)
		{
			if(S[i] == 'A'+j)
			N += j;
		}
	}
	
}

main()
{
	char S[1001];
	int i;
	
	while(scanf("%s", S)!=EOF)
	{
		intochar(S);
		printf("%d\n", N);
		N=0;
	}
	
}*/
