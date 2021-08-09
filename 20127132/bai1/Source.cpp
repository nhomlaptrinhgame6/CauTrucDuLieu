#include "Header.h"
int search(int a[], int n, int key, int start, int step)
{
	for (int i = start; i < n; i+=step)
		if (key == a[i])
			return i;
	return -1;
}
void linearSearch(int a[], int n, int key, string filename2)
{
	fstream fo;
	fo.open(filename2);
	int start = 0, pos = search(a, n, key, start, 1);
	while (pos != -1)
	{
		fo << pos << " ";
		start = pos + 1;
		pos = search(a, n, key, start, 1);
	}
	fo.close();
}
void SentinelLinearSearch(int a[], int n, int key, string filename2)
{
	fstream fo;
	fo.open(filename2);
	int b[100];
	int last = a[n - 1];
	a[n - 1] = key;
	int i = 0, j = 0;
	while (i < n - 2)
	{
		if (a[i] == key)
			b[j++] = i;
		i++;
	}
	a[n - 1] = last;
	if (a[n - 1] == key)
		b[j++] = n - 1;
	if (j == 0)
		b[j] = -1;
	else
	{
		for (int k = 0; k < j; k++)
			fo << b[k] << " ";
		fo << endl;
	}
	fo.close();
}
void binarySearch(int a[], int n, int key, string filename2)
{
	fstream fo;
	fo.open(filename2);
	int l = 0, r = n - 1;
	int mid = l + (r - l) / 2, count = 0;
	while (r >= l)
	{
		if (a[mid] == key)
		{
			fo << mid << " ";
			count++;
		}
		if (a[mid] > key)
			r = mid - 1;
		else l = mid + 1;
		mid = l + (r - l) / 2;
	}
	if (count == 0)
		fo << -1;
	fo.close();
	return;
}