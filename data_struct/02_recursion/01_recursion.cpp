#include <iostream>

// 递归函数: 每次递减输出，递归调用在后面
// 尾递归
void fun(int n)
{
    if(n > 0)
    {
        std::cout << n << " ";
        fun(n-1);
        
    }
}

// 递归函数: 递归调用在前面, 先进入函数，再输出
// 头递归 
// 
void fun2(int n)
{
    if(n > 0)
    {
        fun2(n-1);
        std::cout << n << " ";
    }
}

// 当有静态变量时的递归情况
// 因为时静态变量，所以每个递归函数中不会拷贝其副本，只有一个地方存放该变量
// 当返回时，只能调用最后保留的数值，所以每次返回时被调用相同的数值
int fun3(int n)
{
    static int x = 0;
    if ( n > 0 )
    {
        x++;
        return(fun3(n-1) + x);
    }
    return 0;
}

// 当有全局变量时的递归情况
// 因为时全局变量，所以每个递归函数中不会拷贝其副本，只有一个地方存放该变量
// 当返回时，只能调用最后保留的数值，所以每次返回时被调用相同的数值
int gloabe_a = 0;
int fun4(int n)
{
    if(n > 0)
    {
        gloabe_a++;
        return fun4(n-1) + gloabe_a;
    }
    return 0;
}

int func_static(int n)
{
    static int x = 0;

    if(n > 0)
    {
        x++;
        std::cout << x << std::endl;
        return func_static(n-1) + x;
    }

    return 0;
}



int main()
{
    // fun(3); // 输出 3 2 1
    // fun2(3); // 输出 1 2 3

    // std::cout << fun3(3) <<std::endl;

    // std::cout << fun4(3) << std::endl;

    std::cout << func_static(4) << std::endl;

    return 0;
}
