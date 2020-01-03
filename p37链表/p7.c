#include "p1.c"
LinkedList fun(LinkedList head, int s, int t)
{
    LinkedList prev = head, curr = prev->next;
    while (curr != NULL)
    {
        if (curr->data >= s && curr->data <= t)
        {
            prev->next = curr->next;
        }
        prev = prev->next;
        curr = prev->next;
    }
    return head;
}
void main()
{
    int arr[] = {10, 68, 67, 66, 65, 7, 8};
    LinkedList h;
    createLinkedListWithoutHeadNode(arr, 5, &h);
    traversal(h);
    traversal(fun(h, 67, 67));
}