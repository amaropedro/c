/* Questão 2694- Nessa questão preciso ler caracteres, que estão sempre em uma mesma posição, dentro de uma string e depois somar-los, para isso decidi usar a função sscanf para
ler esses valores da string e coloca-los em inteiros, para depois soma-los.
Decidi fazer isso dentro de uma função chamada soma, que recebe uma string e retorna um inteiro. Para melhor portabilidade desse programa, optei por definir parâmetros n, p1, p2 e p3,
respectivamente o tamanho da string e a posição dos numeros que se deseja somar. */

#include <stdio.h>
#define n 14
#define p1 2
#define p2 5
#define p3 11

int soma (char S[n]) /* recebe a string e retorna a soma*/
{
	int a,  b, c;
	sscanf(S+p1, "%d", &a); /* leio da posição p1 e coloco em a. Estou lendo dessa forma para ressaltar que o vetor se comporta como um ponteiro*/
	sscanf(S+p2, "%d", &b); /* leio da posição p2 e coloco em b*/
	sscanf(S+p3, "%d", &c); /* leio da posição p3 e coloco em c*/
	
	return (a+b+c); /* retorno a soma dos numeros*/
}


main()
{
	char S[n];
	int N;
	
	scanf("%d", &N); /* recebo o numero de interações*/
	
	while(N) /* enquanto esse numero é verdadeiro, faço: */
	{
		scanf("%s", S); /* leio a string*/
		printf("%d\n", soma(S)); /* imprimo o retorno a função soma, passando-lhe o parâmetro S*/
		N--; /* decremento N*/
	}
}
