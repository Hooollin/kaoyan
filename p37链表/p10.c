#include "p1.c"

LinkedList fun(LinkedList head)
{
    LinkedList h1 = (LinkedList)malloc(sizeof(LinkedList)),
               h2 = (LinkedList)malloc(sizeof(LinkedList));
    h1->next = NULL;
    h2->next = NULL;
    LinkedList curr = head->next;
    LinkedList curr2 = h2;
    int count = 0;
    while (curr != NULL)
    {
        LinkedList p = curr->next;
        if (count % 2 == 1)
        {
            curr2->next = curr;
            curr2 = curr2->next;
            curr2->next = NULL;
        }
        else
        {
            curr->next = h1->next;
            h1->next = curr;
        }
        curr = p;
        count += 1;
    }
    traversal(h1);
    traversal(h2);
}
void main()
{
    int id = 1;
    printf("%d,", 1 - !id);
}