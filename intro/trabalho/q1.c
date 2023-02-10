/* Quest�o 2108- Essa quest�o parece relativamente simples a primeira vista, � s� contar quantas letras tem em cada palavra e depois dizer qual delas � a maior. Mas como diferenciar
as palavras e as frases? Bem, cada palavra � separada por um espa�o e cada frase est� em uma linha, mas novamente, como fazer isso em c? A ideia inicial foi colocar um scanf dentro de
um la�o, assim ele pode ser usada repetidamente para ler as strings. Devido ao buffer do teclado, a string receberia a primeira palavra, seu tamanho � armazenado em um vetor, e ent�o
a mesma string pode receber a pr�xima palavra na intera��o seguinte.
Mas ainda h� a necessidade de diferenciar uma frase da outra, ent�o decidi ler, tamb�m, um caractere e checar se ele recebeu nova linha (ou 10 pela tabela ascII), e se for o caso,
sair do la�o. O caractere tamb�m acaba recebendo os espa�os, o que n�o � necessario pois a string n�o iria receber eles de toda forma, mas como � preciso ler o new line, o caractere
ainda exerce uma fun��o pr�pria, e um pouco mais.
Dentro desse mesmo la�o, eu aproveito para checar pela maior palavra, e tamb�m se a string leu 0 (ou 48 pela tabela ascII), pois se for o caso, o programa deve imprimir a maior palavra
e finalizar.
Saindo do la�o o pr�ximo desafio foi imprimir da forma desejada, para isso decidi usar um vetor de tamanho 51, pois cada linha pode conter no m�ximo 100 caracteres, ent�o o pior caso
seria um caractere, um espa�o, outro caractere, e assim por diante at� ter 50 caracteres e 50 espa�os. Mas porqu� 51? Bem, no come�o de toda linha eu limpo o vetor e coloco 0 em suas
posi��es, assim consigo checar se a proxima proxima posi��o (T[i+1]) � verdadeira ou falsa, se for verdadeira ele irar imprimir da forma X-, onde X � o tamanho da string previamente
armazenado nessa posi��o, e consequentemente um numero>0, caso contraio a pr�xima posi��o � 0, pois nenhum tamanho foi armazenado l�, ent�o ser� imprimido no formato X. 
Como preciso fazer isso para todas as linhas, coloquei tudo dentro de um la�o maior.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main()
{
	char S[101], Maior[101], aux;
	int n=1, i, T[51], *p, maior=0, b=0;
	
	p=&T[0]; /* salvo a posi��o inicial de T em p, podendo assim usa-lo para limpar o vetor, e melhor trabalhando o que foi dado na disciplina*/
	
	do /* repetir, entrando pelo menos uma vez*/
	{
	for(i=0; i<51;*(p+i)=0, i++); /* colocando 0 em todas as posi��es do vetor utilizando ponteiros*/
	i=0;
	do /* repetir enquanto aux n�o for igual a 10, correspondente a quebra de linha '\n'*/
	{
		scanf("%100s%c", S, &aux); /* lendo uma string com no m�ximo 100 caracteres, deixando um vago para o \0. e lendo um auxiliar, que vai receber espa�o ou enter*/

		if(S[0]==48) /* se a string na primeira posi��o conter 0, fim de programa*/
		{
			printf("\nThe biggest word: %s\n", Maior); /*imprime a maior palavra antes de finalizar*/
			exit(0); /* poderia ser return 0*/
		}
		
		T[i]=strlen(S); /*salvo o tamanho da string lida em uma posi��o do vetor determinada por i*/
		
		if(strlen(S)>=maior) /* checo  se a palavra lida � maior que a maior palavra lida anteriormente, onde maior come�a com 0*/
			{
				maior=strlen(S); /* atualizo maior*/
				strcpy(Maior, S);	/* copio a string S para a string Maior*/
			}
		i++; /* incremento i para poder salvar a pr�xima palavra na pr�xima posi��o*/
	}while(aux!=10);
	
	for(i=0;T[i];i++) 
	{
		if(T[i+1]) /* checo se a pr�xima posi��o � verdadeira, como dito no coment�rio de inicio*/
		printf("%d-", T[i]); /* imprimindo assim se tiver um numero salvo na posi��o seguinte*/
		else printf("%d\n", T[i]); /* ou assim se for o ultimo*/
	}
	}while(n); /* repito para todas as linhas, com uma vari�vel que eu posso garantir que n�o � nula*/
}
