#include <iostream>

using namespace std;

class Matrix
{
public:
    Matrix(int row, int col):
        _row(row), _col(col)
        {
            cout << "Matrix constructor" << endl;
            _pmat = new double[ row * col ];
        }

    // 析构函数的对内存进行释放
    ~Matrix()
    {
        cout << "deconstructor " << endl;
        delete [] _pmat;
    }


private:
    int _row, _col;
    double *_pmat;
};