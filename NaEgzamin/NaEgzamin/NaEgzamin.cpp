
#include <iostream>
#define PI 3.14159265
#define X 30
#define EPS 0.0001
#define Y 1
#define N 6
#define smallN 1
#define smallM 2

//zadanie 6
double sinus(double x, double eps);
double cosinus(double x, double eps);
double wykl(double x, double eps);
double wykl1(double x, double eps);
int isIdent(char c[]);
int porSlow(char c1[], char c2[]);
double getRzeczywista();
// double sredniaKolumn(double tab[], int nRow, int nCol);
int roznica(int** tab, int nRow, int nCol);

//zadanie 7
double funkRek(int n);
int Lucas(int n);
int Ackerman(int m, int n);


int main()
{
  //sprawdzenie sinusa i cosinusa i sinusa
  double result = sinus(X, EPS);
  double result1 = cosinus(X, EPS);
  printf("sinus = %lf, cosinus = %lf\n", result, result1);

  //sprawdzenie exp
  printf("wynik funkcji e do %d = %lf\nwyniki funkcji e do %d+1 = %lf\n", 
    Y, wykl(Y, EPS), Y, wykl1(Y,EPS));

  // sprawdzenie identyfikatora
  char c[] = "_aa77a";
  int result2 = isIdent(c);
  printf("\n Czy %s jest identyfikatorem? = %d\n", c, result2);

  //sprawdzenie porównywania s³ownikowego
  char c1[] = "Kot";
  char c2[] = "Kotek";
  char c3[] = "auto";
  char c4[] = "koT";

  printf("\n%s vs %s %d\n%s vs %s %d\n%s vs %s %d\n", 
    c1,c2, porSlow(c1, c2), c1, c3, porSlow(c1, c3), c1, c4, porSlow(c1, c4));

  //sprawdzenie funkcji rekurencyjnych
  printf("\nF(%d) = % lf\n", N, funkRek(N));
  printf("Lucas(%d) = %d\n", N, Lucas(N));
  printf("Ackerman(%d,%d) = %d\n", smallM,smallN, Ackerman(smallM, smallN));


  return 0;
}

double sinus(double x, double eps)
{
  x = x * PI / 180;

  double t = x;
  double res = x;
  double i = 3;

  while(t >= eps || t <= -eps)
  {
    t *= (-x * x) / (i * (i - 1)); 
    // potêga podzielona przez silnie (idzie co dwa)
    res += t;
    i += 2;
  }

  return res;

}

double cosinus(double x, double eps)
{
  x = x * PI / 180;
  double res = 1;
  double t = 1;
  double i = 2;

  while(t >= eps || t <= -eps)
  {
    t *= (-x * x) / (i * (i - 1));
    res += t;
    i += 2;
  }
  return res;
}

/*
jedyna ró¿nica miêdzy sinusem i cosinusem jest w wartoœciach pocz¹tkowych
sinus zaczyna t oraz result (dla i = 1) równe x, a cosinus (dla i=0) w 0
*/

//funkcja wyk³adnicza e do x --> x do n podzielone przez n! 
double wykl(double x, double eps)
{
  double res = 1 + x; 
  double t = x;
  int n = 2;
  while(t >= eps)
  {
    t *= x / n++;
    res += t;
  }

  return res;
}

// e do (x+1) --> (x+1) do n /n!
double wykl1(double x, double eps)
{
  double res = x+2; // 1 + (x+1)
  double t = x+1;
  int n = 2;
  while(t >= eps)
  {
    t *= (x+1) / n++; // wa¿na zmiana
    res += t;
  }

  return res;
}


//funkcja sprawdzaj¹ca czy napis jest identyfikatorem
// identyfikator mo¿e zawieraæ jedynie cyfry, liczby i znak podkreœlenia
// nie mo¿e jednak zaczynaæ siê od cyfry!!!

