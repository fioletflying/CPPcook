#include "Stack.hpp"
// #include "Triangular.hpp"
#include "Triangular_const.hpp"
#include "Triangular_static.hpp"
#include "Matrix.hpp"

using namespace std;

vector<int>Triangular::_elems_const;
vector<int>Triangular_static::_elems;



int main()
{

    char ch;
    bool more = true;
    while( more )
    {
        cout << "Enter value: ";
        int ival;
        cin >> ival;

        bool is_elem = Triangular_static::is_elem( ival );

        cout << ival 
             << ( is_elem ? " is " : " is not ")
             << " an element in the series.\n"
             << "Another value?(y/n)";
        cin >> ch;
        if ( ch == 'n' || ch == 'N')
            more = false;
    }

    return 0;
}

// 这里直接调用是无法被调用的
// 因为这里使用const Triangular,而里面的next_reset会改变trian里面的值
// 所以这里需要使用一个新的语法
int sum(const Triangular &trian)
{
    if( !trian.length() )
        return 0;

    int val, sum = 0;
    trian.next_reset();
    while( trian.next(val))
        sum += val;

    return sum;
}


int main_const()
{
    Triangular tri(4,3);
    cout <<  sum(tri) <<endl; 
    return 0;
}




int main_matrix()
{
    // 带有指针内存的创建的类
    Matrix mat(2,3);

    return 0;
}




int main2()
{

    cout << "construction function" <<endl;
    Triangular t(2,1);
    // 不能这样子定义类，会被误认为是函数
    // Triangular t2();
    // 默认的构造函数的对象定义，不需要带括号
    Triangular t2;

    return 0;

}

int main1()
{
    cout << "test class first program." <<endl;

    // 定义一个对象
    Stack stc;
    // 调用对象的成员函数
    stc.push("abc");
    stc.push("def");

    string elem;
    if (stc.peek(elem))
        cout<< elem <<endl;

    return 0;
}