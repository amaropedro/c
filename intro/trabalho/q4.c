/*Questão 1253-  Nessa questão o programa tem que ler o numero de interações, seguido por um string e o numero de rotações para direita que serão aplicados nessa string.
Então decidi criar uma função de decodificação que será chamada antes de imprimir a string decodificada. Para isso, paço o endereço inicial da string para a função (para poder
trabalhar mais os conteúdos dados em sala), permitindo que eu altere seu conteúdo pelo endereço.
Uma vez na função, para cada letra de uma palavra, utilizando dois laços como em uma matriz, um contador recebe o numero de rotações, para todas as letras que não são 'A', ele subtrai 1
da letra, tornando ela a letra anterior pela tabela ascII, para 'A' faço com que ela receba 'Z', pois 'A-1' = @ pela mesma tabela. depois disso decremento o contador, tal que quando
ele chegue a 0, saia do laço, passando assim para a próxima letra.
OBS: a função setbuf(stdin,NULL), que limpa o buffer do teclado, consome bastante tempo, excedendo o tempo da solução, então decidi usar um "jeitinho" ao invés.*/


#include <stdio.h>

void decod(char *S, int r); /* prototipo da função que decodifica*/

main()
{
	int n, r;
	char S[51], aux;
	
	scanf("%d", &n); /* leitura do número de interações*/
	while(n) /* enquanto n é verdadeiro, ou seja, diferente de 0*/
	{
		scanf("%c%50[^\n]", &aux, S); /* como dito na OBS, estou usando um caractere para receber o enter ao invés de usar setbuf, para não exceder o tempo no uri*/
		scanf("%d", &r); /* leio o número de giros para direita*/
		decod(S, r); /* chamo a função que decodifica, passando para ela o endereço de S e o número de giros*/
		printf("%s\n", S); /* imprimo a função já decodificada*/
		n--; /* decremento o número de interações*/
	}
}

void decod(char *S, int r)
{
	int i;
	for( ; *S!=0; *(S++)) /* para cada palavra*/
	for(i=r;i;i--) /* para cada letra*/
	{
		if(*S=='A') /* verifico se o que S aponta é igual a 'A', se sim, o que S aponta recebe 'Z'*/
		{
			*S='Z'; 
		}
		else /* se não, o que S aponta é decrementado em uma unidade*/
		*(S)-=1;
	}
}
