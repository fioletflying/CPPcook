#include"Triangular.hpp"
#include<iostream>

using namespace std;

vector<int>Triangular::_elems;

int Triangular::elem(int pos) const
{
    return _elems[pos - 1];
}

bool Triangular::next(int &value)
{
    if (_next < _beg_pos + _length - 1)
    {
        value = _elems[ _next++ ];
        return true;
    }

    return false;
}

// this 指针的设计
Triangular& Triangular::copy(const Triangular &rhs)
{
    if (this != &rhs)
    {
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos;
    }

    return *this;
}


