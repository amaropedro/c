
#include <stdio.h>
main ()
{
float N1,P1,N2,P2,N3,P3,M; /* N = nota P = peso M = media */
   printf("esse programa calcula a media ponderada de 3 notas, para isso...\n digite a primeira nota: ");
   scanf("%f", &N1);
   printf("digite seu respectivo seu peso: ");
   scanf("%f", &P1);
   printf("digite a segunda nota: ");
   scanf("%f", &N2);
   printf("digite seu respectivo seu peso: ");
   scanf("%f", &P2);
   printf("digite a terceira nota: ");
   scanf("%f", &N3);
   printf("digite seu respectivo seu peso: ");
   scanf("%f", &P3);
   M = (N1*P1 + N2*P2 + N3*P3)/(P1+P2+P3); /* media ponderada */
   printf("\n Media Ponderada: %1.2f",M);
}