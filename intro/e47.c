#include <stdio.h>
#include <stdlib.h>
void putStrInFile (FILE *, char*);

int main()
{
	FILE *fp;
	char string[100];
	int i;
	fp = fopen("arquivo.txt","w");
	if(!fp)
	{
		printf( "Erro na abertura do arquivo");
		exit(1);
	}
	
	printf("Entre com a string a ser gravada no arquivo:");
	scanf("%99[^\n]", string);
	putStrInFile(fp, string);
	fclose(fp);
	return 0;
}

void putStrInFile (FILE *fp, char* string)
{
int i;
for(i=0; string[i]; i++)
putc(string[i], fp); /*Não testei se o caractere foi escrito
com sucesso.*/
}
