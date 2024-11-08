#include <iostream>

using namespace std;

template <class T>
class Arithmetic
{
private:
    T a,b;
public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    return a + b;
}

template <class T>
T Arithmetic<T>::sub()
{
    return a - b;
}





int main()
{
    Arithmetic<int> arr(10, 5);
    cout << arr.add() <<endl;

    Arithmetic<float> arr2(1.1, 2.2);
    cout << arr2.sub() << endl;

    cout << "data struct ch01" << endl;
    return 0;
}