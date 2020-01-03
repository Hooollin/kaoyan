#include "p1.c"

LinkedList *fun(LinkedList h1, LinkedList h2)
{
    int m = 0, n = 0;
    LinkedList t1 = h1->next, t2 = h2->next;
    while (t1 != NULL)
    {
        m += 1;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        n += 1;
        t2 = t2->next;
    }
    t1 = h1->next;
    t2 = h2->next;
    if (m > n)
    {
        int s = m - n;
        for (int i = 0; i < s; i++)
            t1 = t1->next;
    }
    if (m < n)
    {
        int s = n - m;
        for (int i = 0; i < s; i++)
        {
            t2 = t2->next;
        }
    }
    while (t1 != NULL && t2 != NULL)
    {
        if (t1 == t2)
            return t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    return NULL;
}
void main()
{
    int arr[] = {10, 68, 67, 66, 65, 7, 8};
    LinkedList h;
    createLinkedListWithoutHeadNode(arr, 5, &h);
    traversal(h);
    traversal(fun(h));
}