#include <stdio.h>

void decod(char *S, int r);

main()
{
	int n, r;
	char S[51];
	FILE *f = fopen("file.txt", "w");
	
	scanf("%d", &n);
	do
	{
		setbuf(stdin,NULL);
		scanf("%50[^\n]", S);
		scanf("%d", &r);
		decod(S, r);
		fprintf(f, "%s\n", S);
		n--;
	}while(n);
}

void decod(char *S, int r)
{
	int i;
	for( ; *S!=0; *(S++))
	for(i=r;i;i--)
	{
		if(*S=='A')
		{
			*S='Z';
		}
		else
		*(S)-=1;
	}
}
