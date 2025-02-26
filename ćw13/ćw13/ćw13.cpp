
#include <iostream>
#include <stdio.h>
#include<string.h>

typedef unsigned short int USHORT;
// od tej definicji dalej mozna uzywac identyfikatora tego typu
typedef unsigned char BYTE;

typedef enum { BLACK, GRAY, GINGER, YELLOW} HairColor;

/*
typedef enum { BLACK, GRAY, GINGER=100, YELLOW} HairColor;
wtedy yellow będzie równe 101
*/

typedef struct //
{
  BYTE mDay;
  BYTE mMonth;
  BYTE mYear;
} Date;

#define MAXNAME 30
typedef struct
{
  USHORT ID;
  char fName[MAXNAME + 1]; // 1 dodatkowy znak na znacznikać konca lancucha znakowego
  char sName[MAXNAME + 1];
  BYTE YearofStudy;
  double Ave; // średnia studiów
  Date Birth; // data urodzenia
  HairColor hair;
} Student;

void printStudent(Student* pStud, int nSize);

void StrCpy(char* s1, char* s2);
void toupper(char* s);

int main()
{
  //USHORT x = 1;
  Student s1[2] = {10012, "Patrycja", "Niedziela", 2, 3.87,{12,1,2004}, YELLOW};
  s1[0].Birth.mDay = 28;
  printStudent(s1, sizeof(s1)/sizeof(Student));
  return 0;

  char str1[] = "abcdefgh";
  char str2[11] = "0123456789"; // max 10 znaków
  const char* str3 = "ABCDEF";


}

void printStudent(Student* pStud, int nSize)
{
  for(int i = 0; i < nSize;i++, pStud++)
  {

    printf("[%d-rok %d] %s %s srednia=%.2lf (%d/%d/%d)",
      pStud->ID, pStud->YearofStudy, pStud->Ave, pStud->Birth.mDay,
      pStud->Birth.mMonth, pStud->Birth.mYear);

    // można użyc S[i] zamiast strzałki

    switch(pStud->hair)
    {
    case BLACK: printf("włosy: Brunet/ka"); break;
    case GRAY: printf("włosy: Szatyn/ka"); break;
    case GINGER: printf("włosy: Rudy/a"); break;
    case YELLOW: printf("włosy: Blondyn/ka"); break;

    }
    printf("/n");

  }
}

void StrCpy(char* s1, char* s2)
{
 // int i = 0;
  //while(s1[i] = s2[i++]);

  while(*s1++ = *s2++);
}

void toupper(char* s)
{/*
  int i = 0;
  while(s[i])
  {
    if(s[i] >= 'a' && s[i] <= 'z')
      s[i++] -= 0x20; //32 w liczbie szesnastkowej
  }
  */

  int len = (int)strlen(s);
  for(int i = 0;i < len;i++)
    if(s[i] >= 'a' && s[i] <= 'z')
      s[i] -= 0x20;
}