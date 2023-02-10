/* Questão 1022- Nessa questão é preciso fazer operações com numeros racionais, para isso, decidi tratar o numerador e o divisor como números diferentes, cada um indo para uma
variável diferente, e como os numeros são fornecidos da forma a/b 'operador' c/d, é possível fazer o mesmo.
Começo lendo o numero de interações, depois leio cada um dos numeros e o operador. Para isso, utilizo as variáveis N1, D1, N2, D2, O e aux (respectivamente os numeradores, denominadores
a operação que se deseja realizar, e um auxiliar para receber a '/' de cada numero racional).
Basta então fazer um switch case para cada caso, fazendo a devida operação matemática para obter o resultado.
Então, para imprimir do jeito desejado, utilizo uma função que retorna o mdc de dois números, para então dividir o numerador e o denominador final por seu mdc, efetivamente
simplificando eles. OBS: essa questão está excedendo o tempo limite do uri, mas para mais de 1000 casos, ela está batendo com as saídas esperadas.*/

#include <stdio.h>
#include <math.h>

int mdc(int num1, int num2) /* função que recebe dois inteiros e retorna um inteiro*/
{
    int resto;
    do  /* enquanto o resto é diferente de 0*/
	{
        resto = num1 % num2; /* resto recebe o resto da divisão inteira entre os dois números*/
        num1 = num2; /* atualizo o num1 com antigo denominador*/
        num2 = resto; /* atualizo o num2 com o resto, para então dividir novamente num1*/
    } while(resto!=0);

    return abs(num1); /* retorno o modulo de num1, para caso tiver sido feita alguma operação com um numero negativo e outro positivo*/
}

main()
{
	long int n, N1, D1, N2, D2, Nf, Df, MDC;
	char aux, o;
	scanf("%d", &n); /* leio o número de interações*/
	while(n) /* enquanto n!=0*/
	{
		scanf("%d %[/] %d %[+-/*] %d %[/] %d", &N1, &aux, &D1, &o, &N2, &aux, &D2); /* leio todos os componentes do número racional separadamente, assim como o operador. Também uso
		um auxiliar para receber a '/' que virá entre todos os numeradores e denominadores.*/
		switch (o) /* dependendo do operador, faço um caso diferente*/
		{
			case '+':
				Nf=N1*D2 + N2*D1; 
				Df=D1*D2;
				MDC=mdc(Nf, Df); /* depois de calcular os denominadores, mando pra função e recebo o mdc de retorno*/
				printf("%d/%d = %d/%d\n", Nf, Df, Nf/MDC, Df/MDC); /* imprimo os denominadores antes e depois de simplifica-los*/
				break; /* saio do switch, antes de executar todos os outros casos*/
			case '-': /* o mesmo para os demais casos*/
				Nf=N1*D2 - N2*D1;
				Df=D1*D2;
				MDC=mdc(Nf, Df);
				printf("%d/%d = %d/%d\n", Nf, Df, Nf/MDC, Df/MDC);
				break;
			case '*':
				Nf=N1*N2;
				Df=D1*D2;
				MDC=mdc(Nf, Df);
				printf("%d/%d = %d/%d\n", Nf, Df, Nf/MDC, Df/MDC);
				break;
			case '/':
				Nf= N1*D2;
				Df= N2*D1;
				MDC=mdc(Nf, Df);
				printf("%d/%d = %d/%d\n", Nf, Df, Nf/MDC, Df/MDC);
				/* não preciso de break aqui, pois vai entrar no default e sair, mas colocando iria sair do mesmo jeito*/
			default: break;
		}
		n--; /* decremento n*/
	}
}
