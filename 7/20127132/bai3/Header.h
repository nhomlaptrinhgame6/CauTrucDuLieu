#pragma once
#pragma once
#include <iostream>
using namespace std;
struct linkedList
{
	int data;
	linkedList* next;
};
typedef struct linkedList* node;

node createnode(int data);
node init();
node addHead(node head, int x);
node addLast(node head, int x);
int length(node head);
node delHead(node head);
node delLast(node head);
node del_pos(node head, int pos);
int Search(node head, int x);
void printList(node head);
void QuickSort_recursive(node& head);
void QuickSort_non_recursive(node& head);
void MergeSort_recursive(node& head);
void MergeSort_non_recursive(node& head);
void insertionSort_non_recursive(node& head);
void insertionSort_recursive(node& head);
void interchangeSort_recursive(node& head);
void interchangeSort_non_recursive(node& head);
void selectionSort_non_recursive(node& head);
void selectionSort_recursive(node& head);