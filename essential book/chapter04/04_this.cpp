#include<iostream>

using namespace std;


class Triangular{
public:
    Triangular(int length=1, int beg_pos = 1)
        : _length(length > 0 ? length : 1),
         _beg_pos(beg_pos > 0 ? beg_pos : 1)
         {
            _next = _beg_pos - 1;
         }

    Triangular& copy(const Triangular &rhs)
    {
        if (this != &rhs)
        {   
            _length = rhs._length;
            _beg_pos = rhs._beg_pos;
            _next = rhs._next;

        }


        // this 指针的使用
        return *this;
    }

private:
    int _length;
    int _beg_pos;
    int _next;

    
}