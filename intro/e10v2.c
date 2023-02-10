#include <stdio.h>
main()
{ int a,b,y;
   char x;
   printf("digite um valor para a: ");
   scanf("%d", &a);
   printf("digite um valor para b: ");
   scanf("%d", &b);
   printf("digite: \n+ para a+b \n- para a-b \n* para a*b \n/ para a/b \noperacao desejada: ");
   fflush(stdin);
   scanf("%c", &x);
   switch(x)
   {
   case '+': 
      y=a+b;
      break; 
   case '-': 
      y=a-b;
      break;
   case '*': 
      y=a*b;
      break;
   case '/':
    { 
       if(b)      
      y=a/b;
       else printf("divisao por 0!");
          exit(1);
    }
      break;
    {
   default: printf("operacao desejada nao listada");
      exit(2);
    }
   }   
   printf("resultado: %d", y);
}
   

