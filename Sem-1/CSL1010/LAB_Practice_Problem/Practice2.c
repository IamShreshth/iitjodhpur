//Write a C program that takes the basic salary, Dearness Allowance  (DA), and House Rent Allowance (HRA) as input, adds them together to calculate the total monthly salary, and then displays the result.

#include <stdio.h>

int main()
{
	int a,b,c,sum;
	printf("Enter Basic salary: ");
	scanf("%d", &a);
	printf("Enter Dearness Allowance  (DA) ");
	scanf("%d", &b);
	printf("Enter House Rent Allowance (HRA) ");
	scanf("%d", &c);
	sum=a+b+c;
	printf("Total Salary = %d\n",sum);
	return 0;
}

