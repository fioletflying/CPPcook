#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};


int main()
{
    Rectangle r = {10,5};
    Rectangle *pr = &r;

    //使用指针来修改数据
    (*pr).breadth = 100;

    cout << "r.breadth:" << r.breadth << endl;
    //使用指针来修改数据:推荐使用这个方式
    pr->breadth = 200;
    cout << "r.breadth:" << r.breadth << endl;

    // 使用堆来定义
    Rectangle *pr2 = new Rectangle();
    pr2->breadth = 200;
    pr2->length = 100;
    cout << "r2.breadth:" << pr2->breadth << endl;  



    cout << "data struct ch01" << endl;
    return 0;
}