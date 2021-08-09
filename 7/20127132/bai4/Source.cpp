#include "Header.h"
void addHead(Node** head, int data)
{
    Node* p = new Node();
    p->data = data;
    p->next = (*head);
    p->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = p;
    (*head) = p;
}
void insertAfter(Node* prev_node, int data)
{
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }
    Node* p = new Node();
    p->data = data;
    p->next = prev_node->next;
    prev_node->next = p;
    p->prev = prev_node;
    if (p->next != NULL)
        p->next->prev = p;
}
void addPos(Node*& head, int data, int pos)
{
    if (pos == 0 || head == NULL)
        addHead(&head, data);
    else
    {
        int k = 1;
        Node* p = head;
        while (k != pos && p != NULL)
        {
            p = p->next;
            k++;
        }
        if (pos != k)
            addLast(&head, data);
        else
        {
            if (p != NULL && p->next != NULL)
            {
                Node* temp = new Node;
                temp->data = data;
                temp->prev = p;
                temp->next = p->next;
                p->next->prev = temp;
                p->next = temp;
            }
        }
    }
}
void addLast(Node** head, int data)
{
    Node* p = new Node();
    Node* last = *head;
    p->data = data;
    p->next = NULL;
    if (*head == NULL)
    {
        p->prev = NULL;
        *head = p;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = p;
    p->prev = last;
    return;
}
void delHead(Node* &head)
{
    if (head->next==NULL)
        head = head->next;
    else if (head != NULL)
    {
        head = head->next;
        head->prev = NULL;
    }
}
void delLast(Node*& head)
{
    if (head == NULL || head->next == NULL)
        delHead(head);
    else
    {
        Node* p = head;
        while (p->next->next != NULL)
            p = p->next;
        p->next = p->next->next;
    }
}
void delPos(Node*& head, int pos)
{
    if (head == NULL || pos == 0 || head->next == NULL)
        delHead(head);
    else if (head->next->next == NULL&& pos== 1)
        delLast(head);
    else
    {
        int k = 1;
        Node* p = head;
        while (k != pos && p->next->next != NULL)
        {
            k++;
            p = p->next;
        }
        if (k != pos)
            delLast(head);
        else
        {
            Node* temp = p->next;
            Node* p2 = temp->next;
            p->next = p2;
            if (p2 != NULL)
                p2->prev = p;
            
        }//1 2 3 4 5
         // 2  4
    }
}
void printList(Node* node)
{
    if (node == NULL)
    {
        cout << "Empty !\n";
        return;
    }
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
void printList_reverse(Node* node)
{
    if (node == NULL)
    {
        cout << "Empty !\n";
        return;
    }
    Node* last = node;
    while (node != NULL)
    {
        last = node;
        node = node->next;
    }

    while (last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

void sorted(Node** head, Node* data)
{
    Node* cur;
    if (*head == NULL)
        *head = data;
    else if ((*head)->data >= data->data)
    {
        data->next = *head;
        data->next->prev = data;
        *head = data;
    }
    else
    {
        cur = *head;
        while (cur->next != NULL && cur->next->data < data->data)
            cur = cur->next;
        data->next = cur->next;
        if (cur->next != NULL)
            data->next->prev = data;
        cur->next = data;
        data->prev = cur;
    }
}
void insertionSort(Node*& head)
{
    Node* p = NULL;
    Node* cur = head;
    while (cur != NULL)
    {
        Node* q = cur->next;
        cur->prev = cur->next = NULL;
        sorted(&p, cur);
        cur = q;
    }
    head = p;
}