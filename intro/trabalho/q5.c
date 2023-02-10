/* Quest�o 1022- Nessa quest�o � preciso fazer opera��es com numeros racionais, para isso, decidi tratar o numerador e o divisor como n�meros diferentes, cada um indo para uma
vari�vel diferente, e como os numeros s�o fornecidos da forma a/b 'operador' c/d, � poss�vel fazer o mesmo.
Come�o lendo o numero de intera��es, depois leio cada um dos numeros e o operador. Para isso, utilizo as vari�veis N1, D1, N2, D2, O e aux (respectivamente os numeradores, denominadores
a opera��o que se deseja realizar, e um auxiliar para receber a '/' de cada numero racional).
Basta ent�o fazer um switch case para cada caso, fazendo a devida opera��o matem�tica para obter o resultado.
Ent�o, para imprimir do jeito desejado, utilizo uma fun��o que retorna o mdc de dois n�meros, para ent�o dividir o numerador e o denominador final por seu mdc, efetivamente
simplificando eles. OBS: essa quest�o est� excedendo o tempo limite do uri, mas para mais de 1000 casos, ela est� batendo com as sa�das esperadas.*/

#include <stdio.h>
#include <math.h>

int mdc(int num1, int num2) /* fun��o que recebe dois inteiros e retorna um inteiro*/
{
    int resto;
    do  /* enquanto o resto � diferente de 0*/
	{
        resto = num1 % num2; /* resto recebe o resto da divis�o inteira entre os dois n�meros*/
        num1 = num2; /* atualizo o num1 com antigo denominador*/
        num2 = resto; /* atualizo o num2 com o resto, para ent�o dividir novamente num1*/
    } while(resto!=0);

    return abs(num1); /* retorno o modulo de num1, para caso tiver sido feita alguma opera��o com um numero negativo e outro positivo*/
}

main()
{
	long int n, N1, D1, N2, D2, Nf, Df, MDC;
	char aux, o;
	scanf("%d", &n); /* leio o n�mero de intera��es*/
	while(n) /* enquanto n!=0*/
	{
		scanf("%d %[/] %d %[+-/*] %d %[/] %d", &N1, &aux, &D1, &o, &N2, &aux, &D2); /* leio todos os componentes do n�mero racional separadamente, assim como o operador. Tamb�m uso
		um auxiliar para receber a '/' que vir� entre todos os numeradores e denominadores.*/
		switch (o) /* dependendo do operador, fa�o um caso diferente*/
		{
			case '+':
				Nf=N1*D2 + N2*D1; 
				Df=D1*D2;
				MDC=mdc(Nf, Df); /* depois de calcular os denominadores, mando pra fun��o e recebo o mdc de retorno*/
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
				/* n�o preciso de break aqui, pois vai entrar no default e sair, mas colocando iria sair do mesmo jeito*/
			default: break;
		}
		n--; /* decremento n*/
	}
}
