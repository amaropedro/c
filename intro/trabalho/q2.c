/* Quest�o 2694- Nessa quest�o preciso ler caracteres, que est�o sempre em uma mesma posi��o, dentro de uma string e depois somar-los, para isso decidi usar a fun��o sscanf para
ler esses valores da string e coloca-los em inteiros, para depois soma-los.
Decidi fazer isso dentro de uma fun��o chamada soma, que recebe uma string e retorna um inteiro. Para melhor portabilidade desse programa, optei por definir par�metros n, p1, p2 e p3,
respectivamente o tamanho da string e a posi��o dos numeros que se deseja somar. */

#include <stdio.h>
#define n 14
#define p1 2
#define p2 5
#define p3 11

int soma (char S[n]) /* recebe a string e retorna a soma*/
{
	int a,  b, c;
	sscanf(S+p1, "%d", &a); /* leio da posi��o p1 e coloco em a. Estou lendo dessa forma para ressaltar que o vetor se comporta como um ponteiro*/
	sscanf(S+p2, "%d", &b); /* leio da posi��o p2 e coloco em b*/
	sscanf(S+p3, "%d", &c); /* leio da posi��o p3 e coloco em c*/
	
	return (a+b+c); /* retorno a soma dos numeros*/
}


main()
{
	char S[n];
	int N;
	
	scanf("%d", &N); /* recebo o numero de intera��es*/
	
	while(N) /* enquanto esse numero � verdadeiro, fa�o: */
	{
		scanf("%s", S); /* leio a string*/
		printf("%d\n", soma(S)); /* imprimo o retorno a fun��o soma, passando-lhe o par�metro S*/
		N--; /* decremento N*/
	}
}
