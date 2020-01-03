#include "p1.c"
LinkedList fun(LinkedList head)
{
    LinkedList prev = head, curr = head->next;
    while (prev->next != NULL)
    {
        LinkedList minPrev = prev;
        int min = 0x7fff;
        while (curr != NULL)
        {
            if (curr->data < min)
            {
                minPrev = prev;
            }
            prev = prev->next;
            curr = prev->next;
        }
        printf("%d ,", minPrev->next->data);
        minPrev->next = minPrev->next->next;
        prev = head;
        curr = head->next;
    }
    return head;
}
void main()
{
    int arr[] = {10, 68, 67, 66, 65, 7, 8};
    LinkedList h;
    createLinkedListWithoutHeadNode(arr, 5, &h);
    traversal(h);
    fun(h);
}