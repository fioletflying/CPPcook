#include<iostream>
#include<vector>

using namespace std;
int* find01( vector<int> &vec, int value);

template <typename T>
T* find(vector<T>& vec, T value);

template<typename T>
T* find02(T *array, int size, const T &value);

template<typename T>
T* find(T* first, T* last, const T& value);

int main()
{

    vector<int> vec = {1,2,3,13,30};
    vector<double> da = {1.1, 2.0,3.0,5.0};
    string sa[4] = {"abc", "efg", "hij", "klmn"};

    // 测试第一个函数
    // int* find_value = find(vec, value);
    int* find_value = find02(&vec[0], 5, vec[3]);
    // vector 的调用方式
    // double* find_da = find(&da[0], &da[4], da[3]);
    double* find_da = 0;
    if ( !da.empty() )
        find_da = find(&da[0], &da[da.size()], da[3]);
    // 利用 first 与 last的调用,直接使用数组的名字,
    // 因为这个就是可以表示数组的第一个元素的地址
    string* find_sa = find(sa, sa+4, sa[3]);

    cout << find_value << " - " << *find_value <<endl;
    cout << find_da << " - " << *find_da <<endl;
    cout << find_sa << " - " << *find_sa <<endl;


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
// template<typename T>
// T* find(T *array, int size, const T &value)
// {
//     if ( !array || size < 1 )
//         return 0;

//     for ( int ix=0; ix < size; ++ix)
//     // 这里有一个问题，实际传入的array是其第一个元素的地址
//     // 所以这里可以使用array[ix] 来获得索引，而这个就是涉及到了本节的重点
//     // 指针的运算, array[2] : 表示的是数组的在第一个位置上往后偏移2个两个地址
//     // arrary + 2: 实际的地址可能需要计算类型的长度
//     // arrary[2] 就包含提领操作
//         if(array[ix] == value)
//             return &array[ix];
    
//     return 0;
// }

// 这里利用 array的地址来代表每一个元素
// array 每递增1就代表其往下的一个元素
// 如果需要获取这个元素的值,只需进行提领操作
// 指针可以代表数组的开始地址
template <typename T>
T* find02(T* array, int size, const T& value)
{
    if (!array || size < 1)
        return 0;
    
    // ++array每递增1就代表其往下的一个元素
    for(int ix = 0; ix < size; ++ix, ++array)
        if(*array == value)
            return array;
    
    return 0;
}

//使用last的指针标兵作为结束符号
template<typename T>
T* find(T* first, T* last, const T& value)
{
    if ( !first || !last )
        return 0;

    for( ; first != last; ++first)
        if (*first == value)
            return first;
    return 0;
}

// 这里提出一个问题,上面的find可以应用与array 和 vector,但是
// 如果是list那么怎么来适配呢? 是不是需要进行重载呢?
// 因list的不是顺序排布的,所以需要根据特别的情况来处理.
// 这里需要设计一份抽象层,这个层可以直接对其进行操作




