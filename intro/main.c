#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
float f;
char c;
printf("entre com um real: ");
scanf("%f", &f);
printf("entre com um caractere: ");
setbuf(stdin, NULL); /*para limpar o buffer*/
scanf("%c", &c);
printf("\n|%c|%d\n",c,c);


}

