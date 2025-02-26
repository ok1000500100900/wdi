#include <iostream>

#define MAXLINE 10
#define MAX 50

void initTab(int t[],int nSize);
void printTab(int t[], int nSize);
int t[MAX] = { 0 };
int sumOdd(int sum, int k, int *p);


int main()
{
  int sum = 0;
  int k = 0;
  initTab(t, MAX);
  printTab(t, MAX);
  printf(" ");
  sumOdd(sum, k, t);
  int result = sumOdd(sum, k, t);
  printf("%d", result);

  return 0;
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
    if((i+1) % MAXLINE == 0) 
      printf("\n");
  }
  printf("]\n");
}

int sumOdd(int sum, int k, int* p)
{
  for(int i = 0; i < MAX; i++) 
  {
    if(*p % 2 != 0) 
    {
      sum += *p; 
      k++;       
    }
    p++; 
  }

  if(k == 0) 
    return 0;

  sum = sum / k; 
  return sum;    
}
