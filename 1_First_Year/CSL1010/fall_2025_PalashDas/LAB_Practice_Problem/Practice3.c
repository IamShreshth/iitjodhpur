#include <stdio.h>
#include <math.h>

int main()
{
    double r, area;  // use double for more precision
    printf("Enter radius: ");
    scanf("%lf", &r);  // %lf for double input

    area = M_PI * r * r;
    printf("The area of the circle with radius %.2f is %.2f\n", r, area);

    return 0;
}


