#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 前置声明一个class
class Stack;
// 前置声明的作用： 告诉编译器有这样一个类型
// 这样可以进行类指针的定义,用于作为数据类型
Stack *pt = 0;
void process( const Stack& );

// 定义 class
class Stack
{
    // public 接口部分
    public:

        Stack()
        {
            
        };
        // 这里仅仅只是成员函数的声明
        bool push(const string&);
        bool pop(string &elem);
        bool peek(string &elem);
        bool empty();
        bool full();

        // 将函数定义在class 本身中,编译器会默认为inline函数
        int size(){return _stack.size();};

    // private接口部分
    private:
        vector<string> _stack;

};