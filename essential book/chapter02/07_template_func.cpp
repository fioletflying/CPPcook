#include<iostream>
#include<vector>
#include<string>
#include<list>


using namespace std;

// 模版函数：用来实现不同参数类型的适配，避免需要写多个函数体

// 实现的语法如下：将参数的类型抽离出来
// < > 里面的typename 是关键字, T: 是一个占位符,表示类型,可以自定义
template <typename T>
void display_message( const string &msg, const vector<T> &vec);

// list 也是一种容器
template <typename T>
void display_message( const string &msg, const list<T> &lt);

// 模板函数就像一个模具一样可以产生无数的函数,
// 跟重载的区别: 重载是函数的主体会改变
// 但是如果函数主体不变,但是数据类型会改变则可以使用模板函数
// 模板函数也是可以的重载的
template <typename T>
void swap_temp(T& elem1, T& elem2);


int main()
{

    cout << "test inline funciton! \n";

    vector<int> a = {1,2,3,4,5};
    // 如果调用模板函数,这个跟调用普通的函数时一样的方式
    display_message("show vector: ", a);

    return 0;
}

template <typename T>
void swap_temp(T& elem1, T& elem2)
{
    T temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}

template <typename T>
void display_message( const string &msg, const vector<T> &vec)
{
    cout << msg;
    for (int ix=0; ix < vec.size(); ++ix)
    {
        T t = vec[ix];
        cout << t << ' ';
    }
    cout << endl;
}

