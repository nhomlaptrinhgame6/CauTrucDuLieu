#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node
{
	string key;
	Node* left, * right;
};
typedef Node* link;
void FindNode(link root, Node*& find, string data);
void readFile(link& t, int& n);
void printNode(string x, int h);
void printLNR(link t, int h);
Node* createNode(string s);
void printNLR(link t, int h, int n);
void printLRN(link t, int h, int n);