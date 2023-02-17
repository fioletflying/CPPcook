#include<iostream>
#include<fstream>
#include<string>

using namespace std;


/***
 * 实验目的：文件的读写
 * 每次执行结束时，将用户名字和会话写入文件，程序开启的时候读出文件
 * 
 * 
*/

int main()
{
    // 写入到文件
    {
        string usr_name = "Wali";
        int num_tries = 10;
        int num_right = 6;

        ofstream outfile("seq_data.txt", ios_base::app);

        if ( ! outfile )
        {
            // cerr 是ostream 对象，标准错误的输出到终端
            cerr << "Oops! Unable to save session data!\n";
        }
        else
            outfile << usr_name << ' '
                    << num_tries << ' '
                    << num_right << endl;
    }

    // 读取文件
    {
        ifstream infile("seq_data.txt");
        int num_tries = 0;
        int num_cor = 0;
        string usr_name = "Wali";

        if ( !infile )
        {
            cerr << "file open failed" << endl;
        }
        else
        {
            string name;
            int nt;
            int nc;
            // 这里会逐行的迭代文件的每一行
            while ( infile >> name)
            {
                // 将 
                infile >> nt >> nc;
                if (name == usr_name) 
                {
                    cout << "Welcome back, " << usr_name
                    << "\nYour current score is " << nc
                    << " out of " << nt << "\nGood Luck!\n";

                    num_tries = nt;
                    num_cor = nc;
                }
            }
        }
    }

}