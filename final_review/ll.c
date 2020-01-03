#include <stdio.h>
typedef struct node
{
    struct node *next;
    int data;
} LinkedList, ListNode;

void fun1(LinkedList *l, int x)
{
    if (l == NULL)
        return;
    if (l->data == x)
    {
        ListNode *n = l->next;
        l = NULL;
        fun1(n, x);
    }
}

void fun2(LinkedList *l)
{
    if (l != NULL)
    {
        fun2(l->next);
    }
    printf("%d, ", l->data);
}

void fun3(LinkedList *L)
{
    ListNode *prev = L, *curr = L;
    int minVal = 0xffff;
    while (curr->next != NULL)
    {
        if (curr->data < minVal)
        {
            minVal = curr->data;
            prev = curr;
        }
        curr = curr->next;
    }
}

ListNode *fun4(LinkedList *L)
{
    if (L == NULL || L->next == NULL)
    {
        return L;
    }
    ListNode *p = L->next;
    ListNode *newHead = fun4(p);
    p->next = L;
    L->next = NULL;
    return newHead;
}

void insertionSort(LinkedList *head)
{
    ListNode *curr = head->next;
    head->next = NULL;
    ListNode *prev = head;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = NULL;
        while (prev->next != NULL && prev->next->data < curr->data)
        {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
        prev = head;
    }
}

// it can only be the shape of Y, not X
// go through the two list parallel
ListNode *commonNode(LinkedList *A, LinkedList *B)
{
    int lenA = 0, lenB = 0;
    ListNode *currA = A, *currB = B;
    for (; currA != NULL; currA = currA->next)
        lenA++;
    for (; currB != NULL; currB = currB->next)
        lenB++;
    LinkedList *shorterList = lenA > lenB ? A : B;
    LinkedList *anotherList = lenA > lenB ? B : A;
    int steps = lenA > lenB ? lenA - lenB : lenB - lenA;
    while (steps-- != 0)
        shorterList = shorterList->next;
    ListNode *currS = shorterList, *currL = anotherList;
    while (currS != NULL)
    {
        for (ListNode *t = currS; t != NULL; t = t->next)
            if (t == currL)
                return true;
        currS = currS->next;
    }
    return false;
}

void printByAsc(ListNode *L)
{
    ListNode *prev, *curr;
    ListNode *minP = NULL;
    int minVal = 0x7fff;
    while (L->next != NULL)
    {
        prev = L, curr = L->next;
        minVal = 0;
        while (curr != NULL)
        {
            if (curr->data > minVal)
            {
                minP = prev;
                minVal = curr->data;
            }
            prev = prev->next;
            curr = curr->next;
        }
        ListNode t = minP->next;
        printf("%d, ", minP->data);
        minP = minP->next;
        free(t);
    }
}

void splitIntoTwo(LinkedList *A, LinkedList *B)
{
    int i = 0;
    LinkedList *curr = A->next, *currB = B, *currA = A;
    while (curr != NULL)
    {
        ListNode *p = curr->next;
        if (i % 2 == 0)
        {
            currB->next = curr;
            curr->next = NULL;
            currB = currB->next;
        }
        else
        {
            currA->next = curr;
            curr->next = NULL;
            currA = currA->next;
        }
        curr = p;
        i += 1;
    }
}

void splitIntoTwo_(LinkedList *h, LinkedList *A, LinkedList *B)
{
    LinkedList *curr = h->next, *currA = A, *currB = B;
    currA->next = NULL, currB->next = NULL;
    int i = 0;
    while (curr != NULL)
    {
        ListNode *p = curr->next;
        if (i % 2 == 0)
        {
            currA->next = curr;
            curr->next = NULL;
            currA = currA->next;
        }
        else
        {
            curr->next = currB->next;
            currB->next = curr;
        }
        curr = p;
        i += 1;
    }
}

void deleteDup(LinkedList *L)
{
    ListNode *curr = L->next, *next;
    while (curr->next != NULL)
    {
        next = curr->next;
        if (next->data == curr->data)
        {
            curr->next = next->next;
            free(next);
        }
        else
            curr = curr->next;
    }
}

void mergeList(LinkedList *A, LinkedList *B, LinkedList *L)
{
    L->next = NULL;
    ListNode *currA = A->next, *currB = B->next, *t;
    while (currA != NULL && currB != NULL)
    {
        if (currA > currB)
        {
            t = currA;
            currA = currA->next;
        }
        else
        {
            t = currB;
            currB = currB->next;
        }
        t->next = L->next;
        L->next = t;
    }
    while (currA != NULL)
    {
        t = currA;
        currA = currA->next;
        t->next = L->next;
        L->next = t;
    }
    while (currB != NULL)
    {
        t = currB;
        currB = currB->next;
        t->next = L->next;
        L->next = t;
    }
}

struct ListNode *intersect(struct ListNode *A, struct ListNode *B)
{
