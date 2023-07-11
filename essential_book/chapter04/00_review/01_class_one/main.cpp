#include "Stack.hpp"

using namespace std;

int main()
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