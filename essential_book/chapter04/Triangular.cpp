#include"incleude/Triangular.hpp"


vector<int>Triangular::_elems;
const int Triangular::_max_elems = 1024;

Triangular::Triangular(int length, int beg_pos)
    : _length(length > 0 ? length : 1),
    _beg_pos(beg_pos > 0 ? beg_pos : 1)
    {
        _next = _beg_pos - 1;
        int elem_cnt = _beg_pos + _length - 1;

        if (_elems.size() < elem_cnt)
        // 调用static function 跟正常的成员函数一样
            gen_elements( elem_cnt );
            
    }

int Triangular::elem(int pos) const
{
    return _elems[pos - 1];
}

bool Triangular::next(int &value)
{
    if (_next < _beg_pos + _length - 1)
    {
        value = _elems[ _next++ ];
        return true;
    }

    return false;
}

// this 指针的设计
Triangular& Triangular::copy(const Triangular &rhs)
{
    if (this != &rhs)
    {
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos;
    }

    return *this;
}

// staic function
// 无需在添加static关键字
bool Triangular::is_elem(int value)
{
    if ( ! _elems.size() || 
            _elems[ _elems.size()-1 ] < value)
                gen_elements_to_value( value );
    
    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = find( _elems.begin(), _elems.end(), value );
    return found_it != end_it;
}


void Triangular::gen_elements( int length )
{
    if ( length < 0 || length > _max_elems )
    {
        cout << "length error!!!!" <<endl;
        return;
    }

    if ( _elems.size() < length )
    {
        int ix = _elems.size() ? _elems.size() + 1 : 1;
        for(; ix <= length; ++ix )
        {
            _elems.push_back( ix*( ix+1 )/2 );
        }
    }
}

void Triangular::gen_elements_to_value( int value )
{
    int ix = _elems.size();
    if ( !ix )
    {
        _elems.push_back( 1 );
        ix = 1;
    }
    while ( _elems[ix - 1] < value && ix < _max_elems )
    {
        ++ix;
        _elems.push_back( ix*(ix+1)/2 );
    }

    if ( ix == _max_elems )
    {
        cerr << "Triangular Sequence : oops: value too large"
            << value << " -- exceeds max size of"
            << _max_elems << endl;
    }
}

