#include"Triangular.hpp"

using namespace std;

Triangular::Triangular(int length, int beg_pos)
    :_length( length > 0 ? length : 1),
    _beg_pos( beg_pos > 0 ? beg_pos : 1)
{
    _next = _beg_pos - 1;
}


int Triangular::elem(int pos) const
{
    if ((pos > _length) || ( pos < 0))
    {
        cerr << "";
    }
}