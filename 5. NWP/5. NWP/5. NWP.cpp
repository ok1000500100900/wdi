#include <iostream>
using namespace std;
#include<stdio.h>

int x;
int y;
int NWP(int x, int y);
int nwp;
int temp;
int rest;
int test();

int main()
{
  printf("%d ", test());
  printf("Podaj dwie liczby: ");
  cin >> x >> y;
  printf("Ich najwiekszy wspolny podzielnik to %d", NWP(x,y));
  return 0;
}

int NWP(int x, int y)
{
  int nwp;
  int result = x / y;
  int rest = (x - (result*y));
  while(1)
  {
    if(rest == 0)
    {
      nwp = y;
      break;
    }

    result = y / rest;
    int temp = rest;
    rest = y - (rest * result);
    y = temp;

  }

  return nwp;

}

int test()
{
  int result = NWP(21, 24);
  if(result == 3) return 0;
  return 1;
}