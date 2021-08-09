#pragma once
#include <iostream>
#include <list>
using namespace std;
int n = 10;
int m = 5;
class Chaining
{
	int key;
	list<int>* table;
public:
	Chaining(int x)
	{
		this->key = x;
		table = new list<int>[key];
	}
	int hashFunction(int x)
	{
		return (x % key);
	}
	void insert(int x)
	{
		int index = hashFunction(x);
		table[index].push_back(x);
	}
	void display()
	{
		for (int i = 0; i < key; i++)
		{
			cout << i + 1;
			for (auto v : table[i])
				cout << " --> " << v;
			cout << endl;
		}
	}
	int search(int k)
	{
		for (int i = 0; i < key; i++)
		{
			for (auto v : table[i])
			{
				if (v == k)
					return i + 1;
			}
		}
		return -1;
	}
};


class Linear {
public:
    int val;
    int key;
    Linear(int k, int v)
    {
        this->val = k;
        this->key = v;
    }
};
class DelNode :public Linear
{
private:
    static DelNode* del;
    DelNode() :Linear(-1, -1) {}
public:
    static DelNode* getNode()
    {
        if (del == NULL)
            del = new DelNode();
        return del;
    }
};
DelNode* DelNode::del = NULL;
class LinearTable
{
private:
    Linear** li;
public:
    LinearTable()
    {
        li = new Linear * [m];
        for (int i = 0; i < m; i++)
            li[i] = NULL;
    }
    int HashFunc(int k)
    {
        return k % m;
    }
    void insert(int k, int v) 
    {
        int val = HashFunc(k);
        int init = -1;
        int index = -1;
        while (val != init && (li[val] == DelNode::getNode() || li[val] != NULL && li[val]->val != k))
        {
            if (init == -1)
                init = val;
            if (li[val] == DelNode::getNode())
                index = val;
            val = HashFunc(val + 1);
        }
        if (li[val] == NULL || val == init)
        {
            if (index != -1)
                li[index] = new Linear(k, v);
            else
                li[val] = new Linear(k, v);
        }
        if (init != val) {
            if (li[val] != DelNode::getNode())
            {
                if (li[val] != NULL) {
                    if (li[val]->val == k)
                        li[val]->key = v;
                }
            }
            else
                li[val] = new Linear(k, v);
        }
    }
    int search(int k) {
        int val = HashFunc(k);
        int init = -1;
        while (val != init && (li[val] == DelNode::getNode() || li[val] != NULL && li[val]->val != k)) {
            if (init == -1)
                init = val;
            val = HashFunc(val + 1);
        }
        if (li[val] == NULL || val == init)
            return -1;
        else
            return li[val]->key;
    }
    void display()
    {
        for (int i = 0; i < m; i++)
            cout << li[i]->val << " --> " << li[i]->key << endl;
    }
};

enum EntryType
{
    Legi, Emp, Del
};
struct DoubleHashingTable 
{
    int e;
    enum EntryType info;
};
struct DoubleHashing 
{
    int s;
     DoubleHashingTable* t;
};
int DoubleFunc1(int k, int s)
{
    return k % s;
}
int DoubleFunc2(int k, int s)
{
    return (k * s - 1) % s;
}
 DoubleHashing* initiateTableDouble(int s)
 {
     DoubleHashing* ht;
    ht = new  DoubleHashing;
    ht->s = s;
    ht->t = new DoubleHashingTable[ht->s];
    for (int i = 0; i < ht->s; i++) {
        ht->t[i].info = Emp;
        ht->t[i].e = NULL;
    }
    return ht;
}
int SearchKeyDouble(int k, DoubleHashing* ht)
{
    int val = DoubleFunc1(k, ht->s);
    int step = DoubleFunc2(k, ht->s);
    while (ht->t[val].info != Emp && ht->t[val].e != k)
    {
        val = val + step;
        val = val % ht->s;
    }
    return val;
}
void InsertDouble(int k, DoubleHashing* ht)
{
    int pos = SearchKeyDouble(k, ht);
    if (ht->t[pos].info != Legi) {
        ht->t[pos].info = Legi;
        ht->t[pos].e = k;
    }
}
void displayDouble( DoubleHashing* ht) {
    for (int i = 0; i < ht->s; i++) {
        int v = ht->t[i].e;
        if (!v)
            cout << "Position: " << i + 1 << " Element: Null" << endl;
        else
            cout << "Position: " << i + 1 << " Element: " << v << endl;
    }
}


struct QuadraticProbingEntry 
{
    int e;
    enum EntryType info;
};
struct QuadraticProbing 
{
    int s;
    QuadraticProbingEntry* t;
};
bool isPrime(int n) 
{
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
int nextPrime(int n) 
{
    if (n <= 0)
        n == 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime(n); n += 2);
    return n;
}
int HashFunc(int k, int s) 
{
    return k % s;
}
QuadraticProbing* initiateTableQuadratic(int s)
{
    QuadraticProbing* ht;
    ht = new QuadraticProbing;
    ht->s = nextPrime(s);
    ht->t = new QuadraticProbingEntry[ht->s];
    for (int i = 0; i < ht->s; i++) {
        ht->t[i].info = Emp;
        ht->t[i].e = NULL;
    }
    return ht;
}
int SearchKeyQuadratic(int k, QuadraticProbing* ht)
{
    int pos = HashFunc(k, ht->s);
    int collisions = 0;
    while (ht->t[pos].info != Emp && ht->t[pos].e != k) 
    {
        pos = pos + 2 * ++collisions - 1;
        if (pos >= ht->s)
            pos = pos - ht->s;
    }
    return pos;
}
void InsertQuadratic(int k, QuadraticProbing* ht)
{
    int pos = SearchKeyQuadratic(k, ht);
    if (ht->t[pos].info != Legi) {
        ht->t[pos].info = Legi;
        ht->t[pos].e = k;
    }
}
void displayQuadratic(QuadraticProbing* ht)
{
    for (int i = 0; i < ht->s; i++) 
    {
        int value = ht->t[i].e;
        if (!value)
            cout << "Position: " << i + 1 << " Element: Null" << endl;
        else
            cout << "Position: " << i + 1 << " Element: " << value << endl;
    }
}