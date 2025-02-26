
#include <iostream>
using namespace std;
#include<stdio.h>

#define MAXLINE 10

#define MAXVEC1 10

#define MAXVEC2 10

void initTab(int t[], int nSize);
void printTab(int t[], int nSize);

int scalarMult(int v1[], int v2[], int nSize);

int main()   
{
  int v1[MAXVEC1] = { 0 };
  int v2[MAXVEC2] = { 0 };
  printf("v1 = ");
  initTab(v1, MAXVEC1);
  printTab(v1, MAXVEC1);
  printf("\n");
  printf("v2 = ");
  initTab(v2, MAXVEC2);
  printTab(v2, MAXVEC2);

  if(MAXVEC1 != MAXVEC2)
  {
    printf("Wektory sa z roznych przestrzeni wektorowych\n");
    return 1;
  }

  // iloczyn skalarny
  printf("\nIloczyn skalarny v1 i v2 = %d\n", scalarMult(v1, v2, MAXVEC1));
  return 0;
}

int scalarMult(int v1[], int v2[], int nSize)
{
  int sum = 0;
  for(int i = 0;i < nSize;i++)
    sum += v1[i] * v2[i];
  return sum;

}

void initTab(int t[], int nSize)
{
  srand((unsigned int)time(NULL));
  for(int i = 0;i < nSize;i++)
    t[i] = rand() % nSize; //(nSize<<1)
}

void printTab(int t[], int nSize)
{
  printf("[");

    for(int i = 0; i < nSize;i++)
    {
      printf("%d", t[i]);
      if(i < nSize - 1) printf(" ");
      if((i+1) % MAXLINE == 0)
        printf("\n");
  }

    printf("]");

}