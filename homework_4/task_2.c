#include "math.h"
#include "stdio.h"

char getSign(double number)
{
    if (!signbit(number))
        return '+';
}

void printExponentialForm(double number)
{
    double mantissa = 0;
    int exponent = 0;
    mantissa = frexp(number, &exponent);
    printf("Result: ");
    printf("%f = %c%.20f * 2^{%d}\n", number, getSign(number), mantissa * 2, exponent - 1);
}

int main()
{
    double number = 0;
    printf("Enter a number: ");
    scanf("%lf", &number);
    printExponentialForm(number);
    return 0;
}