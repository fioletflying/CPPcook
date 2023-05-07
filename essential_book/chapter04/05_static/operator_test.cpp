#include<iostream>
#include"Triangular.hpp"
#include"Triangular_iterator.hpp"

using namespace std;

int main()
{
    Triangular tri(20);
    Triangular::iterator it = tri.begin();
    Triangular::iterator end_it = tri.end();

    cout << "Triangular Series of" << tri.length() << " elements\n";
    cout << tri <<endl;
}