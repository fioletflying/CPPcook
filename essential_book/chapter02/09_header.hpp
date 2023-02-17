#include<iostream>
#include<vector>


using namespace std;

// 将函数的声明放在头文件中,避免被其他程序文件调用的时候,多次声明
const vector<int>* fibon_seq( int size );
const vector<int>* lucas_seq(int size);
const vector<int>* pell_seq( int size );
const vector<int>* triang_seq(int size);
const vector<int>* square_seq( int size );
const vector<int>* pent_seq(int size);
bool fibon_elem( int pos, int &elem);
inline bool is_size_ok( int size );


// inline 函数需要在头文件中定义,
// 为了在调用的时候编译器能够获得其定义
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

// 对于file scope 的定义的对象,可能被多个文件访问,需要在头文件中声明
// 但是这里const 为什么不加extern
// 因为const  object: 一出文件之外便不可见了,所以需要多个程序代码文件多需要定义
const int seq_cnt = 6;
// 这里是对其进行了定义而不是声明,所以需要使用 extern关键字
// 这里就表示了声明
extern const vector<int>* (*seq_array[seq_cnt])(int);
