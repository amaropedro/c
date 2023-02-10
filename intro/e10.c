#include <stdio.h>
main()
{ int a,b,x,y;
   printf("digite um valor para a: ");
   scanf("%d", &a);
   printf("digite um valor para b: ");
   scanf("%d", &b);
   printf("digite: \n1-para a+b \n2-para a-b \n3-para a*b \n4-para a/b \noperacao desejada: ");
   scanf("%d", &x);
   switch(x)
   {
   case 1: 
      y=a+b;
      break; 
   case 2: 
      y=a-b;
      break;
   case 3: 
      y=a*b;
      break;
   case 4: 
      y=a/b;
      break;
   default: printf("operacao desejada nao listada");
   }   
   printf("resultado: %d", y);
}
   
