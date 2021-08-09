#include "Header.h"
int main()
{
	int choose;
	node head = init();
	
	while (1)
	{
		cout << "1.Push\n2.Display\n3. Pop\n4.Exit\nInput your choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			int x;
			cout << "Input value: ";
			cin >> x;
			head = addHead(head, x);
		}; break;
		case 2:
		{
			cout << "Stack: ";
			output(head);
			cout << endl;
		}; break;
		case 3:
			head = delHead(head); break;
		default:
			return 0;
		}
	}
}