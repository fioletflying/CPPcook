#ifndef __TRIANGULAR__
#define __TRIANGULAR__

#include<vector>

using namespace std;

class Triangular
{
public:
    Triangular(int length, int beg_pos)
        :_length(length > 0 ? length : 1),
        _beg_pos(beg_pos > 0 ? beg_pos : 1),
        _next(_beg_pos - 1)
        {}

        int length() const {return _length;}
        int beg_pos() const {return _beg_pos;}
        int elem(int pos) const;

        // 相关成员变量会被更改
        bool next(int &val);
        void next_reset() {_next = _beg_pos - 1;}
        Triangular& copy(const Triangular &rhs);



private:
    int _length, _beg_pos,_next;
    static vector<int> _elems;


};

#endif