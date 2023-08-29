#include <stdio.h>

int main(){
   float np1,np2,nf,m;
   printf("NP1 = \n");
   scanf("%f",&np1);
   printf("NP2 = \n");
   scanf("%f",&np2);
   printf("NF = \n");
   scanf("%f",&nf);
   m = (np1+np2+nf*2)/4;
   if(nf>m) m = nf;
   printf("Moyenne = %.3f",m);
}