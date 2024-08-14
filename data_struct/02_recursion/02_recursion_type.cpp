#include <iostream>

//递归的种类

/********尾递归（tail recusion）*********************/
//递归函数调用在最后一步执行了返回操作

void fun_tail(int n)
{
    if(n > 0)
    {
        std::cout << n << std::endl;
        fun_tail(n - 1);
    }
}

//可以使用循环来实现
//因是按照顺序来执行的
void fun_tail_loop(int n)
{
    while(n > 0)
    {
        std::cout << n << std::endl;
        n --;
    }
}



/**************************************************/


int main()
{
    fun_tail(5);
    fun_tail_loop(5);

    return 0;
}