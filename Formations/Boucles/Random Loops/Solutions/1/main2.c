#include <stdio.h>

int main(){
    int s = 0;
    for(int i=1;i<=991;i+=2) s+=i;
    for(int i=3;i<=99;i+=2) s+=i;
    printf("Resultat = %d",s);
    return 0;
}