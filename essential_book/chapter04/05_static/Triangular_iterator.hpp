#ifndef __TRIANGULAR_ITERATOR__
#define __TRIANGULAR_ITERATOR__

// #include"Triangular.hpp"
#include<iterator>



class Triangular_iterator
{
class Triangular;
public:
    Triangular_iterator( int index) : _index( index-1 ){}
    // 操作符重载 == 与 !=
    bool operator==( const Triangular_iterator& ) const;
    bool operator!=( const Triangular_iterator& ) const;
    // 提领操作符重载
    int operator*() const;
    // 前置++
    Triangular_iterator& operator++();
    // 后置++
    Triangular_iterator operator++( int );


private:
    int _index;
    void check_integrity() const;
};

#endif