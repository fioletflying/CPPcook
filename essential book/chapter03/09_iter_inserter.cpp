#include<iostream>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

//实现条件查找相关的数据
template<typename inputT, typename outputT,
            typename elemT,typename compT>
outputT filter(inputT first, inputT last, 
        outputT at, elemT val, compT pred)
{
    while((first = find_if(first, last,
             bind2nd(pred, val))) != last)
    {
        // 将符合条件的进行赋值处理
        *at++ = *first++;
    }
    return at;
}


int main()
{
    const int elem_size = 5;
    int ia[5] = {1,23,4,5,6};
    vector<int> ivec(ia, ia+elem_size);

    int ia2[elem_size];
    vector<int> ivec2;

    // 数组无法插入
    filter(ia, ia+elem_size, ia2, elem_size, less<int>());

    filter(ivec.begin(), ivec.end(),
            back_inserter(ivec2),
            elem_size,greater<int>());


}