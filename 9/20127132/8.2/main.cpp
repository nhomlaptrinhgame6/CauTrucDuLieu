#include "Header.h"
int main()
{

    int n;
    fstream fi;
    fstream fo;
    string tmp;
    fi.open("input.txt");
    fo.open("output.txt");
    fi >> n;
    getline(fi, tmp, '\n');
    while (!fi.eof())
    {
        avl* tree = NULL;
        getline(fi, tmp);
        for (int i = 0; i < tmp.size(); i++)
        {
            int k = 0;
            if (tmp[i] != ' ' || tmp[i] != '\0')
            {
                int j;
                for ( j = i; j < tmp.size(); j++)
                {
                    if (tmp[j] == ' ' || tmp[j] == '\0')
                        break;
                    k = k * 10 + tmp[j] - '0';
                }
                i = j;
            }
            if (k != 0)
                tree = insert(tree,k);
        }
        if (check_avl(tree) == 1)
            fo << "Yes\n";
        else
            fo << "No\n";

    }
    fi.close();
    fo.close();
    return 0;
}