#include "Header.h"
int length(node head)
{
	int count = 0;
	for (node p = head; p != NULL; p = p->next)
		count++;
	return count;
}
node createnode(int data)
{
	node tmp = new linkedList;
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}
node init()
{
	node head;
	head = NULL;
	return head;
}
node addHead(node head, int x)
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
node addLast(node head, int x)
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
node add_pos(node head, int x, int pos)
{
	node p = head;
	int k = 1;
	if (pos == 0 || head==NULL)
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
int Search(node head, int x)
{
	int pos = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data == x)
			return pos;
		pos++;
	}
	return -1;
}
int Search_val(node head, int pos)
{
	int k = 0;
	node p = head;
	while (p->next != NULL && k != pos)
	{
		++k;
		p = p->next;
	}
	return p->data;
}
node Search_node(node head, int pos)
{
	int k = 0;
	node p = head;
	while (p->next != NULL && k != pos)
	{
		++k;
		p = p->next;
	}
	return p;
}
void printList(node head)
{
	if (head == NULL)
	{
		cout << "Empty\n";
		return;
	}
	for (node p = head; p != NULL; p = p->next)
		cout << p->data << " ";
}
node append(node head, node sub)
{
	node p1 = head, p2 = sub;
	while (p1->next != NULL)
		p1 = p1->next;
	p1->next = p2;
	return head;
}
void split1(node head, node& l1, node& l2, int x)
{
	if (head == NULL)
		return;
		
	node p = head;
	if (p->data <= x)
		l1 = addHead(l1, p->data);
	else
		l2= addLast(l2, p->data);
	return split1(p->next, l1, l2, x);
}


//Quick Sort recursive
void QuickSort_recursive_sub_sub(node& l1, int x, int pos)
{
	if (pos == length(l1))
		return;
	node p = l1;
	int y = Search_val(l1, pos);
	if (y <= x)
	{
		l1 = del_pos(l1, Search(l1, x));//xóa vị trí hiện tại của cờ trong l1
		l1 = add_pos(l1, x, pos);//thêm vào trước vị trí lớn hơn cờ (trái->phải)
	}
	return QuickSort_recursive_sub_sub(l1, x, pos + 1);
	
}
void QuickSort_recursive_sub(node head, node& l1, node& l2)
{
	if (head == NULL)
		return;
	node p = head; //cờ
	int x = 0;
	if (Search(l1, p->data) != -1) //cờ ở trong l1
		QuickSort_recursive_sub_sub(l1, p->data, x);
	else //cờ ở trong l2
		QuickSort_recursive_sub_sub(l2, p->data, x);
	return QuickSort_recursive_sub(p->next, l1, l2);//tăng vị trí cờ
}
void QuickSort_recursive(node& head)
{
	node l1 = init(), l2 = init();
	node tag, p;
	tag = head;
	p = head;
	//chia thành 2 danh sách lớn hơn nút đầu thì l1, ngược lại l2
	split1(p, l1, l2, tag->data);
	//sort
	QuickSort_recursive_sub(p->next, l1, l2);
	head = append(l1, l2);
}


//Quick Sort non recursive
void QuickSort_non_recursive_sub_sub(node& l1, int x)
{
	int pos = 0;
	node p = l1;
	while (pos != length(l1))
	{
		int y = Search_val(l1, pos);
		if (y <= x)
		{
			l1 = del_pos(l1, Search(l1, x));//xóa vị trí hiện tại của cờ trong l1
			l1 = add_pos(l1, x, pos);//thêm vào trước vị trí lớn hơn cờ (trái->phải)
		}
		pos++;
	}
}
void QuickSort_non_recursive_sub(node head, node& l1, node& l2)
{
	if (head == NULL)
		return;
	node p = head; //cờ
	while (p != NULL)
	{
		if (Search(l1, p->data) != -1) //cờ ở trong l1
			QuickSort_non_recursive_sub_sub(l1, p->data);
		else //cờ ở trong l2
			QuickSort_non_recursive_sub_sub(l2, p->data);
		p = p->next;
	}
}
void QuickSort_non_recursive(node& head)
{
	node l1 = init(), l2 = init();
	node tag, p;
	tag = head;
	p = head;
	//chia thành 2 danh sách lớn hơn nút đầu thì l1, ngược lại l2
	split1(p, l1, l2, tag->data);
	//sort
	QuickSort_non_recursive_sub(p->next, l1, l2);
	head = append(l1, l2);
}


//Merge Sort recursive
node merge(node l1, node l2)
{
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	node p = init();
	if (l1->data < l2->data)
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
	node l1 = init(), l2 = init();
	if (head == NULL || head->next == NULL)
		return;
	//chia danh sách
	splitMerge(head, l1, l2);

	MergeSort_recursive(l1);
	MergeSort_recursive(l2);
	head = merge(l1, l2);
}


