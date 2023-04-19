#ifndef __TRIANGULAR__
#define __TRIANGULAR__

#include<vector>
#include<iostream>

class Triangular
{
public:
    Triangular(int length, int beg_pos);
    // 析构函数
    ~Triangular(){};

// 常量成员函数：不能改变对象的成员变量
// 这个可以被常量对象调用
public:
    int length() const { return _length;}
    int beg_pos() const { return _beg_pos;}
    int elem( int pos ) const;

    bool next( int &val );
    void next_reset() {_next = _beg_pos - 1;}
    

private:
    int _length, _beg_pos, _next;



};



#endif