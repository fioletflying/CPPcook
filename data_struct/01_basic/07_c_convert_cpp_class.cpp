#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    void changeLength(int l)
    {
        length = l;
    }

};


int main()
{

    Rectangle r(1,2);

    // r.initiRect(1,2);

    cout << "r area: " <<  r.area() << endl;




    cout << "data struct ch01" << endl;
    return 0;
}