#include "Header.h"
int main()
{
	int choose;
	
	int a[] = { 15, 11, 27, 8, 12 };
	int b[] = { 1, 2, 3, 4, 5 };
	int nn = 5;
	while (1)
	{
		cout << "1. Chaining Method\n2.Linear Probing\n3.Quadratic Probing\n4.Double hashing\n5.Exit\n";
		cout << "Input your choose : ";
		cin >> choose;
		if (choose == 1)
		{
			Chaining lst(7);
			for (int i = 0; i < nn; i++)
				lst.insert(a[i]);
			lst.display();
			cout << "Search 11: " << lst.search(11) << endl;
		}
		else if (choose == 2)
		{
			LinearTable lst;
			for (int i = 0; i < nn; i++)
				lst.insert(b[i], a[i]);
			lst.display();
			//cout << "Search 11: " << lst.search(11) << endl;
		}
		else if (choose == 3)
		{
			QuadraticProbing* lst = initiateTableQuadratic(n);

			for (int i = 0; i < nn; i++)
				InsertQuadratic(a[i], lst);
			displayQuadratic(lst);
			cout << "Search 11: " << SearchKeyQuadratic(11, lst) << endl;
		}
		else if (choose == 4)
		{
			DoubleHashing* lst = initiateTableDouble(n);

			for (int i = 0; i < nn; i++)
				InsertDouble(a[i], lst);
			displayDouble(lst);
			cout << "Search 11: " << SearchKeyDouble(11, lst) << endl;
		}
		else if (choose == 5)
			return 0;
	}
}