#ifndef __TRIANGULAR__
#define __TRIANGULAR__

#include<vector>
#include<iostream>
#include"Triangular_iterator.hpp"
using namespace std;



class Triangular
{

// 使用 friend关键字实现友元函数，可以直接访问私有变量
friend int Triangular_iterator::operator*() const;
friend void Triangular_iterator::check_integrity() const;

public:
    Triangular(int length, int beg_pos);
    // 析构函数
    ~Triangular(){};

public:
    // 定义一个嵌套类型
    typedef Triangular_iterator iterator;

    Triangular_iterator begin() const
    {
        return Triangular_iterator( _beg_pos );
    }

    Triangular_iterator end() const
    {
        return Triangular_iterator( _beg_pos + _length);
    }



// 常量成员函数：不能改变对象的成员变量
// 这个可以被常量对象调用
public:
    int length() const { return _length;}
    int beg_pos() const { return _beg_pos;}
    int elem( int ) const;

    bool next( int &val );
    void next_reset() {_next = _beg_pos - 1;}

public:
    static bool is_elem( int value );
    static void gen_elements( int length );
    static void gen_elems_to_value( int value);
    static void display();

private:
    int _length, _beg_pos, _next;
    static vector<int> _elems;
    static int _max_elems;



};



#endif