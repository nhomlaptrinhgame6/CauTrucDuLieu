#include "Header.h"
int main()
{
	BST tree;
	int n, l = 0;
	string tmp;
	inf x;
	inf list[100];
	fstream fi;
	fi.open("input.txt");
	fi >> n;
	while (!fi.eof())
	{
		fi >> x.MSSV;
		getline(fi, tmp, ',');
		getline(fi, x.name, ',');
		fi >> x.birth.day;
		getline(fi, tmp, '/');
		fi >> x.birth.month;
		getline(fi, tmp, '/');
		fi >> x.birth.year;
		getline(fi, tmp, ',');
		fi >> x.status;
		getline(fi, tmp, '\n');
		tree.insert(x);
		list[l++] = x;
	}
	
	while (1)
	{
		cout << "1. Add student\n";
		cout << "2. Display student list\n";
		cout << "3. Find a student with unique code\n";
		cout << "4. List all students in lexicographic order of their names\n";
		cout << "5. List all graduated students\n";
		cout << "6. Delete a student given by its code\n";
		cout << "7. Save all graduates  in file\n";
		cout << "8. Exit\n";
		cout << "Input your choose: ";
		int choose;
		cin >> choose;
		if (choose == 1)
		{
			cout << "Input unique code: ";
			cin >> x.MSSV;
			cout << "Input name: ";
			cin >> x.name;
			cout << "Input birthdate (separated by a space): ";
			cin >> x.birth.day >> x.birth.month >> x.birth.year;
			cout << "Input status (0: undergrad, 1: graduated): ";
			cin >> x.status;
			tree.insert(x);
		}
		else if (choose == 2)
			tree.printTree();
		else if (choose == 3)
		{
			int data;
			bool check = 0;
			cout << "Input unique code want to find: ";
			cin >> data;
			tree.FloorUniqueCode(data);
		}
		else if (choose == 4)
		{
			int k = 0;
			while (k <= 10)
			{
				for (int i = 0; i < l; i++)
				{
					if (k > list[i].name.size())
						continue;
					for (int j = i + 1; j < l; j++)
					{
						if (k > list[j].name.size())
							continue;
						if (k != 0 && list[i].name[k] > list[j].name[k] && list[i].name[0] == list[j].name[0])
							swap(list[i], list[j]);
						else if (list[i].name[0] > list[j].name[0])
							swap(list[i], list[j]);
					}
				}
				k++;
			}
			for (int i = 0; i < l; i++)
			{
				cout << "Unique Code: " << list[i].MSSV << endl;
				cout << "Name: " << list[i].name << endl;
				cout << "Birth: ";
				cout << list[i].birth.day << "/" << list[i].birth.month << "/" << list[i].birth.year << endl;
				cout << "Status: ";
				if (list[i].status == 0)
					cout << "Undergrad";
				else
					cout << "Graduate";
				cout << "\n\n";
			}
		}
		else if (choose == 5)
			tree.FloorGraduated();
		else if (choose == 6)
		{
			int data;
			bool check = 0;
			cout << "Input unique code want to delete: ";
			cin >> data;
			tree.delNode(data, check);
			if (check == 1)
				tree.printTree();
			else
				cout << "Do not found!\n";
		}
		else if (choose == 7)
		{
			inf saveNode[100];
			int n;
			tree.LoadFloorGraduated(saveNode, n);
			fstream fi;
			fi.open("student.txt");
			fi << n << endl;
			for (int i = 0; i < n; i++)
			{
				fi << saveNode[i].MSSV << ",";
				fi << saveNode[i].name << ",";
				fi << saveNode[i].birth.day << "/";
				fi << saveNode[i].birth.month << "/";
				fi << saveNode[i].birth.year << ",";
				fi << saveNode[i].status << "\n";
			}
			fi.close();
		}
		else if (choose == 8)
			return 0;
		cout << "\n-----------------------\n\n";
	}
}