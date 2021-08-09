#include "Header.h"
int main()
{
	int choose;
	avl* tree = NULL;
	cout << "1. Create tree\n";
	cout << "2. Input value\n";
	cout << "3. Find the least common ancestor\n";
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
			int n, m;
			cout << "Input two value want to find: ";
			cin >> n >> m;
			if (check(tree, n, m) == -1)
				cout << "Do not found\n";
			else
				cout << check(tree, n, m) << endl;
		}
		else if (choose == 4)
			return 0;
	}
}
