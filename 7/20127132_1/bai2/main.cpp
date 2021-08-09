#include "Header.h"
int main()
{
	int choose;
	node head = init();

	while (1)
	{
		cout << "1.Enqueue\n2.Display\n3.Dequeue\n4.Exit\nInput your choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			int x;
			cout << "Input value: ";
			cin >> x;
			head = addLast(head, x);
		}; break;
		case 2:
		{
			cout << "Queue: ";
			output(head);
			cout << endl;
		}; break;
		case 3:
			head = delLast(head); break;
		default:
			return 0;
		}
	}
}