#include <iostream>

using namespace std;


int main()
{
    int A[5];
    int B[5] = {1,2,3,4,5};
    int C[5] = {1,2};
    int D[5] = {0};

    int E[] = {0,1,2,3,4,5};

    for (size_t i = 0; i < 5; i++)
    {
        cout << A[i] << "," <<endl;
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout << B[i] << "," <<endl;
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout << C[i] << "," <<endl;
    }

    for (size_t i = 0; i < 6; i++)
    {
        cout << E[i] << ":"<< &E[i] <<endl;
    }
    // sizeof 只能计算字节数
    cout << "size of E" << ":"<< sizeof(E) <<endl;
    

    return 0;
}