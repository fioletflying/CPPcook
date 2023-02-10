#include<iostream>

using namespace std;

// 带指针的类定义,需要定义析构函数
// big 3
// 定义析构函数
// 定义拷贝构造函数
// 定义拷贝赋值函数

class Matrix
{
    public:
        Matrix(int row, int col):
            _row(row), _col(col)
            {
                // 创建一个heap的分配空间
                _pmat = new double[row * col];
            }
        // 需要定义析构函数
        ~Matrix()
        {
            // 使用析构函数进行释放
            delete []_pmat
        }
    // 拷贝构造函数
        Matrix(const Matrix &rhs)
            :_row(rhs._row),_col(rhs._col)
            {
                int elem_cnt = _row * _col;
                _pmat = new double[ elem_cnt]
                // 需要独立赋值每个元素的样本
                for(int ix = 0; ix < elem_cnt; ++ix)
                {
                    _pmat[ix] = rhs._pmat[ix]
                }
            }

    private:
        int _row;
        int _col;
        double* _pmat;
}