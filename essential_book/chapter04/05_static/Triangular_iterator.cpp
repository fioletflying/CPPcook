#include"Triangular_iterator.hpp"

inline bool Triangular_iterator::
operator==( const Triangular_iterator &rhs ) const
{
    return _index == rhs._index;
}

inline bool Triangular_iterator::
operator!=( const Triangular_iterator &rhs ) const
{
    return !( *this == rhs );
}

// 成员函数的形式-操作符重载
inline int Triangular_iterator::
operator*()const
{
    check_integrity();
    return Triangular::_elems[ _index ];
}

// // 非成员函数的形式-操作符重载
// inline int
// operator*(const Triangular_iterator rhs)
// {
//     // 这里需要注意的是，如果这个是非成员函数的形式，就需要传入这个对象
//     rhs.check_integrity();
//     return Triangular::_elems[]
// }


inline void Triangular_iterator::
check_integrity()const
{
    if( _index >= Triangular::_max_elems )
        cout << "error for out of range"<<endl;

    if( _index >= Triangular::_elems.size() )
        Triangular::gen_elements(_index);
}

// 前置++
inline Triangular_iterator& Triangular_iterator::
operator++()
{
    ++_index;
    check_integrity();
    return *this;
}

// 后置++, 必须有一个参数int
inline Triangular_iterator Triangular_iterator::
operator++( int )
{
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}
