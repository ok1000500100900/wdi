
#include <iostream>


#include <stdio.h>
using namespace std;

int mult(int a, int b);


int main()
{
// mnożenie przez dodawanie
// 

  int x;
  int y;
  printf("Podaj dwie liczby całkowite: ");
  cin >> x >> y;
  printf("x*y = %d\n", mult(x, y));

  // dzielenie przez odejmowanie
  int q = 0;
  int r = x;
  while( r>= y )
  {
    q++; //q = q+1
    // x = q*y +r-y; r>=y
    r -= y; // r= r-y

  }
  // x = q+y + r // definicja dzielenia z resztą

  printf("x/y = %d reszty %d\n", q, r);

  return 0;
}

int mult(int a, int b)
{
  int res = 0;
  while(b-- )
  {
    res += a;
  }
  return res;
}