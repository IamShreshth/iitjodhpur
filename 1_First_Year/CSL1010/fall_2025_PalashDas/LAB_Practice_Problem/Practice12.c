#include <stdio.h>
int main()
{
	int a=5;
	int b=9;
	printf("a=%u,b=%u\n",a,b);
	printf("a&b=%u\n",a&b);
	printf("a|b=%u\n",a|b);
	printf("a^b=%u\n",a^b);
	printf("~a=%u\n",~a);//Bit Negotiation
	printf("a<<b=%u\n",a<<1);
	printf("a>>b=%u\n",a>>1);
	return 0;

}