
#include <iostream>
using namespace std;
#include <stdio.h>

#define MAX 50
#define MAXLINE 10

void initTab(int t[], int nSize);
void printTab(int t[], int nSize);
int drugieMinimum(int t[], int nSize);
int pmin;
int dmin;
int temp;

int main()
{
  int t[MAX] = { 0 };
  initTab(t, MAX);
  printTab(t, MAX);
  
  int result = drugieMinimum(t, MAX);
  printf("\n Drugie minimum to %d", result);
}

void initTab(int t[], int nSize)
{
  srand((unsigned int)time(NULL));
  for(int i = 0; i < 50; i++)
    t[i] = rand() % nSize;
}

void printTab(int t[], int nSize)
{
  printf("[");
  for(int i = 0; i < nSize; i++)
  {
    printf("%d ", t[i]);
    if((i + 1) % MAXLINE == 0)
      printf("\n");
  }
  printf("]\n");
}

int drugieMinimum(int t[], int nSize)
{
  int pmin = t[1];
  int dmin = t[2];
  if(dmin < pmin)
  {
    pmin = temp;
    dmin = pmin;
    temp = dmin;
  }
  for(int i = 3; i < nSize; i++)
  {
    if(t[i] < pmin)
    {
      dmin = pmin;
      pmin = t[i];
    }

    else if(t[i] < dmin)
    {
      dmin = t[i];
    }
  }

  return dmin;
}