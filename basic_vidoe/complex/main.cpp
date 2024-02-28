#include<iostream>
#include"complex.h"
#include "mystring.hpp"

using namespace std;

int main()
{
    complex c1(1,2);
    cout << c1 <<endl;
    cout << "test" <<endl;


    mystring str("123");
    mystring str2(str);
    mystring str3;
    cout <<"str3:" << str3 <<endl;
    str3 = str;
    cout <<"str3:" << str3 <<endl;
    return 0;
}