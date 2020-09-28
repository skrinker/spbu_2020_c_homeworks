#include "stdbool.h"
#include "stdio.h"
#include "time.h"

int binPow(int a, int n)
{
  int res = 1;
  while (n) {
    if (n & 1)
      res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}

bool isPreviousValuesEqual(int idx, int arr[])
{
  for (int i = 0; i < idx; i++) {
    if (arr[i] == arr[idx])
      return true;
  }
  return false;
}

int* createNumber()
{
  srand(time(NULL));
  int result = 0;
  int i = 0;
  static int number[4];
  while (i < 4) {
    number[i] = rand() % 10;
    while (isPreviousValuesEqual(i, number))
      number[i] = rand() % 10;
    i++;
  }
  return number;
  // for (int i = 0; i < 4; i++)
  //     result += binPow(10, 3 - i) * number[i];
  // return result;
}

int* splitDigits(int n)
{
  static int arr[4];
  for (int i = 0; i < 4; i++) {
    arr[i] = n / binPow(10, 3 - i) % 10;
  }
  return arr;
}

void startGame()
{
  bool isGameOver = false;
  int* generatedNumber = createNumber();
  printf("Компьютер задумывает четыре различные цифры из 0,1,2,...9. \nИгрок делает ходы, чтобы узнать эти цифры и их порядок.\nКаждый ход состоит из четырёх цифр, 0 может стоять на первом месте.\nВ ответ компьютер показывает число отгаданных цифр, стоящих на своих местах (число быков) и число отгаданных цифр, стоящих не на своих местах (число коров). \n");
  while (!isGameOver) {
    int inputValue;
    printf("Enter 4-digit number: \n");
    scanf("%d", &inputValue);
    int* inputNumber = splitDigits(inputValue);
    int cows = 0;
    int bulls = 0;
    for (int i = 0; i < 4; i++) {
      if (inputNumber[i] == generatedNumber[i]) {
        bulls++;
      }
      for (int j = 0; j < 4; j++) {
        if (inputNumber[i] == generatedNumber[j] && i != j) {
          cows++;
        }
      }
    }
    if (bulls == 4) {
      isGameOver = true;
      printf("WIN \n");
    } else {
      printf("Cows: %d, Bulls: %d \n\n", cows, bulls);
    }
  }
}

void main()
{
  startGame();
  return 0;
}
