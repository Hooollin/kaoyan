#include "p1.c"

LinkedList reverse(LinkedList head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedList p = head->next;
    LinkedList newHead = reverse(p);
    p->next = head;
    head->next = NULL;
    return newHead;
}

void main()
{
    int arr[] = {10, 6, 8, 5, 65, 7, 8};
    LinkedList h;
    createLinkedListWithoutHeadNode(arr, 5, &h);
    traversal(h);
    traversal(reverse(h));
}