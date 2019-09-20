#include <stdio.h>

int buffer[10000] = {0};

void f(int *arr, int size)
{
    int insertPos = 0;
    int s = size;
    while (insertPos < s)
    {
        if (buffer[arr[insertPos]] != 0)
        {
            arr[insertPos] = arr[s - 1];
            s--;
        }
        else
        {
            buffer[arr[insertPos]] = 1;
            insertPos += 1;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 2, 4, 4, 5, 5};
    f(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d,", arr[i]);
    }
}