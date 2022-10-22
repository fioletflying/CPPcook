#include<iostream>
using namespace std;

int main()
{
    {
        // 关于指针引入的目的
        // 1、增加程序的灵活性：用来间接的访问每个vector,因为可以通过更改指针的地址，可以定位到不同的vector
        // 2、减少直接操作对象的复杂度
    }

    {
        int ival = 1024;
        // 定义指向int类型的指针
        int *pi;
        // 初始化该指针指向的数据
        pi = &ival;
        // *pi: 提领操作，获取指向对象的数据
        cout << "pi: " << *pi << ' ' << pi << " " << &pi <<endl;

        // 复杂一: 指针的双重性质：
        // 取内存地址 pi 和指针指向的对象值 *pi
        // 修改指针的数据就相当于修改了指向该对象
        if ( *pi == 1024)
        {
            *pi = 2048;
        }
        cout << "pi: " << *pi << " " 
             << "ival:" << ival << endl;

        // 复杂二: 指针可能并不指向任何对象: 在提领之前必须要指向某个对象
        // 比如直接定义的时候, 这样没有初始化,有可能导致错误
        int *ppi = 0;
        cout << ppi << endl;

        if (*ppi && *ppi == 0)
        {
            cout << *ppi << endl;
        }


    }

    cout << "Hello CPP Pointer" <<endl;
    return 0;
}