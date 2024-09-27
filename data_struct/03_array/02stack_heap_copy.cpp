#include<iostream>
using namespace std;
//数组存储位置：栈与堆

int main()
{
    int A[5] = {1,2,3,4,5};
    int *p;
    //在堆上新建相关数组元素
    p = new int[5];
    p[0] = 1;
    p[2] = 3;
    //p = {1,2,3,4,5}; 这样无法初始化

    for (size_t i = 0; i < 5; i++)
    {
        cout << p[i] << ":" << &p[i] << endl;
    }
    
   
    cout << "delete p" <<endl;
    delete []p;
    std::cout << "hello algorithm \n";
    return 0;
}