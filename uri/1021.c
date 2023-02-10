#include <stdio.h>

main()
{
	int num, cem=0, cinquenta=0, vinte=0, dez=0, cinco=0, dois=0, um=0, mcinquenta, mvintecinco, mdez, mcinco, moeda;
	
	scanf("%d.%d", &num, &moeda);
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
	
	mcinquenta = moeda/50;
	moeda -= mcinquenta*50;
	mvintecinco = moeda/25;
	moeda -= mvintecinco*25;
	mdez = moeda/10;
	moeda -= mdez*10;
	mcinco = moeda/5;
	moeda -= mcinco*5;
	
	printf("NOTAS:\n%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\nMOEDAS:\n%d moeda(s) de R$ 1.00\n", cem, cinquenta, vinte, dez, cinco, dois, um);
	
	printf("%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n", mcinquenta, mvintecinco, mdez, mcinco, moeda);
}

