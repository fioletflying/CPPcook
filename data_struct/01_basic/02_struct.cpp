#include <iostream>
#include <cstring>

using namespace std;


//关于矩形结构体的定义
struct Rectangle
{
    int length;
    int breadth;
};

//关于复数结构体的定义
struct Complex
{
    int real;
    int img;
};

// 学生结构体:77bytes
struct Student
{
    int roll;
    char name[25];
    char dept[10];
    char addr[50];
};

// 扑克牌结构体
struct Card
{
    int face;
    int shape;
    int color;
};


int main()
{
    // 声明一个结构体
    Rectangle r1;
    // 定义一个结构体
    Rectangle r2 = {1,2};

    // 修改结构体的内容
    r1.length = 10;
    r1.breadth = 5;

    cout << "r1: " << r1.length << " , " << r1.breadth << endl;
    
    cout << "r2: " << r2.length << " , " << r2.breadth << endl;

    
    Student s1;
    s1.roll = 10;
    // 这里要注意，不能直接使用赋值号 = 来赋值
    // 因为字符数组是一个常量，所以使用字符串操作函数
    strcpy(s1.name, "jacky");
    cout << "name: " << s1.name <<endl;

    




    cout << "data struct ch01" << endl;
    return 0;
}