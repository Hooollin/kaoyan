#include <stdio.h>

int f(int *arr, int *len)
{
    if (*len == 0)
    {
        printf("线性表为空.");
        return 0;
    }
    int index = -1;
    int min = 1000;
    for (int i = 0; i < *len; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    arr[index] = arr[*len - 1];
    *len -= 1;
    return min;
}

int main()
{
    int size = 0;
    int arr[0];
    int res = f(arr, &size);
    printf("%d", res);
}