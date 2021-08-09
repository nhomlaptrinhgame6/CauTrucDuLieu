#include "Header.h"
int main()
{
	string name[100];
	unsigned long phoneNumber[100];
	int size = 100;

	fstream fi;
	fi.open("input.txt");

	string tmp1;
	unsigned long tmp2;

	while (!fi.eof())
	{
		getline(fi, tmp1,',');
		fi >> tmp2;

		insert(tmp1, tmp2,name, phoneNumber,size);

		getline(fi, tmp1, '\n');
	}
	fi.close();

	int choose;
	while (1)
	{
		cout << "1. Add\n";
		cout << "2. Delete\n";
		cout << "3. Update\n";
		cout << "4. Find\n";
		cout << "5. Display\n";
		cout << "6. Exit\n";
		cout << "\nInput your choose: ";
		cin >> choose;
		if (choose == 1)
		{
			cout << "Input name want to add: ";
			cin.ignore();
			getline(cin, tmp1);
			cout << "Input phone number want to add: ";
			cin >> tmp2;
			insert(tmp1, tmp2, name, phoneNumber, size);
		}
		else if (choose == 2)
		{
			cout << "Input name want to remove: ";
			cin.ignore();
			getline(cin, tmp1);
			int pos = search(tmp1, name, phoneNumber, size);
			if (pos != -1)
			{
				name[pos] = "\0";
				phoneNumber[pos] = 0;
			}
			else
				cout << tmp1 << " is not found\n";
		}
		else if (choose == 3)
		{
			cout << "Input name want to update phone number: ";
			cin.ignore();
			getline(cin, tmp1);
			cout << "Input phone number want to update: ";
			cin >> tmp2;
			int pos = search(tmp1, name, phoneNumber, size);
			if (pos != -1)
			{
				phoneNumber[pos] = tmp2;
				cout << name[pos] << " : " << phoneNumber[pos] << endl;
			}
			else
				cout << tmp1 << " is not found\n";
		}
		else if (choose == 4)
		{
			cout << "Input name want to find: ";
			cin.ignore();
			getline(cin, tmp1);
			int pos = search(tmp1, name, phoneNumber, size);
			if (pos != -1)
				cout << name[pos] << " : " << phoneNumber[pos] << endl;
			else
				cout << tmp1 << " is not found\n";
		}
		else if (choose == 5)
			display(name, phoneNumber, size);
		else if (choose == 6)
			return 0;
	}
}