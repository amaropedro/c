#include <stdio.h>
#define n 10
#define tonibus 44

typedef struct
{
	int npassagem;
	char nome[50];
	char sexo;
}passagem;

typedef struct
{
	char de[50];
	char para[50];
	float hora, min;
	float dist;
	int dia, mes, ano;
	passagem p[tonibus];
}onibus;

typedef onibus nonibus[n];

main()
{
	nonibus o;
	int opi, i, j, cont, L[n], dia, min, l=0;
	float hc, temp, M[n], F[n];
	
	for(i=0; i<n; i++) /* limpa vetor e passagens*/
	L[i]=0; M[i]=0; F[i]=0; o[i].dist=0;

	
	while(1)
	{
		printf("\ndigite:\n 1- para ler uma passagem\n 2- para conferir uma passagem\n 3- para sair\n"); scanf("%d", &opi);
	
		switch(opi)
		{
			case 1:
				do
				{
						printf("digite o numero do onibus desejado (-1 para parar): \n"); scanf("%d", &i);
						if(i!=-1)
						{
							if(!i||!o[i].dist)
							{
								setbuf(stdin,NULL); printf("digite o local de partida: \n"); scanf("%50[^\n]", o[i].de);
								setbuf(stdin,NULL); printf("digite o destino: \n"); scanf("%50[^\n]", o[i].para);
								printf("digite a hora de partida, depois os minutos: \n"); scanf("%f %f", &o[i].hora, &o[i].min);
								printf("digite a distancia em km: \n"); scanf("%f", &o[i].dist);
								printf("digite o dia, mes e ano: \n"); scanf("%d %d %d", &o[i].dia, &o[i].mes, &o[i].ano); setbuf(stdin,NULL);
							}else printf("onibus ja cadastrado \n");
							
							do
							{
								printf("digite o numero da poltrona desejada (-1 para parar): \n"); scanf("%d", &j);
								if(j!=-1)
								{
									printf("digite o numero da passagem: \n"); scanf("%d", &o[i].p[j].npassagem);
									setbuf(stdin,NULL); printf("digite seu nome: \n"); scanf("%50[^\n]", o[i].p[j].nome);
									setbuf(stdin,NULL); printf("digite seu sexo: \n"); scanf("%[MF]", &o[i].p[j].sexo); if(o[i].p[j].sexo=='M') M[i]++; else F[i]++; setbuf(stdin,NULL);
									l++;
								}
							}while(j!=-1);
							if(l==tonibus) L[i]=1;
						} 
				}while(i!=-1);
				break;
			case 2:
				do
				{
					printf("digite o numero do onibus que deseja checar (-1 para parar): \n"); scanf("%d", &i);
					if(i!=-1)
					{
						printf("horario de saida: %.0fh%.0f\ndistancia percorrida: %.0fkm\n", o[i].hora, o[i].min, o[i].dist);
						printf("onibus vai de: %s\npara: %s\n", o[i].de, o[i].para);
						printf("na data: %d/%d/%d\n", o[i].dia, o[i].mes, o[i].ano);
						dia=o[i].dia;
						temp=o[i].dist/60;
						hc=o[i].hora+(o[i].min/60)+temp;
						for(; hc>24; hc-=24, dia++);
						printf("duracao da viagem: %.1fh\n", temp);
						printf("previsao de chegada: %.2fh do dia %d/%d/%d\n", hc, dia, o[i].mes, o[i].ano);
						if(L[i]) printf("onibus lotado\n"); else printf("onibus nao lotado\n");
						printf("porcentagem de ocupacao: %.2f%%\npoltronas livres: %d de %d\n", ((float)l/tonibus)*100, tonibus-l, tonibus);
						printf("porcentagem de passageiros do sexo masculino: %.2f%%\nporcentagem de passageiros do sexo feminino: %.2f%%\n", 100*(M[i]/l), 100*(F[i]/l));
					}
				}while(i!=-1);
				
			default: printf("\nfim do programa\n"); return 0; 
		}	
	}	
}
