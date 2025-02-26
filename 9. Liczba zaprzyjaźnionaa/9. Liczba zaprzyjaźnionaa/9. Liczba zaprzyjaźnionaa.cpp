
#include <iostream>
using namespace std;
#include<stdio.h>

int n;
int f;
int Friend(int n);
int SumaPodz(int n);

int main()
{
  printf("Podaj liczbe: ");
  cin >> n;
  printf("%d", f);

  return 0;

}

int Friend(int n)
{
  int f;
  int s1 = SumaPodz(n);
  int s2 = SumaPodz(s1);
  if(n == s2) f = s1;
  else f = 0;
  return f;
}

int SumaPodz(int n)
{
  int sum = 1;
  for(int i = 2; i <= sqrt(n); i++)
  {
    int res = n / i;
    res = res * i;
    if(res == n)
    {
      sum += i;
      res = n / i;
      if(res != i) sum += res;

    }
  }
  return sum;
}
