#include "Header.h"
char lowcase(char a)
{
	if (a >= 65 && a <= 90)
		a += 32;
	return a;
}
void read(string filename, dictionary x[], int arr[], int &count)
{
	int i = 0, j = 0;
	fstream fi;
	fi.open(filename);
	while (!fi.eof())
	{
		getline(fi, x[i].word, ':');
		char tmp1 = lowcase(x[i - 1].word[0]);
		char tmp2 = lowcase(x[i].word[0]);
		if (tmp1 != tmp2)
			arr[j++] = i;
		getline(fi, x[i++].mean, '\n');
	}
	fi.close();
	count = i;
}
string search(string filename, dictionary x[], string key, int arr[], char b[], int count)
{
	int a = 0;
	string tmp;
	for (int i = 0; i < 26; i++)
		if (lowcase(key[0]) == b[i])
		{
			a = arr[i];
			break;
		}
	for (int i = a; i <= count; i++)
	{
		if (key == x[i].word)
		{
			tmp = x[i].mean;
			break;
		}
	}
	return tmp;
}