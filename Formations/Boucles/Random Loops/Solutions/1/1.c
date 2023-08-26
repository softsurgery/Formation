#include <stdio.h>

int main(){
    int s = 0;
    for(int i=1;i<=1001;i++) s+=i;
    for(int i=2;i<=100;i++) s+=i;
    printf("Resultat = %d",s);
    return 0;
}