//Merge Sort non recursive
void merge_non_recursive(node& l1, node& l2, node& l3, node& l4)
{
	node temp = NULL;
	if (l1->data > l3->data)
	{
		swap(l1, l3);
		swap(l2, l4);
	}

	// Merging remaining nodes
	node l11 = l1, l22 = l2;
	node l33 = l3, l44 = l4;
	node l44_tmp = l4->next;
	while (l11 != l22 && l33 != l44_tmp)
	{
		if (l11->next->data > l33->data)
		{
			temp = l33->next;
			l33->next = l11->next;
			l11->next = l33;
			l33 = temp;
		}
		l11 = l11->next;
	}
	if (l11 == l22)
		l11->next = l33;
	else
		l4 = l2;
}
void MergeSort_non_recursive(node& head)
{
	if (head == NULL)
		return;
	node l1 = init(), l2 = init(), l3 = init(), l4 = init();
	node p = NULL;
	int size = length(head);

	for (int i = 1; i < size; i = i * 2)
	{
		l1 = head;
		while (l1)
		{
			// l1 ở đầu
			bool a = 0;
			if (l1 == head)
				a = 1;

			// tách
			int count = i;
			l2 = l1;
			while (--count && l2->next)
				l2 = l2->next;

			l3 = l2->next;
			if (l3 == NULL)
				break;
			count = i;
			l4 = l3;
			while (--count && l4->next)
				l4 = l4->next;

			// save value
			node temp = l4->next;

			// Merge
			merge_non_recursive(l1, l2, l3, l4);

			// cập nhật danh sách
			if (a == 1)
				head = l1;
			else
				p->next = l1;
			p = l4;
			l1 = temp;
		}
		if (p !=NULL)
			p->next = l1;
	}
}


//insertion sort non recursive
void insertionSort_recursive_sub(node& head, node l1, node l2)
{
	if (head == NULL)
		return;
	
	if (l1 == NULL)
	{
		l1 = l2;
		return insertionSort_recursive_sub(head->next, l1, l2);
	}
	node cur = l1;
	node p = head;
	if (cur->data > p->data)
	{
		int tmp = cur->data;
		cur->data = p->data;
		p->data = tmp;
		return insertionSort_recursive_sub(head, cur, l2);
	}
	else
		return insertionSort_recursive_sub(head, cur->next, l2);

}
void insertionSort_recursive(node& head)
{
	if (head == NULL)
		return;
	node p = head;
	node l1 = head;
	node l2 = head;
	insertionSort_recursive_sub(head, l1, l2);
}


//insertion sort non recursive
void insertionSort_non_recursive(node& head)
{
	node p = head;
	while (p != NULL)
	{
		node cur = head;
		while (cur != p->next)
		{
			if (cur->data > p->data)
			{
				int tmp = cur->data;
				cur->data = p->data;
				p->data = tmp;
			}
			else
				cur = cur->next;
		}
		p = p->next;
	}
}



//selection sort recursive
void selectionSort_recursive_sub(node& head, node l1, node& l2)
{
	if (head->next == NULL)
		return;
	node min_idx = l2;
	node q = l1;
	node p = head;
	
	if (min_idx->data > q->data)
		min_idx = q;
	if (l1->next == NULL)
	{
		int tmp = min_idx->data;
		min_idx->data = p->data;
		p->data = tmp;
		return selectionSort_recursive_sub(p->next, p->next->next, p->next);
	}
	return selectionSort_recursive_sub(p, q->next, min_idx);
}
void selectionSort_recursive(node& head)
{
	if (head == NULL)
		return;
	node p = head;
	node l1 = head->next;
	node l2 = head;
	selectionSort_recursive_sub(head, l1, l2);
}



//selection sort non recursive
void selectionSort_non_recursive(node& head)
{
	node p = head;
	while (p->next != NULL)
	{
		node min_idx = p;
		node q = p->next;
		while (q != NULL)
		{
			if (min_idx->data > q->data)
				min_idx = q;
			q = q->next;
		}
		int tmp = min_idx->data;
		min_idx->data = p->data;
		p->data = tmp;
		p = p->next;
	}
}




//Interchange Sort recursive
void interchangeSort_recursive_sub(node& head, node l1)
{
	if (head->next == NULL)
		return;
	node p = head;
	node cur = l1;
	if (cur == NULL)
		return interchangeSort_recursive_sub(p->next, p->next->next);
		
	if (cur->data < p->data)
	{
		int tmp = cur->data;
		cur->data = p->data;
		p->data = tmp;
	}
	return interchangeSort_recursive_sub(p, cur->next);

}
void interchangeSort_recursive(node& head)
{
	if (head == NULL)
		return;
	node p = head;
	node l1 = head->next;
	interchangeSort_recursive_sub(head, l1);
}

//Interchange Sort non recursive
void interchangeSort_non_recursive(node& head)
{
	node p = head;
	while (p->next != NULL)
	{
		node cur = p->next;
		while (cur != NULL)
		{
			if (cur->data < p->data)
			{
				int tmp = cur->data;
				cur->data = p->data;
				p->data = tmp;
			}
			cur = cur->next;
		}
		p = p->next;
	}
}