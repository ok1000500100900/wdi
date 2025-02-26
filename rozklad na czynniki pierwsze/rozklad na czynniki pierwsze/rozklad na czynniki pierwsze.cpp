
#include <iostream>
using namespace std;
#include<stdio.h>

int x;
void czynnikiPierwsze(int x);

int main()
{
  printf("Wpisz liczbe: ");
  cin >> x;
  czynnikiPierwsze(x);
}

void czynnikiPierwsze(int x)
{
  int i = 2;
  int temp = x;

  while(i < sqrt(x))
  {
    if(temp % i == 0)
    {
      printf("%d ", i);
      temp = temp / i;
    }

    else i++;
  }
}