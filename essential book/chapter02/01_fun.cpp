#include<iostream>

using namespace std;
/**
 * 函数的作用
 * 1、取代重复代码
 * 2、方面不同模块待用
 * 3、模块化，团队并行开发
 * ***/

// 函数声明
int fibon_elem_1(int pos);
bool fibon_elem_2(int pos, int& elem);

int main()
{
    cout << fibon_elem_1(10) << endl;
    return 0;
}
/***
 * 函数定义的四个东西
 * 1、返回值： return 定义
 * 2、函数名
 * 3、参数
 * 4、函数体
 * ***/
int fibon_elem_1(int pos)
{
    int elem = 1;
    int n_2 = 1, n_1 = 1;
    for ( int ix = 3; ix <= pos; ++ix )
    {
        elem = n_2 + n_1;
        n_2 = n_1; n_1 = elem;
    }

    return elem;
}

// 需要对传入的参数进行判断
bool fibon_elem_2(int pos, int& elem)
{
    // 判断参数传入的范围
    if (pos < 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }

    elem = 1;
    int n_2 = 1, n_1 = 1;
    for ( int ix = 3; ix <= pos; ++ix )
    {
        elem = n_2 + n_1;
        n_2 = n_1; n_1 = elem;
    }

    return true;
}