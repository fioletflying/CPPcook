#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

template<typename elemType, typename iterType>
iterType find(iterType first, iterType last, const elemType& value);

int main()
{
    //定义迭代器
    vector<string> svec = {"wali", "eva", "peper"};
    //"::"" 这个需要尤其注意的地方, 标注string vector嵌套类型
    // "::" 在类的定义中表示指定的类方式
    vector<string>::iterator iter = svec.begin();
    vector<string>::iterator iter_end = svec.end();

    for(; iter!=iter_end; ++iter )
    {
        // 如果想获得具体的值,可以进行提领操作
        // -> 来获得相关的属性值
        cout << "string " << iter->size() - (iter_end - iter)
            << " : " << *iter <<endl;
    }

    cout << "------------------------"<<endl;

    const int asize = 4;
    int ia[asize] = {1,2,3,4};
    vector<int> ivec(ia, ia+asize);
    list<int> ilist(ia, ia+asize);

    int *pia = find(ia, ia+asize, 3);
    if (pia != ia+asize)
    {
        cout << pia << " : " << *pia << endl;
    }

    vector<int>:: iterator it;
    it = find( ivec.begin(), ivec.end(), 3);
    if (it != ivec.end())
    {
        cout << &it << " : " << *it << endl;
    }

    list<int>::iterator iterlist;
    iterlist = find( ilist.begin(), ilist.end(), 3);
    if ( iterlist != ilist.end())
    {
        cout << &iterlist << " : " << *iterlist << endl;
    }


    cout << "泛型指针的作用" <<endl;

}

// 使用泛型指针迭代器来实现find的方法
// 这里定义了两个模板参数，一个是用来指定关于 first与last的，一个是用来指定value
template<typename elemType, typename iterType>
iterType find(iterType first, iterType last, const elemType& value)
{
    // 这里不需要对其进行判断，如果first为空的话，就直接等于last了
    for (; first != last; ++first)
        if (*first == value)
            return first;

    return last;
}