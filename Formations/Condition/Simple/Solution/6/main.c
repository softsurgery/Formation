#include <stdio.h>

int main() {
	float t;
	printf("Temperature = \n");
	scanf("%f",&t);
	if (t<0) printf("Glace");
	else if (t<100) printf("Eau");
	else printf("Vapeur");
	return 0;
}