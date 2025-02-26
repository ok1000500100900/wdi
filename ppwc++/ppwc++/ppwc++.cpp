// ppwc++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swap2(int* px, int* py)
{
  int* tmp = px;
  px = py;
  py = tmp;
}

int main()
{
  int x = 1, y = 2;
  cout << "x = " << x << ", y = " << y << endl;
  swap2(&x, &y);
  cout << "x = " << x << ", y = " << y << endl;
}

