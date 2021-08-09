#include <iostream>
#include <string>
#include <math.h>
using namespace std;
typedef int Key;
const Key nullKey = -1;
class BST
{
private:
    struct Node
    {
        Key key;
        Node *left, *right;
        int N, h;
        Node(Key key)
        {
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
            this->N = 1;
        }
    };
    typedef Node *link;
    link root;

public:
    BST()
    {
        root = nullptr;
    }
    int size()
    {
        return size(root);
    }
    int size(link x)
    {
        if (x == nullptr)
            return 0;
        else
            return x->N;
    }
    int height()
    {
        return height(root);
    }
    int height(link x)
    {
        if (x == nullptr)
            return 0;
        else
            return x->h;
    }
    void printNode(Key x, int h)
    {
        for (int i = 0; i < h; i++)
            cout << " ";
        cout << x << endl;
    }
    void printTree(link t, int h)
    {
        if (t == nullptr)
        {
            for (int i = 0; i < h; i++)
                cout << " ";
            cout << "*" << endl;
            return;
        }
        printTree(t->right, h + 1);
        printNode(t->key, h);
        printTree(t->left, h + 1);
    }
    void printTree()
    {
        printTree(root, 0);
    }
    void insert(link &t, Key key)
    {
        if (t == nullptr)
        {
            t = new Node(key);
            return;
        }
        if (key == t->key)
            return;
        if (key < t->key)
            insert(t->left, key);
        if (key > t->key)
            insert(t->right, key);
        t->N = size(t->left) + size(t->right) + 1;
    }
    void insert(Key key)
    {
        insert(root, key);
    }
};
int main()
{
    BST tree;
    tree.insert(4);
    tree.insert(3);
    tree.insert(5);
    tree.insert(1);
    tree.insert(2);
    tree.insert(7);
    tree.insert(9);
    tree.insert(8);
    tree.insert(15);
    tree.insert(11);
    tree.insert(12);
    tree.insert(16);
    tree.printTree();
}
