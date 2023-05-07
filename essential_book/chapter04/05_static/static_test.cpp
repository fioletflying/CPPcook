#include<iostream>
#include"Triangular.hpp"
using namespace std;

int main2()
{
    char ch;
    bool more = true;

    while ( more )
    {
        Triangular::display();
        cout << "Enter value: ";
        int ival;

        cin >> ival;



        bool is_elem = Triangular::is_elem(ival);
        cout << ival
            << (is_elem ? "  is " : " is not " )
            << "an element in the Triangular series.\n"
            << "Another value?(y/n)";

        cin >> ch;
        if ( ch == 'n' || ch == 'N')
            more = false;
    }
}