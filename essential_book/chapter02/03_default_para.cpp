#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

// 默认参数两个规则：
/***
 * 1、默认参数应该放到函数参数最右边
 * 2、默认参数只能在一个地方声明：
 *      要么在函数定义的时候
 *      要么在函数声明的时候
 * 
 * ***/

void bubble_sort(vector<int>&vec, ofstream &ofil);
void bubble_sort_default( vector<int>&vec, ofstream *ofil);
void swap(int& x, int& y);
void display(const vector<int> &vec);
void display_default(const vector<int>& vec, ostream &os);

int main()
{
    ofstream outfile("sort_data.txt");
    vector<int> ia = {8, 34, 3, 13, 1, 21, 5, 2};

    cout << "sort befor: " <<endl;
    display_default(ia, cout);


    bubble_sort_default(ia, &outfile);

    cout << "sort after: " <<endl;
    display(ia);
    return 0;

}

void display(const vector<int>& vec)
{
    for( int ix = 0; ix < vec.size(); ++ix)
    {
        cout << vec[ix] << ",";
    }
    cout <<endl;
}

// 这里直接使用引用来作为默认参数：因为输出cout就是一个具体的对象，
void display_default(const vector<int>& vec, ostream &os = cout )
{
    for( int ix = 0; ix < vec.size(); ++ix)
    {
        os << vec[ix] << ",";
    }
    os <<endl;
}

void swap(int& x, int& y)
{
    int temp = x;
    x = y ;
    y = temp;
}

// 使用引用，这里无法进行默认参数设置，引用对象无法赋初值为0
void bubble_sort( vector<int>&vec, ofstream &ofil)
{
    for (int ix=0; ix < vec.size(); ++ix)
    {
        for ( int jx = ix+1; jx < vec.size(); ++jx)
        {
            if (vec[ix] > vec[jx])
            {
                ofil << "about to call swap! ix: " << ix
                    << " jx: " << jx << "\tswapping: "
                    << vec[ix] << " with "<< vec[jx] << endl;

                swap(vec[ix], vec[jx]);
            }
        }
    }
}

// 默认参数，这样方便控制是否进行打印信息的
// 使用指针作为默认参数，通过赋予null初值可以很方便的控制，输入输出
// 这里不使用引用的原因是，引用无法设置为0，其必须代表某个具体的对象
void bubble_sort_default( vector<int>&vec, ofstream *ofil = 0)
{
    for (int ix=0; ix < vec.size(); ++ix)
    {
        for ( int jx = ix+1; jx < vec.size(); ++jx)
        {
            if (vec[ix] > vec[jx])
            {
                if (ofil != 0)  // 通过使用0来做区分
                    (*ofil) << "about to call swap! ix: " << ix
                        << " jx: " << jx << "\tswapping: "
                        << vec[ix] << " with "<< vec[jx] << endl;

                swap(vec[ix], vec[jx]);
            }
        }
    }
}