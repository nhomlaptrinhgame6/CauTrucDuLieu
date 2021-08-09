#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

struct avl {
    int key;
    struct avl* left;
    struct avl* right;
};
int height(avl* t);
avl* insert(avl* t, int x);
bool check(avl* t);