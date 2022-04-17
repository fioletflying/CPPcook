#include<iostream>
#include<vector>

using namespace std;

int main()
{
    // 数组的定义
    int seq_size2 = 18;
    int pell_seq2[seq_size2] = {0,1,2,3};
    cout << sizeof(pell_seq2)<<endl;
    // 数据大小一旦设定后，不能再改变了
    seq_size2 = 20;
    cout <<"change seq_size: "<< sizeof(pell_seq2) << endl;
    // 建议使用常量表达式来定义数组大小
    const int seq_size = 18;
    int pell_seq[seq_size];

    // 数据的初始化
    // 默认初始化为0
    // 使用{}, 逗号隔开, 可以指定部分或者全部的元素
    // 元素的个数不能超过指定的大小, 
    int elem_seq[seq_size] = {
        1, 2, 3,
        3, 4, 7,
        2, 5, 12,
        3, 6, 10,
        4, 9, 16,
        5, 12, 22
    };


    {
        // vector 定义
        // 需要包含头文件
        // vector 是一个class template形式
        // 使用尖括号指定类型
        // vector的设置的大小写在小括号中
        // 这里的大小不一定要使用常量,因为vector 的大小是可以改变的
        vector<int> pell_seq_vector(seq_size);

        // 索引指定容器的位置
        // 使用[]表示索引操作
        // 如果需要取第一个值的话,其index 为0
        // 也就是容器的第一个位置从0开始
        pell_seq[0] = 1;
        pell_seq[1] = 2;
        pell_seq_vector[0] = 1;
        pell_seq_vector[1] = 2;

        cout << pell_seq[0] << "," << pell_seq[1] << endl;
        cout << pell_seq_vector[0] << "," << pell_seq_vector[1] << endl;
        // 有趣的问题, vector所占的内存大小,一直不变
        cout << sizeof(pell_seq_vector) << endl;

        // vector 初始化
        vector<int> elem_seq1(seq_size);
        // 默认值为0
        for (int i = 0; i < seq_size; ++i)
        {
            cout << elem_seq1[i]<<',';
        }
        cout << "\n****************************"<<endl;

        // 不能这样初始化
        // vector<int> ele_test(7) = {1,2,3,4,5,6,7};

        //初始化化的方法一，直接使用使用index 来初始化，
        // elem_seq[0] = 1;
        // elem_seq[1] = 1;
        // elem_seq[2] = 1;
        // elem_seq[3] = 1;

        //初始化化的方法二，利用array来初始化
        int elem_vals[seq_size] = {1,2,3,4,5,6,
                                    1,2,3,4,5,6,
                                    1,2,3,4,5,6};
        // 这里是两个内存地址的起止位置
        // 这种初始化会将array中的数组复制到vector中
        
        vector<int> elem_seq(elem_vals, elem_vals + seq_size ); 
        for (int i = 0; i < seq_size; ++i)
        {
            cout << elem_seq[i]<<',';
        }
        cout << "\n****************************"<<endl;

        // 遍历vector的另外一个方法: 使用vector size表示数组中所有的元素个数
        for (int i = 0; i < elem_seq.size(); ++i )
        {
            cout << elem_seq[i] << ',';
        }
        cout << "\n****************************"<<endl;

    }

     // for 循环的使用
    {

        // for ( 初始化; 判断条件; 每次迭代结束后需要改变的值 )
        for ( int ix=2; ix < seq_size; ++ix)
        {
            pell_seq[ ix ] = pell_seq[ ix-2 ] + 2*pell_seq[ ix-1 ];
            cout << pell_seq[ ix ] << endl;
        }

    }

    {
        const int max_seq = 6;
        string seq_names [max_seq] = {
            "Fibonacii",
            "Lucas",
            "Pell",
            "Triangular",
            "Square",
            "Pentagonal"
        };

        
    }

    
    return 0;
}
