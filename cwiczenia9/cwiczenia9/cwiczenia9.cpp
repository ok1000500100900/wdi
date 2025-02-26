
#include <iostream>
using namespace std;
#include<stdio.h>
#include <math.h>
#define PI 3.14159265358

typedef struct
{
  double mx;
  double my; //m - member
} Point;

double ave(double a, double b);
double deg2rad(int alpha);

int main()
{
  // obrot odcinka wokol srodka
  // zdefiniowac konce odcinka
  
  Point pt1 = { 0,1 };
  Point pt2 = { 1,0 };

  // zdefiniowac kat obrotu w stopniach
  int alpha = 90;

  // zdefiniowac i obliczyc wsp srodka [xsr, ysr]
  Point sr;
  sr.mx = ave(pt1.mx, pt2.mx);
  sr.my = ave(pt1.my, pt2.my);

  // przesunac o wektor [-xsr, -ysr]
  Point pt1p;
  pt1p.mx = pt1.mx - sr.mx;
  pt1p.my = pt1.my - sr.my;

  Point pt2p;
  pt2p.mx = pt2.mx - sr.mx;
  pt2p.my = pt2.my - sr.my;

  // przekonwertowac stopnie do radianow
  double radians = deg2rad(alpha);

  // obrocic oba konce odcinka
  Point pt1o;
  Point pt2o;

  pt1o.mx = pt1p.mx * cos(radians) - pt1p.my * sin(radians);
  pt1o.my = pt1p.mx * sin(radians) + pt1p.my * cos(radians);

  pt2o.mx = pt2p.mx * cos(radians) - pt2p.my * sin(radians);
  pt2o.my = pt2p.mx * cos(radians) + pt2p.my * sin(radians);

  // przesunac o wektor [xsr, ysr]
  pt1o.mx += sr.mx;
  pt1o.my += sr.my;

  pt2o.mx += sr.mx;
  pt2o.my += sr.my;

  // wydrukowac
  printf("odcinek [%.2lf, %.2lf]--[%.2lf, %.2lf] po obrocie o k¹t %d = [%.2lf, %.2lf]--[%.2lf, %.2lf]\n",
    pt1.mx, pt1.my, pt2.mx, pt2.my, alpha, pt1o.mx, pt1o.my, pt2o.mx, pt2o.my);

  return 0;
}


double ave(double a, double b)
{
  return(a + b) / 2;
}

double deg2rad(int alpha)
{
  return alpha * PI / 180.;
}

// kartkowka z c - dwa cwiczonka konkretna funkcja - typ, parametry, typy parametrow WEJSCIOWYCH, obliczenie + wartosc
// kawa³ek kodu (definicja sta³ych i struktury danych i napisaæ algorytm np sortowanie b¹belkowe czyli sam kod i definicje)
// !klamerki, œredniki