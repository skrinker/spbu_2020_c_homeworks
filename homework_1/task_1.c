#include "../library/commonUtils/numericOperations.h"
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define n 7

void printSpiral(int matrix[n][n], int size)
{
  int i = n / 2;
  int j = n / 2;
  printf("%d ", matrix[j][i]);
  int stepNumber = 0;
  int stepsInOneDirection = 0;
  int c;
  int direction = 0; // 0 - left, 1 up, 2 right, 3 down
  while (stepNumber < n * n - 1) {
    if (stepNumber % 2 == 0)
      stepsInOneDirection++;
    for (c = 0; c < stepsInOneDirection * 2; c++) {
      switch (direction) {
      case LEFT:
        i--;
        break;
      case UP:
        j--;
        break;
      case RIGHT:
        i++;
        break;
      case DOWN:
        j++;
        break;
      }
      printf("%d ", matrix[j][i]);
      stepNumber++;
      if (stepNumber == n * n - 1)
        break;
      if (c == stepsInOneDirection - 1)
        direction = (direction + 1) % 4;
    }
    direction = (direction + 1) % 4;
  }
  printf("\n\n");
}

int main()
{
  int a[n][n];
  int i;
  int j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      a[i][j] = rand() % 20;
  }
  printSpiral(a, n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%d \t", a[i][j]);
    printf("\n");
  }
  return 0;
}