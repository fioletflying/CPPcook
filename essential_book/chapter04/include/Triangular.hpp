#ifndef __TRIANGULAR__
#define __TRIANGULAR__

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Triangular
{
public:
    Triangular(int length, int beg_pos);

    int length() const {return _length;}
    int beg_pos() const {return _beg_pos;}
    int elem(int pos) const;

    // 相关成员变量会被更改
    bool next(int &val);
    void next_reset() {_next = _beg_pos - 1;}
    Triangular& copy(const Triangular &rhs);

    static bool is_elem(int );
    static void gen_elements(int length );
    static void gen_elements_to_value(int value );
    // static void display( int length, int beg_pos, ostream &os = cout );


private:
    int _length, _beg_pos,_next;
    static vector<int> _elems;
    static const int _max_elems;

};

#endif