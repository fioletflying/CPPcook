#include <iostream>

//常数复杂度，比如访问数组中某个元素
int access_array(int arr[], int n, int i)
{
    return arr[i];
}

//线性复杂度，比如遍历数组
int traverse_array(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

//对数复杂度，二分查找算法divide and conquer
int binary_search(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}


int main()
{

    return 0;
}