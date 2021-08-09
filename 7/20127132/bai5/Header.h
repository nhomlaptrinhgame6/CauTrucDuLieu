#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

struct list
{
	string name;
	int math;
	int physics;
	int chemistry;
};
struct linkedList
{
	list data;
	linkedList* next;
};
typedef struct linkedList* node;
int length(node head);
node createnode(list data);
node addHead(node head, list x);
node addLast(node head, list x);
node add_pos(node head, list x, int pos);
node delHead(node head);
node delLast(node head);
node del_pos(node head, int pos);
void searchName(node head);
int Search(node head, string x);
void printList(node head);
void writefile(list x[], int& size);
void readFile(list x[], node& head, int size);
void searchMath(node head);
void searchPhysics(node head);
void searchChemistry(node head);
int average_each(node head);
void average(node head);
node deleteByName(node head, string x);
node delSame(node head);
void MergeSort_recursive(node& head);