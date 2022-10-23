#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
    {
        // 指针的内存大小一般都是固定的
        // 它仅仅代表对象的内存地址
        char * pc = 0;
        int * pi = 0;
        double *pd = 0;
        string *ps = 0;

        cout  << "char *: "  << sizeof(pc)  << " "
            << "int *: " << sizeof(pi) << " "
            << "double *: " <<sizeof(pd) << " "
            << "string *: "  << sizeof(ps) << endl;

    }
    {
        vector<int> fibonacci, lucas, pell, triangular, square, pentagonal;
        // 指针需要指向的类型，格式：type_of_object_point_to * name
        vector<int> * pv = 0;
        pv = &fibonacci;
        pv = &lucas;

        cout << pv << endl;

        const int seq_cnt = 6;
        // 指针数组： 用来存放指针的数组
        vector<int> *seq_addrs[seq_cnt] = {
            &fibonacci, &lucas, &pell, &triangular, &square, &pentagonal
        };
        // seq_addrs[0] -> 指向是 fibonacci vector 的地址

        // 遍历指针数组中的元素，这个元素他是一个vector 容器的地址
        vector<int> *current_vec = 0;
        for ( int ix = 0; ix < seq_cnt;  ++ix)
        {
            current_vec = seq_addrs[ix];
        }

        // 随机数的生成
        //rand() 和 srand()
        srand(100); // 随机数生成器， 参数是seed 种子
        // rand() 不指定参数随机生成0-最大整数
        int seq_index = rand() % seq_cnt;
        cout << "seq_index: " << seq_index <<endl;

        // dot 操作
        if (! fibonacci.empty() && (fibonacci[0] == 1))
        {
            cout << "test vector empty" << endl;
        }
        // 指针的arrow操作
        if ( pv && ! pv->empty() && ( (*pv)[1] == 1))
        {
            cout << "test pointer evmpty ->" << endl;
        }
    }



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
        // 主要是用来防止对null指针进行提领操作
        // 这里有一个细节： AND 运算符是从左往右执行的，如果第一个为false，就不会再继续执行了
        if (ppi && *ppi == 0)
        {
            *ppi = 100;
            cout << *ppi << endl;
        }


    }

    cout << "Hello CPP Pointer" <<endl;
    return 0;
}