
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1; // exit with error
    }

    int a, b, temp;

    a = atoi(argv[1]); // convert string to int
    b = atoi(argv[2]);

    temp = a;  // swap
    a = b;
    b = temp;

    printf("a = %d  b = %d\n", a, b);
    printf(&a)

    return 0;
}
