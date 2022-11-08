/***
 * 猜数字的游戏
 * 1、准备六祖数列，每组数列有9个元素
 * 2、
 * **/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<fstream>

using namespace std;

int main()
{
    const int vec_size = 6;
    const int vec_len = 8;
    int num_tries = 0;
    int num_cor = 0;
    bool is_next_try = true;
    bool go_for_it = true;
    bool got_it = false;

    // 准备数据
    vector<int> Fibonacci = {1,1,2,3,5,8,13,21};
    vector<int> Lucas = {1,3,4,7,11,18,29,47};
    vector<int> Pell = {1,2,5,12,29,70,169,408};
    vector<int> Triangular = {1,3,6,10,15,21,28,36};
    vector<int> Square = {1,4,9,16,25,36,49,64};
    vector<int> Pentagonal = {1,5,12,22,35,51,70,92};

    vector<int>* pv[vec_size] = {
        &Fibonacci, &Lucas, &Pell,
        &Triangular, &Square, &Pentagonal};

    // 输入名字
    string user_name;
    cout << "Wellcome here to gusse number!" <<endl;
    cout << "please input your name: " << endl;
    cin >> user_name;
    cout << "\n Hello, " << user_name <<endl;
    // 核对名字是否存在
    ifstream infile("seq_data.txt");
    if(!infile)
    {
        // 说明是一个新的文件，需要生成一个文件
        ofstream outfile("seq_data.txt");
    }
    else
    {
        string name;
        int nt;
        int nc;

        while (infile >> name)
        {
            infile >> nt >> nc;
            if (name == user_name)
            {
                cout << "Welcome back, " << user_name
                << "\nYour current score_is " << nc
                << "out of " << nt << "\nGood Luck!\n";

                num_tries = nt;
                num_cor = nc;
            }
        }
    }

    while(is_next_try)
    {
        int arr_index = rand() % vec_size;
        vector<int>* cuurent_arr = pv[arr_index];
        int start_index = rand() % (vec_len-2);
        int next_elem = (*cuurent_arr)[start_index+2];
        int curr_num_guess = 0;
        int max_num_guess = 3;
        got_it = false;
        go_for_it = true;

        cout << "The number is: " << (*cuurent_arr)[start_index]
            << ", " << (*cuurent_arr)[start_index+1] << endl;

        while (go_for_it && (got_it == false))
        {
            int usr_guess;
            cout << "your guess: " << endl;
            cin >> usr_guess;
            num_tries++;
            curr_num_guess++;

            // 猜对了
            if (usr_guess == next_elem)
            {
                got_it = true;
                num_cor++;

                cout << "well done,  " << user_name 
                      << "\nYour current score_is " << num_cor
                    << " out of " << num_tries << "\nGood Luck!\n";
            }
            else
            {
                if (curr_num_guess == 1)
                {
                    cout << "Oops! Nice guess but not quite it.\n";
                }
                else if ( curr_num_guess == 2)
                {
                    cout << "Hmm, Sorry. Wrong a second time.\n";
                }
                else if ( curr_num_guess == 3)
                {
                    cout << "Ah, this is harder than it looks, isn't it?\n";
                }
                else
                {
                    cout << "It must be getting pretty frustrating by now!\n";
                    cout << "this sequeese is over now.\n";
                    break;
                }

                cout << "Want to try again? (Y/N)";
                char usr_rsp;
                cin >> usr_rsp;
                if (usr_rsp == 'N' || usr_rsp == 'n')
                    go_for_it = false;
            }
        }

        cout << "Want to try another sequence? (Y/N)";
        char try_again;
        cin >> try_again;

        if (try_again == 'N' || try_again == 'n')
            is_next_try = false;
       
    }
    
    cout << "Hello gusser!" <<endl;
    return 0;
}
