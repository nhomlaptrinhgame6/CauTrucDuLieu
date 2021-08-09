#include "Header.h"
int main()
{
	Node* head = NULL;
	int n, x, choose;
	cout << "1. Add Node (in the head of list)\n";
	cout << "2. Add Node (in the last of list)\n";
	cout << "3. Delete Node (in the head of list)\n";
	cout << "4. Delete Node (in the last of list)\n";
	cout << "5. Inser sort\n";
	cout << "6. Print list\n";
	cout << "7. Print reverse list\n";
	cout << "8. Exit\n";
	while (1)
	{
		cout << "\n-----------\nInput your choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			cout << "Input value: ";
			cin >> x;
			addHead(&head, x);
		}; break;
		case 2:
		{
			cout << "Input value: ";
			cin >> x;
			addLast(&head, x);
		}; break;
		case 3: delHead(head); break;
		case 4:	delLast(head); break;
		case 5:
		{
			cout << "Befor sort: ";
			printList(head);
			insertionSort(head);
			cout << "After sort: ";
			printList(head);
		}; break;
		case 6:
		{
			cout << "List: ";
			printList(head);
		}; break;
		case 7:
		{
			cout << "List reverse: ";
			printList_reverse(head);
		}; break;
		case 8: return 0;
		default:
			break;
		}
	}
}