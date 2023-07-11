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
    _name("test")
    {
        _length = ( length < 1 ? 1 : length);
        _beg_pos = ( beg_pos < 1 ? 1 : beg_pos);
        _next = _beg_pos - 1;
        cout << _name <<endl;
    }


private:
    string _name;
    int _length;
    int _beg_pos;
    int _next;

};