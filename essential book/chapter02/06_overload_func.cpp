#include<iostream>
#include<vector>


using namespace std;

inline bool is_size_ok( int size );
inline const vector<int>* fibon_seq( int size );
inline bool fibon_elem( int pos, int &elem);
// 函数重载: 参数列表不同：参数的类型或者参数的个数，函数名称不同
// 编译器会通过其参数来区分调用的是那个函数
// 返回类型无法做重载函数的区分
// 将实现代码不同但是工作内容相似的函数进行重载，方便使用者调用
inline void display_message(char ch);
inline void display_message(const string& info);
inline void display_message(const string& info, int size);
inline void display_message(const string& info, int elem1, int elem2);


int main()
{

    cout << "test inline funciton! \n";

    return 0;
}

void display_message(char ch)
{
    cout << ch << endl;
}

void display_message(const string& info)
{
    cout << info << endl;
}

void display_message(const string& info, int size)
{
    cerr << info << ' ' << size << " -- can't fulfill request.\n";
}


void display_message(const string& info, int elem1, int elem2)
{
    cerr << info << ' ' << elem1 << " and " << elem2;
}


inline bool is_size_ok( int size )
{
    const int max_size = 1024;
    const string msg("Oops: requested size is not supported: ");

    if ( size <= 0 || size > max_size )
    {
        display_message(msg, size);
        return false;
    }
    return true;
}

// 计算数列
inline const vector<int>* fibon_seq( int size )
{
    const int max_size = 1024;
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