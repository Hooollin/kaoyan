#include <stdio.h>

void f(int *arr, int size, int target)
{
    int insertPos = 0;
    int t = size;
    while (insertPos < t)
    {
        if (arr[insertPos] != target)
        {
            insertPos += 1;
        }
        else
        {
            arr[insertPos] = arr[t - 1];
            t -= 1;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 4, 4, 4, 4, 5};
    f(arr, 7, 3);
    for (int i = 0; i < 7; i++)
    {
        printf("%d, ", arr[i]);
    }
}