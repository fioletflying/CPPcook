#include<iostream>
#include<map>
#include<string>

using namespace std;
/**
 * map 是一种键值对的存储方式
 * 
 * 
*/

int main()
{
    //实现一个string 出现次数
    map<string, int> words;

    string tword;
    while(cin >> tword)
    {
        cout << tword << endl;
        words[tword]++;
        if(tword == "0")
            break;
    }

    map<string, int>::iterator it = words.begin();
    for(; it!=words.end(); ++it)
    {
        cout << "key: " << it->first
            << " value: " << it->second << "\n";
    }

    // 查询map内是否内在某个key的三种方法
    //方法一：直接使用key索引来确认，如果不存在，则会直接加入到map中
    string str_key("test");
    {
        int count = 0;
        if (!(cout == words[str_key]))
            cout << str_key << " in map" << endl;
    }

    // 方法二： 使用map的成员函数，find().这个不是泛型算法的find
    {
        int count = 0;
        map<string, int>::iterator it;
        it = words.find(str_key);
        if (it != words.end())
            cout = it->second;

    }
    // 方法三： 使用count函数
    {
        int count = 0;
        if(words.count(str_key))
            count = words[ str_key];

    }

}
