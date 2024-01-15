#ifndef TRIANGULAR_ITEREATOR
#define TRIANGULAR_ITEREATOR

#include"Triangular.hpp"
#include<iostream>

using namespace std;

class Triangular_iterator
{
friend inline int operator*(const Triangular_iterator &rhs);
private:
    int _index;

public:
    Triangular_iterator(int index) : _index(index - 1){};

public:
    bool operator==(const Triangular_iterator& ) const;
    bool operator!=(const Triangular_iterator& ) const;

    // int operator*() const;
    // 前置++
    Triangular_iterator& operator++();
    // 后置++
    Triangular_iterator operator++(int);


public:
    void check_integrity() const;
};


int operator*(const Triangular_iterator &rhs);


#endif