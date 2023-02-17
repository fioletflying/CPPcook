#include<iostream>

using namespace std;

int main()
{
     // continue的使用
    string word;
    const int min_size = 4;
    while ( cin >> word)
    {
        if (word.size() < min_size)
            continue;
        else
            break;
    }
    


    // while循环语句，只有当条件表达式不断成立，循环语句便会不断的执行语句块
    bool next_seq = true;
    bool go_for_it = true;
    bool got_it = false;
    int num_tries = 0;
    int num_right = 0;
    int next_elem = 10;
    
    while (next_seq == true)
    {
        while((got_it == false) && (go_for_it == true))
        {
            int usr_guess;
            cin >> usr_guess;
            num_tries++;
            if (usr_guess == next_elem)
            {
                got_it = true;
                num_right++;
            }
            else
            {
                char usr_rsp;

                cout << "Do you want try again?(y/n): ";
                cin >> usr_rsp;


                if (usr_rsp == 'N' || usr_rsp == 'n')
                    go_for_it = false;
            }
        }

        // 输入是否要继续
        cout << "Want  to try another sequence? (Y/N)";
        char try_again;
        cin >> try_again;

        if (try_again == 'N' || try_again == 'n')
            next_seq = false;

    }




    return 0;
}