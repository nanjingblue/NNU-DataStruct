//
// Created by cherry on 2021/7/30.
//
#include <iostream>
#include "LinkList.h"
#include "Head/demo01Test.h"
using namespace std;

void test01() {
    int a[10] = {1, 2, 3, 4, 5 ,6,7,8,9,10};
    LinkList<int> list1(a, 10);
    cout << list1.listLength() << endl;
    list1.printLinkList();
    cout << "第5个元素为" << list1.get(5) << endl;
    list1.insert(1, 520);
    list1.printLinkList();
    list1.Delete(1);
    list1.printLinkList();
    cout << list1.locate(9) << endl;
    list1.invert();
    list1.printLinkList();
}


int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[6] = {4,6,8,9,11,14};

    LinkList<int> L1(a, 10);
    LinkList<int> L2(b, 6);

    Merge(L1, L2);
    L1.printLinkList();

    return 0;
}
