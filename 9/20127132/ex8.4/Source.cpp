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
int difference(avl* t)
{
    int l = height(t->left);
    int r = height(t->right);
    int dif = l - r;
    return dif;
}
avl* rotateRR(avl* par)
{
    avl* t;
    t = par->right;
    par->right = t->left;
    t->left = par;
    return t;
}
avl* rotateLL(avl* par)
{
    avl* t;
    t = par->left;
    par->left = t->right;
    t->right = par;
    return t;
}
avl* rotateLR(avl* par)
{
    avl* t;
    t = par->left;
    par->left = rotateRR(t);
    return rotateLL(par);
}
avl* rotateRL(avl* par)
{
    avl* t;
    t = par->right;
    par->right = rotateLL(t);
    return rotateRR(par);
}
avl* balance(avl* t)
{
    int bal_factor = difference(t);
    if (bal_factor > 1)
    {
        if (difference(t->left) > 0)
            t = rotateLL(t);
        else
            t = rotateLR(t);
    }
    else if (bal_factor < -1)
    {
        if (difference(t->right) > 0)
            t = rotateRL(t);
        else
            t = rotateRR(t);
    }
    return t;
}
avl* insert(avl* r, int v)
{
    if (r == NULL)
    {
        r = new avl;
        r->key = v;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    else if (v < r->key)
    {
        r->left = insert(r->left, v);
        r = balance(r);
    }
    else if (v >= r->key)
    {
        r->right = insert(r->right, v);
        r = balance(r);
    }
    return r;
}

bool check(avl* t, vector<int>& a, int j)
{
    if (t == NULL)
        return 0;
    a.push_back(t->key);
    if (t->key == j)
        return 1;
    if (check(t->left, a, j) == 1 || check(t->right, a, j) == 1)
        return 1;
    a.pop_back();
    return 0;
}
int check(avl* t, int n, int m)
{
    if (t == NULL)
        return -1;
    vector<int>a, b;
    if (check(t, a, n) == 0 || check(t, b, m) == 0)
        return -1;
    int i;
    for (i = 0; i < a.size() && i < b.size(); i++)
        if (a[i] != b[i])
            break;
    return a[i - 1];
}