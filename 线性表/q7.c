#include <stdio.h>

int *merge(int *l1, int *l2, int size1, int size2)
{
    int *nl = (int *)malloc(sizeof(int) * (size1 + size2));
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (l1[i] < l2[j])
        {
            nl[k++] = l1[i++];
        }
        else
        {
            nl[k++] = l2[j++];
        }
    }
    while (i < size1)
    {
        nl[k++] = l1[i++];
    }
    while (j < size2)
    {
        nl[k++] = l2[j++];
    }
    return nl;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int *nl = merge(arr1, arr2, 5, 5);
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", nl[i]);
    }
}