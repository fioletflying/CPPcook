#include<iostream>
#include<vector>


using namespace std;

int main()
{


    return 0;
}

const vector<int>* fibon_seq( int size )
{
    const int max_size = 1024;
    // 局部静态变量，放在了全局内存地址区域
    // 这个不会被删除
    // 这里不定义file scope的原因是因为破环函数间的独立性，
    // 因为在使用该函数的时候还要考虑是否有定以这个对象。
    static vector< int > elems;

    if ( size <= 0 || size > max_size )
    {
        cerr << "fibon_seq(): oops: invalid size: "
            << size << " -- can't fulfill request.\n";

        return 0;
    }

    if (size > elems.size()){
        for ( int ix = elems.size(); ix < size; ++ix)
        {
            if ( ix == 0 || ix == 1)
                elems.push_back(1);
            else elems.push_back( elems[ix-1] + elems[ix-2]);
        }
    }

    // 因为是局部静态变量，放在全局领域，所以不会被清空
    return &elems;
}