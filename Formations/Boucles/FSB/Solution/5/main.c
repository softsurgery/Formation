#include <stdio.h>

int main(){
    int h,min,s;
    printf("H = "); scanf("%d",&h);
    printf("MIN = "); scanf("%d",&min);
    printf("S = "); scanf("%d",&s);
    printf("Temps : %d:%d:%d\n",h,min,s);
    
    s += 1;
    if (s==60){ 
        s = 0;
        min += 1;
    }
    if (min==60){
        min = 0;
        h +=1;
    } 

    printf("Temps+1 : %d:%d:%d\n",h,min,s);
    return 0;
}