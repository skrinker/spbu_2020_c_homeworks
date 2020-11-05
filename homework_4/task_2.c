#include "stdint.h"
#include "stdio.h"

char getSign(uint64_t bits)
{
    return (bits >> 63 & 1) ? '-' : '+';
}

int getExponent(uint64_t bits)
{
    return ((bits >> 52) & 0x7FF) - 1023;
}

double getMantissa(uint64_t bits)
{
    unsigned long long denominator = (unsigned long long)1 << 52;
    return (double)(bits & 0x000FFFFFFFFFFFFF) / (double)denominator + 1;
}

int main()
{
    double number = 0;
    printf("Enter a number: ");
    scanf("%lf", &number);
    uint64_t bits = *((uint64_t*)&number);
    double mantissa = getMantissa(bits);
    int exponent = getExponent(bits);
    char sign = getSign(bits);
    printf("Result: ");
    printf("%f = %c%.20f * 2^{%d}\n", number, sign, mantissa, exponent);
    return 0;
}