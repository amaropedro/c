/*Questão 1169- Outra questão que é relativamente simples, tendo apelas que tomar cuidado com o tamanho das variáveis e usar a função pow() da biblioteca math.h, mas decidi que
iria resolver ela por recursividade.
Primeiramente leio o número de interações desejados, depois leio a casa do tabuleiro que se deseja checar. Depois disso verifico se X=64, se for, irei dividir o retorno
da função, que me da a quantidade de trigo em uma determinada casa, por 6000 (pois um unsigned long long int vai até 2^63). Caso contrario, entro na função e divido por 12000.
Uma vez na função, checo se X=1, se for, eu retorno n, que é 2. Caso contrario, chamo a função novamente, decrementando x de antemão, e multiplico seu retorno por n.
Assim, efetivamente, estou multiplicando 2 x vezes, ou elevando 2 a x.*/

#include <stdio.h>

unsigned long long int quant(int x) /* função que recebe o número da casa do tabuleiro que se deseja checar e retorna a quantidade de trigo*/
{ 
	unsigned long long int n=2; /* declarando n=2 como unsigned long long int, para poder ter espaço suficiente na variável*/
	if(x==1) /* checo se x=1, se for, retorno n*/
	return n;
	else /* se não, multiplico o retorno da função, usando x decrementado, por n. Que por sua vez checa x novamente, e assim por diante...*/
	n*=quant(--x);
	return n; /* retorno a quantidade*/
}

main()
{
	int n, x;
	
	scanf("%d", &n); /* leio o número de interações*/
	while(n) /* enquanto n!=0*/
	{
		scanf("%d", &x); /* leio a casa que se deseja checar*/
		if(x==64) /* se for igual a 64, não haverá espaço na variável, então para lidar com isso, faço x receber 63...*/
		{
			x=63;
			printf("%lld kg\n", quant(x)/6000); /* e divido por um número duas vezes menor*/
		}
		else
		printf("%lld kg\n", quant(x)/12000); /* se não, chamo a função e divido por 12*1000 para ter o peso em kg*/
		n--; /* decremento n*/
	}
}
