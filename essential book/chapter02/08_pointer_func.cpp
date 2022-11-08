#include<iostream>
#include<vector>


using namespace std;

bool is_size_ok( int size );
const vector<int>* fibon_seq( int size );
const vector<int>* lucas_seq(int size);
const vector<int>* pell_seq( int size );
const vector<int>* triang_seq(int size);
const vector<int>* square_seq( int size );
const vector<int>* pent_seq(int size);
bool fibon_elem( int pos, int &elem);

// 函数指针的定义： 指向函数的指针
/****
 * 具体需要如下的方式：
 * 函数返回类型: const vector<int>*
 * 函数的参数列表: (int)
 * 指针的位置 *
 * 函数指针的名称 （*seq_ptr） 这里的小括号一定要加上
 * const vector<int>* (*seq_ptr)(int);
 * */ 


/***
 * 函数指针赋初值：
 * const vector<int>* (*seq_ptr)(int) = 0
 * ***/

// 函数指针数组
const vector<int>* (*seq_array[])( int ) = {
    fibon_seq,
    lucas_seq,
    pell_seq,
    triang_seq,
    square_seq
};

// 使用 enumm 枚举类型进行标识符的区分
// 0,1,2,3,4,5
enum ns_type{
    ns_fibon, ns_lucas, ns_pell,
    ns_triang, ns_square, ns_pent
};
// 利用枚举的索引来获取函数指针的位置
// seq_ptr = seq_array[ ns_pell ];

int main()
{

    

    return 0;
}

bool is_size_ok( int size )
{
    const int max_size = 1024;
    if (size > max_size || size < 0)
    {
        cerr << "Oops: requested size is not supported: "
            << size << " -- can't fulfill request.\n";
        return false;
    }

    return true;    
}

const vector<int>* fibon_seq( int size )
{
    static vector<int> elems;

    if (is_size_ok)
    {
        return 0;
    }

    for(int ix=elems.size(); ix < size; ix++)
    {
        if ( ix == 0 || ix == 1)
        {
            elems.push_back(1);
        } 
        else
        {
            elems.push_back(elems[ix-1] = elems[ix-2]);
        }
    }

    return &elems;
}

// 参数就是一个函数指针
bool fibon_elem( int pos, int &elem, 
                    const vector<int>* (*seq_ptr)(int))
{
    // 最好座椅个指针判断
    if (! seq_ptr)
        cerr << "Internal Error: seq_ptr is set to null!\n";
    // 函数指针的调用方式：跟函数的调用一直
    const vector<int>* pseq = seq_ptr(pos);

    if (!pseq)
    {
        elem = 0; 
        return false;
    }

    elem = (*pseq)[pos-1];
    return true;
}