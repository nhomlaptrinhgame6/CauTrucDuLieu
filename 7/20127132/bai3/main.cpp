#include "Header.h"
int main()
{
	node head = init();
	int choose;
	int size = 0;
	cout << "1.Add value";
	cout << "\n2.Display";
	cout << "\n3. Delete Last";
	cout << "\n4.Quick Sort (recursive)";
	cout << "\n5. Quick Sort (non-recursive)";
	cout << "\n6.Merge Sort (recursive)";
	cout << "\n7. Merge Sort (non-recursive)";
	cout << "\n8.Insertion Sort (recursive)";
	cout << "\n9. Insertion Sort (non-recursive)";
	cout << "\n10.Selection Sort (recursive)";
	cout << "\n11. Selection Sort (non-recursive)";
	cout << "\n12.Interchange Sort (recursive)";
	cout << "\n13. Interchange Sort (non-recursive)";
	cout << "\n14.Exit";
	while (1)
	{
		cout << "\n----------\nInput your choose : ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			int x;
			cout << "Input size: ";
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				cout << "Input value: ";
				cin >> x;
				head = addHead(head, x);
			}
		}; break;
		case 2:
		{
			cout << "Linked List: ";
			printList(head);
			cout << endl;
		}; break;
		case 3:
			delLast(head); break;
		case 4:
		{
			cout << "Before sort: ";
			printList(head);
			QuickSort_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 5:
		{
			cout << "Before sort: ";
			printList(head);
			QuickSort_non_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 6:
		{
			cout << "Before sort: ";
			printList(head);
			MergeSort_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 7:
		{
			cout << "Before sort: ";
			printList(head);
			MergeSort_non_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 8:
		{
			cout << "Before sort: ";
			printList(head);
			insertionSort_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 9:
		{
			cout << "Before sort: ";
			printList(head);
			insertionSort_non_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 10:
		{
			cout << "Before sort: ";
			printList(head);
			selectionSort_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 11:
		{
			cout << "Before sort: ";
			printList(head);
			selectionSort_non_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 12:
		{
			cout << "Before sort: ";
			printList(head);
			interchangeSort_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		case 13:
		{
			cout << "Before sort: ";
			printList(head);
			interchangeSort_non_recursive(head);
			cout << "\nAfter sort: ";
			printList(head);
			cout << endl;
		}; break;
		default:
			return 0;
		}
	}
}