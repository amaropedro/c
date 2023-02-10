/* Questão 1189- Essa é uma questão simples, então decidi fazer-la de um modo que funcionaria para qualquer matriz quadrada, bastando alterar o parâmetro n. A questão quer que, fornecido
S ou M, o programa faça as respectivas operações (soma e media) com a área a esquerda de uma matriz quadrada de ordem 12. O que seria a área a esquerda de uma matriz? É a área que está
abaixo da diagonal principal e acima da secundaria.
Para fazer isso eu leio um carácter para fazer switch case, depois de ler a matriz. Quando vou ler a matriz, aproveito para somar os numeros que estão abaixo da diagonal principal
(cujo numero de linha (i) é maior que o numero da coluna (j)) e ao mesmo tempo estão acima da secundaria (cuja soma de i e j seja menor que a ordem da matriz).
Depois é só imprimir de acordo com o caso.*/

#include <stdio.h>
#define n 12 /* defino o tamanho da matriz*/
main()
{
	int i, j, aux=0;
	float M[n][n], soma=0;
	char O;
	scanf("%c", &O); /* leio o caractere que define a operação*/
	for(i=0; i<n; i++) /* para cada linha...*/
	{
		for(j=0; j<n; j++) /* preencho todas as colunas*/
		{
			scanf("%f", &M[i][j]);	/* leio a matriz*/
			if(i>j&&i+j<n-1) /* se estão na área a esquerda como explicado no primeiro comentário, apenas tomando cuidado para subtrair 1 de n, pois os indices em c começam em 0*/
			{
				soma+=M[i][j]; /* somo o elemento*/
				aux++; /* incremento a quantidade de elementos somados para poder calcular a media*/
			}
		}
	}
	
	switch (O) /* de acordo com o que foi lido*/
	{
	case 'S': printf("%.1f\n", soma); /* apresento a soma*/
	break; /* saio do switch para não realizar o próximo caso*/
	case 'M': printf("%.1f\n", soma/aux); /* ou a media*/
	/* não preciso de break aqui, pois vai entrar no default e sair, mas colocando iria sair do mesmo jeito*/
	default: break;
	}
}

