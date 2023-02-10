#include <stdio.h>
main ()
{
   int n, d, a=1;
   printf("digite um numero que pertenca ao intervalo [0, 255]: ");
   scanf("%d", &n);
   if(n<0||n>255)
      { printf("numero nao pertence ao intervalo");}
      else 
      { printf("digite o bit que deseja verificar [0,7]: ");
        scanf("%d", &d); 
   if(d<0||d>7) {printf("numero nao pertence ao intervalo");} 
   else 
      { a=a<<d;
        n=n&a;
        n=n>>d; 
        if(n==1) printf("bit ativo");
        else printf("bit nao ativo");} }
}