#include<iostream>
#include<vector>

using namespace std;

//全局内存管理：file scope
vector<int> high_scope;

vector<int> fibon_seq( int size );
// 返回引用的函数
vector<int>& fibon_seq_ref( int size );
void display(const vector<int>& vec);

int main()
{
    vector<int> ia = fibon_seq_ref(8);
    display(ia);

    // dynamic extent 第三种存储形式，动态范围
    // 简单的理解，哪里需要在哪里开辟存储空间
    // 动态的分配内存，通过new来实现，利用指针
    {
        int *pi;
        // 这里在堆 heap memory 上面分配的内存空间
        pi = new int;
        pi = new int(1024); //赋初值
        // 动态的创建数组
        int *pia = new int[24];

        // 由于这个内地址不会主动释放，所以在不需要的时候一定要释放
        if ( pi != 0 )
            delete pi;
        if ( pia != 0)
            delete [] pia;
    }
    
    return 0;
}


vector<int> fibon_seq( int size )
{
    if (size <= 0 || size > 1024 )
    {
        cerr << "Warning: fibon_seq():"
            << size << "not supported -- resetting to 8\n";
        size = 8;
    }

    // 函数内定义的对象，在函数执行后就会释放内存
    vector<int> elems ( size );
    for (int ix = 0; ix < size; ++ix)
        if ( ix == 0 || ix == 1)
            elems[ ix ] = 1;
        else 
            elems[ ix ] = elems[ ix - 1 ] + elems[ ix - 2 ];
    // 返回值, 因为返回的是对象副本,所以不会出现问题
    return elems;


}

// 打印vector 的值 
void display(const vector<int>& vec)
{
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        cout << vec[ix] << ' ';
    }

    cout << endl;
}

// 函数返回引用和指针都会出现处理
// 函数内定义的对象，在函数执行后就会释放内存，所以会出现问题
// 如果使用的是
vector<int>& fibon_seq_ref( int size )
{
    if (size <= 0 || size > 1024 )
    {
        cerr << "Warning: fibon_seq():"
            << size << "not supported -- resetting to 8\n";
        size = 8;
    }
    vector<int> elems_ref ( size );
    for (int ix = 0; ix < size; ++ix)
        if ( ix == 0 || ix == 1)
            elems_ref[ ix ] = 1;
        else 
            elems_ref[ ix ] = elems_ref[ ix - 1 ] + elems_ref[ ix - 2 ];
    // 返回的是引用,也是一个地址,这个会出现问题,返回的局部的引用出问题
    high_scope = elems_ref;
    return high_scope;
}