int isIdent(char c[])
{
  int i = 0;
  if(!((c[i]>='a' && c[i]<='z') || (c[i]>='A' && c[i]<='Z') || (c[i]=='_'))) 
    return 0; //zaprzeczenie

  i = 1;
  while(c[i] != 0) //ci¹g koñczy siê znakiem o wartoœci 0
  {
    if(!((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z') 
      || (c[i] == '_') || (c[i]>='0' && c[i]<='9'))) return 0;

    i++;
  }

  return 1;
}
//WA¯NE!!! musi byæ WIÊKSZE LUB RÓWNE, warto zrobiæ zaprzeczenie, ¿eby sobie u³atwiæ
// no i równa siê piszemy ==, wyjœcie to int, wejœcie to tablica char-ów

//porównywanie s³ownikowe
int porSlow(char c1[], char c2[])
{
  int i = 0;
  while(c1[i] != 0 && c2[i] != 0)
  {
    //funkcja niezwa¿a czy litery s¹ ma³e czy du¿e
    if(c1[i] >= 'a' && c1[i] <= 'z') c1[i] -= 32;
    if(c2[i] >= 'a' && c1[i] <= 'z') c2[i] -= 32;

    if(c1[i] < c2[i]) return 1; //najmniejszy numer - pierwszy w alfabecie
    if(c1[i] > c2[i]) return -1;
    i++;
  }

  //je¿eli jedno s³owo jest d³u¿sze, a drugie krótsze i maj¹ takie
  //same pocz¹tki, to krótsze jest pierwsze w s³owniku

  if(!c1[i] && c2[i]) return 1; // je¿eli nie damy ¿adnej wartoœci to przyrównuje do 1 (True)
  if(c1[i] && !c2[i]) return -1;
  return 0;
}

double getRzeczywista()
{
  char c; //przechowywuje bie¿¹cy znak
  double res = 0; //wartoœæ
  int sign = 0; //okreœla czy jest dodatnia czy ujemna

  //pomijanie bia³ych znaków - spacji, tab, nl
  while((c = getchar()) == ' ' || c == '\t' || c == '\n');
  ungetc(c, stdin);

  //ustawianie znaku
  if((c = getchar()) == '-') sign = 1;
  else if(c != '+')
    ungetc(c, stdin);

  //horner licz¹cy wartoœæ
  while((c = getchar()) >= '0' && c <= '9')
    res = res * 10 + (c - '0');

  //wartoœæ po przecinku
  if(c == '.')
  {
    double coef = 0.1;
    while((c = getchar()) >= '0' && c <= '9')
    {
      res += (c - '0') * coef;
      coef *=0.1;
    }
  }
  //stdin - standard input
  ungetc(c, stdin);
  if(sign) res = -res; 
  return res;
}

/*
double sredniaKolumn(double **tab, int nRow, int nCol)
{
  double tab_wyn[] = { 0 };

  for(int j = 0;j < nCol;j++)
  {
    for(int i = 0;i < nRow;i++)
      tab_wyn[j] += tab[i][j];

    tab_wyn[j] /= nRow;
  }

  return tab_wyn;
}

*/

int roznica(int** tab, int nRow, int nCol)
{
  //int tab[nRow][nCol] = { 0 };
  int min = 0;
  int max = 0;

  for(int i = 0;i < nRow;i++)
  {
    for(int j =0;j < nCol;j++)
    {
      if(tab[i][j] < min)min = tab[i][j];
      if(tab[i][j] > max)max = tab[i][j];
    }
  }
  return max - min;
}

//funkcja rekurencyjna f(0)=0 f(1)=1 f(n)= (-1)^n *1/n + f(n-1)
double funkRek(int n)
{
  if(n == 0) return 0;
  if(n == 1) return 1;
  double a = double(n); //rzutowanie na double
  if(n % 2 == 0) return (1 / a) + funkRek(n - 1); //WA¯NE znak ^ nie oznacza potêgowania tylko XOR
  return (-1 / a) + funkRek(n - 1); // nie u¿ywaj¹c funk bibliotecznych mo¿emy rozbiæ na przypadki
}

//ci¹g Lucasa
int Lucas(int n)
{
  if(n == 0) return 2;
  if(n == 1)return 1;
  return Lucas(n - 1) + Lucas(n - 2);
}

//ci¹g Ackermana
int Ackerman(int m, int n)
{
  if(m == 0) return n + 1;
  if(m > 0 && n == 0) return Ackerman(m - 1, 1);
  if(m > 0 && n > 0) return Ackerman(m-1, Ackerman(m,n - 1));
}