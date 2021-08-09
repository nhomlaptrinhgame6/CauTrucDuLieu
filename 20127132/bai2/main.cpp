#include "Header.h"
dictionary y[150000];
int main(int argc, char* argv[])
{
	input x[100];
	string filename;
	int j = 0;
	for (int i = 2; i < argc; i++)
	{
		if (i == argc - 1)
			filename = argv[i];
		else
			x[j++].word = argv[i];
	}
	
	//alphabet
	char a = 'a';
	char b[27];
	for (int i = 0; i < 26; i++)
		b[i] = a++;
	//save position
	int arr[100];

	//dem so tu vung
	int count = 0;

	//read file
	read("dictionary.txt", y, arr, count);
	cout << count;

	//write file
	fstream fo;
	fo.open(filename);
	for (int i = 0; i < j; i++)
		fo << x[i].word << ": " << search(filename, y, x[i].word, arr, b, count) << endl;
	fo.close();
	return 0;
}