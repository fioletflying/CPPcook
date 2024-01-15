#ifndef __TRIXXXXX__
#define __TRIXXXXX__

#include <iostream>
#include <vector>
#include <algorithm>
#include "Triangular_iterator.hpp"

using namespace std;

class Triangular
{


public:
    Triangular(int len, int beg_pos) : _length(len > 0 ? len : 1),
                                       _beg_pos(beg_pos > 0 ? beg_pos : 1)
    {
        _next = _beg_pos - 1;
        int elem_cnt = _beg_pos + _length - 1;
    }

    // 常量函数的定义
    // 重点是常量函数可以被常量对象调用
public:
    int get_length() const { return _length; }
    int get_beg_pos() const { return _beg_pos; }
    int elem(int pos) const;
    // 这里改变了成员变量，但是又想定义成常量成员函数
    // 那么需要将_next 设置成mutable,否则后报错:
    // 表示_next改变并不会破坏class 对象的常量性
    void next_reset() const { _next = _beg_pos - 1; }

    // 静态成员函数
public:
    static bool is_elem(int value);
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static void display();

public:
    typedef Triangular_iterator iterator;
    friend inline int operator*(const Triangular_iterator &rhs);

    Triangular_iterator begin() const
    {
        return Triangular_iterator(_beg_pos);
    }

    Triangular_iterator end() const
    {
        return Triangular_iterator(_beg_pos + _length);
    }

private:
    int _length;
    int _beg_pos;
    // 这里定义了_next为被改变的成员变量,因为改变并不会对类的本身的状态有任何变化
    mutable int _next;
    // 静态成员变量定义:表示类中唯一,共享:可以被其他的对象共享使用
    // 类似于全局的变量
    static vector<int> _elems;
    static int const _max_elems = 1024;
};

#endif
