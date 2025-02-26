#include <iostream>
using namespace std;
#include <stdio.h>

#define MAX 50
#define MAXLINE 10

// dodac includy
// define ...
// void in


void initTab(int t[], int nSize);
void printTab(int t[], int nSize);
int i = 0;

int t[MAX] = { 0 };

void initTab(int tab[])
{
  srand((unsigned int)time(NULL));
  for(int i = 0; i < 50; i++)
  {
    tab[i] = rand() % nSize;
  }
}

void printTab(int tab[], int nSize)
{
  for(int i = 0; i < 50; i++)
  {
    printf("%d ", t[i]);
    if((i + 1) % MAXLINE == 0)
    {
      printf("\n");
    }
  }
}



int main()
{

  // definiowac tablice 50 elementow
  // zainicjowac losowo
  // wydrukowac 

  //roznica miedzy parzysta a nieparzysta iloscia elementow
  int r = 0; //roznica
  for(int i = 0; i < MAX;i++)
    if(tab[i] % 2 == 0) r++;
    else r--;
  printf("Roznica miedzy iloscia parzystych a nieparzystych = %d\n", r);


  // zad 14
  int i = 0;
  int j = MAX - 1;
  while(i < j)
  {
    int temp = tab[i], tab[i++] = tab[j]; tab[j--] = temp;
    // i++; j==;
  }
  printf("\n Tablica odwrócona: \n");
  printTab(tab, MAX);



  printf("Podaj liczbe k: ");
  int k;
  cin >> k;

  // zadanie 11 - ilosc wystapien k w ciagu
  int No = 0;
  for(int i = 0; i < MAX; i++)
    if(tab[i] == k)
      No++;
  printf("Ilość wystąpień %d w ciągu = %d/n", k, No);

  // zadanie 10

  int sum = 0;
  for(int i = 0; i < MAX; i++)
    if(tab[i] % k == 0)
    {
      sum += tab[i];
      printf("%d ", tab[i]);
    }
  printf("\n Suma elementow ciagu podzielnych przez %d = %d\n", k, sum);


  return 0;
}


