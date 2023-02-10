#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>


using namespace std;

int main()
{
    // 泛型算法的使用
    // 这里确定某个值是否再数列中：
    /***
     * find(): 搜索无序集合
     * binary_search:搜索有序的集合
     * count: 反会数值相符的元素的数目
     * search: 判断容器是否存在某个子序列
     * 
     * **/



    return 0;
}


bool is_elem(vector<int> &vec, int elem)
{
    int max_value = max_element(vec.begin(), vec.end());
    if (max_value < elem)
        return grow_vec(vec, elem);

    if (max_value == elem)
        return true;

    // 使用 binary_search 一定是要保证对象经过排序
    vector<int> temp(vec.size());
    // copy泛型算法的使用:需要拷贝的容器位置,以及开始拷贝的容器的位置
    copy(vec.begin(), vec.end(), temp.begin());
    // 排序进行中
    sort(temp.begin(), temp.end());

    return binary_search(temp.begin(), temp.end(), elem);

}