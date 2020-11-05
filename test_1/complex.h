#include "stdlib.h"

typedef struct ComplexNumber {
    int realPart;
    int imaginaryPart;
} ComplexNumber;

ComplexNumber* createComplexNumber(int realPart, int imaginaryPart);
ComplexNumber* sum(ComplexNumber* a, ComplexNumber* b);
ComplexNumber* product(ComplexNumber* a, ComplexNumber* b);
ComplexNumber* difference(ComplexNumber* a, ComplexNumber* b);
ComplexNumber* quotient(ComplexNumber* a, ComplexNumber* b);
