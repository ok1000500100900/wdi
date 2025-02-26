// ćw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <stdio.h>

int main()
{
	double a = 1;
	double b = 2;
	double c = -4;
	double d = 1;
	double x1 = -2.34;
	double w = ( (a * x1 + b) * x1 + c) * x1 + d;
	printf("wart wielom = %.3lf\n", w );
	return 1;
	// 12.8fl = po przecinku 8, kropka + 3 całkowite razem 12
	// ---------------------------------

	int xx = 13;
	int y = 5;

	int r = xx % y;

	//int r = xx - (xx / y) * y;

	// ----------------------------------
	printf("Podaj liczbę całkowitą: ");
	int x = 0;
	cin >> x;

	//int res = x * x;
	//res = res * res;
	//res = res * x;

	int res = x * x * x * x * x;

	printf("%d^5 = %d\n", x, res);
	return 0;
}

