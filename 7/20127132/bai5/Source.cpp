#include "Header.h"
int length(node head)
{
	int count = 0;
	for (node p = head; p != NULL; p = p->next)
		count++;
	return count;
}
void printNode(node head, int k)
{
	if (k == 1)
	{
		cout << endl << "List:\n\n";
		cout << "    NAME                                      MATH SCORE    PHYSICS SCORE    CHEMISTRY SCORE\n";
	}
	if (k < 10)
		cout << 0;
	cout << k << ". " << head->data.name;
	for (int i = 0; i < 46 - head->data.name.size(); i++)
		cout << " ";
	cout << head->data.math << "               " << head->data.physics << "                " << head->data.chemistry << endl;
}
void printList(node head)
{
	if (head == NULL)
	{
		cout << "Empty\n";
		return;
	}
	int i = 1;
	for (node p = head; p != NULL; p = p->next, i++)
		printNode(p, i);
}
node createnode(list data)
{
	node tmp = new linkedList;
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}
node addHead(node head, list x)
{
	node tmp = createnode(x);
	if (head == NULL)
		head = tmp;
	else
	{
		tmp->next = head;
		head = tmp;
	}
	return head;
}
node addLast(node head, list x)
{
	node tmp = createnode(x);
	node p;
	if (head == NULL)
		head = addHead(head, x);
	else
	{
		p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = tmp;
	}
	return head;
}
node add_pos(node head, list x, int pos)
{
	node p = head;
	int k = 1;
	if (pos == 0 || head == NULL)
		head = addHead(head, x);
	else
	{
		while (k != pos && p != NULL)
		{
			p = p->next;
			k++;
		}
		if (pos != k)
			head = addLast(head, x);
		else
		{
			node tmp = createnode(x);
			if (p != NULL)
			{
				tmp->next = p->next;
				p->next = tmp;
			}
		}
	}
	return head;
}
node delHead(node head)
{
	if (head == NULL)
		cout << "Khong co gi de xoa !";
	else
		head = head->next;
	return head;
}
node delLast(node head)
{
	if (head == NULL)
		head = delHead(head);
	else
	{
		node p = head;
		while (p->next->next != NULL)
			p = p->next;
		p->next = p->next->next;
	}
	return head;
}
node del_pos(node head, int pos)
{
	if (head == NULL || pos == 0 || head->next == NULL)
		head = delHead(head);
	else
	{
		int k = 1;
		node p = head;
		while (k != pos && p->next->next != NULL)
		{
			k++;
			p = p->next;
		}
		if (k != pos)
			head = delLast(head);
		else
			p->next = p->next->next;
	}
	return head;
}
void searchName(node head)
{
	string x;
	if (head == NULL)
		return;
	cout << "Input name: ";
	cin.ignore();
	getline(cin, x);
	if (x == "\0")
		return;
	int j = 1;
	bool a = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data.name == x)
		{
			a = 1;
			printNode(p, j++);
		}
	}
	if (a == 0)
	{
		cout << "Do not found!\n";
		return;
	}
}
void searchMath(node head)
{
	int x;
	if (head == NULL)
		return;
	cout << "Input math score: ";
	cin >> x;
	if (x <0)
		return;
	int j = 1;
	bool a = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data.math == x)
		{
			a = 1;
			printNode(p, j++);
		}
	}
	if (a == 0)
	{
		cout << "Do not found!\n";
		return;
	}
}
void searchPhysics(node head)
{
	int x;
	if (head == NULL)
		return;
	cout << "Input physics score: ";
	cin >> x;
	if (x < 0)
		return;
	int j = 1;
	bool a = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data.physics == x)
		{
			a = 1;
			printNode(p, j++);
		}
	}
	if (a == 0)
	{
		cout << "Do not found!\n";
		return;
	}
}
void searchChemistry(node head)
{
	int x;
	if (head == NULL)
		return;
	cout << "Input chemistry score: ";
	cin >> x;
	if (x < 0)
		return;
	int j = 1;
	bool a = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data.chemistry == x)
		{
			a = 1;
			printNode(p, j++);
		}
	}
	if (a == 0)
	{
		cout << "Do not found!\n";
		return;
	}
}
int Search(node head, string x)
{
	int pos = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data.name == x)
			return pos;
		pos++;
	}
	return -1;
}
void writefile(list x[], int &size)
{
	string tmp;
	int i = 0;
	fstream fo;
	fo.open("input.txt");
	while(!fo.eof())
	{
		getline(fo, x[i].name, ',');
		fo >> x[i].math;
		fo >> x[i].physics;
		fo >> x[i].chemistry;
		i++;
		getline(fo, tmp, '\n');
	}
	fo.close();


	size = i;
	fstream fi;
	fi.open("inputFile.bin", ios::out | ios::binary);
	for (int j = 0; j < i; j++)
	{
		fi.write((const char*)&x[j].name, 50);
		fi.write((const char*)&x[j].math, 1);
		fi.write((const char*)&x[j].physics, 1);
		fi.write((const char*)&x[j].chemistry, 1);
	}
	fi.close();
}
void readFile(list x[], node& head, int size)
{
	fstream fi;
	fi.open("inputFile.bin", ios::in | ios::binary);
	for (int j = 0; j < size; j++)
	{
		fi.read((char*)&x[j].name, 50);
		fi.read((char*)&x[j].math, 1);
		fi.read((char*)&x[j].physics, 1);
		fi.read((char*)&x[j].chemistry, 1);
		head = addLast(head, x[j]);
	}
	fi.close();
}
int average_each(node head)
{
	int avg = head->data.math + head->data.physics + head->data.chemistry;
	avg /= 3;
	return avg;
}
void average(node head)
{
	int avg, i = 1;
	cout << "Average score of each student : \n";
	for (node p = head; p != NULL; p = p->next)
		cout << i++ << ". " << p->data.name << ": "<< average_each(p) << endl;
}
node deleteByName(node head, string x)
{
	int i = 0;
	bool a = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data.name == x)
		{
			a = 1;
			if (i == 0)
				head = delHead(head);
			else
				head = del_pos(head, i);
		}
		else
			i++;
	}
	if (a == 0)
		cout << "Do no found!\n";
	return head;
}
node delSame(node head)
{
	int i = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		for (node q = p->next; q != NULL; q = q->next)
			if (p->data.name == q->data.name)
				p = del_pos(head, i);
			else
				i++;	
	}
	return head;
}

//Merge Sort recursive
node merge(node l1, node l2)
{
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	node p = NULL;
	if (average_each(l1) > average_each(l2))
	{
		p = l1;
		p->next = merge(l1->next, l2);
	}
	else
	{
		p = l2;
		p->next = merge(l1, l2->next);
	}
	return p;
}
node getMid(node head)
{
	if (head == NULL)
		return head;
	node l1, l2;
	l1 = head;
	l2 = head;
	while (l1->next && l1->next->next)
	{
		l2 = l2->next;
		l1 = l1->next->next;
	}
	return l2;
}
void splitMerge(node head, node& l1, node& l2)
{
	node mid = getMid(head);
	l1 = head;
	l2 = mid->next;
	mid->next = NULL;
}
void MergeSort_recursive(node& head)
{
	node l1 = NULL, l2 = NULL;
	if (head == NULL || head->next == NULL)
		return;
	//chia danh sách
	splitMerge(head, l1, l2);

	MergeSort_recursive(l1);
	MergeSort_recursive(l2);
	head = merge(l1, l2);
}