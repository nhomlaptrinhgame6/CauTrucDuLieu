#include "Header.h"
int main()
{
	list x[100];
	node head = NULL;
	node avg = NULL;
	int size = 0;
	int choose;
	string s;

	for (;;)
	{
		cout << "1. Read list of students";
		cout << "\n2. Print list of students";
		cout << "\n3. Search student";
		cout << "\n4. Average score of each student";
		cout << "\n5. Delete student";
		cout << "\n6. Insert a new student at the end of list";
		cout << "\n7. Insert a new student before the head of list";
		cout << "\n8. Insert a new student after specific name";
		cout << "\n9. Search top k students based on average score";
		cout << "\n10. Exit";
		cout << "\nInput your choose(must choose '1' first): ";
		cin >> choose;
		if (choose == 1)
		{
			writefile(x, size);
			readFile(x, head, size);
		}
		else if (choose == 2)
			printList(head);
		else if (choose == 3)
		{
			int choose1;
			cout << "1. Name\n";
			cout << "2. Math score\n";
			cout << "3. Physics score\n";
			cout << "4. Chemistry score\n";
			cout << "Input your choose: ";
			cin >> choose1;
			if (choose1 == 1)
				searchName(head);
			else if (choose1 == 2)
				searchMath(head);
			else if (choose1 == 3)
				searchPhysics(head);
			else if (choose1 == 4)
				searchChemistry(head);
		}
		else if (choose == 4)
			average(head);
		else if (choose == 5)
		{
			int choose2;
			cout << "1. Delete by name\n";
			cout << "2. Delete duplicate\n";
			cout << "Input your choose: ";
			cin >> choose2;
			if (choose2 == 1)
			{
				cout << "Input name want to delete: ";
				cin.ignore();
				getline(cin, s);
				head = deleteByName(head, s);
			}
			else
				head = delSame(head);
		}
		else if (choose == 6)
		{
			list tmp;
			cout << "Input Name: ";
			cin.ignore();
			getline(cin, tmp.name);
			cout << "Input math score: ";
			cin >> tmp.math;
			while (tmp.math<0)
			{
				cout << "Input again math score: ";
				cin >> tmp.math;
			}
			cout << "Input physics score: ";
			cin >> tmp.physics;
			while (tmp.physics < 0)
			{
				cout << "Input again physics score: ";
				cin >> tmp.physics;
			}
			cout << "Input chemistry score: ";
			cin >> tmp.chemistry;
			while (tmp.chemistry < 0)
			{
				cout << "Input again chemistry score: ";
				cin >> tmp.chemistry;
			}
			head = addLast(head, tmp);
		}
		else if (choose == 7)
		{
			list tmp;
			cout << "Input Name: ";
			cin.ignore();
			getline(cin, tmp.name);
			cout << "Input math score: ";
			cin >> tmp.math;
			while (tmp.math < 0)
			{
				cout << "Input again math score: ";
				cin >> tmp.math;
			}
			cout << "Input physics score: ";
			cin >> tmp.physics;
			while (tmp.physics < 0)
			{
				cout << "Input again physics score: ";
				cin >> tmp.physics;
			}
			cout << "Input chemistry score: ";
			cin >> tmp.chemistry;
			while (tmp.chemistry < 0)
			{
				cout << "Input again chemistry score: ";
				cin >> tmp.chemistry;
			}
			head = addHead(head, tmp);
		}
		else if (choose == 8)
		{
			list tmp;
			string s;
			cout << "Input Name want to insert after: ";
			cin.ignore();
			getline(cin, s);
			cout << "New student: \n";
			cout << "Input Name: ";
			getline(cin, tmp.name);
			cout << "Input math score: ";
			cin >> tmp.math;
			while (tmp.math < 0)
			{
				cout << "Input again math score: ";
				cin >> tmp.math;
			}
			cout << "Input physics score: ";
			cin >> tmp.physics;
			while (tmp.physics < 0)
			{
				cout << "Input again physics score: ";
				cin >> tmp.physics;
			}
			cout << "Input chemistry score: ";
			cin >> tmp.chemistry;
			while (tmp.chemistry < 0)
			{
				cout << "Input again chemistry score: ";
				cin >> tmp.chemistry;
			}
			head = add_pos(head, tmp, Search(head, s) + 1);
		}
		else if (choose == 9)
		{
			int n;
			cout << "Input k: ";
			cin >> n;
			readFile(x, avg, size);
			MergeSort_recursive(avg);
			int i = 1;
			for (node p = avg; p != NULL; p = p->next)
			{
				cout << i++ << ". " << p->data.name << " : " << average_each(p) << endl;
				if (i > n)
					break;
			}
		}
		else if (choose == 10)
			return 0;
		
		cout << "\n--------\n";
	}
	return 0;
}