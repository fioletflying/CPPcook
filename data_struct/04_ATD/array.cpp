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

//右移一位数，最后面的数据放到最前面，循环右移
void RightShift(Array *arr)
{
    int val = arr->A[arr->length - 1];
    for (int i = arr->length -1; i > 0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = val;
    
}

// 检查数组是否排好序
int CheckSorted(Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i+1])
        {
            return -1;
        }
        
    }

    return 1; 
}

// 将元素插入到排好序的数组中
void InsertSorted(Array *arr, int val)
{
    if (arr->length == arr->size)
    {
        return;
    }

    int i = arr->length - 1;
    while (val < arr->A[i])
    {
        arr->A[i+1] = arr->A[i];
        i --;
    }

    arr->A[i+1] = val;
    arr->length += 1;
    
    
}

// 将负数移动到左边
void LeftShiftNegative(Array *arr)
{
    int i = 0;
    int j = arr->length -1;
    while (i<j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i<j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
    
}

Array MergeSorted2(Array* arr1, Array* arr2)
{
    Array arrMerge;
    arrMerge.length = arrMerge.size = arr1->length + arr2->length;
    arrMerge.A = new int[arrMerge.size];
    int i,j,k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arrMerge.A[k] = arr1->A[i];
            i++;
            k++;
        }
        else
        {
            arrMerge.A[k] = arr2->A[j];
            j++;
            k++;
        }
        
    }

    for ( ; i < arr1->length; i++, k++)
    {
        arrMerge.A[k] = arr1->A[i];
    }

    for ( ; j < arr2->length; j++, k++)
    {
        arrMerge.A[k] = arr1->A[j];
    }
    
    return arrMerge;
    
}

Array *MergeSorted(Array* arr1, Array* arr2)
{
    Array *arrMerge = new Array;
    arrMerge->length = arrMerge->size = arr1->length + arr2->length;
    arrMerge->A = new int[arrMerge->size];
    int i,j,k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arrMerge->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else
        {
            arrMerge->A[k] = arr2->A[j];
            j++;
            k++;
        }
        
    }

    for ( ; i < arr1->length; i++, k++)
    {
        arrMerge->A[k] = arr1->A[i];
    }

    for ( ; j < arr2->length; j++, k++)
    {
        arrMerge->A[k] = arr1->A[j];
    }
    
    return arrMerge;
    
}

// Set Operation
Array *UnionSetSorted(Array *arr1, Array *arr2)
{
    Array *arrSet = new Array;
    arrSet->A = new int[arr1->length + arr2->length];
    arrSet->size = arr1->size + arr2->size;
    int i = 0, j = 0, k = 0; 
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arrSet->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if (arr1->A[i] > arr2->A[j])   
        {
            arrSet->A[k] = arr2->A[j];
            j++;
            k++;
        }
        else
        {
            arrSet->A[k] = arr2->A[j];
            i++;
            j++;
            k++;
        }   
    }

    for (; i < arr1->length; i++,k++)
    {
        arrSet->A[k] = arr1->A[i];
    }

    for (; j < arr2->length; j++,k++)
    {
        arrSet->A[k] = arr2->A[j];
    }

    arrSet->length = k;
    
    return arrSet;
}

Array *ArraySetSorted(Array *arr1, Array *arr2)
{
    Array *arrSet = new Array;
    arrSet->A = new int[arr1->length + arr2->length];
    arrSet->size = arr1->size + arr2->size;
    int i = 0, j = 0, k = 0; 
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            if (k> 0 && arrSet->A[k-1] == arr1->A[i])
            {
                i++;
                continue;
            }
            arrSet->A[k] = arr1->A[i];
            i++;
            k++;

        }
        else if (arr1->A[i] > arr2->A[j])   
        {
            if (k> 0 && arrSet->A[k-1] == arr2->A[j])
            {
                j++;
                continue;
            }
            arrSet->A[k] = arr2->A[j];
            j++;
            k++;
        }
        else
        {
            if (k> 0 && arrSet->A[k-1] == arr2->A[j])
            {
                j++;
                i++;
                continue;
            }
            arrSet->A[k] = arr2->A[j];
            i++;
            j++;
            k++;
        }   
    }

    for (; i < arr1->length; i++)
    {
        if (k> 0 && arrSet->A[k-1] == arr1->A[i])
        {
            continue;
        }
        arrSet->A[k] = arr1->A[i];
        k++;
    }

    for (; j < arr2->length; j++)
    {
        if (k> 0 && arrSet->A[k-1] == arr2->A[j])
        {
            continue;
        }
        arrSet->A[k] = arr2->A[j];
        k++;
    }

    arrSet->length = k;
    
    return arrSet;
}

Array *SetIntersection(Array *arr1, Array *arr2)
{
    Array *interSet = new Array;
    interSet->size = arr1->size + arr2->size;
    interSet->A = new int[arr1->length + arr2->length];
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j]) i++;
        else if (arr1->A[i] > arr2->A[j]) j++;
        else
        {
            interSet->A[k] = arr1->A[i];
            k++;
            i++;
            j++;
        }
    }
    interSet->length = k;

    return interSet;
}

