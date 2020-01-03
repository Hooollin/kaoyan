#include "p1.c"

void reversePrint(LinkedList head)
{
    if (head == NULL)
        return;
    reversePrint(head->next);
    printf("%d, ", head->data);
}

void deleteMin(LinkedList head)
{
    LinkedList minPre = head, curr = head;
    int min = 1000;
    while (curr->next != NULL)
    {
        if (min > curr->next->data)

            min = curr->next->data;
        minPre = curr;
    }
    curr = curr->next;
}
minPre->next = minPre->next->next;
}
void main()
{
    int arr[] = {10, 6, 8, 5, 65, 7, 8};
    LinkedList h;
    createLinkedListWithoutHeadNode(arr, 5, &h);
    traversal_h(h);
    deleteMin(h);
    traversal_h(h);
}