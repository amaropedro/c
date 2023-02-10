#include <stdio.h>
#include <string.h>

main()
{
	FILE *f;
	f = fopen("arquivo.txt", "r");
	if(!f)
	{
		printf("erro\n");
		return 1;
	}
	 
	while(!feof(f))
	{
		printf("%c", (char)getc(f));
	}
}

	/*do
	{
		S[0+i]=getc(f);
		printf("string= %s\n", S);
		i++;
	}while(i,20); */
	
	/* 	for(i=0; i<50; i++)
	{
		S[i]=getc(f);
		if(S[i]==EOF)
		{
			printf("i=%d end of file\n", i);
			S[i]=0;
			printf("string final= %s\ne seu tamanho= %d\n", S, strlen(S));
			return 0;
		}
	}*/
	
	/* 	for(i=0; getc(f)!=EOF&&i<150; i++)
	{
		S[i]=getc(f);
	}
	S[i]=0;*/
