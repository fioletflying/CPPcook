#include <iostream>
#include <stdlib.h>


using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

// 显示相关的数据
void Display(struct Array arr)
{
    cout << "The array elments are: " << endl;

    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << "," ;
    }

    cout << endl;
    
}

// 在末尾追加元素
void Append(Array *arr, int x)
{
    if (arr->length == arr->size)
    {
        cout<< "\n no space in this array \n";
        return;
    }
    else
    {
        arr->A[arr->length++] = x;
    }
    
}

// 在某个位置插入相关的元素
void Insert(Array *arr, int index, int x)
{
    if ( index > arr->length || index < 0)
    {
        cout<< "\n no space in this array \n";
        return;
    }

    for (int i = arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i-1]; 
    }
    arr->A[index] = x;
    arr->length++;
}

// 删除在某个位置的元素
void Delete_arr(Array *arr, int index)
{
    if (index < 0 || index >= arr->length)
    {
        cout << "index is out of range. \n" ;
    }

    for (int i = index; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }

    arr->length--;
}

// 线性查找某个数据
int LinearSearch(Array *arr, int value)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == value)
        {
            return i;
        }
        
    }

    return -1;
}

void swap(int* a, int *b)
{
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 线性查找，优化查找的数据位置信息，让需要经常查找的信息往前移动
int TranspositionLinearSearch(Array *arr, int value)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == value)
        {
            if (i != 0)
            {
                swap(&arr->A[i], &arr->A[i-1]);
            }
            return i;
        }
        
    }
    return -1; 
}

// 线性查找，优化查找的数据位置信息，让查到的位置移动最开始的地方
int MovetoheadLinearSearch(Array* arr, int value)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == value)
        {
            if (i != 0)
            {
                swap(&arr->A[i], &arr->A[0]);
            } 
            return i;
        }
        
    }
    return -1;

}

// 二分查询法，需要数组已经排行顺序
int BinarySearch(Array arr, int value)
{
    int l=0, h = arr.length - 1, mid;
    while(l <= h )
    {
        mid = (l + h) / 2;
        if (arr.A[mid] == value)        
        {
            return mid;
        }
        else if (arr.A[mid] < value)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

// 指定范围内的二分查询法
int RangeBinarySearch(Array arr, int l, int h, int value)
{
    if (l <= h)
    {
        int mid = (l + h) /2;

        if (arr.A[mid] == value)
        {
            return mid;
        }
        else if (arr.A[mid] < value)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        } 
    }

    return -1;
}

int Get(Array arr, int index)
{
    if (index < 0 || index >= arr.length)
    {
        return -1;
    }
    return arr.A[index]; 
}

int Set(Array *arr, int index, int value)
{
    if (index < 0 || index > arr->length)
    {
        return -1; 
    }
    arr->A[index] = value;
    return 1;
}

int Max(Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
        
    }
    return max;
    
}


int Min(Array arr) 
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// 累加
int Sum(Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum+=arr.A[i];
    }
    return sum;
}

// 递归累积
int RSum(Array arr, int n)
{
    if(n < 0)
        return 0;
    return RSum(arr, n-1) + arr.A[n];
}

// Reverse array
void Reverse1(Array *arr)
{
    int i, j;
    // 创建一个相同大小的数组
    int *B;
    B = new int[arr->length];

    // 从后往前拷贝到新建的数组中
    for (int i = 0, j = arr->length - 1; j>0 ; i++, j--)
    {
        B[0] = arr->A[i];
    }

    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

// 利用两端一一调换的方式
void Reverse2(Array *arr)
{
    for (int i = 0, j = arr->length -1; i > j; i++, j--)
    {
        swap(arr->A[i], arr->A[j]);
    }
    
}

//左移一位数，最前面的数据放到最后面，循环左移
void LeftShift(Array *arr)
{
    int val = arr->A[0];
    for (int i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] =  arr->A[i+1];
    }
    arr->A[arr->length -1] = val;
    
}

void RightShift(Array *arr)
{
    int val = arr->A[arr->length - 1];
    for (int i = arr->length -1; i > 0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = val;
    
}

int main()
{

    //// display example
    // struct Array arr1;
    // cout << "input the array size: " <<endl;
    // cin >> arr1.size;
    // arr1.A = new int[arr1.size];
    // // arr1.length = 0;
    // int n;
    // cout << "Enter number of numbers: \n";
    // cin >> arr1.length;
    // cout << "Enter all Elements \n" ;
    // for (int i = 0; i < arr1.length; i++)
    // {
    //     cin >> arr1.A[i];
    // }
    // Display(arr1);

    // struct Array arr2 = {{1,2,3,4.5},20,5};
    // Display(arr2);
    
    Array arr1;
    arr1.size = 100;
    arr1.length = 0;
    arr1.A = new int[arr1.size];
    // append(&arr1, 6);
    insert(&arr1, 0, 3);

    append(&arr1, 6);
    append(&arr1, 7);
    append(&arr1, 8);
    append(&arr1, 9);

    Display(arr1);
    cout << "arr1.length: " << arr1.length << endl;


    delete_arr(&arr1,1);
    Display(arr1);
    cout << "arr1.length: " << arr1.length << endl;

    // 线性搜索测试
    int searchIndex = LinearSearch(&arr1, 8);
    cout << "search value 8 index: " << searchIndex << endl;

    searchIndex = TranspositionLinearSearch(&arr1, 8);
    cout << "search value 8 index: " << searchIndex << endl;

    searchIndex = LinearSearch(&arr1, 8);
    cout << "search value 8 index: " << searchIndex << endl;

    searchIndex = MovetoheadLinearSearch(&arr1, 8);
    cout << "search value 8 index: " << searchIndex << endl;

    searchIndex = LinearSearch(&arr1, 8);
    cout << "search value 8 index: " << searchIndex << endl;

    // for (int i = 0; i < arr1.length; i++)
    // {
    //     cout << arr1.A[i] << ",";
    // }
    


    delete []arr1.A;

    cout << " buiding array !" << endl;
    return 0;
}