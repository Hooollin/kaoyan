#include <stdio.h>

int f(int *arr, int size, int s, int t)
{
    if (size <= 0)
    {
        printf("顺序表为空");
        return -1;
    }
    int insertPos = 0;
    int index = size;
    while (insertPos < index)
    {
        if (arr[insertPos] >= s && arr[insertPos] <= t)
        {
            arr[insertPos] = arr[index - 1];
            index--;
        }
        else
        {
            insertPos += 1;
        }
    }
    return index; // 新的arr size
}

int main()
{
    int arr[] = {1, 4, 5};
    f(arr, 3, 2, 4);
    for (int i = 0; i < 3; i++)
    {
        printf("%d, ", arr[i]);
    }
}