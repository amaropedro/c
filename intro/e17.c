#include <stdio.h>
#include <math.h>
main()
{
	int n, aux;
	printf("digite uma sequencia de numeros, digite 0 para parar: ");
	do
	{ 
	scanf("%d", &n);
	if(n==0) break;
	aux=(int) (sqrt(n)*10);
	if(aux%10==0)
	printf("%d eh um quadrado perfeito\n", n);
	else
	printf("%d nao eh um quadrado perfeito\n", n);	
	}while(n);
}
