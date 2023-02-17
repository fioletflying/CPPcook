# include <iostream>
# include <string>
using namespace std;


int main()
{
    string user_name_first, user_name_sconde;
    cout << "Please enter your first name: ";
    cin >> user_name_first;
    cout << "Please enter your second name: ";
    cin >> user_name_sconde;
    cout << '\n'
         << "Hello, "
         << user_name_sconde 
         << "."
         << user_name_first
         << "... and goodbye!\n";
    
    return 0;
}