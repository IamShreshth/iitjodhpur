#include <stdio.h>

int main()
{
    int a, b, c, largest;

    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Enter c: ");
    scanf("%d", &c);
    largest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    printf("The largest number is: %d\n", largest);
    return 0;
}

