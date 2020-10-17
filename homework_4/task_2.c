#include "math.h"

int main()
{
    double number = 0;
    double mantissa = 0;
    int exponent = 0;
    printf("Enter a number: ");
    scanf("%lf", &number);
    mantissa = frexp(number, &exponent);
    printf("Result: ");
    printf("%f = %.20f * 2^{%d}\n", number, mantissa * 2, exponent - 1);
    return 0;
}