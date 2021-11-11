#include <iostream>
#include "SeqList.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int a[10] = {1,2,3,4,6,7,8,9,10,11};
    SeqList<int, 100> list(a, 10);
    list.traserse();
    list.insertOrder(5);
    list.traserse();
    return 0;
}
