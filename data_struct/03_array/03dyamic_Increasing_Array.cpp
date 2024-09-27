#include<iostream>
using namespace std;

//数组存储位置：栈与堆

int main()
{
    int *p, *q;
    p = new int[5];
    //不能直接使用{}来初始化，这个静态数组可以使用
    // p = {1};
    for (size_t i = 0; i < 5; i++)
    {
        // *p = i;
        // p++;

        p[i] = i;
    }

    cout << p[2] <<endl;

    for (size_t i = 0; i < 5; i++)
    {
        // 使用这种方式会改变指针的位置
        // cout << *p << "," << endl;
        // p++;
        cout << p[i] << endl;
    }

    //****扩展p的大小****
    // 1 创建一个新的指针,并指定需要扩展的大小
    q = new int[10];

    // 2 利用原来的数组进行初始化
    for (size_t i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    for (size_t i = 0; i < 5; i++)
    {
        // cout << *q << ",";
        // q++;
        cout << q[i] << endl;
    }

    // 3 释放原来数组的内存
    delete[] p;

    // 4 将指针指向新的数据
    p = q;
    // 5 让新的指针赋值为NULL
    q = NULL;

    for (size_t i = 0; i < 10; i++)
    {
        cout << p[i] << endl;
    }

    

    std::cout << "hello algorithm \n";
    return 0;
}