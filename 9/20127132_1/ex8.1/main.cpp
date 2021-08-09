#include "Header.h"
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