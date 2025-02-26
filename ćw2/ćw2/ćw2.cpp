#include <iostream>
using namespace std;

int main()
{
  int x = 1;
  int w = x - 5;
  if( w<0 ) 
    w = -w;
  //w = w * 2 / 3;
  w *= 2 / 3;

  return 0;
}

