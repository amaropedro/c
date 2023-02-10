#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int mdc(int num1, int num2) /* função que recebe dois inteiros e retorna um inteiro*/
{
    int resto;
    do  /* enquanto o resto é difernte de 0*/
	{
        resto = num1 % num2; /* resto recebe o resto da divisão inteira entre os dois numeros*/
        num1 = num2; /* atualizo o num1*/
        num2 = resto; /* atualizo o num2 com o resto*/
    } while(resto!=0);

    return abs(num1); /* retorno o modulo de num1, para caso tiver sido feita alguma operação com um numero negativo e outro positivo*/
}

main()
{
	long int n, N1, D1, N2, D2, Nf, Df, MDC;
	char aux, o;
	FILE *f = fopen("file.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	scanf("%d", &n);
	while(n)
	{
		scanf("%d %[/] %d %[+-/*] %d %[/] %d", &N1, &aux, &D1, &o, &N2, &aux, &D2); 
		switch (o)
		{
			case '+':
				Nf=N1*D2 + N2*D1; 
				Df=D1*D2;
				MDC=mdc(Nf, Df);
				fprintf(f, "%d/%d = %d/%d\n", Nf, Df, Nf/MDC, Df/MDC);
				break;
			case '-':
				Nf=N1*D2 - N2*D1;
				Df=D1*D2;
				MDC=mdc(Nf, Df);
				fprintf(f, "%d/%d = %d/%d\n", Nf, Df, Nf/MDC, Df/MDC);
				break;
			case '*':
				Nf=N1*N2;
				Df=D1*D2;
				MDC=mdc(Nf, Df);
				fprintf(f, "%d/%d = %d/%d\n", Nf, Df, Nf/MDC, Df/MDC);
				break;
			case '/':
				Nf= N1*D2;
				Df= N2*D1;
				MDC=mdc(Nf, Df);
				fprintf(f, "%d/%d = %d/%d\n", Nf, Df, Nf/MDC, Df/MDC);
				break;
			default: break;
		}
		n--;
	}
}
