#include<stdio.h>
#define MAX 9

int i = 1;


int main()
{

  for(i = 1; i <= MAX; i++)
  {
    // wydrukowaæ spacje
    for(int j = 1; j <= 9 - i; j++)
      printf(" ");
    
    // wydrukowac cyfry od 1 do i
    for(int j = 1; j <= i;j++)
      printf("%d", j);

    //wydrukowac od i-1 = 1
    for(int j = i - 1;j >= 1;j--)
      printf("%d", j);

    // nowa linia
    printf("\n");

  }

  return 0;
}
