#include <stdio.h>
main()
{ 
float a, b;
printf("digite um valor real maior que zero: ");
scanf("%f", &a);
printf("digite um outro valor real maior que zero: ");
scanf("%f", &b);
printf("percentual do maior valor que o menor valor representa: %.2f%%", a>b?100*(b/a):100*(a/b)); 
/* 
a--100%
b--x
ax=100*b
x=100*(b/a)

ou

b--100
a--x
bx=100a
x=100*(a/b)
*/
}
