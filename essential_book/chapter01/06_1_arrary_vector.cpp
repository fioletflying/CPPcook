#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    {
        int cur_tuple = 0;
        bool next_seq = false;
        const int seq_size = 18;
        int elem_vals [ seq_size] = {1,2,3,4,5,6,7,8,9};
        vector<int> elem_seq(elem_vals, elem_vals+seq_size);
        int usr_guess;
        char usr_rsp;

        const int max_seq = 6;
        int num_cor = 0;
        string seq_names[ max_seq ] = {
            "Fibonacii",
            "Lucas",
            "Pell",
            "Triangular",
            "Square",
            "Pentagonal"
        };

        // if (usr_guess == elem_seq[ cur_tuple+2 ])
        // {
        //     ++num_cor;
        //     cout << "Very good. Yes"
        //     << elem_seq[cur_tuple+2]
        //     << "is the next element in the "
        //     << seq_names[ cur_tuple/3 ] << "sequence. \n";
        // }

        while (next_seq == true && cur_tuple < seq_size)
        {
            cout << "The first tow elements of the sequence are: "
            << elem_seq[ cur_tuple ] << ","
            << elem_seq[ cur_tuple+1 ] 
            << "\nWhat is the next elements?";

            if (usr_guess == elem_seq[cur_tuple+2])
            {
                ++num_cor;
                cout << "Very good. Yes"
                << elem_seq[cur_tuple+2]
                << "is the next element in the "
                << seq_names[ cur_tuple/3 ] << "sequence. \n";
            }

            if (usr_rsp == 'N' || usr_rsp == 'n')
                next_seq = false;
            else 
                cur_tuple += 3;
        }

    }


    {
        // 定义需要尖括号带上列表的类型
        // 需要设置其大小
        const int pell_size = 18;
        vector<int> pell_seq_vec(pell_size);
        pell_seq_vec[0] = 1;
        pell_seq_vec[1] = 2;
        for (int ix=0; ix<pell_seq_vec.size(); ++ix)
        {
            cout << pell_seq_vec[ix] << " ";
        }

        // 初始化的方式
        //1 一个一个的设置
        pell_seq_vec[0] = 1;
        pell_seq_vec[1] = 2;

        //2. 利用arrary来设置
        int elem_vals [ pell_size] = {1,2,3,4,5,6,7,8,9};
        vector<int> elem_seq(elem_vals, elem_vals+pell_size);
        for (int ix=0; ix<elem_seq.size(); ++ix)
        {
            cout << elem_seq[ix] << " ";
        }
        // 可以获得size的属性获取其列表大小
    }


    {
        // 数组array 大小在定义的时候就需要指定，其大小须是一个常量类型
        // 因为数组一旦指定了大小就不能再更改
        const int seq_size = 18;
        int pell_seq[ seq_size ];

        cout << "pell_seq: " << pell_seq  << "  "
            << sizeof(pell_seq) << "   "
            << pell_seq[10] << endl;
        
        // 计算每个元素的值，利用for与语句
        pell_seq[0] = 1;
        pell_seq[1] = 2;
        for ( int ix = 2; ix < seq_size; ++ix)
        {
            pell_seq[ ix ] = pell_seq[ ix-2 ] + 2*pell_seq[ix-1];
            cout << pell_seq[ix] << " ";
        }

        //数组的初始化方式,直接使用大括号+逗号定义
        // 不能超过数组定义的个数
        // 小于的部分默认为零
        int elem_seq[ seq_size ] = {1,2,3};
        for(int ix = 0; ix < seq_size; ++ix)
        {
            cout << elem_seq[ix] << " ";
        }
    }

    return 0;
}