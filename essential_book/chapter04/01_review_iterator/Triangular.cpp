#include"Triangular.hpp"

vector<int>Triangular::_elems;

// 在class外面进行定义的时候一定要加上const 这个关键字
int Triangular::elem(int pos) const
{
    // 成员函数使用静态成员变量跟普通的成员变量是相同的
    if (pos > 0 & pos < _elems.size())
    {
        return _elems[pos - 1];
    }
    return -1;
}

bool Triangular::is_elem(int value)
{
    if (!_elems.size() ||
        _elems[_elems.size() - 1] < value)
    {
        gen_elems_to_value(value);
    }

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    // 调用算法实现
    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elements(int length)
{
    if (length < 0 || length > _max_elems)
    {
        cerr << length << " exceeds max size of " << _max_elems << endl;
        return;
    }

    if (_elems.size() < length)
    {
        int ix = _elems.size() ? _elems.size() + 1 : 1;
        for (; ix <= length; ++ix)
        {
            _elems.push_back(ix * (ix + 1) / 2);
        }
    }
}

void Triangular::gen_elems_to_value(int value)
{
    int ix = _elems.size();
    if (!ix)
    {
        _elems.push_back(1);
        ix = 1;
    }

    while (_elems[ix - 1] < value && ix < _max_elems)
    {
        ++ix;
        _elems.push_back(ix * (ix + 1) / 2);
    }

    if (ix == _max_elems)
    {
        cerr << value << " exceeds max size of " << _max_elems << endl;
    }
}

void Triangular::display()
{
}
