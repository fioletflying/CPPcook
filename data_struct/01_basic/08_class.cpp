#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;
public:
    Rectangle(){length = 1; breadth =2;}
    Rectangle(int l, int b);

    int area();
    int getLength();
    void setLength(int l);
};

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int Rectangle::area()
{
    return length * breadth;
}

int Rectangle::getLength()
{
    return length;
}

void Rectangle::setLength(int l)
{
    length = l;
}


int main()
{

    Rectangle r(4,2);

    // r.initiRect(1,2);

    cout << "r area: " <<  r.area() << endl;




    cout << "data struct ch01" << endl;
    return 0;
}