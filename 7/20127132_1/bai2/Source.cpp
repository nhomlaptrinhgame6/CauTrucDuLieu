#include "Header.h"
node createNode(int x)
{
	node tmp = new ListNode;
	tmp->value = x;
	tmp->next = NULL;
	return tmp;
}
node init()
{
	node p = NULL;
	return p;
}
node addHead(node head, int x)
{
	node tmp = createNode(x);
	if (head == NULL)
		head = tmp;
	else
	{
		tmp->next = head;
		head = tmp;
	}
	return head;
}
node addLast(node head, int x)
{
	node tmp = createNode(x);
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
void output(node head)
{
	for (node p = head; p != NULL; p = p->next)
		cout << p->value << " ";
}