#include <stdio.h>
#include <math.h> /*lembrar de perguntar como representar um numero elevado a outro*/
main ()
{ 
double x; /*recebe x e soma a 3*/
printf("atribua um valor real para x: ");
scanf("%lf", &x);
x+=3; /*soma 3 a x*/
x=pow(x,3); /* eleva (x+3) ao cubo*/
x*=5; /*multiplica (x+3)^3 por 5 */
printf("resultado: %.2lf", sqrt(x)); /*calcula a raiz de ((x+3)^3 * 5) e exibe ao usuario*/
}
