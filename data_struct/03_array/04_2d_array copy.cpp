#include<iostream>

using namespace std;


int main()
{

    //定义一个二维数组，2行4列
    int A[2][4] = {{1,2,3,4}, {5,6,7,8}};

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ,";
        }
        cout << endl; 
    }

    //指针数组：用来存放指针的数组
    //比如这里就存放了两根指针
    int *B[2];
    B[0] = new int[4];
    B[1] = new int[4];

    cout << B[0] <<endl;
    cout << B[1] <<endl;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ,";
        }
        cout << endl; 
    }

    //指针的指针
    int **C = new int*[2];
    // C = new int*[2];
    C[0] = new int[4];
    C[1] = new int[4];
    for (size_t i = 0; i < 2; i++)
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