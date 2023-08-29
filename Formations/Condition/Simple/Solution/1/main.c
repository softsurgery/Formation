#include <stdio.h>

int main(){
    int a,b;
    printf("A ="); scanf("%d",&a);
    printf("B ="); scanf("%d",&b);

    printf("A =%d ; B =%d",a,b);

    int aux = a;
    a = b;
    b = aux;

    printf("A =%d ; B =%d",a,b);
    return 0;
}