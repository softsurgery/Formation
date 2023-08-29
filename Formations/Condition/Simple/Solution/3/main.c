#include <stdio.h>

int main(){
	int n;
	printf("N ="); scanf("%d",&n);
	int c,d,u;
	c = n / 100;
	d = n % 100 / 10;
	u = n % 10;
	int S = c + d + u;
	int P = c * d * u;
	printf("S = %d ; P = %d\n",S,P);
	return 0;
}