#include "Header.h"
unsigned hashFunc(string s, int size)
{
    unsigned val = 0;
    for (int i = 0; i < s.size(); i++)
        val = s[i] + 31 * val;
    return val % size;
}
void insert(string s, unsigned long number,string name[], unsigned long phoneNumber[], int size)
{
    unsigned index = hashFunc(s, size);
    while (name[index] != "")
        index = (index + 1) % size;
    name[index] = s;
    phoneNumber[index] = number;
}
void display(string name[], unsigned long phoneNumber[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (name[i] == "\0")
            continue;
        cout << name[i] << " : " << phoneNumber[i] << endl;
    }
}
int search(string s, string name[], unsigned long phoneNumber[], int size)
{
    int index = hashFunc(s, size);
    while (name[index] != s and name[index] != "")
        index = (index + 1) % size;
    if (name[index] == s)
        return index;
    else
        return -1;
}