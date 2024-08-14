#include<iostream>


int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

//函数传参，值传递
//值传递时，传递的是实参的拷贝的值，不会影响实参的值
void swapByVal(int a, int b)
{
    int temp;    //temporary variable to store the value of a
    temp = a;    //store the value of a in temp
    a = b;       //assign the value of b to a
    b = temp;    //assign the value of temp to b
}

//函数传参，指针传递
// 指针传递时，传递的是指针的地址，而不是指针指向的值,会实际改变实参的值
void swapByPtr(int *a, int *b)
{
    int temp;    //temporary variable to store the value of a
    temp = *a;    //store the value of a in temp
    *a = *b;       //assign the value of b to a
    *b = temp;    //assign the value of temp to b
}

//函数传参，引用传递
// 引用传递时，传递的是引用的地址，而不是引用指向的值,会实际改变实参的值
void swapByRef(int &a, int &b)
{
    int temp;    //temporary variable to store the value of a
    temp = a;    //store the value of a in temp
    a = b;       //assign the value of b to a
    b = temp;    //assign the value of temp to b
}

// 函数传参，数组传递，数组名作为实参，传递的是数组的地址，而不是数组的元素
// 数组名作为实参，传递的是数组的地址，而不是数组的元素，会实际改变数组的值
void changeArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] += 10;
    }
    
}

//数组作为返回值
int* createArray(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    return arr;
}

//函数传参：结构体按值传递
// 结构体作为实参，按值传递时，传递的是结构体的拷贝，不会影响实参的值
// 即使结构体包含数组，也会被拷贝，数组中的元素也会被拷贝
struct Person
{   
    char name[20];
    int age;
};

void changePerson(Person person)
{
    person.age += 10;
}

//函数传参：结构体按引用传递
// 结构体作为实参，按引用传递时，传递的是结构体的地址，会改变实参的值
void changePersonAge(Person& person, int age)
{
    person.age = age;
}

int main()
{
    int x, y, z;
    x = 10;
    y = 5;

    z = add(x, y);
    std::cout << "sum is: " << z << std::endl;

    std::cout << "Before swap: x = " << x << " y = " << y << std::endl;
    swapByVal(x, y);
    std::cout << "After swap: x = " << x << " y = " << y << std::endl;

    std::cout << "Before swap: x = " << x << " y = " << y << std::endl;
    swapByPtr(&x, &y);
    std::cout << "After swap: x = " << x << " y = " << y << std::endl;

    std::cout << "Before swap: x = " << x << " y = " << y << std::endl;
    swapByRef(x, y);
    std::cout << "After swap: x = " << x << " y = " << y << std::endl;

    std::cout <<"sum is: " << z << std::endl;

    //数组作为实参
    int arr[5] = {1, 2, 3, 4, 5};
    changeArray(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " "<< std::endl;
    }

    //数组作为返回值
    int* arr2 = createArray(5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr2[i] << " " << std::endl;
    }
    delete[] arr2;

    //结构体作为实参，按值传递
    Person person={"Alice",25};
    changePerson(person);
    std::cout << "Name: " << person.name << " Age: " << person.age << std::endl;

    //结构体作为实参，按引用传递
    Person person2={"Bob",30};
    std::cout << "Name: " << person2.name << " Age: " << person2.age << std::endl;
    changePersonAge(person2, 35);
    std::cout << "Name: " << person2.name << " Age: " << person2.age << std::endl;
    return 0;
}
