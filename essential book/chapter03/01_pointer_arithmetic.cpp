#include<iostream>
#include<vector>

using namespace std;
int* find01( vector<int> &vec, int value);

template <typename T>
T* find(vector<T>& vec, T value);

int main()
{

    vector<int> vec = {1,2,3,13,30};
    int value = 13;

    // 测试第一个函数
    int* find_value = find(vec, value);
    cout << find_value << " - " << *find_value <<endl;


    cout << "实现指针的算术运算！" << endl;
    return 0;
}

// 从vector中查找一个元素是否存在
// 如果存在则返回指针指向该值，若不存在则返回0
int* find01( vector<int>& vec, int value)
{
    for ( int ix = 0; ix < vec.size(); ++ix)
    {
        if (vec[ix] == value)
            return &vec[ix];
    }

    return 0;
}

// 从vector中查找一个元素是否存在: 任意类型
// 如果存在则返回指针指向该值，若不存在则返回0
// 这里使用模板函数来实现： 需要保证定义有“==”运算符   
template <typename T>
T* find(vector<T>& vec, T value)
{
    for( int ix = 0; ix < vec.size(); ++ix)
    {
        if (vec[ix] == value)
            return &vec[ix];
    }
    return 0;
}

// 如果实现array的任意元素，这里的思路之一：使用重载函数
// 但是基于函数最大化利用的原则，思考使用一个函数
// 将 array的元素传入其中， 将vector的元素传入其中
// 使用指针进行操作
template<typename T>
T* find(const T *array, int size, const T &value)
{
    if ( !array || size < 1 )
        return 0;

    for ( int ix=0; ix < size; ++ix)
        if(array[ix] == value)
            return &array[ix];
    
    return 0;
}


