#include <iostream>

using namespace std;

int main()
{
    // 整除
    cout << "5/3:" << 5 / 3 << endl
         << "5/4:" << 5 / 4 << endl
         << "5/4:" << 5 / 5 <<endl;

    // 取余
    cout << "5%3:" << 5 % 3 <<endl
         << "5%4:" << 5 % 4 <<endl
         << "5%5:" << 5 % 5 <<endl;

    // 取余的用法
    // 条件运算符
    const int line_size = 3;
    int cnt = 1;
    string a_string = "abcdefj";
    for(int i = 0; i < 20; i++)
    {
        // 条件运算符 expr ? a : b
        // 如果 为 ture:  执行 a
        // 如果 为 false: 执行 b  
        cout << a_string
            << (cnt % line_size ? ' ' : '\n');
        cnt++;
    }

    // 复合赋值: 就是将对象中的某个运算符然后将结果再赋值给对象本身
    cnt = cnt + 2;
    // 复合运算符赋值: +=, -=, *=, /=, %=
    cnt += 2;
    cout << cnt << endl;

    // 递增和递减的方式: ++ --
    // 前置++ --: 表示该变量已经实现了运算,并获得了结果
    int tries = 0;
    cout << "Are you read for try #" 
         << ++tries << "?\n";
    // 后置++ --: 表示该变量已经实现了运算,但是该结果并没有更新,需要过后才更新
    int tries2 = 0;
    cout << "Are you read for try #"
        << tries2++ << "?\n";

    // 关系运算符: 反馈结果是否为true 或者 false
    // == != < > <= >= 
    bool usr_more = true;
    char usr_rsp;

    if(usr_rsp == 'N')
        usr_more = false;
    
    // 逻辑运算符: || or &&
    // 判断大小写 或 与 与操作: 这里有一个短路求值法,先触发左边,再计算右边
    if (usr_rsp == 'N' || usr_rsp == 'n')
        usr_more = false;
    
    if (usr_rsp == 'N' and usr_more)
        usr_more = false;

    return 0;
}