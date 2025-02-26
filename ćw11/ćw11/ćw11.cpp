
#include <stdio.h>

#define ROWS 6
#define COLS 6

void printTab2d(int t[][COLS], int nRows, int nCols); //nCols nadmiarowo
void calc(int out[][COLS], int in[][COLS], int nRows, int nCols, int nDist); //nCOLS nadmiarowo

int main()
{
  // mamy obliczyc do tablicy wynikowej pod indeks (i, j) sumy elementów otaczających
  // element (i,j) w tablicy we na dystansie nDist

  int nDist = 1;

  int t[ROWS][COLS] = { {1,0,0,0,1},
                        {1, 1, 1, 0,0, 1},
                        {1,0,0,0,0,1},
                        {0,0,0,1,1},
                        {0,1},
                        {0,0,0,1,1} };

  int w[ROWS][COLS] = {0};
  printf("Tablica we:\n");
  printTab2d(t, ROWS, COLS);

  calc(w, t, ROWS, COLS, nDist);
  printf("\nTablica wynikowa:\n");
  printTab2d(w, ROWS, COLS);
    return 0;
}

void printTab2d(int t[][COLS], int nRows, int nCols)
{
  for(int i = 0; i < nRows;i++)
  {
    for(int j = 0; j < nCols;j++)
      printf("%1d ", t[i][j]);
    printf("\n");
  }
}

void calc(int out[][COLS], int in[][COLS], int nRows, int nCols, int nDist)
{
  for(int i = 0;i < nRows; i++)
  {
    for(int j = 0;j < nCols;j++)
    {
      int rb = i - nDist;
      int re = i + nDist;
      int cb = j - nDist;
      int ce = j + nDist;

      if(rb < 0)rb = 0;
      if(re >= nRows)re = nRows - 1;
      if(cb < 0)cb = 0;
      if(ce >= nCols)ce = nCols - 1;

      int sum = 0;
      for(int row = rb; row <= re;row++)
      {
        for(int col = cb;col <= ce;col++)
        {
          if(row == i && col == j) continue; // przerywamy aktualną iterację a nie całą pętle
          sum += in[row][col];
        }
      }

      out[i][j] = sum;

    }
  }
}