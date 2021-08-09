#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct dictionary
{
	string word;
	string mean;
};
struct input
{
	string word;
};
void read(string filename, dictionary x[], int arr[], int& count);
string search(string filename, dictionary x[], string key, int arr[], char b[], int count);