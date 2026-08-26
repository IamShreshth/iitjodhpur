#include <stdio.h>
#include <stdlib.h>

int main (int argc,char **argv)
{
	int sum = 0,avg;
	printf("You have entered %d arguments\n", argc);
	printf("You have entered %s\n", argv[0]);
	printf("You have entered %s\n", argv[1]);
	printf("You have entered %s\n", argv[2]);
	printf("You have entered %s\n", argv[3]);
	sum = (atoi(argv[1]) + atoi(argv[2])+ atoi(argv[3]));
	printf("The sum is %f\n", sum);
	float avg=sum/3;
	printf("average=%f\n",avg);
	return 0;

}






