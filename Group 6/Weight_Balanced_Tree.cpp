#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;
/* Class WBTNode */
class WBTNode
{
public:
    WBTNode *left;
    WBTNode *right;
    int height, element;
    WBTNode(int theElement, int wt, WBTNode *lt, WBTNode *rt)
    {
        element = theElement;
        left = lt;
        right = rt;
        height = wt;
    }
    WBTNode(int theElement, int wt)
    {
        WBTNode(theElement, wt, NULL, NULL);
    }
};
WBTNode *nullNode;
class heightBalancedTree
{
private:
    WBTNode *root;

public:
    heightBalancedTree()
    {
        root = nullNode;
    }
    bool isEmpty()
    {
        return root == nullNode;
    }
    void makeEmpty()
    {
        root = nullNode;
    }
    void insert(int x, int wt)
    {
        root = insert(x, wt, root);
    }
    WBTNode *insert(int x, int wt, WBTNode *t)
    {
        if (t == nullNode)
            t = new WBTNode(x, wt, nullNode, nullNode);
        else if (x < t->element)
        {
            t->left = insert(x, wt, t->left);
            if (t->left->height < t->height)
                t = rotateLeft(t);
        }
        else if (x > t->element)
        {
            t->right = insert(x, wt, t->right);
            if (t->right->height < t->height)
                t = rotateRight(t);
        }
        return t;
    }
    void Delete(int x)
    {
        if (isEmpty())
            cout << "Cay Rong" << endl;
        else if (search(x) == false)
            cout << x << " khong co" << endl;
        else
        {
            root = Delete(x, root);
            cout << x << " da xoa" << endl;
        }
    }
    WBTNode *Delete(int x, WBTNode *t)
    {
        if (t != nullNode)
        {
            if (x < t->element)
                t->left = Delete(x, t->left);
            else if (x > t->element)
                t->right = Delete(x, t->right);
            else
            {
                if (t->left->height == 0)
                    t->left->height = MAX_VALUE;
                if (t->right->height == 0)
                    t->right->height = MAX_VALUE;
                if (t->left->height < t->right->height)
                    t = rotateLeft(t);
                else
                    t = rotateRight(t);
                if (t != nullNode)
                    t = Delete(x, t);
                else
                    t->left = nullNode;
            }
        }
        return t;
    }
    WBTNode *rotateLeft(WBTNode *k2)
    {
        WBTNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        return k1;
    }
    WBTNode *rotateRight(WBTNode *k1)
    {
        WBTNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        return k2;
    }
    int countNodes()
    {
        return countNodes(root);
    }
    int countNodes(WBTNode *r)
    {
        if (r == nullNode)
            return 0;
        else
        {
            int l = 1;
            l += countNodes(r->left);
            l += countNodes(r->right);
            return l;
        }
    }
    bool search(int val)
    {
        return search(root, val);
    }
    bool search(WBTNode *r, int val)
    {
        bool found = false;
        while ((r != nullNode) && !found)
        {
            int rval = r->element;
            if (val < rval)
                r = r->left;
            else if (val > rval)
                r = r->right;
            else
            {
                found = true;
                break;
            }
            found = search(r, val);
        }
        return found;
    }
    void inorder()
    {
        inorder(root);
    }
    void inorder(WBTNode *r)
    {
        if (r != nullNode)
        {
            inorder(r->left);
            cout << r->element << "   ";
            inorder(r->right);
        }
    }
    void preorder()
    {
        preorder(root);
    }
    void preorder(WBTNode *r)
    {
        if (r != nullNode)
        {
            cout << r->element << "   ";
            preorder(r->left);
            preorder(r->right);
        }
    }
    void postorder()
    {
        postorder(root);
    }
    void postorder(WBTNode *r)
    {
        if (r != nullNode)
        {
            postorder(r->left);
            postorder(r->right);
            cout << r->element << "   ";
        }
    }
};
int main()
{
    nullNode = new WBTNode(0, MAX_VALUE);
    nullNode->left = nullNode->right = nullNode;
    heightBalancedTree wbt;
    int choice, val, wt;
    char ch;
    while (1)
    {
        cout << "1. Insert " << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Count nodes" << endl;
        cout << "5. Check empty" << endl;
        cout << "6. Clear" << endl;
        cout << "7. Post order" << endl;
        cout << "8. Pre order" << endl;
        cout << "9. In order" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Nhap gia tri muon them: ";
            cin >> val;
            cout << "Nhap do cao: ";
            cin >> wt;
            wbt.insert(val, wt);
            break;
        case 2:
            cout << "Nhap gia tri muon xoa: ";
            cin >> val;
            wbt.Delete(val);
            break;
        case 3:
            cout << "Nhap gia tri muon tim kiem: ";
            cin >> val;
            if (wbt.search(val) == true)
                cout << "Gia tri " << val << " co trong cay" << endl;
            else
                cout << "Gia tri " << val << " khong co trong cay" << endl;
            break;
        case 4:
            cout << "Nodes = " << wbt.countNodes();
            break;
        case 5:
            if (wbt.isEmpty() == true)
                cout << "Cay rong" << endl;
            else
                cout << "Cay khong rong" << endl;
            break;
        case 6:
            cout << "\nDa tao lai cay";
            wbt.makeEmpty();
            break;
        case 7:
            cout << "\nPost order : ";
            wbt.postorder();
            break;
        case 8:
            cout << "\nPre order : ";
            wbt.preorder();
            break;
        case 9:
            cout << "\nIn order : ";
            wbt.inorder();
            break;
        case 10:
            return 0;
        default:
            cout << "Loi ! \n ";
            break;
        }
        /*  Display tree  */

        cout << "\n-------------------\n";
    }
    return 0;
}
