
#include <iostream>
using namespace std;

int getNum();
int isDigit(char c);
void skipSpaces();

int main()
{
  skipSpaces();
  printf("Podaj liczbe naturalna: ");
  printf("Wczytano %d\n", getNum());

  return 0;
}

int getNum()
{
  char c;
  int res = 0;

  while(isDigit(c=getchar()))
  res = res * 10 + (c - '0');

  return res;
}

int isDigit(char c)
{
  return c >= '0' && c <= '9';
}

void skipSpaces()
{
  char c;
  while((c = getchar()) == ' ');
  ungetc(c, stdin);
}
// takie cos ale z ominieciem spacji