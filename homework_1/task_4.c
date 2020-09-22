#include <stdbool.h>
#include <stdio.h>

bool isPrime(int a)
{
  if (a % 2 == 0) return false; 
  int i;
  bool isPrime = true;
  for (i = 3; i < a / 2; i = i + 2) {
    if (a % i == 0) {
      isPrime = false;
      break;
    }
  }
  return isPrime;
}

int main()
{
  int n = 10000;
  int i;
  for (i = 2; i <= n; i++) {
    if (isPrime(i)) {
      printf("%d\n", i);
    }
  }
}