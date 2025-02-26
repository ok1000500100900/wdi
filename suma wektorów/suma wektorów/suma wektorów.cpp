#include <iostream>
using namespace std;
#include<stdio.h>

#define MAXLINE 10

#define MAXVEC1 10
#define MAXVEC2 10

void initTab(int t[], int nSize);
void printTab(int t[], int nSize);
void scalarAdd(int v1[], int v2[], int result[], int nSize); 

int main()
{
  int v1[MAXVEC1] = { 0 };
  int v2[MAXVEC2] = { 0 };
  int v3[MAXVEC1] = { 0 }; // Wynikowy wektor

  printf("v1 = ");
  initTab(v1, MAXVEC1);
  printTab(v1, MAXVEC1);
  printf("\n");

  printf("v2 = ");
  initTab(v2, MAXVEC2);
  printTab(v2, MAXVEC2);
  printf("\n");

  if(MAXVEC1 != MAXVEC2)
  {
    printf("Wektory sa z roznych przestrzeni wektorowych\n");
    return 1;
  }

  scalarAdd(v1, v2, v3, MAXVEC1);

  printf("v1 + v2 = ");
  printTab(v3, MAXVEC1);
  printf("\n");

  return 0;
}

void scalarAdd(int v1[], int v2[], int result[], int nSize)
{
  for(int i = 0; i < nSize; i++)
  {
    result[i] = v1[i] + v2[i]; // Suma odpowiadaj¹cych sobie elementów
  }
}

void initTab(int t[], int nSize)
{
  srand((unsigned int)time(NULL));
  for(int i = 0; i < nSize; i++)
    t[i] = rand() % 10; // Liczby losowe z zakresu 0-9
}

void printTab(int t[], int nSize)
{
  printf("[");
  for(int i = 0; i < nSize; i++)
  {
    printf("%d", t[i]);
    if(i < nSize - 1)
      printf(", "); // Przecinki miêdzy elementami
    if((i + 1) % MAXLINE == 0 && i != nSize - 1)
      printf("\n ");
  }
  printf("]");
}