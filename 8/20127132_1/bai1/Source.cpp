#include "Header.h"
Node* createNode(string s)
{
	Node* p = new Node;
	p->key = s;
	p->left = p->right = NULL;
	return p;

}
void FindNode(link root, Node*& find, string data) {
	if (root == NULL)
		return;
	if (root->key == data) {
		find = root;
		return;
	}
	else
	{
		FindNode(root->left, find, data);
		FindNode(root->right, find, data);
	}
}
void readFile(link& t, int& n)
{
	string cha, con1, con2, tmp;
	fstream fi;
	fi.open("input.txt");
	fi >> n;

	while (!fi.eof())
	{
		getline(fi, tmp, '(');
		getline(fi, cha, ' ');
		getline(fi, tmp, '(');
		getline(fi, con1, ' ');
		getline(fi, con2, ')');
		getline(fi, tmp, '\n');
		if (!t)
		{
			t = createNode(cha);
			
			if (t != NULL)
			{
				t->left = createNode(con1);
				t->right = createNode(con2);
			}
		}
		else
		{
			Node* parentNode = NULL;
			FindNode(t, parentNode, cha);
			parentNode->left = createNode(con1);
			parentNode->right = createNode(con2);
		}
	}
	fi.close();
}
void printNode(string x, int h)
{
	for (int i = 0; i < h; i++)
		cout << "\t";
	cout << x << endl;
}
void printLNR(link t, int h)
{
	if (t == nullptr)
	{
		for (int i = 0; i < h; i++)
			cout << "\t";
		cout << "*" << endl;
		return;
	}
	printLNR(t->right, h + 1);
	printNode(t->key, h);
	printLNR(t->left, h + 1);
}
void printNodeNLR(string x, int h, int n)
{
	for (int i = 0; i < n - h - 3; i++)
		cout << "\t";
	cout << x;
}
void printNLR(link t, int h, int n)
{
	if (t == nullptr)
	{
		for (int i = 0; i < n - h - 3; i++)
			cout << "\t";
		return;
	}
	printNodeNLR(t->key, h, n);
	cout << endl;
	printNLR(t->left, h + 1, n);
	printNLR(t->right, h + 1, n);
}
void printNodeLRN(string x, int h, int n)
{
	for (int i = 0; i < n - h - 3; i++)
		cout << "\t";
	cout << x;
}
void printLRN(link t, int h, int n)
{
	if (t == nullptr)
	{
		for (int i = 0; i < n - h - 3; i++)
			cout << "\t";
		return;
	}
	printLRN(t->left, h + 1, n);
	printLRN(t->right, h + 1, n);
	printNodeLRN(t->key, h, n);
	cout << endl;
}