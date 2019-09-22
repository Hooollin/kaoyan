#include <stdio.h>

typedef struct n
{
    int data;
    struct n *next;
} Node, *LinkedList;

LinkedList f(LinkedList l, int x)
{
    if (l == NULL)
    {
        return l;
    }
    if (x == l->data)
    {
        return f(l->next, x);
    }
    l->next = f(l->next, x);
    return l;
}

void createLinkedListWithoutHeadNode(int *arr, int size, LinkedList *l)
{
    *l = (LinkedList)malloc(sizeof(LinkedList));
    (*l)->data = arr[0];
    (*l)->next = NULL;
    LinkedList curr = *l;
    for (int i = 1; i < size; i++)
    {
        Node *t = (LinkedList)malloc(sizeof(LinkedList));
        t->data = arr[i];
        t->next = NULL;
        curr->next = t;
        curr = t;
    }
}

void traversal(LinkedList l)
{
    while (l != NULL)
    {
        printf("%d->", l->data);
        l = l->next;
    }
    printf("\n");
}

void traversal_h(LinkedList l)
{
    Node *n = l->next;
    while (n != NULL)
    {
        printf("%d->", n->data);
        n = n->next;
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 4, 5, 6};
    LinkedList l;
    createLinkedListWithoutHeadNode(arr, sizeof(arr) / sizeof(arr[0]), &l); //注意这里的形参
    traversal(l);
    l = f(l, 3);
    traversal(l);
}
