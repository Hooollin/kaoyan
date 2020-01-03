
#include "p1.c"
void reverse(LinkedList h)
{
    LinkedList prev = NULL, curr = h->next;
    LinkedList t = NULL;
    while (curr != NULL)
    {
        t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    h->next = prev;
}

LinkedList reverseWithOutHead(LinkedList h)
{
    if (h == NULL || h->next == NULL)
    {
        return h;
    }
    LinkedList p = h->next;
    LinkedList newHead = reverseWithOutHead(p);
    p->next = h;
    h->next = NULL;
    return newHead;
}

void main()
{
    int arr[] = {1, 2, 3, 4, 5, 65, 7, 8};
    LinkedList h;
    createLinkedListWithoutHeadNode(arr, 5, &h);
    traversal_h(h);
    h->next = reverseWithOutHead(h->next);
    traversal_h(h);
}