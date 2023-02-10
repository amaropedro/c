/* Questão 2108- Essa questão parece relativamente simples a primeira vista, é só contar quantas letras tem em cada palavra e depois dizer qual delas é a maior. Mas como diferenciar
as palavras e as frases? Bem, cada palavra é separada por um espaço e cada frase está em uma linha, mas novamente, como fazer isso em c? A ideia inicial foi colocar um scanf dentro de
um laço, assim ele pode ser usada repetidamente para ler as strings. Devido ao buffer do teclado, a string receberia a primeira palavra, seu tamanho é armazenado em um vetor, e então
a mesma string pode receber a próxima palavra na interação seguinte.
Mas ainda há a necessidade de diferenciar uma frase da outra, então decidi ler, também, um caractere e checar se ele recebeu nova linha (ou 10 pela tabela ascII), e se for o caso,
sair do laço. O caractere também acaba recebendo os espaços, o que não é necessario pois a string não iria receber eles de toda forma, mas como é preciso ler o new line, o caractere
ainda exerce uma função própria, e um pouco mais.
Dentro desse mesmo laço, eu aproveito para checar pela maior palavra, e também se a string leu 0 (ou 48 pela tabela ascII), pois se for o caso, o programa deve imprimir a maior palavra
e finalizar.
Saindo do laço o próximo desafio foi imprimir da forma desejada, para isso decidi usar um vetor de tamanho 51, pois cada linha pode conter no máximo 100 caracteres, então o pior caso
seria um caractere, um espaço, outro caractere, e assim por diante até ter 50 caracteres e 50 espaços. Mas porquê 51? Bem, no começo de toda linha eu limpo o vetor e coloco 0 em suas
posições, assim consigo checar se a proxima proxima posição (T[i+1]) é verdadeira ou falsa, se for verdadeira ele irar imprimir da forma X-, onde X é o tamanho da string previamente
armazenado nessa posição, e consequentemente um numero>0, caso contraio a próxima posição é 0, pois nenhum tamanho foi armazenado lá, então será imprimido no formato X. 
Como preciso fazer isso para todas as linhas, coloquei tudo dentro de um laço maior.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main()
{
	char S[101], Maior[101], aux;
	int n=1, i, T[51], *p, maior=0, b=0;
	
	p=&T[0]; /* salvo a posição inicial de T em p, podendo assim usa-lo para limpar o vetor, e melhor trabalhando o que foi dado na disciplina*/
	
	do /* repetir, entrando pelo menos uma vez*/
	{
	for(i=0; i<51;*(p+i)=0, i++); /* colocando 0 em todas as posições do vetor utilizando ponteiros*/
	i=0;
	do /* repetir enquanto aux não for igual a 10, correspondente a quebra de linha '\n'*/
	{
		scanf("%100s%c", S, &aux); /* lendo uma string com no máximo 100 caracteres, deixando um vago para o \0. e lendo um auxiliar, que vai receber espaço ou enter*/

		if(S[0]==48) /* se a string na primeira posição conter 0, fim de programa*/
		{
			printf("\nThe biggest word: %s\n", Maior); /*imprime a maior palavra antes de finalizar*/
			exit(0); /* poderia ser return 0*/
		}
		
		T[i]=strlen(S); /*salvo o tamanho da string lida em uma posição do vetor determinada por i*/
		
		if(strlen(S)>=maior) /* checo  se a palavra lida é maior que a maior palavra lida anteriormente, onde maior começa com 0*/
			{
				maior=strlen(S); /* atualizo maior*/
				strcpy(Maior, S);	/* copio a string S para a string Maior*/
			}
		i++; /* incremento i para poder salvar a próxima palavra na próxima posição*/
	}while(aux!=10);
	
	for(i=0;T[i];i++) 
	{
		if(T[i+1]) /* checo se a próxima posição é verdadeira, como dito no comentário de inicio*/
		printf("%d-", T[i]); /* imprimindo assim se tiver um numero salvo na posição seguinte*/
		else printf("%d\n", T[i]); /* ou assim se for o ultimo*/
	}
	}while(n); /* repito para todas as linhas, com uma variável que eu posso garantir que não é nula*/
}
