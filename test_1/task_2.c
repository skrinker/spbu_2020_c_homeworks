#include "../library/vector/vector.h"
#include <stdio.h>

Vector* inputVector()
{
    int numberOfCoordinates = 0;
    printf("Input number of coordinates: \n");
    scanf("%d", &numberOfCoordinates);

    printf("Input number coordinates: \n");
    int* coordinates = (int*)malloc(sizeof(int) * numberOfCoordinates);
    memset(coordinates, 0, sizeof(int) * numberOfCoordinates);
    for (int i = 0; i < numberOfCoordinates; ++i) {
        scanf("%d", &coordinates[i]);
    }

    return createVector(coordinates, numberOfCoordinates);
}

int main()
{
    Vector* vector1 = inputVector();
    Vector* vector2 = inputVector();
    Vector* result = vector1;

    printf("Input vectors: \n");
    printVector(vector1);
    printVector(vector2);

    if (!isEqualSize(vector1, vector2)) {
        printf("Operations unavailable - non-equal size");

        destroyVector(vector1);
        destroyVector(vector2);

        return 0;
    }

    printf("Scalar product: %d \n", multiplyScalar(vector1, vector2));

    printf("Addition: ");
    result = add(vector1, vector2);
    printVector(result);

    printf("Subtraction: ");
    result = subtract(vector1, vector2);
    printVector(result);

    destroyVector(vector1);
    destroyVector(vector2);
    destroyVector(result);

    return 0;
}