#include <stdio.h>

void f(int *arr, int size, int x)
{
    int lo = 0, hi = size - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] <= x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (arr[hi] == x)
    {
        if (hi < size - 1)
        {
            int temp = arr[hi];
            arr[hi] = arr[hi + 1];
            arr[hi + 1] = temp;
        }
    }
    else
    {
        for (int j = size - 1; j >= lo; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[lo] = x;
    }
}

int main()
{
    int arr[] = {1, 2, 2, 2, 4, 5};
    f(arr, 6, 3);
    for (int i = 0; i < 6; i++)
    {
        printf("%d, ", arr[i]);
    }
}