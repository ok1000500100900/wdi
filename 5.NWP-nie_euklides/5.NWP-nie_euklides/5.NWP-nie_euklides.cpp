
#include <iostream>
using namespace std;
#include<stdio.h>

int x;
int y;
int NWP(int x, int y);
int temp;

int main()
{
  printf("Podaj dwie liczby: ");
  cin >> x >> y;
  printf("Wspolnym podzielnikiem %d, %d jest %d", x, y, NWP(x, y));
  return 0;
}

int NWP(int x, int y)
{
  while(y != 0)
  {
    temp = y;
    y = x % y;
    x = temp;

  }

  return x;

}
