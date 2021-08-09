#include "Header.h"
int main()
{
	int choose;
	avl* tree = NULL;
	cout << "1. Create tree\n";
	cout << "2. Input value\n";
	cout << "3. Check if all leaves are at same level\n";
	cout << "4. Exit\n";
	while (1)
	{
		cout << "Input your choose: ";
		cin >> choose;
		if (choose == 1)
			tree = NULL;
		else if (choose == 2)
		{
			int x;
			cout << "Input value: ";
			cin >> x;
			tree = insert(tree, x);
		}
		else if (choose == 3)
		{
			if (check(tree))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else if (choose == 4)
			return 0;
	}
}
