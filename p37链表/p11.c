#include "p1.c"

LinkedList fun(LinkedList head)
{
    LinkedList dummy = (LinkedList)malloc(sizeof(LinkedList));
    dummy->next = head;
    LinkedList curr = head, prev = dummy;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == curr->data)
        {
            prev->next = curr->next;
        }
        prev = prev->next;
        curr = prev->next;
    }
    return dummy->next;
}

void main()
{
    int arr[] = {10, 11, 11, 12, 12, 13, 14, 7, 8};
    LinkedList h;
    createLinkedListWithoutHeadNode(arr, 7, &h);
    traversal(fun(h));
}