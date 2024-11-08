#include <iostream>

using namespace std;


int main()
{

    int a = 10;
    // 定义引用一定要初始化
    // ra一旦初始化了，就不能在指向其他的变量
    int &ra = a;

    cout << "a :" << a << endl;

    ra =100;

    cout << "ra: " << ra << endl;
    cout << "a: " << a << endl;

    int b = 2;
    // 这里不是让ra 指向b,而是将b的值赋给a
    ra = b;
    cout << "ra: " << ra << endl;   
    cout << "a: " << a << endl;


    cout << "data struct ch01" << endl;
    return 0;
}