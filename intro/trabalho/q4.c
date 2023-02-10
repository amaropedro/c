/*Quest�o 1253-  Nessa quest�o o programa tem que ler o numero de intera��es, seguido por um string e o numero de rota��es para direita que ser�o aplicados nessa string.
Ent�o decidi criar uma fun��o de decodifica��o que ser� chamada antes de imprimir a string decodificada. Para isso, pa�o o endere�o inicial da string para a fun��o (para poder
trabalhar mais os conte�dos dados em sala), permitindo que eu altere seu conte�do pelo endere�o.
Uma vez na fun��o, para cada letra de uma palavra, utilizando dois la�os como em uma matriz, um contador recebe o numero de rota��es, para todas as letras que n�o s�o 'A', ele subtrai 1
da letra, tornando ela a letra anterior pela tabela ascII, para 'A' fa�o com que ela receba 'Z', pois 'A-1' = @ pela mesma tabela. depois disso decremento o contador, tal que quando
ele chegue a 0, saia do la�o, passando assim para a pr�xima letra.
OBS: a fun��o setbuf(stdin,NULL), que limpa o buffer do teclado, consome bastante tempo, excedendo o tempo da solu��o, ent�o decidi usar um "jeitinho" ao inv�s.*/


#include <stdio.h>

void decod(char *S, int r); /* prototipo da fun��o que decodifica*/

main()
{
	int n, r;
	char S[51], aux;
	
	scanf("%d", &n); /* leitura do n�mero de intera��es*/
	while(n) /* enquanto n � verdadeiro, ou seja, diferente de 0*/
	{
		scanf("%c%50[^\n]", &aux, S); /* como dito na OBS, estou usando um caractere para receber o enter ao inv�s de usar setbuf, para n�o exceder o tempo no uri*/
		scanf("%d", &r); /* leio o n�mero de giros para direita*/
		decod(S, r); /* chamo a fun��o que decodifica, passando para ela o endere�o de S e o n�mero de giros*/
		printf("%s\n", S); /* imprimo a fun��o j� decodificada*/
		n--; /* decremento o n�mero de intera��es*/
	}
}

void decod(char *S, int r)
{
	int i;
	for( ; *S!=0; *(S++)) /* para cada palavra*/
	for(i=r;i;i--) /* para cada letra*/
	{
		if(*S=='A') /* verifico se o que S aponta � igual a 'A', se sim, o que S aponta recebe 'Z'*/
		{
			*S='Z'; 
		}
		else /* se n�o, o que S aponta � decrementado em uma unidade*/
		*(S)-=1;
	}
}
