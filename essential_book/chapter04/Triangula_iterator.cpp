#include"include/Triangular_iterator.hpp"

inline bool Triangular_iterator::
operator==(const Triangular_iterator &rhs) const
{return _index == rhs._index;}

int bool Trianguar_iterator::
operator!=( const Triangular_iterator &rhs) const
    {return !(*this == rhs);}