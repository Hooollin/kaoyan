#include <stdio.h>
/* 
    算法设计基本思想；
        逆序整个顺序表；
        逆序前size-p个元素；
        逆序后p个元素；

    时间复杂度:
        逆序过程时间复杂度为o(n), 一共执行三次，总时间复杂度为o(n)
*/
void f(int *arr, int size, int k)
{
    reverse(arr, 0, size);
    reverse(arr, 0, size - k);
    reverse(arr, size - k, size);
}

void reverse(int *arr, int lo, int hi)
{
    while (lo < hi)
    {
        int temp = arr[lo];
        arr[lo] = arr[hi];
        arr[hi] = temp;
        lo += 1;
        hi -= 1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    f(arr, 7, 3);
    for (int i = 0; i < 7; i++)
    {
        printf("%d, ", arr[i]);
    }
}