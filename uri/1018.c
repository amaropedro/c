#include <stdio.h>

main()
{
	int num, n, cem=0, cinquenta=0, vinte=0, dez=0, cinco=0, dois=0, um=0;
	
	scanf("%d", &num);
	n = num;
	cem = num/100;
	num -= cem*100;
	cinquenta = num/50;
	num -= cinquenta*50;
	vinte = num/20;
	num -= vinte*20;
	dez = num/10;
	num -= dez*10;
	cinco = num/5;
	num -= cinco*5;
	dois = num/2;
	num -= 2*dois;
	um = num;
	
	printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", n, cem, cinquenta, vinte, dez, cinco, dois, um);
}

