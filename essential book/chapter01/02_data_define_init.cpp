#include <iostream>

using namespace std;

int main()
{

    bool go_for_it = true;
    if(go_for_it)
    {
        cout << "go_for_it : \t" << go_for_it <<endl;
    }

    char usr_more;
    cout << "Try another sequence? Y/N\n";
    cin >> usr_more;

    if(usr_more == 'Y')
    {
        go_for_it = true;
        cout << "try again! \n";
    }
    else
    {
        cout << "quit!!!!";
        return 0;
    }

    const int max_tries = 3;
    cout << max_tries <<endl;
    // 报错无法进行修改
    // max_tries = 5
}