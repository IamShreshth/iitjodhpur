#include <stdio.h>
#include <stdlib.h>

int main (int argc,char * argv[])
{
	int a,b;
	
	a=atoi(argv[1]);
	b=atoi(argv[2]);

	a=a+b;
	b=a-b;
	a=a-b;

	printf("a =%d  b=%d\n",a,b);

	return 0;

}