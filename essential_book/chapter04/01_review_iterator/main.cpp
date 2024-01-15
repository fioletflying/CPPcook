#include <iostream>
#include <string>
#include "Triangular.hpp"

using namespace std;

// static的使用案例
int main()
{
    Triangular t(10, 1);
    char ch;
    bool more = true;

    while (more)
    {

        cout << "Enter value:";
        int ival;
        cin >> ival;

        bool is_elem = Triangular::is_elem(ival);

        cout << ival
             << (is_elem ? " is " : " is not ")
             << " an element in the series.\n"
             << "Another value?(y/n)";

        cin >> ch;
        if (ch == 'n' || ch == 'N')
            more = false;
    }

    cout << "2023-10-11 review chapter 04" << endl;
}