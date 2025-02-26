#include <iostream>
using namespace std;
#include <stdio.h>

int x;
int y;
int a;
int b;
int NWW(int x, int y);
int nww;

int main()
{
  printf("Podaj dwie liczby: ");
  cin >> x >> y;
  printf("\nNajmniejszy wspolna wielokrotnosc to: %d", NWW(x,y));
  return 0;
}

int NWW(int x, int y)
{

  a = x;
  b = y;


  while(1)
  {
    if(x == y)
    {
      nww = x;
      break;
    }
      
    else if(y > x)
    {
      x += a;
    }

    else if(x > y)
    {
      y += b;
    }

  }

  return nww;

}