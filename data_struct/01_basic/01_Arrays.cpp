#include <iostream>

using namespace std;


int main()
{

    // 声明数组
    int a[3];
    // 数组赋值
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    // 定义数组
    int b[5] = {1,2,3,4,5};

    // 访问数组元素
    a[1] = 3;

    // 使用循环来遍历数组
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << ",";
    }
    cout << endl;
    




    cout << "data struct ch01" << endl;
    return 0;
}