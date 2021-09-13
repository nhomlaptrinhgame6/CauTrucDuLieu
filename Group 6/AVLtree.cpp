#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
using namespace std;
struct avl {
    int key;
    struct avl* left;
    struct avl* right;
}*tree;
class avl_tree
{
public:
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
    avl* minValue(avl* par)
    {
        avl* cur = par;
        while (cur->left != NULL)
            cur = cur->left;
        return cur;
    }
    avl* search(avl* r, int v) 
    {
        if (r == NULL) 
            return r;
        else if (v < r->key)
            return search(r->left,v);
        else if (v > r->key)
            return search(r->right,v);
        return r;
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
    avl* del(avl* r, int key)
    {
        if (r == NULL)
            return r;
        if (key < r->key)
            r->left = del(r->left, key);
        else if (key > r->key)
            r->right = del(r->right, key);
        else
        {
            if ((r->left == NULL) ||
                (r->right == NULL))
            {
                avl* tmp = r->left ?
                    r->left :
                    r->right;
                if (tmp == NULL)
                {
                    tmp = r;
                    r = NULL;
                }
                else
                    *r = *tmp;
                free(tmp);
            }
            else
            {
                avl* tmp = minValue(r->right);
                r->key = tmp->key;
                r->right = del(r->right, tmp->key);
            }
        }
        if (r == NULL)
            return r;
        r = balance(r);
    }
    void inorder(avl* t) 
    {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->key << " ";
        inorder(t->right);
    }
    void preorder(avl* t) 
    {
        if (t == NULL)
            return;
        cout << t->key << " ";
        preorder(t->left);
        preorder(t->right);
    }
    void postorder(avl* t) 
    {
        if (t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        cout << t->key << " ";
    }
    avl_tree() 
    {
        tree = NULL;
    }
};  
int main() {
    int choose, x;
    avl_tree avl;
    while (1)
    {
        cout << "1.Insert\n";
        cout << "2. Delete\n";
        cout << "3. Tree height\n";
        cout << "4. Display InOrder\n";
        cout << "5. Display PreOrder\n";
        cout << "6. Display PostOrder\n";
        cout << "7. Exit\n";
        cout << "Input your choose: ";
        cin >> choose;
        switch (choose) {
        case 1:
        {
            cout << "Input value wanto insert: ";
            cin >> x;
            tree = avl.insert(tree, x);
        }; break;
        case 2:
        {
            cout << "Input value wanto delete: ";
            cin >> x;
            tree = avl.del(tree, x);
        }
        case 3:
        {
            cout << "Tree height: ";
            cout << avl.height(tree) << endl;
        }; break;
        case 4:
        {
            cout << "InOrder: ";
            avl.inorder(tree);
            cout << endl;
        }; break;
        case 5:
        {
            cout << "PreOrder: ";
            avl.preorder(tree);
            cout << endl;
        }; break;
        case 6:
        {
            cout << "PostOrder: ";
            avl.postorder(tree);
            cout << endl;
        }; break;
        case 7:
            return 0;
        default:
            break;
        }
        cout << "---------------\n";
    }
    return 0;
}