
#include <iostream>
using namespace std;

#include <stdio.h>
#include<math.h>

int sumaPodz(int x);

int main()
{
  // suma podzielnikow danej liczby
  printf("Podaj liczbe calkowita >0 : ");
  int x = 0;
  cin >> x;
  
  if(x <= 1)
  {
    perror("ERRORL Wczytano bledna liczbe!\n");
    return 1;
  }

  printf("Suma podzielnikow %d = %d\n", x, sumaPodz(x));


  return 0;
}

int sumaPodz(int x)
{
  int res = 1 + x;
  int p = 2;
  while(p <= (int)sqrt(x)+0.5)
  {
    if(x%p == 0)
    {
      res += p;
      int d = x / p;
      if(d != p) res += d;
    }
  }
  return res;
}

// zrobic zadanie 5,6, 9 z listy algorytmów