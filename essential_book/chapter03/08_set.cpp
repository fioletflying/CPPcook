#include<iostream>
#include<set>
#include<map>
#include<string>
#include<vector>

using namespace std;

/***
 * 关于set的作用
 * 用来保存集合， 
 * 里面不能出现重复的对象
 * **/

int main()
{
    vector<int> vec = {1,2,3,48,3,5,1,7};
    // 用set 来进行去重并且执行less_than排序
    set<int> iset(vec.begin(), vec.end());

    set<int>::iterator set_it = iset.begin();

    for ( ; set_it != iset.end(); set_it++)
    {
        cout << *set_it << " ";
    }
    cout << endl;

    // set 元素的增加单个元素
    iset.insert(999);
    //  set 元素增加一个序列
    iset.insert(vec.begin(), vec.end());
    set_it = iset.begin();
    for ( ; set_it != iset.end(); set_it++)
    {
        cout << *set_it << " ";
    }

    

    set<string> word_exclusion={"a","an","the"};
    map<string,int> words;
    string tword;
    while(cin >> tword)
    {
        if(word_exclusion.count(tword))
            continue;
        if(tword == "0")
            break;
        words[tword]++;
    }

    map<string,int>::iterator it = words.begin();
    for( ; it!=words.end(); ++it)
        cout<< "key: " <<it->first
             <<" value: " <<it->second << endl;


    return 0;
}