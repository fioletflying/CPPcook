#include"Triangular.hpp"

using namespace std;

int Triangular::_max_elems = 1024;
vector<int> Triangular::_elems;

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
        // 作为一个标准的流对象，用来记录错误信息
        cerr << "Error: pos is not a good number." << endl;
        return -1;
    }

    return _elems[pos-1];
}

bool Triangular::is_elem(int value)
{
    if ( !_elems.size() || _elems[ _elems.size()-1 ] < value)
    {
        Triangular::gen_elems_to_value(value);
        cerr << " the value is not in _elems" << endl;
        return false;
    }

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elems_to_value( int value )
{
    int ix = _elems.size();
    if (!ix )
    {
        _elems.push_back(1);
        ix = 1;
    }
    while ( _elems[ ix-1 ] < value && ix < _max_elems )
    {
        ++ix;
        _elems.push_back( ix*(ix+1)/2 );
    }
    if ( ix == _max_elems )
    {
        cerr << "Triangular Sequence: oops: value too large"
            << value << "-- exceeds max size of "
            << _max_elems <<endl;
    }
}

void Triangular::gen_elements(int length)
{
    if ( length < 0 || length > _max_elems)
    {
        cerr << "The " << length << "is not a suitable number" << endl;
        return;
    }

    if ( _elems.size() < length )
    {
        int ix = _elems.size() ? _elems.size()+1 : 1;
        for( ; ix <= length; ++ix)
            _elems.push_back( ix*(ix + 1)/2);
    }

    return;
}

void Triangular::display()
{
    if(_elems.size())
    {
        vector<int>::iterator ix = _elems.begin();
        for(; ix != _elems.end(); ++ix)
        {
            cout << *ix << " ";
        }
        cout << endl; 
        return;
    }
    return;
}
