#include <stdio.h>

void f(int *arr, int size, int k)
{
    reverse(arr, 0, size);
    reverse(arr, 0, k);
    reverse(arr, k, size);
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