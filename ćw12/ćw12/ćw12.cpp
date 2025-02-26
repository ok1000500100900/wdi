
#include <iostream>
#include "Stack.h"
using namespace std;

#include <stdio.h>

int main()
{
  // implementacja modułu stosu znakowego - kolejka LIFO (last in first out)

  push('A');
  push('B');
  push('C');

  // cout << pop() << pop() << pop(); <-- nie wolno wywoływać wiecej niz raz funkcje
  // która modyfikuje tą saną strukturę

  cout << pop();
  cout << pop();
  cout << pop();


  printf("\n");
  return 0;
}

// spróbować napisać moduł liczbowy, tak samo, ale typ
// zamiast char double
// nie mozna zwrocic zero, trzeba wypisac DBL_MIN i zainkludować plik
// jak bedziemy robic int stack to nazwac go dstack
// można zrobić kalkulator