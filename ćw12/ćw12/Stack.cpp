#include "Stack.h"
#include <stdio.h>

#include <limits.h> // dla typow calkowitoliczbowych DBL_MIN
#include <float.h> // dla zmiennoprzecinkowych

#define MAXSTACK 10
char Stack[MAXSTACK] = { 0 };
int nHead; // indeks pierwszego wolnego miejsca na stosie

//zdefiniowa� nag��wki funkcji prywatnych i na koncu je zaimplementowac w dowolnej kolejnosci
void funkcjaPrywatna();

void initStack() // inicjuje stos
{
  nHead = 0;
}

void push(char c) //w�o�y� na stos znak c
{
  if(nHead >= MAXSTACK)
  {
    printf("\nERROR: Stack overflow!!\n");
    return;
  }

  Stack[nHead++] = c;
}

char pop() // zdjecie ze stosu elementu szczytowego i zwr�cenie go (=top()+del())
{
  if(isEmpty())
  {
    printf("\nERROR: stack underflow!!\n"); //stack is empty
    return 0;
  }

  char c = top();
  del();
  return c;

}

char top() //zwraca warto�� elementu szczytowego (nie usuwa go)
{
  if(isEmpty())
    return 0;
 
  return Stack[nHead-1];
}

void del() // usuwa element szczytowy
{
  if(!isEmpty())
  {
    nHead--;
  }
  else printf("\nERROR: stack underflow!!\n");
}

int isEmpty() // sprawdza czy stos jest pusty, je�li tak to True(1) else False(0)
{
  return !nHead;  // wa�ne ka�dy warunek trzeba tak pisa�
}

void funkcjaPrywatna()
{

}