Array *SetDifference(Array *arr1, Array *arr2)
{
    Array *diffSet = new Array;
    diffSet->size = arr1->size + arr2->size;
    diffSet->A = new int[arr1->length + arr2->length];
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            diffSet->A[k] = arr1->A[i];
            k++;
            i++;
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    for ( ; i < arr1->length; i++, k++)
    {
        diffSet->A[k] = arr1->A[i];
    }
    
    diffSet->length = k;

    return diffSet;
}

// Find Missing Elements
int FindFirstMissing(Array arr)
{
    int diff = arr.A[0]; 
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            cout << "the first missing elements is: " << i+diff << endl;
            return i+diff;
        }
        
    }
    return -1;
}

int FindMultMissing(Array arr)
{
    int diff = arr.A[0];
    int missingCount = 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            while (arr.A[i] - i != diff)
            {
                cout << "missing element : " << i +diff << endl;
                diff++;
                missingCount++;
            }
            
        }
        
    }
    return missingCount;
}

void FindMultMissHash(Array arr)
{
    int max = Max(arr);
    int min = Min(arr);
    int hashRang = max - min + 1;
    int h[hashRang] = {0};
    for (int i = 0; i < arr.length; i++)
    {
        h[arr.A[i] - min]++; 
    }
    for (int i = 0; i < max; i++)
    {
        if (h[i] == 0)
        {
            cout << "miss elements: " << i + min << endl;
        }
        
    }
    
    
}

void FindDuplicates(Array arr)
{
    int lastDuplicat = 0;
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i+1] && arr.A[i] != lastDuplicat)
        {
            cout << "duplicate : " << arr.A[i] << endl;;
            lastDuplicat = arr.A[i];
        }
    }  
}

void CountDuplicates(Array arr)
{
    int count, j = 0;
    for (int i = 0; i < arr.length -1; i++)
    {
        
        if (arr.A[i] == arr.A[i+1])
        {
            j = i + 1;
            count = 0;
            while (arr.A[j] == arr.A[i])
            {
                count++;
                j++;
            }
            i = j - 1;
            cout << "Duplicate element : " << arr.A[i] << " apear: " << count << " times\n";
        }
       
        
    }
    
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
    
    /*******search test**********/
    // Array arr1;
    // arr1.size = 100;
    // arr1.length = 0;
    // arr1.A = new int[arr1.size];
    // // append(&arr1, 6);
    // Insert(&arr1, 0, 3);

    // Append(&arr1, 6);
    // Append(&arr1, 7);
    // Append(&arr1, 8);
    // Append(&arr1, 9);

    // Display(arr1);
    // cout << "arr1.length: " << arr1.length << endl;


    // Delete_arr(&arr1,1);
    // Display(arr1);
    // cout << "arr1.length: " << arr1.length << endl;

    // // 线性搜索测试
    // int searchIndex = LinearSearch(&arr1, 8);
    // cout << "search value 8 index: " << searchIndex << endl;

    // searchIndex = TranspositionLinearSearch(&arr1, 8);
    // cout << "search value 8 index: " << searchIndex << endl;

    // searchIndex = LinearSearch(&arr1, 8);
    // cout << "search value 8 index: " << searchIndex << endl;

    // searchIndex = MovetoheadLinearSearch(&arr1, 8);
    // cout << "search value 8 index: " << searchIndex << endl;

    // searchIndex = LinearSearch(&arr1, 8);
    // cout << "search value 8 index: " << searchIndex << endl;
    
    // delete []arr1.A;


    // Array arr1, arr2;
    // arr1.length = 0;
    // arr2.length = 0;
    // arr1.size = 100;
    // arr2.size = 100;
    // arr1.A = new int[3];
    // arr2.A = new int[3];

    // Append(&arr1,1);
    // Append(&arr1,1);
    // Append(&arr1,1);

    // Append(&arr2,1);
    // Append(&arr2,3);
    // Append(&arr2,3);

    // // Array *arr3 = Merge(&arr1, &arr2);
    // // Display(*arr3);
    // // delete []arr3->A;
    // // delete arr3;
    // // Display(*arr3);

    // // Array arr4 = Merge2(&arr1, &arr2);
    // // Display(arr4);

    // Array *arr3 = ArraySetSorted(&arr1, &arr2);
    // Display(*arr3);

    Array arr1;
    arr1.length = 0;
    arr1.size = 20;
    arr1.A = new int[20];

    arr1.A[0] = 6;
    arr1.A[1] = 7;
    arr1.A[2] = 8;
    arr1.A[3] = 8;
    arr1.A[4] = 10;
    arr1.A[5] = 10;
    arr1.A[6] = 12;
    arr1.length = 7;

    // int diff_element = FindFirstMissing(arr1);

    // int miss_count = FindMultMissing(arr1);

    // FindMultMissHash(arr1);

    CountDuplicates(arr1);

    cout << " buiding array !" << endl;
    return 0;
}