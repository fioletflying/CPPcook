#include<iostream>
#include<vector>

using namespace std;

void display(const vector<int>& vec);
void swap_value( int val1, int val2 );
void swap_ref( int& val1, int& val2 );
void bubble_sort( vector<int>& vec );

int main()
{
    vector<int> ia = {8, 34, 3, 13, 1, 21, 5, 2};

    cout << "sort befor: " <<endl;
    display(ia);


    bubble_sort(ia);

    cout << "sort after: " <<endl;
    display(ia);
    return 0;
}

// 打印vector 的值 
void display(const vector<int>& vec)
{
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        cout << vec[ix] << ' ';
    }

    cout << endl;
}
// 交换两个数值
// 从内存角度来理解：当函数被调用的时候，内存会建立一个特殊的区域：program stack 程序堆栈
// 这个内存块用来提供函数参数的存储空间以及函数内部定义的对象空间 - 局部对象(local object)
// 这个内存空间，一旦函数完成，将会自动释放。所以如果将对象数据按照pass by value的方式进行
// 传入的话，就相当于将参数复制一份给参数，而这个参数是局部对象，它跟传入的数据没有任何关联
void swap_value( int val1, int val2 )
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

// 传引用/地址
void swap_ref( int& val1, int& val2 )
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}


// 传引用的好处:
// 1. 可以直接修改传入的对象
// 2. 提高效率,降低复制大型的对象的额外负担
// 参数优先考虑传引用,如果希望该参数不被修改可以加上const
void bubble_sort( vector<int>& vec )
{
    for (int ix =0; ix < vec.size(); ++ix)
    {
        for (int jx = ix+1; jx < vec.size(); ++jx)
        {
            if (vec[ix] > vec[jx])
            //这里是关键，我们传递的是两个值给交换函数
            // 对于 swap_value函数来说，它会将vec[ix], vec[jx]复制一份，这样传进的参数与原对象vec就没有关系了
            // 也就是说，里面做任何事情，vec都不会有任何改变，这就是函数传值参数的概念
                //swap_value(vec[ix], vec[jx]);
                swap_ref(vec[ix], vec[jx]);
        }
    }
}

void reference_mean()
{
    int ival = 1024; // 定义了一个int 的对象
    int *pi = &ival;    // 定义了一个指针，它指向一个int 对象
    int &rval = ival;   //定义了一个引用，代表一个int对象

    int * const pci = &ival; //引用有点像常量指针，指向了一个地址后就不会再改变了

    int jval = 4096;
    rval = jval;    // 引用无法代表jval, 只能代表初始化的那个对象
    //pci = &jval;
    pi = &jval; // 指针时可以改变其指向对象的地址
}

// 指针常量，这个指针指向的对象的值是不允许被修改的
// 使用指针作为参数跟引用作为参数的区别有三点：
//      1. dot变成arrow 即 .变成 ->, 需要使用提领操作才能取得对象的数据
//      2. 调用的时候传入的参数是要加取地址符号: &
//      3. 指针可能指向某个实际对象,也可能是一个null,所以在做提领的时候要建一个判断是否为0,但是引用就不需要有这个顾虑
void display_point(const vector<int>* vec)
{
    if(!vec)
    {
        cout << "display(): the vector pointer is 0\n";
        return;
    }
    for (int ix = 0; ix < vec->size(); ++ix)
    {
        cout << (*vec)[ix] << ' ';
    }

    cout << endl;
}

//display_point(&vec)
// 使用引用常量,传入进去的参数不会被修改
// 这个时候就代表了传入进去的参数,使用的时候就是跟使用实际的对象的一样
// 引用就像是对象的别名,直接使用该对象
void display_ref(const vector<int>& vec)
{
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        cout << vec[ix] << ' ';
    }

    cout << endl;
}