#include <stdio.h>

void reverse(int *arr, int size)
{
    int start = 0;
    int end = size - 1;
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
    int size = 7;
    int arr[] = {12, 3, 4, 5, 6, 7, 7};
    reverse(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}