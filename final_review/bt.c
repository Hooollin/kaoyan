#include <stdio.h>
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} BinaryTree, Node;

void postOrderNonRecursive(BinaryTree *root)
{
    BinaryTree *stack[100];
    int top = -1;
    Node *r;
    Node *curr = root;
    while (curr != NULL || top != -1)
    {
        if (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        else if (top != -1)
        {
            Node *t = stack[top--];
            if (t->right && t->right != r)
            {
                curr = t->right;
            }
            else
            {
                visit(t);
                r = t;
                t = NULL;
            }
        }
    }
}
Node *head = NULL;
Node *fun(BinaryTree *root, Node *pre)
{
    if (root != NULL)
    {
        fun(root->left, pre);
        if (root->left == root->right)
        {
            if (pre == NULL)
            {
                head = root;
                pre = root;
            }
            else
            {
                pre->right = root;
                pre = root;
            }
        }
        fun(root->right, pre);
    }
    return head;
}

int isSimilar(BinaryTree *A, BinaryTree *B)
{
    if (A == NULL && B == NULL)
        return 1;
    if (A == NULL || B == NULL)
        return 0;
    return isSimilar(A->left, B->left) && isSimilar(A->right, B->right);
}

int WPL(BinaryTree *root, int level)
{
    if (root == NULL)
        return 0;
    int left = WPL(root->left, level + 1);
    int right = WPL(root->right, level + 1);
    return left + right + level * root->weight;
}
