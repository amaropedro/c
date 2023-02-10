#include <stdio.h>
main()
{ 
unsigned char x, d, y=1;
printf("insira um valor que esteja no intervalo [0,255]: ");
scanf("%c", &x);
printf("insira o byte que deseja saber valor[0,7]: ");
scanf("%d", &d);
y=y<<d;
x=x&y;
x=x>>d;
printf("valor do byte: %d", x);
}
