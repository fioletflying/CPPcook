#include<iostream>
using namespace std;

//数组存储位置：栈与堆

int main2()
{
    // 在栈区定义一个数组变量
    int A[5] = {2,4,6,8,10};
    // 在堆上面定义一个数组变量
    // 需要通过指针的方式来定义
    int *p = new int[5];
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;

    for (size_t i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    }

    // 指针访问的方式
    for (size_t i = 0; i < 5; i++)
    {
        // cout << p[i] << endl;
        cout << *p << endl;
        p++;
    }
    
    std::cout << "hello algorithm \n";
    return 0;
}