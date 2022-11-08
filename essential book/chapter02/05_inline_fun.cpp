#include<iostream>
#include<vector>


using namespace std;

inline bool is_size_ok( int size );
inline const vector<int>* fibon_seq( int size );
inline bool fibon_elem( int pos, int &elem);

// 加上inline的好处就是：当调用的时候，编译器会将该函数直接拷贝过来，而不是去调用
// 但是编译器不一定会执行这个函数，因为这边不是一种强制的方式，只是建议编译器进行内联函数
// 一般体积小，计算不复杂的就会被调用

int main()
{

    cout << "test inline funciton! \n";

    return 0;
}


// 这里将一个函数拆分为三个：
// 好处是，方便其他的函数多次调用
// 坏处是，调用的时候会牺牲一定的性能和速度
// 可以通过inline函数来弥补
inline bool is_size_ok( int size )
{
    const int max_size = 1024;
    if ( size <= 0 || size > max_size )
    {
        cerr << "Oops: requested size is not supported: "
            << size << " -- can't fulfill request.\n";
        return false;
    }
    return true;
}

// 计算数列
inline const vector<int>* fibon_seq( int size )
{
    static vector< int > elems;

    if (! is_size_ok( size ))
        return 0;

    for (int ix = elems.size(); ix < size; ++ix)
    {
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back( elems[ix-1]+elems[ix-2]);
    }    
    return &elems;
}


// 获得在pos位置的数列的元素
inline bool fibon_elem( int pos, int &elem)
{
    const vector<int> *pseq = fibon_seq( pos );

    if ( ! pseq )
    {
        elem = 0; 
        return false;
    }

    elem = (*pseq)[pos-1];
    return true;
}