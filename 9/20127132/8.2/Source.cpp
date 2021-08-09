#include "Header.h"
int height(avl* t)
{
    int h = 0;
    if (t != NULL)
    {
        int l = height(t->left);
        int r = height(t->right);
        int _max = max(l, r);
        h = _max + 1;
    }
    return h;
}
avl* insert(avl* t, int x)
{
    if (t == NULL)
    {
        avl* temp = new avl;
        temp->key = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else
    {
        if (x < t->key)
            t->left = insert(t->left, x);
        else
            t->right = insert(t->right, x);
        return t;
    }
}
bool check_avl(avl* t)
{
    if (t == NULL)
        return 1;
    if (abs(height(t->left) - height(t->right)) > 1)
        return 0;
    return check_avl(t->left) && check_avl(t->right);
}