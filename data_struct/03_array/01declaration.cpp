#include<iostream>

//数组的定义

int main0()
{
    // 声明一个数组,大小为5个
    int A[5];
    // 声明并初始化所有元素的值
    int B[5] = {1,2,3,4,5};
    // 声明并初始化部分元素的值
    int C[5] = {1,2};
    int D[5] = {0};
    // 通过初始化来设置数组的大小
    int E[] = {2,3,4,5,6};

    // 打印关于数组存放元素的地址
    // 整个存储空间的地址是连续地
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "&E" << i <<" : " << &E[i] << std::endl;
    }
    

    std::cout << "A[0]: " << A[0] << std::endl;
    std::cout << "B[0]: " << B[0] << std::endl;
    std::cout << "C[2]: " << C[2] << std::endl;
    std::cout << "D[2]: " << D[2] << std::endl;
    std::cout << "E: " << sizeof(E) << std::endl;
    std::cout << "hello algorithm \n";
    return 0;
}