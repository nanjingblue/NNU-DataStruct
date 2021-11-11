//
// Created by cherry on 2021/7/30.
//
#include <iostream>
#include "LinkList.h"
using namespace std;


int main() {
    int a[] = {21,4356,54,675,4,78,43,78,4,78,3,5,56,324,768,5287,348};
    LinkList<int> list1(a, sizeof(a)/sizeof(int));
//    list1.printLinkList();
//    LinkList<int> list2(list1);
//    LinkList<int> list3;
//    list3 = list1;
////    genList(list1, list2, list3);
//    list2.printLinkList();
//    list3.printLinkList();
    list1.printByOrder();
    return 0;
}


