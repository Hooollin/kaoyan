#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    struct n *left;
    struct n *right;
    int data;
} Node, *BinaryTree;

void preoder(BinaryTree root);
void levelTravesal(BinaryTree root);
void inorder(BinaryTree root);
BinaryTree swapChild(BinaryTree root);

/*
    创建二叉树
*/
BinaryTree creatBinaryTree(int arr[], int index, int n)
{
    Node *pNode = NULL;

    if (index < n && arr[index] != -1) //数组中-1 表示该节点为空
    {
        pNode = (Node *)malloc(sizeof(Node));
        if (pNode == NULL)
            return NULL;
        pNode->data = arr[index];
        pNode->left = creatBinaryTree(arr, 2 * index + 1, n); //将二叉树按照层序遍历, 依次标序号, 从0开始
        pNode->right = creatBinaryTree(arr, 2 * index + 2, n);
    }
    return pNode;
}

/*
    先序遍历
*/
void _preorder(BinaryTree root)
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        _preorder(root->left);
        _preorder(root->right);
    }
}

void preorder(BinaryTree root)
{
    _preorder(root);
    printf("\n");
}

void preorderNonRecursive(BinaryTree root)
{
    Node *stack[100];
    int top = -1;
    Node *curr = root;
    while (curr != NULL || top != -1)
    {
        if (curr != NULL)
        {
            printf("%d, ", curr->data);
            stack[++top] = curr;
            curr = curr->left;
        }
        else
        {
            curr = stack[top--];
            curr = curr->right;
        }
    }
    printf("\n");
}

/*
    层次遍历
*/

void levelTravesal(BinaryTree root)
{
    Node *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;
    Node *top = NULL;
    while (front < rear)
    {
        top = q[front++];
        printf("%d, ", top->data);
        if (top->left != NULL)
            q[rear++] = top->left;
        if (top->right != NULL)
            q[rear++] = top->right;
    }
    printf("\n");
}

/*
    中序遍历
*/

void _inorder(BinaryTree root)
{
    if (root != NULL)
    {
        _inorder(root->left);
        printf("%d, ", root->data);
        _inorder(root->right);
    }
}

void inorder(BinaryTree root)
{
    _inorder(root);
    printf("\n");
}

void inorderNonRecursive(BinaryTree root)
{
    Node *stack[100];
    int top = -1;
    Node *curr = root;
    while (top != -1 || curr != NULL)
    {
        if (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        else
        {
            curr = stack[top--];
            printf("%d, ", curr->data);
            curr = curr->right;
        }
    }
    printf("\n");
}

/* 有关算法题 */

BinaryTree swapChild(BinaryTree root)
{
    Node *stack[100];
    int top = -1;
    Node *curr = root;
    while (top != -1 || curr != NULL)
    {
        if (curr != NULL)
        {
            Node *temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            stack[++top] = curr;
            curr = curr->right;
        }
        else
        {
            curr = stack[top--];
            curr = curr->left;
        }
    }
    return root;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    BinaryTree root = creatBinaryTree(arr, 0, sizeof(arr) / sizeof(arr[0]));
    inorder(root);
    inorderNonRecursive(root);
}