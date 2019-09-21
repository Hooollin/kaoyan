#include <stdio.h>

int t[1000] = {0};
int f(int *arr, int size)
{
    int res = -1;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        t[arr[i]] += 1;
        if (t[arr[i]] > count)
        {
            count = t[arr[i]];
            res = arr[i];
        }
    }
    return count >= size / 2 ? res : -1;
}

int ff(int *arr, int size)
{
    int res;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (count == 0)
        {
            res = arr[i];
        }

        if (res == arr[i])
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
    }
    int t = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == res)
        {
            t += 1;
        }
    }

    return t > size / 2 ? res : -1;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5};
    printf("%d,", ff(arr, sizeof(arr) / sizeof(int)));
}