#include <stdio.h>
/*
    算法思想：
        用res数组存储可能称为中位数的值，通过类似归并排序中的归并过程扫描数组，并更新res，找到
        比中点下标大一的位置为止，如果长度为偶数，则返回res数组元素之和除二作为中位数；若长度为奇数，
        则返回中间那个数。
    
    时间复杂度：
        最多扫描两个顺序表长度之和的一半的数据元素一次，因此时间复杂度为o(n)
*/

int f(int *l1, int s1, int *l2, int s2)
{
    int res[] = {0, 0};
    int mid = (s1 + s2) / 2 + 1;
    int i = 0, j = 0;
    while (i < s1 && j < s2 && i + j <= mid)
    {
        if (l1[i] < l2[j])
        {
            swap(res, 0, 1);
            res[1] = l1[i];
            i += 1;
        }
        else
        {
            swap(res, 0, 1);
            res[1] = l2[j];
            j += 1;
        }
    }
    while (i + j <= mid && i < s1)
    {
        swap(res, 0, 1);
        res[1] = l1[i];
        i += 1;
    }
    while (i + j < mid && j < s2)
    {
        swap(res, 0, 1);
        res[1] = l2[j];
        j += 1;
    }
    if ((s1 + s2) % 2 == 1)
        return res[1];
    else
        return (res[0] + res[1]) / 2;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int ff(int *l1, int *l2, int s)
{
    int a, b;
    int i = 0;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 5, 5, 5, 5, 6};
    printf("%d", f(arr1, 5, arr2, 7));
}