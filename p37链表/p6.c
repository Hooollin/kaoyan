#include "p1.c"
LinkedList fun(LinkedList head)
{
    LinkedList prev = head, curr = head->next;
    prev->next = NULL;
    while (curr != NULL)
    {
        prev = head;
        LinkedList p = curr->next;
        curr->next = NULL;
        LinkedList t = prev->next;
        while (t != NULL && t->data < curr->data)
        {
            prev = prev->next;
            t = prev->next;
        }
        curr->next = t;
        prev->next = curr;
        curr = p;
    }
    return head;
}
void main()
{
    int arr[] = {10, 68, 67, 66, 65, 7, 8};
    LinkedList h;
    createLinkedListWithoutHeadNode(arr, 5, &h);
    traversal(h);
    traversal(fun(h));
}