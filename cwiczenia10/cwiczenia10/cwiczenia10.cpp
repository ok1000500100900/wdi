
#include <iostream>
using namespace std;
#include <stdio.h>

int Fib1 (int n);
int Fib2 (int n);

void filtr(double x[], double y[], int nSize);

int main()
{
  printf("Podaj wartoœæ n: ");
  int n;
  cin >> n;
  if(n < 0)
  {
    perror("ERROR: bledna wartosc numeru wyrazu ciagu!!!\n");
  }

  if(n==0)
    printf("%d-wy", n);
  else if(n==1)
    printf("%d-szy", n);
  else if(n==2)
    printf("%d-gi", n);
  else if(n==3)
    printf("%d-ci", n);
  else
    printf("%d-ty", n);

  printf(" wyraz ciagu to %d\n", Fib2(n));

  return 0;
}

int Fib1(int n)
{
  if(n == 0) return 0;
  if(n == 1) return 1;
  
  int f0 = 0;
  int f1 = 1;
  int fn;

  for(int i = 2; i <= n; i++)
  {
    fn = f1 + f0;
    f0 = f1;
    f1 = fn;
  }

  return fn;
}

//tylko w fib mozemy uzywac drugiego sposobu, pozostale
// przypadki liczymy pierwszym sposobem
// na kartkowce MOGA sie pojawic metody sortowania
// mogloby byc 36 na kartkowce
// porywnanie lancuchow znakowych bez wzgledu na wielkosc
// policzyc sinus
// bez rekurencji

int Fib2(int n)
{
  if(n == 0) return 0;
  int a = 1;
  int b = 0; //wynik
  for(int i = 1; i <= n; i++)
  {
    b = a + b;
    a = b - a;
  }

  return b;
}

void filtr(double x[], double y[], int nSize) // nSize >1
{
  y[0] = (2 * x[0] + x[1]) / 3.;// *(x+1)
  
  for(int i = 1; i < nSize - 1; i++)
    y[i] = (y[i - 1] + 2 * x[i] + x[i + 1]) / 4.;

  y[nSize - 1] = (y[nSize - 2] + 2 * x[nSize - 1]) / 3.;

}

// przyszlosc - ale szybsze do napisania
// tablice dynamiczne
void printTab(int* pTab, int nSize)
{
  for(int i = 0; i < nSize; i++)
    printf("%d ", *pTab++);
}