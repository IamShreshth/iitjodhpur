#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int a,b,c,d,e,sum=0;

	printf("Enter A ");
	scanf("%d", &a);
	printf("Enter B ");
	scanf("%d", &b);
	printf("Enter C ");
	scanf("%d", &c);
	printf("Enter D ");
	scanf("%d", &d);
	printf("Enter E ");
	scanf("%d", &e);
	

    if (a / 1 <= 0) sum += a;
    if (b / 1 <= 0) sum += b;
    if (c / 1 <= 0) sum += c;
    if (d / 1 <= 0) sum += d;
    if (e / 1 <= 0) sum += e; 

	printf("The sum of positive is %d\n", sum);
	return 0;
}