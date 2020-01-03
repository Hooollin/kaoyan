void inThread(ThreadTree p, ThreadTree pre)
{
    if (p != NULL)
    {
        inThread(p->left, pre);
        if (p->left == NULL)
        {
            p->left = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->right == NULL)
        {
            pre->right = p;
            pre->rtag = 1;
        }
        p = pre;
        inThread(p->right, pre);
    }
}

void firstNode(ThreadThree p)
{
    while (p->ltag == 0)
    {
        p = p->left;
    }
    return p;
}