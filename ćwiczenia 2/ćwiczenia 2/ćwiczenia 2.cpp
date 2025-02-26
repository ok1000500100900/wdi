
#include <iostream>
using namespace std;

#include <stdio.h>   // dolaczam pliki naglowkowe C bo mozna wtedy wywalic iostream
#include<math.h>       // i na pewno bedzie sie kompilowac roznymi kompilatorami
#define ZERO 1.e-100

int main()
{
  // rozwiazanie trojmianu kwadratowego
  // wczytac dane do a, b, c
  double a;
  double b;
  double c;
  printf("Podaj współczyniki trójmianu kwadratowego a, b, c: ");
  cin >> a >> b >> c;
  
  // obliczyc delte!

  double delta = b * b - 4 * a * c;

  // zdefiniowac wyniki x1 i x2

  double x1 = 0;
  double x2 = 0;

  if(delta > ZERO)
  {
    delta = sqrt(delta);
    x1 = (-b + delta) / 2 * a;
    x2 = (-b - delta) / 2 * a;
    printf("Pierwiastkami trójmianu jest %.2lf oraz %.2lf\n", x1, x2);
  }
  else if(fabs(delta) == ZERO)
  {
    x1 = x2 = (-b / 2) / 2 * a;
    printf("Pierwiastkiem trójmianu jest %.2lf\n", x1);
  }
  else
  {
    printf("Delta jest mniejsza od zera");
  }
      
  // fabs absolute value dla float double itp
  // abs absolute value dla intów


  // delta > 0
    // obliczyc x1 i x2 - wypisac
  // jeśli nie delta >0 czy delta = )   fabs(delta) < 0
    // obliczyc x1 = x2
      // jesli nie wypisac ze nie ma pierw


    return 0;
}
