// zabezpieczycy przed wielokrotnym inkludowaniem

#ifndef STACK_H
#define STACK_H

void initStack(); // inicjuje stos
void push(char c); //w�o�y� na stos znak c
char pop(); // zdjecie ze stosu elementu szczytowego i zwr�cenie go (=top()+del())
char top(); //zwraca warto�� elementu szczytowego (nie usuwa go)
void del(); // usuwa element szczytowy
int isEmpty(); // sprawdza czy stos jest pusty, je�li tak to True(1) else False(0)

#endif
