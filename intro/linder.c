#include <stdio.h>
main ()
{
unsigned char desloca, valor_byte, aux=1;
printf("\nDigite um numero pertencente ao intervalo [0,255]: ");
scanf("%d", &valor_byte);
printf("\nDigite o bit a testar(0 a 7): ");
scanf("%d", &desloca);
aux = aux << desloca;
valor_byte = valor_byte & aux;
valor_byte = valor_byte >> desloca;
printf("\nO valor do bit eh %d",valor_byte);
}
