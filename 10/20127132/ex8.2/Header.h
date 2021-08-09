#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;
unsigned hashFunc(string s, int size);
void insert(string s, unsigned long number, string name[], unsigned long phoneNumber[], int size);
void display(string name[], unsigned long phoneNumber[], int size);
int search(string s, string name[], unsigned long phoneNumber[], int size);