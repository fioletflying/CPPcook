#include<iostream>
#include<string>
#include<algorithm>
// 三种顺序容器
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
    // 定义容器对象的5种方式:
    {

        // 第一种: 
        list<string> slist;
        vector<int> ivec;
        // 第二种: 产生特定大小的容器,每个元素的初值为其默认值
        list<int> ilist(1024);
        vector<string> svec(32);
        // 第三种: 产生特定大小的容器,每个元素进行赋初值
        vector<int> ivec2(10, 1);
        list<string> slist2(16, "unassigned");
        // 第四种:通过一对iterator定义容器, 这里使用数组
        int ia[8] = {1,2,3,4,5,6,7,8};
        vector<int> fib(ia, ia+8);
        // 第五种:通过某容器来初始化新的容器
        list<string> slist3(slist2);
    }

    // 首尾端的插入list deque:  push_front pop_front 
    {
        deque<int> a_line;
        int ival;

        while (cin >> ival)
        {
            // 在末端插入
            a_line.pusœh_back(ival);
            // 获取最前端的值
            int curr_value = a_line.front();
            cout << "a_line first value: " << curr_value <<endl;
            // 删除最前端的值,vector没有此函数
            a_line.pop_front();
            break;
        }

    }

    // insert的插入方式:四种用法
    {
        cout << "************insert的用法********************"<<endl;
        list<int> ilist = {1,2,3,6,8};
        // 第一种方法: iterator insert(iterator pos, elemType value)
        // 在value插入到pos之前的方式, 返回被插入元素的iterator
        
        // 实现list递增的插入
        list<int>::iterator it = ilist.begin();

        cout << "--------插入前-------\n";
        for(; it != ilist.end(); ++it)
        {
            cout << *it << " ";
        }
        int ival = 4;
        while ( it != ilist.end() )
        {
            if (*it >= ival )
            {
                // 在 it之前插入
                ilist.insert (it, ival);
                break;
            }

            ++it;
        }

        // 如果没有比ival大的元素,那么直接插入到最后
        if(it == ilist.end())
        {
            ilist.push_back(ival);
        }

        cout << "\n--------插入后-------\n";
        it = ilist.begin();
        for(; it != ilist.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << "\n";


        // 第二种方法: void insert(pos, count, value)
        // 在pos 前面插入count个元素, 且这些元素的值都是value
        string sval("Part Two");
        list<string> slist = {"Part One", "Part Two", "Part Three"};
        cout << "\n--------插入前-------\n";
        list<string>:: iterator it_list_b = slist.begin();
        for(; it_list_b != slist.end(); ++ it_list_b)
        {
            cout << *it_list_b << " ";
        }
        cout << "\n";

        list<string>:: iterator 
            it_list = find(slist.begin(), slist.end(), sval);

        slist.insert(it_list, 8, string("wali"));

        cout << "\n--------插入后-------\n";
        it_list_b = slist.begin();
        for(; it_list_b != slist.end(); ++ it_list_b)
        {
            cout << *it_list_b << " ";
        }
        cout << "\nilist size: " << slist.size() <<"\n";
        cout << "\n";


        // 第三种方式: insert(pos, first, last)
        // 在pos之前插入[first, last)所标示的各个元素
        int ia1[7] = {1, 1, 3, 4, 5, 55, 89};
        int ia2[4] = {8, 13, 21, 34};
        list<int> elems(ia1, ia1+7);

        list<int>::iterator it3 = find(elems.begin(), elems.end(), 55);
        elems.insert( it3, ia2, ia2+4);

        cout << "\n--------插入后-------\n";
        list<int>::iterator it_list_i = elems.begin();
        for(; it_list_i != elems.end(); ++it_list_i)
        {
            cout << *it_list_i << " ";
        }

        // 第4种方式: insert(pos)
        // 在pos之前插入元素,元素的初值为所属类型的默认值


    }

    // erase的删除方式:两种用法
    {
        // 第一种: erase(pos) 删除pos所指定的元素
        list<string> slist = {"Part One", "Part Two", "Part Three"};
        string sval("Part Two");
        list<string>::iterator 
            it = find(slist.begin(), slist.end(), sval);
        slist.erase(it);
        cout << "\n--------去除后-------\n";
        it = slist.begin();
        for(; it != slist.end(); ++ it)
        {
            cout << *it << " ";
        }
        cout << "\n";

        // 第二种: erase(first, last)
        // 删除[first, last)范围内的元素
        slist = {"Part One", "Part Two", "Part Three"};
        list<string>::iterator
            first = slist.begin(),
            last = slist.end();

        list<string>::iterator it1 = find(first, last, string("Part One"));
        list<string>::iterator it2 = find(first,last,sval);

        slist.erase( it1, it2);
        cout << "\n--------去除后-------\n";
        it = slist.begin();
        for(; it != slist.end(); ++ it)
        {
            cout << *it << " ";
        }



            

    }









}