#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{

    // 随机数
    {   
        const int seq_cnt = 6;
        srand(3);
        int seq_index = rand() % seq_cnt;
        cout << "random number: " << seq_index <<endl;

    }




    // 指针数组的定义: 用来存放数组的指针
    // 数组指针:用来指向数组的指针
    // C++ 的语法就是那么的讨厌,总是整这些东西,让人费解
    // 这个也是为了使得C++达到灵活,高效为设计的
    {
        vector<int> fibonacci, lucas, pell, triangular, square, pentagonal;

        vector<int> * pv = 0;

        pv = &fibonacci;

        cout << "*pv: " << pv->size() << endl; 

        const int seq_cnt = 6;

        // 定义一个指针数组, 数组里面每个对象都指向一个vector <int>对象
        vector<int> *seq_addrs[ seq_cnt ] = {
            &fibonacci, &lucas, &pell, &triangular, &square, &pentagonal
        };

        // 访问指针数组
        vector<int> *current_vec = 0;
        for ( int ix = 0; ix < seq_cnt; ++ix)
        {
            current_vec = seq_addrs[ ix ];
            // 指针的操作->
            cout << "current_vec size: " <<ix << "::" << current_vec->size() <<endl;
        }

        
        
    }




    // 指针的定义
    {
        int ival = 1023;
        // 取地址符号的使用： &，获得当前的变量对象的地址
        cout << "ival: " << ival << endl
             << "&ival: " << &ival << endl;
        // 定义了一个指针，指向int类型的指针
        int *pi = &ival;
        cout << "pi: " << pi << endl
             << "*pi: " << *pi << endl;
        if (*pi != 1024)
            *pi = 1024;

        // 复杂一: 指针的双重性质：
        // 取内存地址 pi 和指针指向的对象值 *pi
        cout << "ival: " << ival << endl
             << "&ival: " << &ival << endl;

        // 复杂二: 指针可能并不指向任何对象: 在提领之前必须要指向某个对象
        // 比如直接定义的时候, 这样没有初始化,有可能导致错误
        int *ppi;
        cout << "*ppi: " << *ppi << endl
            << "ppi: " << ppi << endl;
        // 一般处理这个问题,可以让其赋值为0或者null
        // 任何一个类型的指针都可以赋值为0
        int *pi2 = 0;
        double *pd = 0;
        string *ps = 0;
        // cout << "*pi2: " << *pi2 << endl
        //     << "pi2: " << pi2 << endl;
        // 为了防止这个错误,可以在使用的指针的时候使用一个验证程序
        // 这里有一个if的短路原则，从左往右执行，所以当第一个判断为fasle时，
        // 其不会再进行判断了
        if (pi2 && *pi2 != 1024)
        {
            *pi2 = 1024;
            cout << "*pi2: " << *pi2 << endl
                << "pi2: " << pi2 << endl;
        }




    }

    return 0;
}
