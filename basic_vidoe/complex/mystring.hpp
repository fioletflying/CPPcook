#ifndef __MYSTRING__
#define __MYSTRING__
#include<cstring>
#include<ostream>

using namespace std;

class mystring
{

public:
    mystring(const char* cstr = 0);

    mystring(const mystring& cstr);
    mystring& operator=(const mystring& cstr);

    char* get_cstr_data() const;


private:
    char* my_data;


};

// 构造函数
// 判断传入的指针是否为空
// 如果为空就仅仅添加终止符
// 如果不为空则进行复制
mystring::mystring(const char* cstr)
{
    if(cstr)
    {
        my_data = new char[strlen(cstr) + 1];
        strcpy(my_data, cstr);
    }
    else
    {
        my_data = new char[1];
        *my_data = '\0';
    }

}

// 拷贝构造函数
// 这里需要注意：所谓深拷贝，就是将类中的指针指向的值进行一一拷贝
mystring::mystring(const mystring& cstr)
{
    my_data = new char[strlen(cstr.my_data) + 1];
    strcpy(my_data, cstr.my_data);
}

// 拷贝赋值操作符重载
// 首先赋值对象是同一个的时候，直接返回，不加这个会导致错误
// 然后先释放自己的成员变量的空间
// 再创建对应的空间，
// 最后进行一对一的深度拷贝
inline
mystring& mystring::operator=(const mystring& cstr)
{

    // 判断是否为相同的数据地址
    if(this == &cstr) return *this;

    
    delete [] my_data;
    my_data = new char[strlen(cstr.my_data) + 1];
    strcpy(my_data, cstr.my_data);
    return *this;
}


char* mystring::get_cstr_data() const
{
    return my_data;
}

ostream& operator<<(ostream& os, const mystring& str)
{
    os << str.get_cstr_data();
    return os;
}




#endif