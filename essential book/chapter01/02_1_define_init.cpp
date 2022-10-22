#include<iostream>
#include<string>

#include<complex>

using namespace std;

int main()
{
    string user_name;
    int usr_val;

    // 使用赋值=语句来进行初始化的赋值
    // int num_tries = 0;
    // int num_right = 0;

    // 可以使用一条语句来申明并初始化多个对象
    int num_tries = 0, num_right = 0;

    // 可以使用构造语法来实现初始化
    int num_tries2(0);

    cout << "num_tries2: " << num_tries2 << endl
         << "num_tries: " << num_tries << endl;

    // 为什么需要使用构造函数初始化，因为这个方便对多值进行初始化
    complex<double> comp_test(0,7);

    // 比如对复数进行初始化的时候就需要对实部和虚部进行初始化
    cout << "comp_test" << comp_test << endl;

    // 计分使用double类型来定义
    double usr_score = 0.0;

    // char的使用:单引号代表字符常量：'a', '7'
    char usr_more;
    cout << "Try another sequence? Y/N? ";
    // cin >> usr_more;

    char a_char = 'a';
    cout << "a_char: " << a_char <<endl;  

    
    // 一种特殊的字符类型： 转义字符(escape sequence)
    // '\n'
    // 比如需要定义 ' 字符，就需要使用‘\’来定义
    char star_char = '\'';
    cout << "star_char: " << star_char <<endl;  
    cout << "1*1 = 1\n"
         << "1*2 = 2\t" << "2*2 = 4 \n"
         << "1*3 = 3\t" << "2*3 = 6\t" << "3*3 = 9\n";


    // const 常量对象定义
    const double double_pi = 3.14159;
    // 这个会报错，无法被修改
    // double_pi = 3.14


    // return 0;
}