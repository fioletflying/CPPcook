#include<iostream>
using namespace std;

//数组存储位置：栈与堆

int main()
{
    int *p, *q;
    p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for (size_t i = 0; i < 5; i++)
    {
        cout << p[i] <<" : " << &p[i] <<endl;
    }

    cout << "p指向的地址: " << p <<endl;
    cout << "&p指针的地址: " << &p <<endl;
    //这里需要注意的是，如果对p进行取地址操作的化，会获得存储指针p的地址，
    //这个就是在栈上面了

    //创建需要扩大的动态内存空间
    q = new int[10];

    //拷贝原来的数据到新的内存空间
    for (size_t i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    // 删除原来的内存空间
    delete []p;

    // 将指针指向芯德内存空间的地址
    p = q;
    cout << "p指向的新地址: " << p <<endl;
    cout << "&p指针的地址: " << &p <<endl;
    // 让临时的指针赋值为NULL,断开新建的内存空间的链接
    q = NULL;
    for (size_t i = 0; i < 10; i++)
    {
        cout << p[i] <<" : " << &p[i] <<endl;
    }
    
    
    std::cout << "hello algorithm \n";
    return 0;
}