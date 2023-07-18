#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Triangular
{
public:
    // 默认构造函数
    Triangular()
    {
        _length = 1;
        _beg_pos = 1;
        _next = 0;
    }
    // 带有参数的构造函数
    Triangular( int length, int beg_pos):
    _name("Trangular")
    {
        cout << _name << endl;
        _length = ( length < 1 ? 1 : length);
        _beg_pos = ( beg_pos < 1 ? 1 : beg_pos);
        _next = _beg_pos - 1;
        cout << _name <<endl;
    }

public:
    int length() const { return _length;}
    int beg_pos() const { return _beg_pos;}
    int elem( int pos ) const;

// 如果需要修改class member parameter, 则不能定义其为const
    // bool next(int &val ) const;
    // void next_reset() const { _next = _beg_pos - 1; }

    bool next(int &val ) const;
    void next_reset() const { _next = _beg_pos - 1; }
     // 可变成员变量的定义方式
    // int sum( const Triangular& trian );

   
    // this 指针的由来
    Triangular copy(Triangular& rhs);
    

private:
    string _name;
    int _length;
    int _beg_pos;
    // mutable表示_next改变并不会破坏class 对象的常量性
    mutable int _next;

    static vector<int> _elems_const;

};

int Triangular::elem( int pos) const
{
    if(pos > 0 && pos < _elems_const.size())
    {
        return _elems_const[ pos-1 ];
    }

    return -1;
        
}

// const 成员函数错误示例
// bool Triangular::next( int &val) const
// {
//     if ( _next < _beg_pos + _length - 1)
//     {
//         // 如果函数定义了const ,而这里又对其next做了修改，编译器会报错
//         val = _elems[ _next++ ];
//         return true;
//     }

//     return false;
// }


bool Triangular::next( int &val) const
{
    if ( _next < _beg_pos + _length - 1 && _elems_const.size())
    {
        // 如果函数定义了const ,而这里又对其next做了修改，编译器会报错
        val = _elems_const[ _next++ ];
        return true;
    }

    return false;
}

// 这里返回的是对象本身, 在class中一般使用this指针了表示
// 可以简单的认为:对于member function,里面有一个默认参数,就是this
// 这个跟python中类的方法里面显性的定义个self道理是类似的
Triangular Triangular::copy(Triangular &rhs)
{
    if(&rhs != this)
    {
        _length = rhs.length();
        _beg_pos = rhs.beg_pos();
        _next = _beg_pos - 1;
    }
    return *this;
}
