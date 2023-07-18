#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Triangular_static
{
public:
    Triangular_static(int len, int beg_pos):
        _length(len > 0 ? len : 1),
        _beg_pos(beg_pos > 0 ? beg_pos : 1)
    {
        _next = _beg_pos - 1;

        int elem_count = _beg_pos + _length - 1;
        if(elem_count > _elems.size())
        {
            gen_elems(elem_count);
        }
    }

public:
    int get_length() const {return _length; }
    int get_begpos() const {return _beg_pos;}
    int get_elem(int pos) const;

public:
    static void gen_elems(int);
    static void gen_elems_to_value(int value);
    static bool is_elem(int);
    static void display(int length, int beg_pos, ostream &os);

private:
    int _length;
    int _beg_pos;
    int _next;

    static vector<int> _elems;
    // 这里要注意如果不是const 不能在class内部定义
    // 需要在class 外面某个地方定义，比如在cpp文件中定义
    const static int _max_length = 1024;

};

// 在外面定义的时候可以不用
void Triangular_static::gen_elems(int length)
{
    if( length < 0 || length > _max_length)
    {
        return;
    }

    if( length > _elems.size())
    {
        int ix = _elems.size() ? _elems.size()+1 : 1;
        for( ; ix <= length; ++ix )
            _elems.push_back( ix*( ix + 1 )/2 );
    }
}

void Triangular_static::gen_elems_to_value(int value)
{
    int ix = _elems.size();
    if( !ix )
    {
        _elems.push_back(1);
        ix = 1;
    }

    while( _elems[ix - 1] < value && ix < _max_length )
    {
        ++ix;
        _elems.push_back( ix*( ix + 1 )/2 );
    }

    if (ix == _max_length)
    {
        cerr <<  value << "is out of max length:  " << _max_length <<endl;
    }

}

bool Triangular_static::is_elem(int value)
{
    if( !_elems.size() || 
        _elems[ _elems.size() - 1] < value)
            gen_elems_to_value(value);
    
    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();
    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;

    return true;
}



int Triangular_static::get_elem(int pos) const
{
    if( pos > 0 && pos < _elems.size())
    {
        return _elems[pos-1];
    }

    return -1;
}

void Triangular_static::display(int length, int beg_pos, ostream &os)
{
    for (int ix = beg_pos; ix < beg_pos + length; ix++)
    {
        os << _elems[ix - 1] << ' ';
    }
}