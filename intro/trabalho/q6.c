/*Quest�o 1169- Outra quest�o que � relativamente simples, tendo apelas que tomar cuidado com o tamanho das vari�veis e usar a fun��o pow() da biblioteca math.h, mas decidi que
iria resolver ela por recursividade.
Primeiramente leio o n�mero de intera��es desejados, depois leio a casa do tabuleiro que se deseja checar. Depois disso verifico se X=64, se for, irei dividir o retorno
da fun��o, que me da a quantidade de trigo em uma determinada casa, por 6000 (pois um unsigned long long int vai at� 2^63). Caso contrario, entro na fun��o e divido por 12000.
Uma vez na fun��o, checo se X=1, se for, eu retorno n, que � 2. Caso contrario, chamo a fun��o novamente, decrementando x de antem�o, e multiplico seu retorno por n.
Assim, efetivamente, estou multiplicando 2 x vezes, ou elevando 2 a x.*/

#include <stdio.h>

unsigned long long int quant(int x) /* fun��o que recebe o n�mero da casa do tabuleiro que se deseja checar e retorna a quantidade de trigo*/
{ 
	unsigned long long int n=2; /* declarando n=2 como unsigned long long int, para poder ter espa�o suficiente na vari�vel*/
	if(x==1) /* checo se x=1, se for, retorno n*/
	return n;
	else /* se n�o, multiplico o retorno da fun��o, usando x decrementado, por n. Que por sua vez checa x novamente, e assim por diante...*/
	n*=quant(--x);
	return n; /* retorno a quantidade*/
}

main()
{
	int n, x;
	
	scanf("%d", &n); /* leio o n�mero de intera��es*/
	while(n) /* enquanto n!=0*/
	{
		scanf("%d", &x); /* leio a casa que se deseja checar*/
		if(x==64) /* se for igual a 64, n�o haver� espa�o na vari�vel, ent�o para lidar com isso, fa�o x receber 63...*/
		{
			x=63;
			printf("%lld kg\n", quant(x)/6000); /* e divido por um n�mero duas vezes menor*/
		}
		else
		printf("%lld kg\n", quant(x)/12000); /* se n�o, chamo a fun��o e divido por 12*1000 para ter o peso em kg*/
		n--; /* decremento n*/
	}
}
