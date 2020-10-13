#include "complex.h"

ComplexNumber* createComplexNumber(int realPart, int imaginaryPart)
{
    ComplexNumber* complexNumber = malloc(sizeof(ComplexNumber));
    complexNumber->imaginaryPart = imaginaryPart;
    complexNumber->realPart = realPart;
    return complexNumber;
}

ComplexNumber* sum(ComplexNumber* a, ComplexNumber* b)
{
    ComplexNumber* complexNumber = malloc(sizeof(ComplexNumber));
    complexNumber->imaginaryPart = a->imaginaryPart + b->imaginaryPart;
    complexNumber->realPart = a->realPart + b->realPart;
    return complexNumber;
}

ComplexNumber* difference(ComplexNumber* a, ComplexNumber* b)
{
    ComplexNumber* complexNumber = malloc(sizeof(ComplexNumber));
    complexNumber->imaginaryPart = a->imaginaryPart - b->imaginaryPart;
    complexNumber->realPart = a->realPart - b->realPart;
    return complexNumber;
}

ComplexNumber* product(ComplexNumber* a, ComplexNumber* b)
{
    ComplexNumber* complexNumber = malloc(sizeof(ComplexNumber));
    complexNumber->imaginaryPart = a->realPart * b->imaginaryPart + b->realPart * a->imaginaryPart;
    complexNumber->realPart = a->realPart * b->realPart - a->imaginaryPart * b->imaginaryPart;
    return complexNumber;
}

ComplexNumber* quotient(ComplexNumber* a, ComplexNumber* b)
{
    ComplexNumber* complexNumber = malloc(sizeof(ComplexNumber));
    complexNumber->imaginaryPart = (a->imaginaryPart * b->realPart - b->imaginaryPart * a->realPart)
        / (b->realPart * b->realPart + b->imaginaryPart * b->imaginaryPart);
    complexNumber->realPart = (a->realPart * b->realPart + a->imaginaryPart * b->imaginaryPart)
        / (b->realPart * b->realPart + b->imaginaryPart * b->imaginaryPart);
    return complexNumber;
}