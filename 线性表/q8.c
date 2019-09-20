#include <stdio.h>

void f(int *arr, int size1, int size2)
{
    reverse(arr, 0, size1 + size2);
    reverse(arr, 0, size2);
    reverse(arr, size2, size1 + size2);
}

void reverse(int *arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 2, 3, 4, 5};
    f(arr, 5, 4);
    for (int i = 0; i < 9; i++)
    {
        printf("%d, ", arr[i]);
    }
}