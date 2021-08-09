#include "Header.h"
int main()
{
	link root = NULL;
	int n = 0;
	
	readFile(root, n);
	while (1)
	{
		cout << "1. Display with NLR:\n";
		cout << "2. Display with LNR:\n";
		cout << "3. Display with LRN:\n";
		cout << "4. Exit\n";
		cout << "Input your choose: ";
		int choose;
		cin >> choose;
		if (choose == 1)
			printNLR(root, 0, n);
		else if (choose == 2)
			printLNR(root, 0);
		else if (choose == 3)
			printLRN(root, 0, n);
		else if (choose == 4)
			return 0;
		cout << endl << endl << endl;
	}
}