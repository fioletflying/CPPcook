#include<iostream>

using namespace std;


int main()
{

    // 二维数组的概念

    // ****第一种方式,在栈中定义数组****
    // 这里注意申明二维数组用2个中括号来表示
    // 两个维度表示:行与列,比如3行4列
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << A[i][j] << ",";
        }
        cout << endl;
        
    }


    // ****第二种方式,利用指针的数组来实现****
    // 定义一个存放指针的数组
    // 比如这里定义了一个存放3个指针的数组
    // 再利用动态内存来定义每个指针的指向的数组
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << B[i][j] << ",";
        }
        cout << endl;
        
    }

    // ****第三种方式,利用指针的指针来实现****
    int **C;
    // 新建一个指针数组,动态分配相关的数据
    C = new int*[3];
    // 对每个指针进行分配相关内存
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];
    
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << C[i][j] << ",";
        }
        cout << endl;
    }



    cout << "welcome to algorithm world!" << endl;
    return 0;
}