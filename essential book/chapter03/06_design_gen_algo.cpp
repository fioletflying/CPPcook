#include<iostream>
#include<vector>
#include<list>

#include<algorithm>
#include<functional>


using namespace std;

/**
 * 本节的任务是：从vector 中找到小于10的数值，返回一个新的vector
 * 
*/
// 第一版： 单纯的实现相关功能
vector<int> less_than_10( const vector<int> &vec)
{
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ++ix)
        if (vec[ix] < 10)
            nvec.push_back(vec[ix]);

    return nvec;
}

// 用户可以指定需要比较的值：
// 第二版： 将10作为参数传入，用户可以任意指定需要比较的参数
vector<int> less_than(const vector<int> &vec, int less_than_val)
{
    // 这里有一个问题，这样是声明还是定义的vector
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ++ix)
        if (vec[ix] < less_than_val)
            nvec.push_back(vec[ix]);

    return nvec;
}


// 第三版:
// 用户可以指定不同的比较操作:大于,小于,等于...
// 这里的思路是可以使用函数指针传入这些操作的函数
// 就是将if (vec[ix] < less_than_val): 比较操作返回bool的值
// 这里less_than需要改名字:filter

// 这里先定义比较函数
bool less_than( int x1, int x2)
{
    return x1 < x2 ? true : false;
}

bool greater_than( int x1, int x2)
{
    return x1 > x2 ? true : false;
}


vector<int> filter(const vector<int>& vec, int filter_value, bool (*comp)(int,int))
{
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ++ix)
        if (comp(vec[ix], filter_value))
            nvec.push_back(vec[ix]);

    return nvec;
}


// 这里有一个find函数使用的铺垫
// find: 
// 比如是这里找出每个等于10的元素
int count_occurs( const vector<int> &vec, int val )
{
    vector<int>::const_iterator it = vec.begin();
    int occurs_count = 0;
    // 这里使用find泛型算法函数,如果找到了,就移动到下一个
    // 两个iterator和一个需要寻找的数值
    while( find(it, vec.end(), val) != vec.end())
    {
        ++it; // 指向下一个元素
        ++occurs_count; // 记录找到的个数
    }

    return occurs_count;
}

/****
 * 
 * // Function Object 的使用
 * #include<functional>
 * 它是一个class的实力对象, 对于函数调用的运算符做了操作符重载
 * 功能:之前使用独立函数做的事情, 这个实例对象可以替代
 * 好处:将函数变成inline 提升效率
 * 提供的相关函数对象:
 * 算法运算:plus<type>, minus<type>, negate<type>, multiplies<type>, divides<type>, modules<type>
 * 关系运算:less<type>, less_equal<type>, greater<type>, greater_equal<type>, equal_to<type>, not_equal_to<type>
 * 逻辑运算:logical_and(type),logical_or<type>,logical_not<type>
 * 
 * 
 * *****/
// 使用函数对象
// sort(vec.begin(), vec.end(), greater<int>())
// binary_search(vec.begin(), vec.end(), elem, greater<int>())

/**
 * adapter 适配器
 * 将 less<type> 转换成一个一元运算符
 * bind1st 将指定的值绑定到第一个操作数
 * bind2nd 将指定的值绑定到第二个操作数
 * ***/
// 第四版: 使用find_if来替代for循环
// 使用适配器进行绑定,
vector<int> filter(const vector<int> &vec, int val, less<int>& lt)
{
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();
    // 使用了绑定适配器,使用相关的绑定适配器完成,需要筛选的条件
    while ((iter = find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end())
    {
        nvec.push_back(*iter);
        iter++;
    }
    return nvec;
}

// 第五版,使用模版函数
template<typename inputIterType, typename elemType, 
        typename outputType, typename compT>
outputType filter(inputIterType first, inputIterType last, outputType at, elemType val, compT pred)
{
    while((first = find_if(first, last, bind2nd(pred, val))) != last)
    {
        cout << "found value: " << *first <<endl;

        *at++ = *first++;
    }

    return at;
}

// 保留某些元素:第一版
vector<int> sub_vec(const vector<int> &vec, int val)
{
    vector<int>local_vec(vec);
    sort(local_vec.begin(), local_vec.end());

    vector<int>::iterator iter = find_if(
        local_vec.begin(),
        local_vec.end(),
        bind2nd( greater<int>(), val));
    
    local_vec.erase(iter, local_vec.end());
    return local_vec;
}

// 保留某些元素:第二版 函数模版
template<typename inputIterT, typename outputIterT,
            typename elemT, typename comp>
outputIterT sub_vec(inputIterT first, inputIterT last,
                    outputIterT at, elemT val, comp pred)
{
    outputIterT at_first = at;
    while(first != last)
    {
        *at++ = *first++;
    }
    sort(at_first, at)
    at = find_if(at_first, at, bind2nd(pred, val));
    return at;
    
}


void display_vec(const vector<int>& vec)
{
    vector<int>::const_iterator it = vec.begin();

    for(; it!=vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
}


int main()
{
    vector<int> vec = {1, 1, 2, 3, 5, 8, 13, 21, 34};
    display_vec(vec);
    vector<int> nvec1 = less_than_10(vec);
    display_vec(nvec1);
    vector<int> nvec2 = less_than(vec, 0);
    display_vec(nvec2);
    vector<int> nvec3 = filter(vec, 10, greater_than);
    display_vec(nvec3);
    // 统计1的个数:
    int find_value =  count_occurs(vec, 1 );
    cout << "find 1 count: " << find_value << "\n";
    // 没有用一个对象进行赋值也是可以直接调用
    // 主要是因为其iterator 指针
    filter(vec.begin(),vec.end(),nvec3.begin(),10,less<int>());
    display_vec(nvec3);

    // 使用函数对象
    bool is_find = binary_search(vec.begin(), vec.end(), 1, greater<int>());
    cout << "is find " << is_find << endl;
    sort(vec.begin(), vec.end(), greater<int>());
    display_vec(vec);
    vector<int> nvec4(vec);
    vector<int> nvec_plus(vec);
    // 转化操作: 可以实现对应函数的相加和相减
    // 参数: 一对iterator
    // 一个iterator: 另一个容器的其实地址
    // 转换结果存放地址
    // 使用函数对象需要做的操作
    transform( vec.begin(), vec.end(),
                nvec4.begin(),
                vec.begin(),
                plus<int>());
    display_vec(vec);

    // 调用sub_vector
    vector<int> nvec6 = sub_vec(nvec3,10);
    display_vec(nvec6);


    return 0;
}