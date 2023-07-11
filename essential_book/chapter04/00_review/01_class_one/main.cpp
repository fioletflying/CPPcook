#include "Stack.hpp"
#include "Triangular.hpp"

using namespace std;


int main()
{

    cout << "construction function" <<endl;
    Triangular t(2,1);
    // 不能这样子定义类，会被误认为是函数
    // Triangular t2();
    // 默认的构造函数的对象定义，不需要带括号
    Triangular t2;


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