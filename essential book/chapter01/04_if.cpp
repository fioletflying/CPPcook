#include <iostream>

using namespace std;

int main()
{
    // swtch case

    char next_char = 'a';
    switch (next_char)
    {
        case 'a':
            cout << "a is now\n";
            break;
        case 'b':
            cout << "b is now\n";
            break;
        case 'c':
            cout << "c is now\n";
            break;
        default:
            cout << "other char is now\n";
            break;
    }

    // 多个case组合，这样可以实现多个条件组合
    switch (next_char)
    {
        case 'a': case 'e':
        case 'o': case 'u':
        case 'i':
            cout << "vowel char.";
            break;
        default:
            cout << "other char.";
            break;
    }



    char usr_rsp;
    bool go_for_it = true;
    bool got_it = false;
    int usr_guess = 0; 
    int num_right = 0;
    int next_elem = 10;
    int num_tries = 3;
    

    cout << "please guss the number: ";
    cin >> usr_guess;
    // 在if语句中出现了多个执行需要使用语句大括号
    if (usr_guess == next_elem)
    {
        num_right++;
        got_it = true;
    }
    // 使用 else语句块，
    else
    {
        // // else if 结合可以实现多种情况的判断
        // if (num_tries == 1)
        // {
        //     cout << "1111\n";
        // }
        // else if (num_tries == 2)
        // {
        //     cout << "22222\n";
        // }
        // else if (num_tries == 3)
        // {
        //     cout << "33333\n";
        // }

        switch (num_tries)
        {
            case 1:
                cout << "1111\n";
                break;
            case 2:
                cout << "2222\n";
                break;
            case 3:
                cout << "3333\n";
                break;
            default:
                cout << "45678\n";
                break;
        }

        got_it = false;
        cout << "sorry, the number is wrong.";
        cout << "Want to try again? (Y/N):";
        cin>>usr_rsp;
        // 单个执行动作可以不使用大括号，这里建议先习惯使用大括号
        if (usr_rsp == 'N' || usr_rsp == 'n' )
            go_for_it = false;
        
    }


    
    cout << go_for_it;

    return 0;
}