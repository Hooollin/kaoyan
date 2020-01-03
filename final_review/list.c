#include <stdio.h>

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
void swap(int *arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int fun1(int *arr, int length)
{
    int min_idx = -1, min_val = 0x7fff;
    for (int i = 0; i < length; i++)
    {
        if (min_val < arr[i])
        {
            min_idx = i;
            min_val = arr[i];
        }
    }
    arr[min_idx] = arr[length - 1];
    return length - 1;
}

void fun2(int *arr, int length)
{
    int start = 0, end = length - 1;
    while (start < end)
    {
        swap(arr, start, end);
        start += 1;
        end -= 1;
    }
}

int fun3(int *arr, int length, int s, int t)
{
    if (s > t)
        return -1;
    int inPos = 0;
    int i = 0;
    while (i < length)
    {
        if (arr[i] < s || arr[i] > t)
        {
            arr[inPos++] = arr[i];
        }
        i += 1;
    }
    return inPos;
}

void main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fun3(arr, 10, 1, 5);
    print(arr, 5);
}
