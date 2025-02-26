// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
   // cout << "To jest pierwszy przyk³ad w C \n Podaj wartosc int: ";
    printf("To jest pierwszy przyk³ad w C \n Podaj wartosc int: ");
    int x = 0;
    cin >> x;
    //cout << " x = " << x << '\n';
    // pojedyncze cudzys³ów to 1 bajt, cudzys³ów to 10 bajtów, dlatego przy jednym znaku lepiej tak
    printf("x = %d (hex)%x (oct)%o\n", x, x, x );
    return 0;
}

// void oznacza funkcje bezparametrow¹

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
