#include<iostream>
#include<vector>

using namespace std;

// 常量成员函数
// 用来确保这些函数不会修改class的成员变量
// const object 是无法访问非常量成员函数
class Triangular
{

public:
    Triangular(int len=1, int beg_pos=1):
        _length(len>0 ? len: 1),_beg_pos(beg_pos > 0 ? beg_pos:1)
    {
        _next = _beg_pos - 1;
    }

public:
    // const member function常量成员函数
    int length() const {return _length;}
    int length() {return _length;}
    int beg_pos() const {return _beg_pos;}
    // 申明一个常量成员函数
    int elem(int pos) const;

    //一个被修改的案例
    // 这个会修改 _next的值,编译时会报错
    bool next(int &value) const
    {
        if (_next < _beg_pos + _length - 1)
        {
            // 报错, 更改了_next的值
            value = _elems[_next++];
            return true;
        }
        return false;
    }



private:
    int _length;
    int _beg_pos;
    // 关键字mutable 表示即使_next被改变也不会破坏class的常量属性
    mutable int _next;

    vector<int> _elems= {1,3,5,6,7};

};

// 在class外面定义的时候也要加上const
int Triangular::elem(int pos) const
{
    return _elems[pos - 1];
}

// 求和统计
int sum(const Triangular &train)
{
    // 定义为常量对象只能调用常量成员函数
    int beg_pos = train.beg_pos();
    int length = train.length();

    int sum = 0;

    for (int ix = 0; ix < length; ++ix)
    {
        sum += train.elem(beg_pos+ix);
    }
    return sum;
}

// 返回non_const reference的指向也是不行的,因为这个引用可以被外部修改

class val_class {
public:
    val_class(const int &v)
        : _val(v){}

    // 返回non_const reference的指向也是不行的,因为这个引用可以被外部修改
    // 所以返回值需要加上 const
    const int& val() const {return _val;}
    // 这里也可以看出成员函数重载,可以使用const被区分
    int& val() {return _val;}

private:
    int _val;

};

int main()
{
    
    cout << "常量成员函数的使用" << endl;
    return 0;
}