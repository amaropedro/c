#include <stdio.h>
main()

{int x,y,z,w=0;
printf("digite o primeiro numero: ");
scanf("%d", &x);
printf("digite o segundo numero: ");
scanf("%d", &y);
for(z=x; z<=y; z=z+1)
 {
 if(z%2==0)
   {
   w=w+z;
  	}	
 }
 printf("%d", w);
}
