#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int randomNumber(int a)
{
  return rand() % a;
}

int getPos(char a)
{
  if (a == ' ') {
    return 26;
  }
  return a - 'a' + 1;
}

int binPow(int a, int n)
{
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 1) {
    return binPow(a, n - 1) * a;
  } else {
    int c = binPow(a, n / 2);
    return c * c;
  }
}

int hash(int a, int b, char str[], int prime_number)
{
  int i;
  int result = 0;
  for (i = a; i < b; i++) {
    result += binPow(prime_number, b - a - i - 1) * getPos(str[i]);
  }
  return result;
}

int search(char pattern[], char text[], int prime_number)
{
  int i;
  int n = 0;
  int pattern_length = strlen(pattern);
  int text_length = strlen(text);
  int pattern_hash = hash(0, pattern_length, pattern, prime_number);
  int buff_hash = hash(0, pattern_length, text, prime_number);
  for (i = 0; i < text_length - pattern_length + 1; i++) {
    if (buff_hash == pattern_hash) {
      int c = randomNumber(pattern_length);
      if (text[i + c] == pattern[c]) {
        n++;
      }
    }
    buff_hash = prime_number * buff_hash - binPow(prime_number, pattern_length) * hash(i, i + 1, text, prime_number)
        + hash(i + pattern_length, i + pattern_length + 1, text, prime_number);
  }
  return n;
}

int main()
{
  char s[1000];
  printf("%d", search("this", "this is a test", 13));
  return 0;
}