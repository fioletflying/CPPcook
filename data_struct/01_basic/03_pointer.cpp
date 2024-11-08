#include <iostream>

using namespace std;


int main()
{

    int a= 10;
    // 声明一个指针
    int *p;
    // 初始化一个指针指向变量 a 的地址
    p = &a;

    cout << "a: " << a << endl;
    cout << "&a: " << &a <<  endl;

    cout << "p: " << p << endl;

    cout << "*p: " << *p << endl;

    // 访问堆上面的数据
    // 使用new在堆上新建数据
    int *p2 = new int[3];
    p2[0] = 0;
    p2[1] = 1;
    p2[2] = 2;

    for (int i = 0; i < 3; i++)
    {
        cout << p2[i] << " , ";
    }

    cout << endl;
    

    




    cout << "data struct ch01" << endl;
    return 0;
}