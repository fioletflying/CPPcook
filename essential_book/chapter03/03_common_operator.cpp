#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

int main()
{
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {1,2,3};

    // 1、equality 相等 或者不等运算符
    if(v1 == v2)
    {
        cout << "v1" << "=" << "v2" <<endl;
    }
    else
    {
        cout << "v1" << "!=" << "v2" <<endl;
    }
    // 2 是否为空
    if(v1.empty() || v2.empty())
        cout << "empty!!!" << endl;

    //3 赋值操作 与 size()
    vector<int> t = v1;

    if (t.size() > v1.size())
    {
        cout << "t szie > v1 size" <<endl; 
    }

    t.clear();

    cout << "t.size = " << t.size() << endl;


    cout << "所有容器都具有的共同的函数操作"  << endl;
    return 0;
}