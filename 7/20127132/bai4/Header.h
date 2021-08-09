#pragma once
#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
void addHead(Node** head, int data);
void insertAfter(Node* prev_node, int data);
void addLast(Node** head, int data);
void addPos(Node*& head, int data, int pos);
void delHead(Node* &head);
void delLast(Node*& head);
void delPos(Node*& head, int pos);
void printList(Node* node);
void printList_reverse(Node* node);
void insertionSort(Node*& head);