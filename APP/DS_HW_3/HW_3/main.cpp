#include <iostream>
#include "LinkList.h"
#include "SeqList.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {5,8,4,6,2,1,7};
    int len = sizeof(a) / sizeof(int);
    // LinkList<int> list(a, len);
    // cout << "循环链表的长度: "<< list.listLength() << endl;
    // list.printLinkList();
    
    SeqList<int, 20> list(a, len);
    list.traserse();
    list.splitByA(1);
    list.traserse();
    return 0;
}
