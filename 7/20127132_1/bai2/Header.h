#pragma once
#pragma once
#include <iostream>
using namespace std;
struct ListNode
{
	int value;
	struct ListNode* next;
};
typedef struct ListNode* node;
node createNode(int x);
node init();
node addHead(node head, int x);
void output(node head);
node delHead(node head);
node addLast(node head, int x); 
node delLast(node head);