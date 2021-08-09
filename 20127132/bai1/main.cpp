#include "Header.h"

int main(int argc, char* argv[])
{
	int tmp, x = 2, choose = 1, a[100];
	string filename1, filename2;
	for (int i = 0; i < argc; i++)
	{
		if (i == 1)
			choose = atoi(argv[i]);
		else if (i == 2)
			x = atoi(argv[i]);
		else if (i == 3)
			filename1 = argv[i];
		else if (i == 4)
			filename2 = argv[i];
	}
	// 1 3 test1.txt out1.txt

	fstream fi;
	fi.open(filename1);
	fi >> tmp;
	int size = 0;
	while (!fi.eof())
		fi >> a[size++];
	fi.close();
	if (choose == 1)
		linearSearch(a, size, x, filename2);
	else if (choose == 2)
		SentinelLinearSearch(a, size, x, filename2);
	else if (choose == 3)
	{
		sort(a, a + size);
		binarySearch(a, size, x, filename2);
	}
	return 0;
}