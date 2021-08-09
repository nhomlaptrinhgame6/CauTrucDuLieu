#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int search(int a[], int n, int key, int start, int step);
void linearSearch(int a[], int n, int key, string filename2);
void SentinelLinearSearch(int a[], int n, int key, string filename2);
void binarySearch(int a[], int n, int key, string filename2);