#include <stdio.h>
main()
{
 int i;
 printf("digite sua idade: ");
 scanf("%d", &i);
 printf("vc eh um(a): ");
 if(i<12)
 printf("crianca");
 else 
 {
 if (i<=18)
 printf("adolecente");
 else
 printf("adulto");
 }
 
}
