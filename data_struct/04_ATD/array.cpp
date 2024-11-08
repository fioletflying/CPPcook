#include <iostream>
#include <stdlib.h>


using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout << "The array elments are: " << endl;

    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << "," ;
    }

    cout << endl;
    
};


int main()
{
    struct Array arr1;

    cout << "input the array size: " <<endl;

    cin >> arr1.size;
    arr1.A = new int[arr1.size];
    // arr1.length = 0;

    int n;
    cout << "Enter number of numbers: \n";
    cin >> arr1.length;

    cout << "Enter all Elements \n" ;
    for (int i = 0; i < arr1.length; i++)
    {
        cin >> arr1.A[i];
    }

    Display(arr1);

    // struct Array arr2 = {{1,2,3,4.5},20,5};
    // Display(arr2);
    


    cout << " buiding array !" << endl;
    return 0;
}