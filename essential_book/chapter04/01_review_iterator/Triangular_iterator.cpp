#include "Triangular_iterator.hpp"

bool Triangular_iterator::operator==(const Triangular_iterator & rhs) const
{
    return _index == rhs._index;
}

bool Triangular_iterator::operator!=(const Triangular_iterator & rhs) const
{
    return *this != rhs;
}

Triangular_iterator &Triangular_iterator::operator++()
{
    // TODO: insert return statement here
    ++_index;
    check_integrity();
    return *this;
}

Triangular_iterator Triangular_iterator::operator++(int)
{
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;

}

void Triangular_iterator::check_integrity() const
{
    if (_index >= Triangular::_max_elems)
        cerr << "error for index which is out of range.";

    if ( _index >= Triangular::elems.size() )
        Triangular::gen_elements( _index );
}

// inline int Triangular_iterator::operator*() const
// {
//     check_integrity();
//     return Triangular::_elems[ _index ];
// }


inline int operator*(const Triangular_iterator &rhs)
{
    rhs.check_integrity();

    return Triangular::_elems[ _index ];
}
