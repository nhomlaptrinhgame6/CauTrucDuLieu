#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
struct birthDate
{
	int day;
	int month;
	int year;
};
struct inf
{
	int MSSV;
	string name;
	birthDate birth;
	bool status;
};
class BST
{
private:
	struct Node
	{
		inf data;
		Node* left, * right;
		int N, h;
		Node(inf key)
		{
			this->data.MSSV = key.MSSV;
			this->data.name = key.name;
			this->data.birth.day = key.birth.day;
			this->data.birth.month = key.birth.month;
			this->data.birth.year = key.birth.year;
			this->data.status = key.status;
			this->left = nullptr;
			this->right = nullptr;
			this->N = 1;
		}
	};
	typedef Node* link;
	link root;

public:
	BST()
	{
		root = nullptr;
	}
	int size()
	{
		return size(root);
	}
	int size(link x)
	{
		if (x == nullptr)
			return 0;
		else
			return x->N;
	}
	int height()
	{
		return height(root);
	}
	int height(link x)
	{
		if (x == nullptr)
			return 0;
		else
			return x->h;
	}
	void printBirth(inf x)
	{
		cout << x.birth.day << "/" << x.birth.month << "/" << x.birth.year << endl;
	}
	void printNode(inf x)
	{
		cout << "Unique Code: " << x.MSSV << endl;
		cout << "Name: " << x.name << endl;
		cout << "Birth: ";
		printBirth(x);
		cout << "Status: ";
		if (x.status == 0)
			cout << "Undergrad";
		else
			cout << "Graduate";
		cout << "\n\n";
	}
	void printTree(link t)
	{
		if (t == nullptr)
			return;
		printNode(t->data);
		printTree(t->left);
		printTree(t->right);
	}
	void printTree()
	{
		printTree(root);
	}
	void insert(link& t, inf key)
	{
		if (t == nullptr)
		{
			t = new Node(key);
			return;
		}
		if (key.MSSV == t->data.MSSV)
			return;
		if (key.MSSV < t->data.MSSV)
			insert(t->left, key);
		if (key.MSSV > t->data.MSSV)
			insert(t->right, key);
		t->N = size(t->left) + size(t->right) + 1;
	}
	void insert(inf key)
	{
		insert(root, key);
	}
	void TmpNode(link& X, link& Y)
	{
		if (Y->left != NULL)
			TmpNode(X, Y->left);
		else
		{
			X->data = Y->data;
			X = Y;
			Y = Y->right;
		}
	}
	void delNode(link& t, int data, bool& check)
	{
		if (t == NULL)
			return;
		else
		{
			if (data < t->data.MSSV)
				delNode(t->left, data, check);
			else if (data > t->data.MSSV)
				delNode(t->right, data, check);
			else
			{
				Node* X = t;
				if (t->left == NULL)
					t = t->right;
				else if (t->right == NULL)
					t = t->left;
				else
					TmpNode(X, t->right);
				delete X;
				check = 1;
			}
		}
	}
	void delNode(int data, bool& check)
	{
		return delNode(root, data, check);
	}
	void FloorUniqueCode(link t, int key)
	{
		if (t == nullptr)
		{
			cout << "Do not found!\n";
			return;
		}
		if (key == t->data.MSSV)
		{
			printNode(t->data);
			return;
		}
		else if (key < t->data.MSSV)
			return FloorUniqueCode(t->left, key);
		else if (key > t->data.MSSV)
			return FloorUniqueCode(t->right, key);
	}
	void FloorUniqueCode(int key)
	{
		FloorUniqueCode(root, key);
	}
	void FloorGraduated(link t)
	{
		if (t == nullptr)
			return;
		if (1 == t->data.status)
			printNode(t->data);
		FloorGraduated(t->left);
		FloorGraduated(t->right);
	}
	void FloorGraduated()
	{
		FloorGraduated(root);
	}
	void LoadFloorGraduated(link t, inf saveNode[], int& i)
	{
		fstream fi;
		fi.open("student.txt");
		if (t == nullptr)
			return;
		if (1 == t->data.status)
			saveNode[i++] = t->data;
		LoadFloorGraduated(t->left, saveNode, i);
		LoadFloorGraduated(t->right, saveNode, i);
	}
	void LoadFloorGraduated(inf saveNode[], int& n)
	{
		int i = 0;
		LoadFloorGraduated(root, saveNode, i);
		n = i;
	}
};