#include<iostream>

using namespace std;

// 第一个版本的Triangular
// 定义三个构造函数

class Triangular{
public:
    // 无任何参数的构造函数
    Triangular();
    // 带一个参数
    Triangular(int len);
    // 带两个参数
    Triangular(int len, int beg_pos);
    // 带三个参数
    Triangular(int len, int beg_pos, string name);
//类的参数
private:
    int _length;    // 元素个数
    int _beg_pos;   // 起始位置
    int _next;      // 下一个迭代目标
    string _name;
};

Triangular::Triangular()
{
    cout << "no parameter" <<endl;
    _length = 1;
    _beg_pos = 1;
    _next = 0;
}

Triangular::Triangular(int len)
{
    cout << "one parameter" <<endl;
    _length = len > 0 ? len : 1;
    _beg_pos = 1;
    _next = 0;
}

Triangular::Triangular(int len, int bp)
{
    cout << "tow parameter" <<endl;
    _length = len > 0 ? len : 1;
    _beg_pos = bp > 0 ? bp : 1;
    _next = _beg_pos - 1;
}

// 使用初始化列表的方式来定义构造函数
Triangular::Triangular(int len, int bp, string name):_length(len),_beg_pos(bp),_name("Triangular")
{

}


int main()
{
    Triangular t11;
    // 这个不能改成 t1（）, 会被定义为一个函数，无法定义为一个对象
    // Triangular t1();
    Triangular t2(10);
    Triangular t3(10,1);    

    cout << "constractor example!"<<endl;
    return 0;
}




